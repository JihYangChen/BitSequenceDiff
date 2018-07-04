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
	BitSequenceList getMinDiffBitAmountListWithMSTApproximation();

private:
	vector<BitSequence *> bitSequenceList;
	vector<struct Edge> kruskalMST();
	vector<struct Edge> getSortedEdges();
	void preorderTraversal(BitSequence *currentVertex, vector<struct Edge> &edgesetsMST, vector<BitSequence *> &resultList);
};

#endif
