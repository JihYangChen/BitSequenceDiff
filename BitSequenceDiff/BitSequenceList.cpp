#include "BitSequenceList.h"

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