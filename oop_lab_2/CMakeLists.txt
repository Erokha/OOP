cmake_minimum_required(VERSION 3.15)
project(OOP_lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_lab_2 main.cpp BaseMatrix.h Matrix.h Array.h errors.h constIterator.h Iterator.h implement/matrixConstructors.hpp implement/matrixGettersAndSetters.hpp implement/matrixPlusMinus.hpp implement/matrixEquals.hpp implement/matrixMultiplyDivision.hpp implement/matrixPrivate.hpp implement/matrixInOutOperators.hpp implement/matrixMath.hpp implement/iteratorImp.hpp implement/constIteratorImp.hpp)