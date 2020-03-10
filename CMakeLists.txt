cmake_minimum_required(VERSION 3.15)
project(oop_lab_01)

set(CMAKE_CXX_STANDARD 14)



include_directories (/System/Library/Frameworks)
find_library (GLUT_LIBRARY GLUT)
find_library (OpenGL_LIBRARY OpenGL)
mark_as_advanced (GLUT_LIBRARY
        OpenGL_LIBRARY)
set (EXTRA_LIBS ${GLUT_LIBRARY} ${OpenGL_LIBRARY})



add_executable(oop_lab_01 main.cpp point.h point.cpp model.h defines.h model.cpp)

target_link_libraries(oop_lab_01 ${EXTRA_LIBS})