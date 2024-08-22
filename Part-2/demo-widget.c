#include "demo-widget.h"

enum /* 从 1 开始的原因：0 是被 gobjcet 系统保留的 */
{
    PROP_LABEL = 1,
    N_PROPERTIES
};

static GParamSpec *properties[N_PROPERTIES];

static void demo_widget_dispose(GObject* object);
static void demo_widget_finalize(GObject* object);

struct _DemoWidget {
    GtkWidget parent_instance;
    GtkWidget *button;
};

G_DEFINE_TYPE(DemoWidget, demo_widget, GTK_TYPE_WIDGET)

/* private method */

static void
demo_widget_set_property(   GObject *object, 
                            guint property_id, 
                            const GValue *value, 
                            GParamSpec *pspec)
{
    DemoWidget *self = DEMO_WIDGET(object);

    switch (property_id)
    {
        case PROP_LABEL:
            demo_widget_set_label(self, g_value_get_string(value));
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}

static void
demo_widget_get_property(   GObject *object, 
                            guint property_id, 
                            GValue *value,
                            GParamSpec *pspec)
{
    DemoWidget *self = DEMO_WIDGET(object);

    switch (property_id)
    {
        case PROP_LABEL:
            g_value_set_string(value,demo_widget_get_label(self));
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}

static void
demo_widget_dispose(GObject* object)
{
    DemoWidget *self = DEMO_WIDGET(object);

    g_clear_pointer(&self->button, gtk_widget_unparent);

    G_OBJECT_CLASS(demo_widget_parent_class)->dispose(object);
}

static void
demo_widget_finalize(GObject* object)
{
    G_OBJECT_CLASS(demo_widget_parent_class)->finalize(object);
}

static void
demo_widget_init(DemoWidget *self)
{
    GtkWidget *widget = GTK_WIDGET(self);
    
    self->button = gtk_button_new_with_label("Hello, world!");
    gtk_widget_set_hexpand(self->button, TRUE);
    gtk_widget_set_parent(self->button, widget);
}

static void
demo_widget_class_init(DemoWidgetClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);
    GParamFlags default_flags = G_PARAM_READWRITE | 
                                G_PARAM_STATIC_STRINGS |
                                G_PARAM_EXPLICIT_NOTIFY;

    /* 映射虚函数 */

    object_class->dispose = demo_widget_dispose;
    object_class->finalize = demo_widget_finalize;

    object_class->set_property = demo_widget_set_property;
    object_class->get_property = demo_widget_get_property;

    /* 注册属性 */

    properties[PROP_LABEL] = g_param_spec_string(
        "label",
        "Button label",
        "Set label name for button in DemoWidget",
        "Hi",
        default_flags
    );

    g_object_class_install_properties(object_class, N_PROPERTIES, properties);

    /* 设置默认的布局管理器 */
    gtk_widget_class_set_layout_manager_type(GTK_WIDGET_CLASS(klass), GTK_TYPE_BOX_LAYOUT);
}

/* public method */

GtkWidget *
demo_widget_new(void)
{
    return g_object_new(DEMO_TYPE_WIDGET,NULL);
}

void
demo_widget_set_label(DemoWidget *self, const gchar *label)
{
    gtk_button_set_label(GTK_BUTTON(self->button), label);
    g_object_notify_by_pspec(G_OBJECT(self),properties[PROP_LABEL]);
}

const gchar *
demo_widget_get_label(DemoWidget *self){
    return gtk_button_get_label(GTK_BUTTON(self->button));
}