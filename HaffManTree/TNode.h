#pragma once
class TNode
{
public:
	TNode();
	TNode(unsigned char  value,int weight,int parent,int lChild,int rChild,int visited);
	void setWeight(int weight);
	void setLChild(int lChild);
	void setRChild(int rChild);
	void setVisited(int Visited);
	void setParent(int parent);
	void setValue(unsigned char value);
	unsigned char getValue();
	/*重写小于运算符*/
	bool operator >(const TNode &node);
	int getWeight();
	int  getLChild();
	int getRChild();
	int getVisited();
	int getParent();
	~TNode();
private:

	//字符频度权重
	int weight;
	//父节点
	int parent;
	//左孩子
	int lChild;
	//右孩子
	int rChild;
	//是否已经访问过
	int visited;
	//结点值
	unsigned char value;
};

