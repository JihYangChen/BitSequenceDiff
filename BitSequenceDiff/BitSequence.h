#ifndef BITSEQUENCE_H
#define BITSEQUENCE_H

#include <string>
using std::string;

class BitSequence {
public:
	BitSequence(string bitSequence);
	int calculateDiffBitAmount(BitSequence &otherSequence);
	string getBitSequence();

private:
	string bitSequence;
};

#endif