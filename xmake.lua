add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

add_requires("gtk4")

target("Part-2")
    set_kind("binary")
    set_languages("c11")
    set_optimize("fastest")
    add_packages("gtk4")
    add_includedirs("Part-2")
    add_files("Part-2/**.c")