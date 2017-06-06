
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

    LANGUAGE* Value() { return &_value; }
    VOICE_SEMANTIC_LANGUAGE_TYPE Type() { return _type; }

    VOICE_SEMANTIC_STATUS Set(LANGUAGE* val, VOICE_SEMANTIC_LANGUAGE_TYPE type)
    {
        VOICE_SEMANTIC_LANGUAGE_SET(&_value, val);
	    _type = type;
	    return VOICE_SEMANTIC_OK;
    }

    CMatchResult Match(CSentence& data);
};

#endif /* _CTOKEN_H_ */

