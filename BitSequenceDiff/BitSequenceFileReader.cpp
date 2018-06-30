#include "BitSequenceFileReader.h"
#include <iostream>
#include <fstream>
using namespace std;

BitSequenceFileReader::BitSequenceFileReader(string fileName) : fileName(fileName) {}

vector<string> BitSequenceFileReader::readSequences() {
	ifstream file(fileName);
	string line;
	vector<string> sequenseList;

	if (file.is_open()) {
		while (getline(file, line)) {
			sequenseList.push_back(line);
		}
		file.close();
	}
	else {
		std::cerr << "Exception occured when reading file" + fileName + "\n";
		system("PAUSE");
		exit(-1);
	}

	return sequenseList;
}