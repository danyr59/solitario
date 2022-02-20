cmake_minimum_required(VERSION 3.5)

project(solitario CXX)

include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

include_directories(engine/)




# add_subdirectory(ui)
add_subdirectory(engine)

add_executable(
  ${PROJECT_NAME}.run
  main.cpp
)


target_link_libraries(
  ${PROJECT_NAME}.run
  PUBLIC A_ENGINE
)

set_property(
  TARGET ${PROJECT_NAME}.run
  PROPERTY ${CMAKE_CXX_STANDARD}
)


add_test(
  NAME ${PROJECT_NAME}
  COMMAND ./${PROJECT_NAME}.run
  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
