cmake_minimum_required(VERSION 3.0.0)
project(heap_espaconave)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp heap.cpp espacoNave.cpp passageiro.cpp recurso.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(heap_espaconave ${SOURCE_FILES})
add_custom_target(run
    COMMAND heap_espaconave
    DEPENDS heap_espaconave
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})