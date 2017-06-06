
/***
 *
 *  matchResult.h
 *
 ***/

#ifndef _CMATCH_RESULT_H_
#define _CMATCH_RESULT_H_

#include "token.h"

class CMatchResult {

private:
    CToken* _token;
    int     _start;

public:
    CMatchResult(CToken* token, int start);
    CMatchResult(CMatchResult& res);
    ~CMatchResult();

    bool operator<(CMatchResult& res);
    
};

#endif /* _CMATCH_RESULT_H_ */


