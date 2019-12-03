#pragma once

#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "platform.h"
#include "string.h"

class ConfigParser
{
public:

};

String
readFile(const char* filename);

String
parseToken(String *str);

bool
compare(const char* src, const char *val);


#endif // !PARSER_H

