cmake_minimum_required(VERSION 3.15)
project(oop_lab_01)

set(CMAKE_CXX_STANDARD 14)



include_directories (/System/Library/Frameworks)
find_library (GLUT_LIBRARY GLUT)
find_library (OpenGL_LIBRARY OpenGL)
mark_as_advanced (GLUT_LIBRARY
        OpenGL_LIBRARY)
set (EXTRA_LIBS ${GLUT_LIBRARY} ${OpenGL_LIBRARY})



add_executable(oop_lab_01 main.cpp point/point.h point/point.cpp frameModel/model.h defines.h frameModel/model.cpp frameModel/modelRotation.h frameModel/frameStructure.h frameModel/modelRotation.cpp drawing/drawing.h drawing/drawing.cpp frameModel/zoom.h frameModel/zoom.cpp matrix/matrix.h matrix/matrix.cpp manager/myManager.h manager/myManager.cpp glutWindow/myGLUT.h glutWindow/myGLUT.cpp drawing/colorsDefine.h request/request.cpp request/request.h glutWindow/glutDefines.h)

target_link_libraries(oop_lab_01 ${EXTRA_LIBS})