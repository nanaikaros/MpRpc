cmake_minimum_required(VERSION 3.0.0)
project(mprpc VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
link_directories(${PROJECT_SOURCE_DIR}/lib)

#add_executable(mprpc main.cpp)
#example包含了mprpc框架使用的示例代码
add_subdirectory(example)
#src包含了mprpc框架所有相关的代码
add_subdirectory(src)
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
