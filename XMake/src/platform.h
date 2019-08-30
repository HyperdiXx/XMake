#pragma once


#ifdef _WIN64

    #define _CRT_SECURE_NO_WARNINGS
    #define OS "WINDOWS"
    #define CONFIG "X64"
    #define MAXLENGHT 1000

#include <iostream>
#include <fstream>
#include <cstdio>

#elif __linux__

#endif