cmake_minimum_required(VERSION 3.10)
project(labels-in-video)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules" CACHE STRING "Modules for CMake" FORCE)

find_package(FFmpeg REQUIRED)

add_executable(stream stream.cpp)
target_link_libraries(stream
        ${FFMPEG_LIBRARY}
        )
