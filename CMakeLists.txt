cmake_minimum_required(VERSION  3.17.1)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
# set(CMAKE_CXX_COMPILER /usr/local/bin/x86_64-apple-darwin20-g++-10)
# set(CMAKE_BUILD_TYPE Release)


file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/ph/${PROJECT_NAME}/*.hpp src/pch.pch)

add_library(${PROJECT_NAME} SHARED
    ${HEADERS}
    ${SOURCES}   
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/pch.pch)

# target_include_directories(${PROJECT_NAME} PUBLIC include)

target_include_directories(${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ph/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/ph/${PROJECT_NAME}>
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:include>
    $<INSTALL_INTERFACE:include>
)

