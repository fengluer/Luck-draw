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
long long max;
using namespace std;
struct ex
{
	string num;
	string name;
	bool bo;
} human[1000];
void jh()
{
	string a;
	bool bo=false;
	ifstream fin("jhm.dll");
	fin>>a;
	if(a=="jihuochenggong=20191355zhuangyaohan")
		return;
	else
	{
		ofstream fout("jhm.dll");
		while(true)
		{
			cout<<"���뼤���룺"<<endl;
			cin>>a;
			if(a=="20191355zhuangyaohan")
			{
				system("cls");
				fout<<"jihuochenggong=20191355zhuangyaohan";
				system("start https://www.cnblogs.com/kangflict/p/4111010.html");
				Sleep(5000);
				MessageBox(NULL,"����Ϊ�������ֺſɱ����","�����",MB_ICONEXCLAMATION|MB_OK);
				return;
			}
			system("cls");
			cout<<"���������������";
		}
	}
}
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
		MessageBox(NULL,"����Ϊ�գ�����������","�����",MB_ICONEXCLAMATION|MB_OK); 
		cout<<"������ʽΪ���������ո��������ո�Ȩֵ�����У�" ;
		system("namelist.txt") ;
		MessageBox(NULL,"�Ժ������޸ģ��뵽����װĿ¼�е�namelist.txt�޸�","�����",MB_ICONEXCLAMATION|MB_OK);
		MessageBox(NULL,"�������ʣ�����ϵ����","�����",MB_ICONEXCLAMATION|MB_OK); 
		system("start www.weibo.com/fengluluer") ;
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
			if(MessageBox(NULL,"�Ƿ������","�����",MB_ICONEXCLAMATION|MB_OKCANCEL)!=1)
				return 0;
			system("cls");
		}
		if(MessageBox(NULL,"������ѽ���\n�Ƿ����¿�ʼ","�����",MB_ICONEXCLAMATION|MB_OKCANCEL)!=1)
			return 0;
	}
	while(true);
}
