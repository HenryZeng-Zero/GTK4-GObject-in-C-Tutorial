# GTK4/GObject in C Tutorial

这份学习记录是按照 Youtube 课程 [GTK4/GObject in C Tutorial](https://www.youtube.com/playlist?list=PLFnRB0VoVErpBiFZlMg_JAPKdJJobzyV3) 推进的，

## 用 GObject 创建自定义 Widget 类

根据 [GObject Tutorial - Boilerplate header code](https://docs.gtk.org/gobject/tutorial.html#boilerplate-header-code)

需要为你的头文件和源代码选择一个名称约定，并坚持使用：
+ 使用 "-" 来分隔 前缀 和 类型名称: `viewer-file.h` 和 `viewer-file.c` (这种约定被大部分 GNOME 库以及应用程序所采用)
+ 使用 "_" 来分隔 前缀 和 类型名称: `viewer_file.h` 和 `viewer_file.c`
+ 不分隔 前缀 和 类型名称: `viewerfile.h` 和 `viewerfile.c` (这种约定被 GTK 所采用)

尽管视频中采用的是不分隔 前缀 和 类型名称的风格，但是为了阅读方便，我并没有采用这种方式，而是选用 GNOME 的默认命名风格。

---

在 Part-1/