cmake_minimum_required(VERSION 3.9)
project(brainfuck-interpretor C)

include_directories(include)

add_executable(bfi src/main.c src/parser.c src/loops.c src/interpretor.c src/init.c)
