
#include "lv2/lv2plug.in/ns/lv2core/lv2.h"
#include "lv2/lv2plug.in/ns/extensions/ui/ui.h"

// xwidgets.h includes xputty.h and all defined widgets from Xputty
#include "xwidgets.h"
#include "xmidi_keyboard.h"


#include "./Xmonc.h"

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                define controller numbers
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

#define CONTROLS 5

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                the main LV2 handle->XWindow
-----------------------------------------------------------------------
----------------------------------------------------------------------*/
// png's linked in as binarys
EXTLD(mandala_png)

// main window struct
typedef struct {
    void *parentXwindow;
    Xputty main;
    Widget_t *win;
    Widget_t *widget;
    Widget_t *button;
    Widget_t *key_button;
    Widget_t *keyboard;
    MidiKeyboard *keys;
    int block_event;

    void *controller;
    LV2UI_Write_Function write_function;
    LV2UI_Resize* resize;
} X11_UI;


// if controller value changed send notify to host
static void value_changed(void *w_, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    X11_UI* ui = (X11_UI*)w->parent_struct;
    if (ui->block_event != w->data) 
        ui->write_function(ui->controller,w->data,sizeof(float),0,&w->adj->value);
    ui->block_event = -1;
}

// if controller value changed send notify to host
static void adj_changed(Widget_t *w, PortIndex index, float value) {
    X11_UI* ui = (X11_UI*)w->parent_struct;
    if (ui->block_event != index) 
        ui->write_function(ui->controller,index,sizeof(float),0,&value);
    ui->block_event = -1;
}

// draw the window
static void draw_window(void *w_, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    if (!w) return;
    XWindowAttributes attrs;
    XGetWindowAttributes(w->app->dpy, (Window)w->widget, &attrs);
    int width = attrs.width;
    int height = attrs.height;
    double state_x = adj_get_state(w->adj_x);
    double state_y = adj_get_state(w->adj_y);
    
    double pos_x1 = 4.0 + (double)((width-8) * state_x);
    double pos_y1 = height-( 4.0 + (double)((height-8) * state_y));
    
    double pos_x2 = width/2. + ((width/3.9) * (state_x-0.5));
    double pos_y2 = height/2 - ((width/3.9) * (state_y-0.5));

    cairo_pattern_t *pat;

    pat = cairo_pattern_create_linear (0.0, 0.0,  0.0+pos_y1, width+pos_x1);
    cairo_pattern_add_color_stop_rgba (pat, 1, 0, 0, 0, 1);
    cairo_pattern_add_color_stop_rgba (pat, 0, 1, 1, 1, 1);
    cairo_rectangle(w->crb,0,0,width,height);
    cairo_set_source (w->crb, pat);
    cairo_fill (w->crb);
    cairo_pattern_destroy (pat);

    pat = cairo_pattern_create_radial (pos_x2, pos_y2, 25.6,
                                       width/2.8, height/2.8, width/2);
    cairo_pattern_add_color_stop_rgba (pat, 0, 1, 1, 1, 1);
    cairo_pattern_add_color_stop_rgba (pat, 1, 0, 0, 0, 1);
    cairo_set_source (w->crb, pat);
    cairo_arc (w->crb, width/2, height/2, width/4, 0, 2 * M_PI);
    cairo_fill (w->crb);
    cairo_pattern_destroy (pat);

    widget_set_scale(w);
    cairo_set_source_surface (w->crb, w->image, 0, 0);
    cairo_paint(w->crb);
    widget_reset_scale(w);

    use_fg_color_scheme(w, get_color_state(w));
    cairo_move_to(w->crb, pos_x1, pos_y1);
    cairo_line_to(w->crb, pos_x1, pos_y1);
    cairo_set_line_width(w->crb, 8.0);
    cairo_set_line_cap (w->crb,CAIRO_LINE_CAP_ROUND);
    cairo_stroke(w->crb);
    
}

static void _motion(void *w_, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    if (!w) return;
    adj_changed(w,VOWEL,adj_get_value(w->adj_x));
    adj_changed(w,NOTE,adj_get_value(w->adj_y));

   // transparent_draw(w_,NULL); 
}

static void window_button_press(void *w_, void* button, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    if (!w) return;
    adj_changed(w, GATE, 1.0);
}

static void window_button_release(void *w_, void* button_, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    if (!w) return;
    adj_changed(w, GATE, 0.0);
    
}

static void get_note(Widget_t *w, int *key, bool on_off) {
    X11_UI* ui = (X11_UI*)w->parent_struct;
    if (on_off) {
        //adj_set_value(w->adj_y, (float)(*key));
        adj_changed(w,NOTE,(float)(*key));
        adj_changed(w, GATE, 1.0);    
    } else {
        if(!have_key_in_matrix(ui->keys->key_matrix)) {
            adj_changed(w, GATE, 0.0);
        }
    }
}

static void get_pitch(Widget_t *w,int *value) {
    //X11_UI* ui = (X11_UI*)w->parent_struct;
    //fprintf(stderr, "get pitch wheel value %i\n",(*value));
}

static void get_mod(Widget_t *w,int *value) {
    adj_changed(w,VOWEL,(float)(*value)/32.0);
    //fprintf(stderr, "get mod wheel value %i\n",(*value));
}

static void get_all_sound_off(Widget_t *w,int *value) {
    adj_changed(w, GATE, 0.0);
}

static void key_button_callback(void *w_, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    Widget_t *p = w->parent;
    X11_UI* ui = (X11_UI*)p->parent_struct;
    
    if (w->flags & HAS_POINTER && adj_get_value(w->adj)){
        widget_show_all(ui->keyboard);
    }
    if (w->flags & HAS_POINTER && !adj_get_value(w->adj)){
        widget_hide(ui->keyboard);
    }
}

// init the xwindow and return the LV2UI handle
static LV2UI_Handle instantiate(const struct _LV2UI_Descriptor * descriptor,
            const char * plugin_uri, const char * bundle_path,
            LV2UI_Write_Function write_function,
            LV2UI_Controller controller, LV2UI_Widget * widget,
            const LV2_Feature * const * features) {

    X11_UI* ui = (X11_UI*)malloc(sizeof(X11_UI));

    if (!ui) {
        fprintf(stderr,"ERROR: failed to instantiate plugin with URI %s\n", plugin_uri);
        return NULL;
    }

    ui->parentXwindow = 0;
    LV2UI_Resize* resize = NULL;
    ui->block_event = -1;

    int i = 0;
    for (; features[i]; ++i) {
        if (!strcmp(features[i]->URI, LV2_UI__parent)) {
            ui->parentXwindow = features[i]->data;
        } else if (!strcmp(features[i]->URI, LV2_UI__resize)) {
            resize = (LV2UI_Resize*)features[i]->data;
        }
    }

    if (ui->parentXwindow == NULL)  {
        fprintf(stderr, "ERROR: Failed to open parentXwindow for %s\n", plugin_uri);
        free(ui);
        return NULL;
    }
    // init Xputty
    main_init(&ui->main);
    // create the toplevel Window on the parentXwindow provided by the host
    ui->win = create_window(&ui->main, (Window)ui->parentXwindow, 0, 0, 300, 300);
     // store a pointer to the X11_UI struct in the parent_struct Widget_t field
    ui->win->parent_struct = ui;
    widget_get_png(ui->win, LDVAR(mandala_png));
    ui->win->adj_x = add_adjustment(ui->win,2.0, 2.0, 0.0, 4.0, 0.02, CL_CONTINUOS);
    ui->win->adj_y = add_adjustment(ui->win,40.0, 40.0, 28.0, 52.0, 0.1, CL_CONTINUOS);
    //ui->win->func.adj_callback = _motion;
    ui->win->func.value_changed_callback = _motion;
    ui->win->func.button_press_callback = window_button_press;
    ui->win->func.button_release_callback = window_button_release;
    // connect the expose func
    ui->win->func.expose_callback = draw_window;

    // create a slider widget
    ui->widget = add_vslider(ui->win, "Gain", 5, 10, 40, 280);
    // store the port index in the Widget_t data field
    ui->widget->data = GAIN;
    // store a pointer to the X11_UI struct in the parent_struct Widget_t field
    ui->widget->parent_struct = ui;
    // set the slider adjustment to the needed range
    set_adjustment(ui->widget->adj,0.0, 0.25, 0.0, 1.0, 0.005, CL_CONTINUOS);
    // connect the value changed callback with the write_function
    ui->widget->func.value_changed_callback = value_changed;

    ui->key_button = add_image_toggle_button(ui->win, "Keyboard", 260, 10, 30, 30);
    widget_get_png(ui->key_button, LDVAR(midikeyboard_png));
    ui->key_button->func.value_changed_callback = key_button_callback;


    // create a combobox widget
    ui->button = add_combobox(ui->win, "", 200, 260, 90, 30);
    combobox_add_entry(ui->button,"---");
    combobox_add_entry(ui->button,"12-ET");
    combobox_add_entry(ui->button,"19-ET");
    combobox_add_entry(ui->button,"24-ET");
    combobox_add_entry(ui->button,"31-ET");
    combobox_add_entry(ui->button,"41-ET");
    combobox_add_entry(ui->button,"53-ET");
    combobox_set_active_entry(ui->button, 0);
    // store the port index in the Widget_t data field
    ui->button->data = SCALE;
    // store a pointer to the X11_UI struct in the parent_struct Widget_t field
    ui->button->parent_struct = ui;
    // connect the value changed callback with the write_function
    ui->button->func.value_changed_callback = value_changed;

    ui->keyboard = open_midi_keyboard(ui->win);
    ui->keys = (MidiKeyboard*)ui->keyboard->parent_struct;
    ui->keys->mk_send_note = get_note;
    ui->keys->mk_send_pitch = get_pitch;
    ui->keys->mk_send_mod = get_mod;
    ui->keys->mk_send_all_sound_off = get_all_sound_off;
    
    // finally map all Widgets on screen
    widget_show_all(ui->win);
    // set the widget pointer to the X11 Window from the toplevel Widget_t
    *widget = (void*)ui->win->widget;
    // request to resize the parentXwindow to the size of the toplevel Widget_t
    if (resize){
        ui->resize = resize;
        resize->ui_resize(resize->handle, 300, 300);
    }
    // store pointer to the host controller
    ui->controller = controller;
    // store pointer to the host write function
    ui->write_function = write_function;
    
    return (LV2UI_Handle)ui;
}

// cleanup after usage
static void cleanup(LV2UI_Handle handle) {
    X11_UI* ui = (X11_UI*)handle;
    // Xputty free all memory used
    main_quit(&ui->main);
    free(ui);
}

/*---------------------------------------------------------------------
-----------------------------------------------------------------------    
                        LV2 interface
-----------------------------------------------------------------------
----------------------------------------------------------------------*/

// port value change message from host
static void port_event(LV2UI_Handle handle, uint32_t port_index,
                        uint32_t buffer_size, uint32_t format,
                        const void * buffer) {
    X11_UI* ui = (X11_UI*)handle;
    float value = *(float*)buffer;
    int i=0;
    for (;i<CONTROLS;i++) {
        if (port_index == GAIN) {
            check_value_changed(ui->widget->adj, &value);
            // prevent event loop between host and plugin
            ui->block_event = (int)port_index;
        } else if (port_index == VOWEL) {
            check_value_changed(ui->win->adj_x, &value);
            // prevent event loop between host and plugin
            ui->block_event = (int)port_index;
        } else if (port_index == NOTE) {
            check_value_changed(ui->win->adj_y, &value);
            // prevent event loop between host and plugin
            ui->block_event = (int)port_index;
        } else if (port_index == SCALE) {
            check_value_changed(ui->button->adj, &value);
            // prevent event loop between host and plugin
            ui->block_event = (int)port_index;
        }
    }
}

// LV2 idle interface to host
static int ui_idle(LV2UI_Handle handle) {
    X11_UI* ui = (X11_UI*)handle;
    // Xputty event loop setup to run one cycle when called
    run_embedded(&ui->main);
    return 0;
}

// LV2 resize interface to host
static int ui_resize(LV2UI_Feature_Handle handle, int w, int h) {
    X11_UI* ui = (X11_UI*)handle;
    // Xputty sends configure event to the toplevel widget to resize itself
    if (ui) send_configure_event(ui->win,0, 0, w, h);
    return 0;
}

// connect idle and resize functions to host
static const void* extension_data(const char* uri) {
    static const LV2UI_Idle_Interface idle = { ui_idle };
    static const LV2UI_Resize resize = { 0 ,ui_resize };
    if (!strcmp(uri, LV2_UI__idleInterface)) {
        return &idle;
    }
    if (!strcmp(uri, LV2_UI__resize)) {
        return &resize;
    }
    return NULL;
}

static const LV2UI_Descriptor descriptor = {
    PLUGIN_UI_URI,
    instantiate,
    cleanup,
    port_event,
    extension_data
};


LV2_SYMBOL_EXPORT
const LV2UI_Descriptor* lv2ui_descriptor(uint32_t index) {
    switch (index) {
        case 0:
            return &descriptor;
        default:
        return NULL;
    }
}

