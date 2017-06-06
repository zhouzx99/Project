/*
 * syntax.h
 *
 * */

#ifndef _VOICE_SYNTAX_H_
#define _VOICE_SYNTAX_H_

#include "metadata.h"

class CSyntax {

private:
    CMetaData _root;
    CAction   _action;
    int _timeout;

public:
    CSyntax();
    ~CSyntax();

public:
    int Init(void);
    int BuildSyntaxTree(void);
    int TimeOut(int ms);
    int Parse(CSentence& data);
};

#endif /* _VOICE_SYNTAX_H_ */
