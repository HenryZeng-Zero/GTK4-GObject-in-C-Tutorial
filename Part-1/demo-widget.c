#include "demo-widget.h"

static void demo_widget_dispose(GObject* object);
static void demo_widget_finalize(GObject* object);

struct _DemoWidget {
    GtkWidget parent_instance;
    GtkWidget *button;
};

G_DEFINE_TYPE(DemoWidget, demo_widget, GTK_TYPE_WIDGET)

static void
demo_widget_init(DemoWidget *self){
    GtkWidget *widget = GTK_WIDGET(self);
    
    self->button = gtk_button_new_with_label("Hello, world!");
    gtk_widget_set_hexpand(self->button, TRUE);
    gtk_widget_set_parent(self->button, widget);
}

static void
demo_widget_class_init(DemoWidgetClass *klass){

}

/* public method*/

GtkWidget *
demo_widget_new(void){
    return g_object_new(DEMO_TYPE_WIDGET,NULL);
}