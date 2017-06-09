/*
 * File: language.cc
 *
 */
#include <iostream>
#include <string>

#include "language.h"

LANGUAGE::LANGUAGE()
{
    memset(_data, 0, sizeof(_data));
    _length = 0;
}

LANGUAGE::LANGUAGE(const char* str)
{
    if (str != NULL) {
        strncpy(_data, str, sizeof(_data) - 1);
        _length = strlen(str);
    }
}

LANGUAGE::~LANGUAGE()
{
}

int LANGUAGE::Compare(LANGUAGE& src, int start)
{
    return strcmp(_data, src._data);
}


