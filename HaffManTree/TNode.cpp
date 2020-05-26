#include "TNode.h"
TNode::TNode()
{

	this->weight = 0;
	this->parent = -1;
	this->lChild = -1;
	this->rChild = -1;
	this->visited = 0;
}

TNode::TNode(unsigned char value, int weight, int parent, int lChild, int rChild, int visited)
{
	this->value = value;
	this->weight = weight;
	this->parent = parent;
	this->lChild = lChild;
	this->rChild = rChild;
	this->visited = visited;
}

void TNode::setWeight(int weight)
{
	this->weight = weight;
}

void TNode::setLChild(int lChild)
{
	this->lChild = lChild;
}

void TNode::setRChild(int rChild)
{
	this->rChild = rChild;
}

void TNode::setVisited(int visited)
{
	this->visited = visited;
}

void TNode::setParent(int parent)
{
	this->parent = parent;
}

void TNode::setValue(unsigned char value)
{
	this->value = value;
}

unsigned char  TNode::getValue()
{
	return this->value;
}

bool TNode::operator >(const TNode & node)
{
	return this->weight>=node.weight;
}

int TNode::getWeight()
{
	return this->weight;
}

int TNode::getLChild()
{
	return this->lChild;
}

int TNode::getRChild()
{
	return this->rChild;
}

int TNode::getVisited()
{
	return this->visited;
}

int TNode::getParent()
{
	return this->parent;
}


TNode::~TNode()
{
}
