#include "demo-widget.h"

static void demo_widget_dispose(GObject* object);
static void demo_widget_finalize(GObject* object);

struct _DemoWidget {
    GtkWidget parent_instance;
    GtkWidget *button;
};

G_DEFINE_TYPE(DemoWidget, demo_widget, GTK_TYPE_WIDGET)

/* private method */

static void
demo_widget_dispose(GObject* object){
    DemoWidget *self = DEMO_WIDGET(object);

    g_clear_pointer(&self->button, gtk_widget_unparent);

    G_OBJECT_CLASS(demo_widget_parent_class)->dispose(object);
}

static void
demo_widget_finalize(GObject* object){
    G_OBJECT_CLASS(demo_widget_parent_class)->finalize(object);
}

static void
demo_widget_init(DemoWidget *self){
    GtkWidget *widget = GTK_WIDGET(self);
    
    self->button = gtk_button_new_with_label("Hello, world!");
    gtk_widget_set_hexpand(self->button, TRUE);
    gtk_widget_set_parent(self->button, widget);
}

static void
demo_widget_class_init(DemoWidgetClass *klass){
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->dispose = demo_widget_dispose;
    object_class->finalize = demo_widget_finalize;

    /* 设置默认的布局管理器 */
    gtk_widget_class_set_layout_manager_type(GTK_WIDGET_CLASS(klass), GTK_TYPE_BOX_LAYOUT);
}

/* public method */

GtkWidget *
demo_widget_new(void){
    return g_object_new(DEMO_TYPE_WIDGET,NULL);
}