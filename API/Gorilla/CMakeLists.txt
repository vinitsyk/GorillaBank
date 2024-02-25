cmake_minimum_required(VERSION 3.22)
project(Gorilla CXX)

include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cxx)

target_link_libraries(${PROJECT_NAME} PRIVATE pqxx)
target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp)
target_link_libraries(${PROJECT_NAME} PRIVATE hiredis)

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

target_compile_options(${PROJECT_NAME} PRIVATE -O3 -pedantic -fomit-frame-pointer -finline-functions -mtune=native -march=native -g -pthread -Wvla)

aux_source_directory(controllers CTL_SRC)

target_sources(${PROJECT_NAME} PRIVATE ${CTL_SRC})