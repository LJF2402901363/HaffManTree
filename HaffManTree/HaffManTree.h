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
	/*初始化构造器*/
	HaffManTree();
	/*读取文本数据，并统计每个字符的权重*/
	void readData(const char* filePath);
	/*初始化节点数据*/
	void initNodeData();
	/*输出数据*/
	void outPutData();
	/*创建哈曼夫最小生成树*/
	void createHanffMan();
	/*快速排序升序*/
	void quickSort(TNode * node, int len);
	/*前序遍历*/
	void preOrderReverse();
	//打印每个叶子节点的编码以及其他信息
	void outPuInfo();
	//打印每个叶子节点的编码
	void outputCode();
	/*获取编码*/
	void enCoding();
	/*压缩文件*/
	void zipFile();
	/*解压缩文件*/
	void unZipFile(const char* filePath);
	TNode* unZip(TNode*root,int flag);
	~HaffManTree();
private:
	void quickSort(int low,int high,TNode* node);
	/*获取编码*/
	void enCoding(TNode* root, char * keepCode, int index);
	int partIndex(int low, int high, TNode* node);
private:
	/** Haffman树结点序列，依次构建编码解码的字符映射表 */
	TNode node[MAX_SIZE];
	/** 使用二维数组来存储字符的赫夫曼编码，其中第一维的下标就是这个字符的ASCII码 */
	char code[MAX_SIZE][HALF_MAX];
	//读取的文件路径
	char inFilePath[HALF_MAX];
	//保存文件的路径
	char outFilePath[HALF_MAX];
	//字符的个数
	int count = 0;
	//所有字符的权重
	int w[MAX_SIZE] = { 0 };
	/*所有左孩子节点*/
	TNode lChilds[MAX_SIZE];
	/*所有右孩子的节点*/
	TNode rChilds[MAX_SIZE];
	/*根节点*/
	TNode root;
	CodeInfo codeinfos[MAX_SIZE];
	//文件长度
	int fileLen = 0;
};

