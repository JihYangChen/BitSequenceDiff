#ifndef SEQUENCEFILEREADER_H
#define SEQUENCEFILEREADER_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class BitSequenceFileReader {
public:
	BitSequenceFileReader(string fileName);
	vector<string> readSequences();

private:
	string fileName;
};

#endif
