/*
 * syntaxFactory.h
 *
 * */

#ifndef _VOICE_SYNTAX_FACTORY_H_
#define _VOICE_SYNTAX_FACTORY_H_

#include "metadata.h"

typedef enum {
    VOICE_SYNTAX_TYPE_NONE   = 0,
    VOICE_SYNTAX_TYPE_NORMAL = 1
} VOICE_SYNTAX_TYPE;

class CSyntaxFactory {

public:
    static CMetaData* CreateSyntaxTree(VOICE_SYNTAX_TYPE type = VOICE_SYNTAX_TYPE_NORMAL);

};

#endif /* _VOICE_SYNTAX_FACTORY_H_ */
