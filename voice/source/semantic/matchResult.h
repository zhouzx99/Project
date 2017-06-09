
/***
 *
 *  matchResult.h
 *
 ***/

#ifndef _CMATCH_RESULT_H_
#define _CMATCH_RESULT_H_

#include "token.h"

class CToken;
class CMetaData;
class CMatchResult;

class CMatchResult {

private:
    CToken*      _token;
    int          _start;
    CMetaData*   _data;

public:
    CMatchResult();
    CMatchResult(CToken* token, int start);
    CMatchResult(CMatchResult& res, CMetaData* data);
    CMatchResult(CMatchResult& res);
    ~CMatchResult();

    unsigned int GetCurrentOffset();
    CMetaData* GetMatchedMetadata();
    CToken* GetMatchedToken();
    bool Result(void);
    bool operator<(CMatchResult& res);
    
};

#endif /* _CMATCH_RESULT_H_ */


