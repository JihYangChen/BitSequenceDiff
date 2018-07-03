#include "BitSequence.h"

BitSequence::BitSequence(string bitSequence) : bitSequence(bitSequence) {}

int BitSequence::calculateDiffBitAmount(BitSequence &otherSequence) {
	int count = 0;
	if (diffBitAmountMap.find(&otherSequence) == diffBitAmountMap.end()) {
		for (int i = 0; i < bitSequence.length(); i++) {
			if (bitSequence[i] ^ otherSequence.bitSequence[i])
				count++;
		}
		diffBitAmountMap[&otherSequence] = count;
	}
	else {
		count = diffBitAmountMap[&otherSequence];
	}
	return count;
}

string BitSequence::getBitSequence() {
	return bitSequence;
}