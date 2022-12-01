cmake_minimum_required(VERSION 3.16)

project(practice    VERSION 0.1.0
                    DESCRIPTION "practice app"
                    LANGUAGES C CXX)

set(SOURCES 
    main.cpp)

add_executable(app ${SOURCES})