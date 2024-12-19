add_executable(ne

../lib/generic.h
../lib/hash.h
../lib/misc.h
../lib/regexp.h
../lib/term.h
block.c
block.h
crt.c
crt.h
cursor.c
cursor.h
disp.c
disp.h
ed.h
file.c
file.h
filer.c
filer.h
function.h
hearderr.c
input.c
input.h
iskanji.c
iskanji.h
kanji.h
keyf.c
keyf.h
keys.c
line.c
line.h
lineedit.c
lineedit.h
list.c
list.h
menu.c
ne.c
ne.h
profile.c
profile.h
search.c
search.h
setopt.c
setopt.h
sh.h
sh_defs.h
sh_shells.c
)
target_compile_definitions(ne PRIVATE -DSYSCONFDIR="${SYSCONFDIR}" -DPROG="${PROG}" -DVER="${VER}")
target_include_directories(ne
    # The location of the headers before installation 
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    # The location of the headers after installation
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(ne ele
    ${TERMCAP_LIB}
    ${NCURSES_LIB}
    ${CURSES_LIB}
)

add_custom_command(
    PRE_BUILD
    OUTPUT sh_defs.h sh_shells.c
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${CMAKE_BINARY_DIR}/lib/sh_make ${CMAKE_CURRENT_BINARY_DIR}/sh_shells.c > ${CMAKE_CURRENT_BINARY_DIR}/sh_defs.h
    DEPENDS sh_make function.h
)
