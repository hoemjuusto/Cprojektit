cmake_minimum_required(VERSION 3.13)
project(Cprojektit C)

set(CMAKE_C_STANDARD 99)

add_executable(Cprojektit source.c testi.c main.cpp fraction.h fraction.c queue.h queue.c maintesti.c gameoflife.h gameoflife.c bits.h bits.c tcpheader.c tcpheader.h xorcipher.c xorcipher.h macros.h compare.c)