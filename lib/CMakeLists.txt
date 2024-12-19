add_library(ele STATIC
generic.c generic.h
hash.c hash.h misc.h
misc.c 
regexp.c regexp.h
term.c term.h
term_inkey.c ../src/ed.h ../src/kanji.h ../src/disp.h ../src/setopt.h
tparm.c
)
target_include_directories(ele
    # The location of the headers before installation 
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    # The location of the headers after installation
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(sh_make
sh_make.c
)
