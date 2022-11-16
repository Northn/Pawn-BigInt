cmake_minimum_required(VERSION 3.9)
project(Pawn-BigInt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/third-party/samp-cmake)
include(AddSAMPPlugin)

include_directories(third-party)

add_samp_plugin(${PROJECT_NAME} src/main.cpp src/common.h src/plugin.cpp src/plugin.h src/script.cpp src/script.h src/native_param.h src/plugin.def)
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/EHsc")
endif ()
