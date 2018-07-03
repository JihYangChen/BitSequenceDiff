#ifndef BITSEQUENCE_H
#define BITSEQUENCE_H

#include <string>
#include <map>
using std::string;
using std::map;

class BitSequence {
public:
	BitSequence(string bitSequence);
	int calculateDiffBitAmount(BitSequence &otherSequence);
	string getBitSequence();

private:
	string bitSequence;
	map<BitSequence *, int> diffBitAmountMap;
};

#endif