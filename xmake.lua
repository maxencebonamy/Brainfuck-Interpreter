add_rules("mode.debug", "mode.release")
add_includedirs("src")
set_rundir(".")

target("main")
    set_kind("binary")
    add_files("src/**.cpp")
