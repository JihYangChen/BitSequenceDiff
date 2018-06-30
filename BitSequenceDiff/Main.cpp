#include <iostream>
#include "BitSequenceFileReader.h"
using std::cout;

int calculateSequencesBitwiseXORAmount(const string sequenceA, const string sequenceB) {
	int count = 0;
	for (int i = 0; i < sequenceA.length(); i++) {
		if (sequenceA[i] ^ sequenceB[i])
			count++;
	}
	return count;
}

int calculateSequenceListXORAmount(const vector<string>& sequenceList) {
	int totalCount = 0;
	for (auto sequence = sequenceList.begin(); sequence != sequenceList.end() - 1; sequence++)
		totalCount += calculateSequencesBitwiseXORAmount(*sequence, *(sequence + 1));
	return totalCount;
}

int main(int argc, char *argv[]) {
	BitSequenceFileReader bitSequenceFileReader("inputSequence.txt");

	vector<string> bitSequenceList = bitSequenceFileReader.readSequences();
	for (auto it : bitSequenceList)
		cout << it << '\n';

	cout << "Sequences bitwise difference amount: " << calculateSequenceListXORAmount(bitSequenceList) << "\n";

	system("PAUSE");
	return 0;
}

