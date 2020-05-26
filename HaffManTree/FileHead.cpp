#include "FileHead.h"



FileHead::FileHead()
{
}

void FileHead::setFileLen(int fileLen)
{
	this->fileLen = fileLen;
}



int FileHead::getFileLen()
{
	return this->fileLen;
}

void FileHead::setFileType(const char *fileType)
{
	strcpy_s(this->fileType,fileType);
}

char * FileHead::getFileType()
{
	return this->fileType;
}

int * FileHead::getWeight()
{
	return this->weight;
}


void FileHead::setWeight(int * weight)
{
	for (int i = 0; i < 256; i++)
	{
		this->weight[i] = weight[i];
	}
}

FileHead::~FileHead()
{
}
