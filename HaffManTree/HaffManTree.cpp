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
			//�����ȡ�ַ���Ȩ�ء�
			int index = ism->get();
			if (index > -1)
			{
				this->fileLen++;
				w[index]++;
			}
		
		}
		//��ʼ���ڵ�����
		initNodeData();
	}
	else {
		cout << "���ļ�ʧ�ܣ�" << endl;
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
			//��ÿ���ڵ���������
			this->node[this->count].setWeight(w[i]);
			this->node[this->count].setValue(i);
			this->count++;
		}
	}

}

void HaffManTree::outPutData()
{   
	cout << "����" << this->count << "���ַ�" << endl;
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
������Ϊlen������ڵ㴴��һ�ù�������
@param node :�ڵ�����
@param len:����ĳ���
*/
void HaffManTree::createHanffMan()
{
	
	int len = this->count;
	
	while (len > 1)
	{
		//���Ƚ����齵������,�����node[len-1]�϶�����Сֵ��
		this->quickSort(node, len);
		//����
		lChilds[len-1] = node[len - 1];
		//�Һ���
		rChilds[len-1] = node[len - 2];
		//�����
		TNode parent(-1,lChilds[len-1].getWeight() + rChilds[len-1].getWeight(), -1, len-1, len-1, 0);
		lChilds[len-1].setParent(len-1);
		rChilds[len-1].setParent(len-1);
		//�����Ӻ��Һ��ӵĸ�������ӵ�node�ڵ�������
		node[len - 2] = parent;
		//���鳤�ȼ�һ
		len--;
	}
	//����ʣ������ڵ���ǹ��������ĸ��ڵ�
	this->root = node[0];
	

}
/*
������Ϊlen��������н�������
@param node :Ҫ����Ľڵ�����
@param len:����ĳ���
*/
void HaffManTree::quickSort(TNode * node,int len)
{
	this->quickSort(0,len-1,node);
}

void HaffManTree::preOrderReverse()
{
	//��Ÿ��ڵ��ջ
	stack<TNode*> *s = new stack<TNode*>();
	//��ʱ�ڵ�
	TNode* currNode = &this->root;
	printf_s("byte	weight	parent	leftChild	rightChild\n");
	while (currNode->getLChild() > -1 || currNode->getRChild()>-1||s->size()>0)
	{
		while (true)
		{
			if (currNode->getVisited() != 1)
			{
				//�����Ѿ����ʹ��ýڵ�
				  currNode->setVisited(1);
					printf_s("%c	%d	%d	%d		%d\n", currNode->getValue(), currNode->getWeight(),
						currNode->getParent(), currNode->getLChild(), currNode->getRChild());
              //���ýڵ���ջ��Ϊ�����				
				s->push(currNode);
			}
			if (currNode->getLChild() > -1)
			{
				//��������һ�����ӽڵ�
				currNode = &lChilds[currNode->getLChild()];
			}
			else {
				//���ýڵ㲻�����ӽڵ�ʱ����ѭ����
				break;
			}
			
		}
		//��ǰ�ڵ㶨λ��ջ�������
		currNode = s->top();
		//���������
		s->pop();
		if (currNode->getRChild() > -1)
		{
			//ת���ҽڵ㡣
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
	cout << "���нڵ�:" << n<<endl;
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
	cout << "�ܵı��볤�ȣ�" << sum << endl;
}




void HaffManTree::enCoding(TNode* root, char * keepCode, int index)
{
	if (root == nullptr)
	{
		return;
	}
	//����Ҷ���
	if (root->getLChild() == -1 || root->getRChild() == -1)
	{
		//��������������һ����ֹ�����γ�һ���������ַ��������㿽��(��ֹ������֮ǰ�ı���)
		keepCode[index] = '\0';
		//node->data-0��char��תint�͵ļ�㷽��
		strcpy_s(code[root->getValue()], keepCode);
		return;
	}
	if (root->getLChild() != -1)
	{
		//���֧����Ϊ'0', �ҷ�֧����Ϊ'1'
		keepCode[index] = '0';
		enCoding(&this->lChilds[root->getLChild()], keepCode, index + 1);
	}
	//���֧����Ϊ'0', �ҷ�֧����Ϊ'1'
	if (root->getRChild()!= -1)
	{
		keepCode[index] = '1';
		enCoding(&rChilds[root->getRChild()], keepCode, index + 1);
	}
	
}

void HaffManTree::enCoding()
{
	char haffCode[HALF_MAX];        //��������ÿ�δӸ���Ҷ�������ı���(����Ĺ�������)
	this->enCoding(&this->root, haffCode,0);
}

void HaffManTree::zipFile()
{
	cout << "������ѹ���ļ�·����";
	cin >> this->outFilePath;
	//�ļ����
	fstream* osm = new fstream(outFilePath,ios::out|ios::binary);
	if (!osm->is_open())
	{
		return;
	}
	//�������ļ���д���ļ�ͷ��Ϣ
	FileHead fileHead;
	fileHead.setFileLen(this->fileLen);
	fileHead.setWeight(this->w);
	//ĿǰĬ��ʹ��ѹ��bmp��ʽͼƬ
	fileHead.setFileType("bmp");
	osm->write((char*)&fileHead,sizeof(FileHead));
	//��ʼ���¶�ȡ�ļ�
	fstream *ism = new fstream(this->inFilePath,ios::in|ios::binary);
	int readChar = -1;
	unsigned char saveChar = 0;
	//��ȡ�ַ���������ÿ8��Ϊһ���ֽ�
	int index = 0;
	//ѹ�����ļ���С
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
					//��saveChar������е�ÿһλ���л���������ַ�'1'-'0'�Ϳ��Եõ�0000 0001
					//'1'-'0'�Ϳ��Եõ�0000 0001, '0'-'0'���Եõ�  0000 0000
					//������Ϊ'1',ͨ�������������ӵ��ֽڵ����λ
					saveChar |= code[readChar][i] - '0';
					index++;
					//ÿ8λд��һ���ļ�
					if (index == 8)
					{
						osm->write((char*)&saveChar, sizeof(unsigned char));
						//�����ַ�����
						saveChar = 0;
						index = 0;
						zipFileLen++;
					}
					else {
						saveChar = saveChar << 1;   //ÿ����һ����������һλ
					}
				}
			}

		}
		//������ʣ��ı��벻��8λ�������Ƶ������
		if (index < 8 && index > 0)
		{
			saveChar = (saveChar << (8 - index));
			osm->write((char*)&saveChar, sizeof(unsigned char));
			zipFileLen++;
		}
	}
	printf_s("ѹ��ǰ�ļ���СΪ�� %d �ֽڣ�ѹ����Ϊ�� %d �ֽڣ�ѹ����Ϊ: %.21f%%\n",fileLen,zipFileLen,(double)zipFileLen/fileLen*100);
	cout << endl;
	osm->close();
	ism->close();
}

void HaffManTree::unZipFile(const char* filePath)
{
	cout << "�������ѹ����ļ��� ��";
	cin >> this->outFilePath;
	fstream *ism = new fstream(filePath,ios::in|ios::binary);
	fstream* osm = nullptr;
	string* outputFilePath = new string(outFilePath);
	outputFilePath->append(".");
	if (ism->is_open())
	{
		FileHead fileHead;
		char op;    //��ѹ���õ���
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
				//��ʼ���ڵ�����
				initNodeData();
				//������������
				this->createHanffMan();
				//����
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
						tempChar = tempChar >> 7;   //ȡtempChar/readChar�����λ��Ϊunzip��flag
						readChar = readChar << 1;
						currNode = unZip(currNode, tempChar - 0);
						if (currNode->getLChild() == -1 || currNode->getRChild() == -1) {
							unsigned char saveChar = currNode->getValue();
						//	cout << saveChar;
							osm->write((char*)&saveChar, sizeof(unsigned char));
							osm->flush();
							index++;      //ÿд��һ���ַ���index+1
							currNode = &node[0];        //ÿ�ҵ�һ��Ҷ��㣬�㽫��ǰ���ָ������
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
		printf_s("��ѹ�ļ��ɹ�����ѹǰ�ļ���С%d�ֽ�,��ѹ���ļ���С��%d�ֽ�\n", zipFilelen,this->fileLen);
	}
	else {
		cout << "��ѹʱ���ļ�ʧ�ܣ�" << endl;
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
ʹ�ÿ���������н����齵������
@param low:������������
@param high:������Ҷ˶�����
@param node:����
*/
void HaffManTree::quickSort(int low, int high, TNode * node)
{
	if (low < high)
	{
		//��ȡ�ֽ�����
		int index = this->partIndex(low,high,node);
		//��߽��п�������
		this->quickSort(low,index -1,node);
		//�ұ߽��п�������
		this->quickSort(index+1, high, node);
	}
}
/*
��ȡ����������м�ֽ�����
@param low:������������
@param high:������Ҷ˶�����
@param node:����
*/
int HaffManTree::partIndex(int low, int high, TNode * node)
{
	//�趨��׼ֵ
	TNode key = node[low];
	while (low < high)
	{
		//��������Ѱ�ҵ�һ���Ȼ�׼ֵ���Ԫ��
		while (low < high && key > node[high] )
		{
			high--;
		}
		//����node[low]��Ԫ��ֵ
		node[low] = node[high];
		//��������Ѱ�ҵ�һ���Ȼ�׼ֵС��Ԫ��
		while (low < high && node[low] > key)
		{
			low++;
		}
		//����node[high]��Ԫ��ֵ
		node[high] = node[low];
	}
	//�ָ���׼ֵ
	node[low] = key;
	//���طֽ�����
	return low;
}
