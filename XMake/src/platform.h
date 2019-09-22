#pragma once

#if defined (_WIN64)

    #define PLATFORM_WINDOWS

#elif defined (__linux__)

    #define PLATFORM_LINUX

#endif

#ifdef PLATFORM_WINDOWS

    #define WIN32_LEAN_AND_MEAN
    //#define _CRT_SECURE_NO_WARNINGS
    #define OS "WINDOWS"
    #define CONFIG "X64"
    #define MAXLENGHT 1000

#include <iostream>
#include <fstream>
#include <cstdio>

#elif defined PLATFORM_LINUX
    
    #define OS "LINUX"
    #define CONFIG "X64"
    #define MAXLENGHT 1000

#include <unistd.h>

#endif


