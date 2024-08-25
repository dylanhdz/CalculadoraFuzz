cmake_minimum_required(VERSION 3.10)
project(deber_act3)

set(CMAKE_CXX_STANDARD 11)

# Añadir esta línea para encontrar la biblioteca pthread
find_package(Threads REQUIRED)

add_executable(calculadora main.cpp)

# Compilar pruebas.cc como una biblioteca compartida
add_library(fuzzer SHARED pruebas.cc)

# Enlazar la biblioteca pthread a los ejecutables
target_link_libraries(calculadora ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(fuzzer ${CMAKE_THREAD_LIBS_INIT} ${LIB_FUZZING_ENGINE})