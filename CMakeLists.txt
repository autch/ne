cmake_minimum_required(VERSION 3.0)
project(ne VERSION 3.05 LANGUAGES C)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

set(VER "3.05")
set(PROG "ne")
set(SYSCONFDIR "${CMAKE_INSTALL_PREFIX}/etc/ne")
set(RETSIGTYPE "void")

# Checks for programs.
find_program(CC NAMES gcc cc)
if(NOT CC)
    message(FATAL_ERROR "C compiler not found")
endif()

# Checks for libraries.
find_library(TERMCAP_LIB termcap)
find_library(NCURSES_LIB ncurses)
find_library(CURSES_LIB curses)

if(NOT TERMCAP_LIB AND NOT NCURSES_LIB AND NOT CURSES_LIB)
    message(FATAL_ERROR "None of termcap, ncurses, or curses libraries found")
endif()

# Checks for header files.
include(CheckIncludeFile)
check_include_file("fcntl.h" HAVE_FCNTL_H)
check_include_file("unistd.h" HAVE_UNISTD_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("time.h" HAVE_TIME_H)
check_include_file("stdarg.h" HAVE_STDARG_H)
check_include_file("varargs.h" HAVE_VARARGS_H)
check_include_file("regex.h" HAVE_REGEX_H)
check_include_file("sys/utsname.h" HAVE_SYS_UTSNAME_H)
check_include_file("dirent.h" HAVE_DIRENT_H)

check_include_file("termcap.h" HAVE_TERMCAP_H)
check_include_file("termio.h" HAVE_TERMIO_H)
check_include_file("termios.h" HAVE_TERMIOS_H)

if(HAVE_TIME_H AND HAVE_SYS_TIME_H)
    set(TIME_WITH_SYS_TIME 1)
endif()

# Checks for typedefs, structures, and compiler characteristics.
include(CheckTypeSize)
check_type_size("off_t" OFF_T)
check_type_size("size_t" SIZE_T)
check_type_size("pid_t" PID_T)

include(CheckStructHasMember)
check_struct_has_member("struct tm" "tm_zone" "time.h" HAVE_STRUCT_TM)

# Checks for library functions.
# (Add checks for specific functions if needed)
include(CheckSymbolExists)
check_symbol_exists("select" "sys/select.h" HAVE_SELECT)
check_symbol_exists("strdup" "string.h" HAVE_STRDUP)
check_symbol_exists("strsep" "string.h" HAVE_STRSEP)
check_symbol_exists("strstr" "string.h" HAVE_STRSTR)
check_symbol_exists("strftime" "time.h" HAVE_STRFTIME)
check_symbol_exists("flock" "unistd.h" HAVE_FLOCK)
check_symbol_exists("mkdir" "unistd.h" HAVE_MKDIR)


include(CheckLibraryExists)
check_library_exists("termcap" "tgetent" "" HAVE_LIBTERMCAP)

# Configure a header file to pass some of the CMake settings


configure_file(
 "${PROJECT_SOURCE_DIR}/lib/config.h.cmake"
 "${PROJECT_BINARY_DIR}/lib/config.h"
)
configure_file(
 "${PROJECT_SOURCE_DIR}/src/config.h.cmake"
 "${PROJECT_BINARY_DIR}/src/config.h"
)

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(src)