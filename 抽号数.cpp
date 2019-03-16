#include<iostream>
#include<cstdio>
#include<windows.h>
#include<cctype>
#include<fstream>
#include<cstring>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#define MIN 1
#define MAX 1000
long long max;
using namespace std;
struct ex
{
	string num;
	string name;
	bool bo;
} human[MAX];
void s(string a)
{
	for(int i=0; i<a.length(); i++)
	{
		cout<<a[i];
		Sleep(50);
	}
}
int main()
{
	ifstream fin("namelist.txt");
	int tt,top=0,max=0;
	while(fin>>human[0].num)
	{
		fin>>human[0].name;
		fin>>tt;
		max++;
		for(int i=1; i<=tt; i++)
		{
			human[++top].num=human[0].num;
			human[top].name=human[0].name;
		}
	}
	if(max==0)
	{
		ofstream fout("namelist.txt");
		fout.close();
		fin.close();
		MessageBox(NULL,"名单为空，请输入名单","抽号数",MB_ICONEXCLAMATION|MB_OK); 
		cout<<"名单格式为：号数（空格）姓名（空格）权值（换行）" ;
		system("namelist.txt") ;
		MessageBox(NULL,"以后如需修改，请到程序安装目录中的namelist.txt修改","抽号数",MB_ICONEXCLAMATION|MB_OK);
		MessageBox(NULL,"如有疑问，请联系作者","抽号数",MB_ICONEXCLAMATION|MB_OK); 
		system("start www.weibo.com/fengluluer") ;
		essageBox(NULL,"调整为新宋体字号可变更大","抽号数",MB_ICONEXCLAMATION|MB_OK);
		return 0; 
	}
	srand((unsigned)time(NULL));
	int temp;
	do
	{
		for(int i=1; i<=top; i++)
			human[i].bo=true;
		for(int i=1; i<=max; i++)
		{
			temp=(rand() % (top-MIN+1))+ MIN;
			while(!human[temp].bo)
				temp=(rand() % (top-MIN+1))+ MIN;
			string exa=human[temp].num;
			int k=temp;
			while(human[k].num==exa)
			{
				human[k].bo=false;
				k++;
			}
			k=temp;
			while(human[k].num==exa)
			{
				human[k].bo=false;
				k--;
			}
			s(human[temp].num);
			cout<<"    ";
			s(human[temp].name);
			if(MessageBox(NULL,"是否继续？","抽号数",MB_ICONEXCLAMATION|MB_OKCANCEL)!=1)
				return 0;
			system("cls");
		}
		if(MessageBox(NULL,"抽号数已结束\n是否重新开始","抽号数",MB_ICONEXCLAMATION|MB_OKCANCEL)!=1)
			return 0;
	}
	while(true);
}
