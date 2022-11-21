add_rules("mode.debug", "mode.release")
add_includedirs("src")
set_allowedarchs("x64")

target("brainfuck")
    set_kind("binary")
    add_files("src/**.cpp")
    set_rundir(".")
