#include <iostream>
#include "BitSequenceFileReader.h"
#include "BitSequenceList.h"
using std::cout;

int main(int argc, char *argv[]) {
	BitSequenceFileReader bitSequenceFileReader("inputSequence.txt");
	BitSequenceList bitSequenceList = bitSequenceFileReader.readSequences();
	
	cout << "Bit Sequence List: \n" << bitSequenceList.getDisplayString() << "\n";
	cout << "Sequence list different bit amount: " << bitSequenceList.calculateDiffBitAmount() << "\n\n";
	
	BitSequenceList MinDiffBitAmountList = bitSequenceList.getMinDiffBitAmountListWithBruteForce();
	cout << "Minimum different bit amount sequence list : \n" << MinDiffBitAmountList.getDisplayString() << "\n";
	cout << "Minimum sequence list different bit amount: " << MinDiffBitAmountList.calculateDiffBitAmount() << "\n";

	system("PAUSE");
	return 0;
}