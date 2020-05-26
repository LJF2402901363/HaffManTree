#pragma once
#include<string>
#include<iostream>
using namespace std;
class FileHead
{
public:
	FileHead();
	void setFileLen(int fileLen);
	int getFileLen();
	void setFileType(const char *fileType);
	char* getFileType();
	int * getWeight();
	void setWeight(int *weight);
	~FileHead();
private:
	//压缩前文件长度
	int fileLen;
	//文件类型
	char fileType[4];
	//每个字符的权重
	int weight[256];

};

