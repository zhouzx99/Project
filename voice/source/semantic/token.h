
/***
 *
 *  token.h
 *
 ***/

#ifndef _CTOKEN_H_
#define _CTOKEN_H_

#include "language.h"
#include "matchResult.h"
#include "sentence.h"

class CToken {

private:
    LANGUAGE _value;
    VOICE_SEMANTIC_LANGUAGE_TYPE _type;

public:
    CToken(){}
    ~CToken(){}

    LANGUAGE* Value();
    unsigned int Length();
    VOICE_SEMANTIC_LANGUAGE_TYPE Type();

    VOICE_SEMANTIC_STATUS Set(LANGUAGE* val, VOICE_SEMANTIC_LANGUAGE_TYPE type);
    CMatchResult Match(CSentence& data);
};

#endif /* _CTOKEN_H_ */

