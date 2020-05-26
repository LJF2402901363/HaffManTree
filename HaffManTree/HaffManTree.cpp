#include "HaffManTree.h"



HaffManTree::HaffManTree()
{
	
	this->count = 0;
	for (int  i = 0; i < MAX_SIZE; i++)
	{
		TNode newnode(-1,0,-1,-1,-1,0);
		this->node[i] = newnode;
	}
}

void HaffManTree::readData(const char* filePath)
{

	strcpy_s(this->inFilePath,filePath);
	fstream* ism = new fstream(filePath, ios::binary | ios::in);
	//fstream* ism = new fstream("test.txt", ios::binary | ios::in);
	if (ism->is_open())
	{
		while (!ism->eof())
		{
			//逐个读取字符的权重。
			int index = ism->get();
			if (index > -1)
			{
				this->fileLen++;
				w[index]++;
			}
		
		}
		//初始化节点数据
		initNodeData();
	}
	else {
		cout << "打开文件失败！" << endl;
	}
	ism->close();

}

void HaffManTree::initNodeData()
{
	this->count = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (w[i] > 0)
		{
			//给每个节点设置数据
			this->node[this->count].setWeight(w[i]);
			this->node[this->count].setValue(i);
			this->count++;
		}
	}

}

void HaffManTree::outPutData()
{   
	cout << "共有" << this->count << "个字符" << endl;
	cout << "Byte----" << "Weight" << endl;
	for (int i = 0; i < this->count; i++) {
		printf_s("%d\t%d\n", this->node[i].getValue(), this->node[i].getWeight());

	}
	cout << "Byte----" << "Weight" << endl;
	this->quickSort(this->node,this->count);
	for (int i = 0; i < this->count;i++) {
		printf_s("%d\t%d\n", this->node[i].getValue(), this->node[i].getWeight());
	
	}

}
/*
将长度为len的数组节点创建一棵哈夫曼数
@param node :节点数组
@param len:数组的长度
*/
void HaffManTree::createHanffMan()
{
	
	int len = this->count;
	
	while (len > 1)
	{
		//首先将数组降序排序,排序后node[len-1]肯定是最小值。
		this->quickSort(node, len);
		//左孩子
		lChilds[len-1] = node[len - 1];
		//右孩子
		rChilds[len-1] = node[len - 2];
		//父结点
		TNode parent(-1,lChilds[len-1].getWeight() + rChilds[len-1].getWeight(), -1, len-1, len-1, 0);
		lChilds[len-1].setParent(len-1);
		rChilds[len-1].setParent(len-1);
		//将左孩子和右孩子的父结点连接到node节点数组中
		node[len - 2] = parent;
		//数组长度减一
		len--;
	}
	//最后仅剩的这个节点就是哈夫曼树的根节点
	this->root = node[0];
	

}
/*
将长度为len的数组进行降序排序
@param node :要排序的节点数组
@param len:数组的长度
*/
void HaffManTree::quickSort(TNode * node,int len)
{
	this->quickSort(0,len-1,node);
}

void HaffManTree::preOrderReverse()
{
	//存放父节点的栈
	stack<TNode*> *s = new stack<TNode*>();
	//临时节点
	TNode* currNode = &this->root;
	printf_s("byte	weight	parent	leftChild	rightChild\n");
	while (currNode->getLChild() > -1 || currNode->getRChild()>-1||s->size()>0)
	{
		while (true)
		{
			if (currNode->getVisited() != 1)
			{
				//设置已经访问过该节点
				  currNode->setVisited(1);
					printf_s("%c	%d	%d	%d		%d\n", currNode->getValue(), currNode->getWeight(),
						currNode->getParent(), currNode->getLChild(), currNode->getRChild());
              //将该节点入栈作为父结点				
				s->push(currNode);
			}
			if (currNode->getLChild() > -1)
			{
				//遍历到下一个左孩子节点
				currNode = &lChilds[currNode->getLChild()];
			}
			else {
				//当该节点不是左孩子节点时跳出循环。
				break;
			}
			
		}
		//当前节点定位到栈顶父结点
		currNode = s->top();
		//弹出父结点
		s->pop();
		if (currNode->getRChild() > -1)
		{
			//转到右节点。
			currNode = &rChilds[currNode->getRChild()];
		}
	
	}


}

void HaffManTree::outPuInfo()
{
	int n = 0;
	printf_s("byte		weight		parent	 leftChild	 rightChild		code\n");
	for (int  i = 0; i < MAX_SIZE; i++)
	{
		if (lChilds[i].getLChild() == -1 && lChilds[i].getRChild() == -1 && lChilds[i].getValue()> -1)
		{
			printf_s("%d		%d		%d		%d		%d		%s\n",

				lChilds[i].getValue(), lChilds[i].getWeight(),
				lChilds[i].getParent(), lChilds[i].getLChild(),
				lChilds->getRChild(), this->code[lChilds[i].getValue()]
			
			);
			n++;
			
		}
		if (rChilds[i].getLChild() == -1 && rChilds[i].getRChild() == -1 && rChilds[i].getValue() > -1)
		{
			printf_s("%d		%d		%d		%d		%d		%s\n",
				rChilds[i].getValue(), rChilds[i].getWeight(),
				rChilds[i].getParent(), rChilds[i].getLChild(),
				rChilds->getRChild(), this->code[rChilds[i].getValue()]
			);
			n++;
		}
	
	}
	cout << endl;
	cout << "共有节点:" << n<<endl;
}

void HaffManTree::outputCode()
{
	int sum = 0;
	cout << "byte	"<<"weight	" << "code" << endl;
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		codeinfos[i].value = i;
		codeinfos[i].weight = w[i];
		strcpy_s(codeinfos[i].code,code[i]);
		sum += strlen(code[i]);
	//	cout <<i<<"	"<<w[i]<<"	" <<code[i] << endl;
	}
	
	/*
	for (int  i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE - i -1; j++)
		{
			CodeInfo temp;
			if (codeinfos[j+1].weight>codeinfos[j].weight) {
				temp = codeinfos[j + 1];
				codeinfos[j + 1] = codeinfos[j];
				codeinfos[j ] = temp;
			}

		}
	}
	*/
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (w[i]>0)
		{
			cout << (char)codeinfos[i].value << "	" << codeinfos[i].weight << "	" << codeinfos[i].code << endl;
		}
	
	}
	cout << "总的编码长度：" << sum << endl;
}




void HaffManTree::enCoding(TNode* root, char * keepCode, int index)
{
	if (root == nullptr)
	{
		return;
	}
	//处理叶结点
	if (root->getLChild() == -1 || root->getRChild() == -1)
	{
		//给编码数组设置一个终止符，形成一个完整的字符串，方便拷贝(防止拷贝到之前的编码)
		keepCode[index] = '\0';
		//node->data-0是char型转int型的简便方法
		strcpy_s(code[root->getValue()], keepCode);
		return;
	}
	if (root->getLChild() != -1)
	{
		//左分支编码为'0', 右分支编码为'1'
		keepCode[index] = '0';
		enCoding(&this->lChilds[root->getLChild()], keepCode, index + 1);
	}
	//左分支编码为'0', 右分支编码为'1'
	if (root->getRChild()!= -1)
	{
		keepCode[index] = '1';
		enCoding(&rChilds[root->getRChild()], keepCode, index + 1);
	}
	
}

void HaffManTree::enCoding()
{
	char haffCode[HALF_MAX];        //用来保存每次从根到叶结点遍历的编码(编码的过渡数组)
	this->enCoding(&this->root, haffCode,0);
}

void HaffManTree::zipFile()
{
	cout << "请输入压缩文件路径：";
	cin >> this->outFilePath;
	//文件输出
	fstream* osm = new fstream(outFilePath,ios::out|ios::binary);
	if (!osm->is_open())
	{
		return;
	}
	//首先向文件中写入文件头信息
	FileHead fileHead;
	fileHead.setFileLen(this->fileLen);
	fileHead.setWeight(this->w);
	//目前默认使用压缩bmp格式图片
	fileHead.setFileType("bmp");
	osm->write((char*)&fileHead,sizeof(FileHead));
	//开始重新读取文件
	fstream *ism = new fstream(this->inFilePath,ios::in|ios::binary);
	int readChar = -1;
	unsigned char saveChar = 0;
	//读取字符计数器，每8个为一个字节
	int index = 0;
	//压缩后文件大小
	int zipFileLen = 0;
	if (ism->is_open())
	{
		while (!ism->eof())
		{
			readChar = ism->get();
			if (readChar > -1)
			{
			//	cout << (char)readChar<<"--->"<<code[readChar]<<endl;
				for (int i = 0; i < strlen(code[readChar]); i++)
				{
					//将saveChar与编码中的每一位进行或操作，用字符'1'-'0'就可以得到0000 0001
					//'1'-'0'就可以得到0000 0001, '0'-'0'可以得到  0000 0000
					//当编码为'1',通过或操作将其添加到字节的最低位
					saveChar |= code[readChar][i] - '0';
					index++;
					//每8位写入一次文件
					if (index == 8)
					{
						osm->write((char*)&saveChar, sizeof(unsigned char));
						//保存字符置零
						saveChar = 0;
						index = 0;
						zipFileLen++;
					}
					else {
						saveChar = saveChar << 1;   //每做完一步，向左移一位
					}
				}
			}

		}
		//如果最后剩余的编码不足8位，将其移到最左端
		if (index < 8 && index > 0)
		{
			saveChar = (saveChar << (8 - index));
			osm->write((char*)&saveChar, sizeof(unsigned char));
			zipFileLen++;
		}
	}
	printf_s("压缩前文件大小为： %d 字节，压缩后为： %d 字节，压缩率为: %.21f%%\n",fileLen,zipFileLen,(double)zipFileLen/fileLen*100);
	cout << endl;
	osm->close();
	ism->close();
}

void HaffManTree::unZipFile(const char* filePath)
{
	cout << "请输入解压后的文件名 ：";
	cin >> this->outFilePath;
	fstream *ism = new fstream(filePath,ios::in|ios::binary);
	fstream* osm = nullptr;
	string* outputFilePath = new string(outFilePath);
	outputFilePath->append(".");
	if (ism->is_open())
	{
		FileHead fileHead;
		char op;    //解压缩用到的
		int index = 0;
		int readChar = -1;
		unsigned char tempChar = 0;
		TNode * currNode = &this->node[0];
		int zipFilelen = 0;
		while (!ism->eof())
		{
			if (index == 0)
			{
				ism->read((char*)&fileHead, sizeof(FileHead));
				int *weight = fileHead.getWeight();
				for (int i = 0; i < 256; i++)
				{
					this->w[i] = weight[i];
				}
				//初始化节点数据
				initNodeData();
				//创建哈曼夫树
				this->createHanffMan();
				//编码
				this->enCoding();

				char* type = fileHead.getFileType();
				string *s = new string(type);
				outputFilePath->append(type);
				this->fileLen = fileHead.getFileLen();
				osm = new fstream(*outputFilePath, ios::out | ios::binary);
				index++;
			}
			else {
				readChar = ism->get();
				if (readChar != -1)
				{
					zipFilelen++;
					op = 128;
					for (int i = 0; i < 8; i++)
					{
						tempChar = readChar & op;
						tempChar = tempChar >> 7;   //取tempChar/readChar的最高位作为unzip的flag
						readChar = readChar << 1;
						currNode = unZip(currNode, tempChar - 0);
						if (currNode->getLChild() == -1 || currNode->getRChild() == -1) {
							unsigned char saveChar = currNode->getValue();
						//	cout << saveChar;
							osm->write((char*)&saveChar, sizeof(unsigned char));
							osm->flush();
							index++;      //每写入一个字符，index+1
							currNode = &node[0];        //每找到一个叶结点，便将当前结点指向根结点
							if (index == this->fileLen + 1)
							{
								break;
							}

						}

					}

					if (this->fileLen <= index)
					{
						break;
					}
				}
			
			
			}

		}
		printf_s("解压文件成功，解压前文件大小%d字节,解压后文件大小：%d字节\n", zipFilelen,this->fileLen);
	}
	else {
		cout << "解压时打开文件失败！" << endl;
	}

}

TNode* HaffManTree::unZip(TNode * root, int flag)
{
	if (flag == 0) {
		return &lChilds[root->getLChild()];
	}
	if (flag == 1) {
		return  &rChilds[root->getRChild()];;
	}
}

HaffManTree::~HaffManTree()
{

}
/*
使用快速排序进行将数组降序排序。
@param low:数组的左端索引
@param high:数组的右端端索引
@param node:数组
*/
void HaffManTree::quickSort(int low, int high, TNode * node)
{
	if (low < high)
	{
		//获取分界索引
		int index = this->partIndex(low,high,node);
		//左边进行快速排序
		this->quickSort(low,index -1,node);
		//右边进行快速排序
		this->quickSort(index+1, high, node);
	}
}
/*
获取快速排序的中间分界索引
@param low:数组的左端索引
@param high:数组的右端端索引
@param node:数组
*/
int HaffManTree::partIndex(int low, int high, TNode * node)
{
	//设定基准值
	TNode key = node[low];
	while (low < high)
	{
		//从右往左寻找第一个比基准值大的元素
		while (low < high && key > node[high] )
		{
			high--;
		}
		//设置node[low]的元素值
		node[low] = node[high];
		//从左往右寻找第一个比基准值小的元素
		while (low < high && node[low] > key)
		{
			low++;
		}
		//设置node[high]的元素值
		node[high] = node[low];
	}
	//恢复基准值
	node[low] = key;
	//返回分界索引
	return low;
}
