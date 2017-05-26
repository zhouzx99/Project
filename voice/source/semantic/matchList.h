/*
 * matchList.h
 *
 * */

#ifndef _MATCH_LIST_H_
#define _MATCH_LIST_H_

#include "token.h"

class CMatchList {
private:
    CToken _list[32];
    VOICE_SEMANTIC_LANGUAGE_TYPE _type;

public:
    CMatchList(){}
    ~CMatchList(){}
};

#endif /* _MATCH_LIST_H_ */

