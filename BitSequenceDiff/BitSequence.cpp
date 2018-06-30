#include "BitSequence.h"

BitSequence::BitSequence(string bitSequence) : bitSequence(bitSequence) {}

int BitSequence::calculateDiffBitAmount(BitSequence &otherSequence) {
	int count = 0;
	for (int i = 0; i < bitSequence.length(); i++) {
		if (bitSequence[i] ^ otherSequence.bitSequence[i])
			count++;
	}
	return count;
}

string BitSequence::getBitSequence() {
	return bitSequence;
}