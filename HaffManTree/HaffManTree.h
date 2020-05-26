#pragma once
#include"TNode.h"
#include<fstream>
#include<iostream>
#include<stack>
#include<string>
#include"FileHead.h"
using namespace std;
#define MAX_SIZE 256
#define HALF_MAX MAX_SIZE / 2
#define ASCII_SIZE 128   
class HaffManTree
{
public:
	struct CodeInfo
	{
		unsigned char value;
		int weight;
		char code[HALF_MAX];
	};
	/*��ʼ��������*/
	HaffManTree();
	/*��ȡ�ı����ݣ���ͳ��ÿ���ַ���Ȩ��*/
	void readData(const char* filePath);
	/*��ʼ���ڵ�����*/
	void initNodeData();
	/*�������*/
	void outPutData();
	/*������������С������*/
	void createHanffMan();
	/*������������*/
	void quickSort(TNode * node, int len);
	/*ǰ�����*/
	void preOrderReverse();
	//��ӡÿ��Ҷ�ӽڵ�ı����Լ�������Ϣ
	void outPuInfo();
	//��ӡÿ��Ҷ�ӽڵ�ı���
	void outputCode();
	/*��ȡ����*/
	void enCoding();
	/*ѹ���ļ�*/
	void zipFile();
	/*��ѹ���ļ�*/
	void unZipFile(const char* filePath);
	TNode* unZip(TNode*root,int flag);
	~HaffManTree();
private:
	void quickSort(int low,int high,TNode* node);
	/*��ȡ����*/
	void enCoding(TNode* root, char * keepCode, int index);
	int partIndex(int low, int high, TNode* node);
private:
	/** Haffman��������У����ι������������ַ�ӳ��� */
	TNode node[MAX_SIZE];
	/** ʹ�ö�ά�������洢�ַ��ĺշ������룬���е�һά���±��������ַ���ASCII�� */
	char code[MAX_SIZE][HALF_MAX];
	//��ȡ���ļ�·��
	char inFilePath[HALF_MAX];
	//�����ļ���·��
	char outFilePath[HALF_MAX];
	//�ַ��ĸ���
	int count = 0;
	//�����ַ���Ȩ��
	int w[MAX_SIZE] = { 0 };
	/*�������ӽڵ�*/
	TNode lChilds[MAX_SIZE];
	/*�����Һ��ӵĽڵ�*/
	TNode rChilds[MAX_SIZE];
	/*���ڵ�*/
	TNode root;
	CodeInfo codeinfos[MAX_SIZE];
	//�ļ�����
	int fileLen = 0;
};

