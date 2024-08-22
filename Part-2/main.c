#include <stdio.h>
#include "demo-widget.h"

static void
activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *demo;

    (void)user_data; /* unused */

    window = gtk_application_window_new(app);
    demo = demo_widget_new();

    g_object_set(demo, "label", "Change property", NULL);

    gtk_window_set_title(GTK_WINDOW(window), "window-example-2");
    gtk_window_set_default_size(GTK_WINDOW(window), 720, 480);
    gtk_window_set_child(GTK_WINDOW(window), demo);
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
}

int
main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("rikki.gtk.example-2", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}