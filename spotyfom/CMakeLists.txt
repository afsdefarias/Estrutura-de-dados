cmake_minimum_required(VERSION 3.23)
project(spotyfom C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(spotyfom
        main.c
        spotyfom.c
        spotyfomAndre.c
        spotyfomAndre.h)
