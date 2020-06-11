cmake_minimum_required(VERSION 3.0)
project(kevin)

 INCLUDE_DIRECTORIES(
  include
  ${CMAKE_SOURCE_DIR}/include
  )

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

find_package (Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR}/unsupported/)
include_directories(${EIGEN3_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR}/supported/)



ADD_LIBRARY(quaternion ${CMAKE_SOURCE_DIR}/src/quaternion.cpp)
ADD_LIBRARY(node ${CMAKE_SOURCE_DIR}/src/Node.cpp)
ADD_LIBRARY(frame ${CMAKE_SOURCE_DIR}/src/Frame.cpp)

ADD_EXECUTABLE(run ${CMAKE_SOURCE_DIR}/main.cpp)
TARGET_LINK_LIBRARIES(run quaternion)
TARGET_LINK_LIBRARIES(run node)
TARGET_LINK_LIBRARIES(frame quaternion)
TARGET_LINK_LIBRARIES(frame node)
TARGET_LINK_LIBRARIES(run frame)


# Define a distclean target to remove every generated file:
ADD_CUSTOM_TARGET(distclean
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
  COMMAND ${CMAKE_COMMAND} -E remove_directory CMakeFiles
  COMMAND ${CMAKE_COMMAND} -E remove CMakeCache.txt cmake_install.cmake Makefile
  COMMENT "distclean invoked"
  )