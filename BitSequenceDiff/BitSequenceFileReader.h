#ifndef SEQUENCEFILEREADER_H
#define SEQUENCEFILEREADER_H

#include "BitSequenceList.h"

class BitSequenceFileReader {
public:
	BitSequenceFileReader(string fileName);
	BitSequenceList readSequences();

private:
	string fileName;
};

#endif