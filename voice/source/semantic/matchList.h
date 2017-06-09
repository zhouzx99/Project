/*
 * matchList.h
 *
 * */

#ifndef _MATCH_LIST_H_
#define _MATCH_LIST_H_

#include "token.h"

class CMatchList {
private:
    CToken _list[32]; /* first match long token */
    VOICE_SEMANTIC_LANGUAGE_TYPE _type;

public:
    CMatchList();
    ~CMatchList();

public:
    int AddToken(CToken& token);
    CMatchResult MatchToken(CSentence& data);
};

#endif /* _MATCH_LIST_H_ */

