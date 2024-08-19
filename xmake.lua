add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

add_requires("gtk4")

target("Init")
    set_kind("binary")
    set_languages("c11")
    set_optimize("fastest")
    add_packages("gtk4")
    add_includedirs("include")
    add_files("src/**.c")