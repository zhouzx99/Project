/*
 * metadata.h
 *
 * */

#ifndef _VOICE_METADATA_H_
#define _VOICE_METADATA_H_

#include "matchList.h"
#include "action.h"
#include "sentence.h"

class CMatchResult;
class CMatchList;
class CSentence;
class CAction;

class CMetaData {

private:
    CMatchList _list;

    CMetaData* _parent;
    CMetaData* _brother;
    CMetaData* _child;

public:
    CMetaData();
    ~CMetaData();

public:
    int Match(CSentence& data, CAction& action);
    CMetaData* Brother(void);
    CMatchResult MatchToken(CSentence& data);
    CMatchResult MatchBrother(CSentence& data);
    CMatchResult MatchChild(CSentence& data);
};

#endif /* _VOICE_METADATA_H_ */
