#pragma once

#include "platform.h"

#ifdef _WIN64

std::string readFile(const char* filename);

std::string parseToken(std::string in);

#endif  

