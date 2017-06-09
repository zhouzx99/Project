/*
 * sentence.h
 *
 * */

#ifndef _VOICE_SENTENCE_H_
#define _VOICE_SENTENCE_H_

#include "token.h"

class CSentence {

private:
    LANGUAGE _data;
    int      _pos;

public:
    CSentence();
    CSentence(LANGUAGE& str);
    ~CSentence();

public:
    int Init(void);
    int Reset(void);
    int Match(CToken& token);
};

#endif /* _VOICE_SENTENCE_H_ */

