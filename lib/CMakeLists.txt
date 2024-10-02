add_library(liblebron
    tuple.c
    math.c
    color.c
    canvas.c
    mat2.c
    mat3.c
    mat4.c
)
target_include_directories(liblebron PUBLIC ../include)