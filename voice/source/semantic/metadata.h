/*
 * metadata.h
 *
 * */

#ifndef _VOICE_METADATA_H_
#define _VOICE_METADATA_H_

#include "matchList.h"
#include "action.h"

class CMetaData {

private:
    CMatchList _list;

    CMetaData* _parent;
    CMetaData* _brother;
    CMetaData* _child;

public:
    CMetaData(){}
    ~CMetaData(){}

public:
    int Match(LANGUAGE* data, CAction& action);
};

#endif /* _VOICE_METADATA_H_ */
