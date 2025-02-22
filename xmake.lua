
add_requires("libsdl3")

target("shmup-game")
    set_languages("c11")
    set_kind("binary")
    add_files("src/*.c")
    add_packages("libsdl3")