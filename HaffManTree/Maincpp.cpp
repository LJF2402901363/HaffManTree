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
		
		cout << "1--------每个字符展示权重信息------" << endl;
		cout << "2--------展示哈曼夫数节点信息------" << endl;
		cout << "3--------展示每个节点的对应编码信息------" << endl;
		cout << "0--------退出------" << endl;
		cout << "请输入选择：";
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
		cout << "1.------压缩文件----" << endl;
		cout << "2.------解压文件----" << endl;
		cout << "请输入选择：";
		cin >> i;
		char filePath[128];
		switch (i)
		{
		case 1:
			cout<< "请输入要压缩的文件路径：";
			cin >> filePath;
			zip(filePath);
			cin.clear();
			cin.sync();
			cin.ignore();
			break;
		case 2:
			cout << "请输入要解压的文件路径：";
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