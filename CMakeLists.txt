cmake_minimum_required(VERSION 3.14)

project(SimpleATMController
    VERSION 1.0.0
    DESCRIPTION "Simple ATM controller"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(bank_api 
    src/BackAPI.cpp
    src/KoreaBank.cpp)
target_include_directories(bank_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(seoul_atm src/main.cpp)
target_link_libraries(seoul_atm PRIVATE bank_api)