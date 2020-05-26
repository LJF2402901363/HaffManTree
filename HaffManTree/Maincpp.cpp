#include<iostream>
#include"HaffManTree.h"
using namespace std;
HaffManTree tree;
void zip(char* filePath) {
	tree.readData(filePath);
	
	tree.createHanffMan();
	
	tree.enCoding();
	tree.zipFile();
	int i = -1;
	
	while (i != 0)
	{
		
		cout << "1--------ÿ���ַ�չʾȨ����Ϣ------" << endl;
		cout << "2--------չʾ���������ڵ���Ϣ------" << endl;
		cout << "3--------չʾÿ���ڵ�Ķ�Ӧ������Ϣ------" << endl;
		cout << "0--------�˳�------" << endl;
		cout << "������ѡ��";
		cin >> i;
		switch (i)
		{
		case 1:
			tree.outPutData();
			break;
		case 2:
			tree.preOrderReverse();
			break;
		case 3:
			tree.outputCode();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}
void unZip(const char* filePath) {
	tree.unZipFile(filePath);
}
void show() {
	tree.outPuInfo();
	tree.outputCode();
}
void showMenu() {
	int i = 0;
	while (true)
	{
		cout << "1.------ѹ���ļ�----" << endl;
		cout << "2.------��ѹ�ļ�----" << endl;
		cout << "������ѡ��";
		cin >> i;
		char filePath[128];
		switch (i)
		{
		case 1:
			cout<< "������Ҫѹ�����ļ�·����";
			cin >> filePath;
			zip(filePath);
			cin.clear();
			cin.sync();
			cin.ignore();
			break;
		case 2:
			cout << "������Ҫ��ѹ���ļ�·����";
			cin >> filePath;
			unZip(filePath);
			cin.clear();
			cin.sync();
			cin.ignore();
			break;
		default:
			break;
		}
	}
}
int main()
{
//	zip();
	//unZip();
	
	showMenu();

	
	system("pause");
	return 0;
}