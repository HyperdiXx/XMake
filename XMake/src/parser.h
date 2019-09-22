#pragma once

#include "platform.h"
#include "string.h"

#ifdef _WIN64

std::string readFile(const char* filename);

std::string parseToken(char* in);

bool compare(const char* src, const char *val);

#endif  

