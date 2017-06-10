/*
 * language.h
 * */

#ifndef _LANGUAGE_H_
#define _LANGUAGE_H_

#include <iostream>

//typedef char LANGUAGE;

#define VOICE_PRINT printf

typedef enum {
    VOICE_SEMANTIC_LANGUAGE_TYPE_ERROR = -1,
    VOICE_SEMANTIC_LANGUAGE_TYPE_NONE = 0,
    VOICE_SEMANTIC_LANGUAGE_TYPE_ROOM = 1,
    VOICE_SEMANTIC_LANGUAGE_TYPE_ACTION = 2,
    VOICE_SEMANTIC_LANGUAGE_TYPE_OBJ = 3,

} VOICE_SEMANTIC_LANGUAGE_TYPE;

typedef enum {
    VOICE_SEMANTIC_ERROR = -1,
    VOICE_SEMANTIC_OK = 0
} VOICE_SEMANTIC_STATUS;


class LANGUAGE {

private:
    char _data[1024];
    unsigned int _length;

public:
    LANGUAGE();
    LANGUAGE(const char* str);
    ~LANGUAGE();

public:
    const char* c_str() {return _data; }
    unsigned int Length(){ return _length; }
    int Compare(LANGUAGE& src, int start = 0);
};

#define VOICE_SEMANTIC_LANGUAGE_SET(DST, SRC) do{ (DST) = (SRC); }while(0)

#endif /* _LANGUAGE_H_ */
