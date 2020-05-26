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
	//ѹ��ǰ�ļ�����
	int fileLen;
	//�ļ�����
	char fileType[4];
	//ÿ���ַ���Ȩ��
	int weight[256];

};

