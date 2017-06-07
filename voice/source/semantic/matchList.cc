/*
 * File: matchList.cc
 *
 */

#include "matchList.h"


CMatchList::CMatchList()
{
}

CMatchList::~CMatchList()
{
}

CMatchResult CMatchList::MatchToken(CSentence& data)
{
    int i = 0;
	CMatchResult current();
	CMatchResult best();
	
	best = current;
	for (i = 0; i < 32; i++) {
		current = _list[i].Match(data);
		if (current < best) {
			best = current;
		}
	}
	return best;
}

