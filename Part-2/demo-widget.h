#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS // 在 C++ 编译器下会被替换成 extern "C" { 使用 C 接口，防止破坏 abi

/* 类型定义 */

#define DEMO_TYPE_WIDGET demo_widget_get_type()
G_DECLARE_FINAL_TYPE(DemoWidget, demo_widget, DEMO, WIDGET, GtkWidget)

/* 方法定义 */

GtkWidget *
demo_widget_new(void);

void
demo_widget_set_label(DemoWidget *self, const gchar *label);

const gchar *
demo_widget_get_label(DemoWidget *self);

G_END_DECLS // 在 C++ 编译器下会被替换成 }