#include<iostream>
#include<cstdio>
#include<windows.h>
#include<cctype>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#define MIN 1
long long max,year,month,day;
using namespace std;
struct ex
{
	string num;
	string name;
	bool bo;
} ;
void getSystemTime()
{
    time_t timer;
    time(&timer);
    tm* t_tm = localtime(&timer);
    year=t_tm->tm_year+1900;
    month=t_tm->tm_mon+1;
    day=t_tm->tm_mday;
}
void date()
{
    ifstream fin("data.chs");
    getSystemTime();
    if(!fin)
    {
        ofstream fout("data.chs");
        fout<<year<<" "<<month<<" "<<day;
        if(MessageBox(NULL,"ϵͳ��⵽������ѧ�꣬�Ƿ��������","",MB_ICONEXCLAMATION|MB_OKCANCEL)!=1)
                MessageBox(NULL,"�Ժ������޸ģ��뵽����װĿ¼�е�namelist.txt�޸�","",MB_ICONEXCLAMATION|MB_OK);
    }
    else
    {
        long long yy,mm,dd;
        fin>>yy>>mm>>dd;
        if(yy<year&&(month>9||mm<9)||year==yy&&month>=9&&mm<9)
            if(MessageBox(NULL,"ϵͳ��⵽������ѧ�꣬�Ƿ��������","",MB_ICONEXCLAMATION|MB_OKCANCEL)!=1)
            {
                MessageBox(NULL,"�Ժ������޸ģ��뵽����װĿ¼�е�namelist.txt�޸�","",MB_ICONEXCLAMATION|MB_OK);
            }
            else
            {
                ofstream fout("namelist.txt");
                fout.close();
                ofstream sout("data.chs");
                sout<<year<<" "<<month<<" "<<day;
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
        date();
        ex human[100];
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
		fin.close();
		MessageBox(NULL,"����Ϊ�գ�����������","�����",MB_ICONEXCLAMATION|MB_OK);
		ofstream fout("namelist.txt");
		fout.close();
		ofstream sout("read_me.txt");
		sout<<"���ڸ���������ļ����µ�namelist.txt��������\n������ʽΪ���������ո��������ո�Ȩֵ�����У�\nȨֵΪ0ʱ�൱���޴��ˣ�����֪��ȨֵΪ�������ȫ��Ϊ3\n" ;
		sout<<"Example:\n7 ���� 3" ;
                sout.close();
		system("read_me.txt") ;
                system("namelist.txt") ;
		MessageBox(NULL,"�Ժ������޸ģ��뵽����װĿ¼�е�namelist.txt�޸�","�����",MB_ICONEXCLAMATION|MB_OK);
		MessageBox(NULL,"�������ʣ�����ϵ����΢��@��¶��","�����",MB_ICONEXCLAMATION|MB_OK);
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

