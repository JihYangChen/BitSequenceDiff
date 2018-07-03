#include "BitSequenceList.h"
#include <algorithm>
using std::next_permutation;
using std::sort;

BitSequenceList::BitSequenceList(vector<BitSequence *> bitSequenceList) : bitSequenceList(bitSequenceList) {}

int BitSequenceList::calculateDiffBitAmount() {
	int totalCount = 0;
	for (auto sequence = bitSequenceList.begin(); sequence != bitSequenceList.end() - 1; sequence++)
		totalCount += (*sequence)->calculateDiffBitAmount(**(sequence + 1));
	return totalCount;
}

string BitSequenceList::getDisplayString() {
	string displayString = "";
	for (int i = 0; i < bitSequenceList.size(); i++)
		displayString += "[" + std::to_string(i+1) + "]: " + bitSequenceList[i]->getBitSequence() + "\n";
	return displayString;
}

BitSequenceList BitSequenceList::getMinDiffBitAmountListWithBruteForce() {
	vector<BitSequence *> permutationBitSequenceList = bitSequenceList;
	sort(permutationBitSequenceList.begin(), permutationBitSequenceList.end());
	
	BitSequenceList minDiffBitAmountList(permutationBitSequenceList);
	int minDiffBitAmount = minDiffBitAmountList.calculateDiffBitAmount();

	while (next_permutation(permutationBitSequenceList.begin(), permutationBitSequenceList.end())) {
		BitSequenceList list(permutationBitSequenceList);
		int diffBitAmount = list.calculateDiffBitAmount();
		if (diffBitAmount < minDiffBitAmount) {
			minDiffBitAmount = diffBitAmount;
			minDiffBitAmountList = list;
		}
	};

	return minDiffBitAmountList;
}