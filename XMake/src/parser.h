#pragma once

#include "platform.h"
#include "string.h"

#ifdef _WIN64

String 
readFile(const char* filename);

String 
parseToken(String *str);

bool 
compare(const char* src, const char *val);


#endif  

