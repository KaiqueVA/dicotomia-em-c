cmake_minimum_required(VERSION 3.28)
project(CLion C)

set(CMAKE_C_STANDARD 17)

add_executable(CLion main.c calculo.c exibicao.c allocation.c)

