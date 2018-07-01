#ifndef BITSEQUENCELIST_H
#define BITSEQUENCELIST_H

#include "BitSequence.h"
#include <vector>
using std::vector;

class BitSequenceList {
public:
	BitSequenceList(vector<BitSequence *> bitSequenceList);
	int calculateDiffBitAmount();
	string getDisplayString();
	BitSequenceList getMinDiffBitAmountListWithBruteForce();

private:
	vector<BitSequence *> bitSequenceList;
};

#endif
