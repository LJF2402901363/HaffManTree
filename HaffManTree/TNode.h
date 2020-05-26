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
	/*��дС�������*/
	bool operator >(const TNode &node);
	int getWeight();
	int  getLChild();
	int getRChild();
	int getVisited();
	int getParent();
	~TNode();
private:

	//�ַ�Ƶ��Ȩ��
	int weight;
	//���ڵ�
	int parent;
	//����
	int lChild;
	//�Һ���
	int rChild;
	//�Ƿ��Ѿ����ʹ�
	int visited;
	//���ֵ
	unsigned char value;
};

