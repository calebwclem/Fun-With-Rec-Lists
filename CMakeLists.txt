cmake_minimum_required(VERSION 4.0)
project(reclistsStudentVersion)

set(CMAKE_CXX_STANDARD 20)

add_executable(reclistsStudentVersion main.cpp lex.cpp parser.cpp reclists.cpp solutions.cpp
        solutions.cpp)
