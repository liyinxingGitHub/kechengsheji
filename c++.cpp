/***************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: ���.cpp
Author:������   Version :1.01   Date:2018.06.24
Description: // ģ������
Version: 1.01��// �汾��Ϣ
Function List: // ��Ҫ�������书��
1.main����������Ҫ�Ǹ����û���ָ����ø������ܺ�����
2.read()������Ҫ�Ƕ�ȡְ���������ݡ�
3.write()������Ҫ�Ǳ���ְ���������ݡ�
4.void fin()������Ҫ�ǲ�ѯְ���������ݡ�
5.list()������Ҫ�����ְ���������ݡ�
6.modify()������Ҫ���޸�ְ�����ʡ�
7.del()������Ҫ��ɾ��ְ���������ݡ�
8.add()������Ҫ�����ְ���������ݡ�
9.grsds(int a)������Ҫ�Ǽ����������˰
History: // ��ʷ�޸ļ�¼
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle
***************************************************************************/
#include<iostream>
#include<iomanip>
#include<float.h>
#include<stdlib.h>
#include<string>
#include"string.h"
#include<fstream>
float grsds(int a);
int n=0;
using namespace std;
struct zggz{               //����ְ�����ʽṹ�壻     
       char num[10];       //����
	   char name[10];      //����
	   float gwgz;        //��λ����
	   float xjgz;        //н������
	   float zwjt;        //ְ����
	   float jxgz;        //��Ч����
	   float yfgz;        //Ӧ������
	   float grsds1;      //��������˰
	   float sfgz;        //ʵ������
}zggz[100];

/***************************************************************************
Function:read����             // ��������
Description:������ȡ�ļ���gx.dat���е����ݣ����浽�ṹ��zggz��                  // �������ܡ����ܵȵ�����
Calls:  ����                    // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ļ���gx.dat��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input: ����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return:����          // ��������ֵ��˵��
Others:����          // ����˵��
***************************************************************************/
int read()//��ȡְ���������ݵĺ�����
{
	fstream in("gx.dat",ios::in|ios::binary);//�򿪶������ļ�
	if(!in)
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳�����
	}
	for(int i=0;i<100;i++)
	{
		if(!in.eof())//����ļ��Ƿ񵽴�ĩλ�á�
	    {
		in>>zggz[i].num>>zggz[i].name>>zggz[i].gwgz>>zggz[i].xjgz>>zggz[i].zwjt>>zggz[i].jxgz>>zggz[i].yfgz>>zggz[i].grsds1>>zggz[i].sfgz;//���ļ��е�������һ����ṹ�� 
		n=n+1;
		}
		else break;//����ļ��Ѿ���ĩβ�����ѭ�� 
	}n=n-1;         //ȥ���ա� 
	in.close();   //�ر��ļ� 
	return 0;
}

/***************************************************************************
Function:write����             // ��������
Description:�������ṹ���е����ݱ������ļ���gx.dat���С�                  // �������ܡ����ܵȵ�����
Calls:  ����                    // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ļ���gx.dat��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input:����               // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output:����              // �����������˵����
Return:����          // ��������ֵ��˵��
Others:����          // ����˵��
***************************************************************************/
int write()      //����ְ���������ݵĺ���
{
		fstream out("gx.dat",ios::out|ios::binary);//�򿪶������ļ�
	if(!out)
	{
		cout<<"Cannot open input file.\n";
		abort();          //�˳�����
	}
	for(int i=0;i<n;i++)
		if(!out.eof())          //����ļ��Ƿ񵽴�ĩλ�á�
	    {
		out<<zggz[i].num<<"  "<<zggz[i].name<<"  "<<zggz[i].gwgz<<"  "<<zggz[i].xjgz<<"  "
		<<zggz[i].zwjt<<"  "<<zggz[i].jxgz<<"  "<<zggz[i].yfgz<<"  "<<zggz[i].grsds1<<"  "<<zggz[i].sfgz<<"  "<<endl;   //������һ���浽�ļ��С� 
       	}
	out.close();   //�ر��ļ� 
	cout<<"�ļ��ѱ��棡"<<endl;
	return 0;
}

/***************************************************************************
Function:fin����             // ��������
Description:������������ͨ�����Ż������ֲ�ѯ��Ӧ�˵Ĺ������ݡ�                // �������ܡ����ܵȵ�����
Calls: ����                   // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input:����               // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output:����              // �����������˵����
Return:����          // ��������ֵ��˵��
Others:����          // ����˵��
***************************************************************************/
void fin()//��ѯְ���������ݺ�����
{
	int i;
	char ghname[10];//���ڱ�������Ĺ��Ż����֡� 
	cout<<"�����빤�Ż�������:"<<endl;
	cin>>ghname;       //���빤�Ż����� 
	for(i=0;i<=n;i++)       //ѭ��������� 
		{
		if(strcmp(zggz[i].num,ghname)==0||strcmp(zggz[i].name,ghname)==0)//�ȽϹ��Ż������Ƿ���ͬ��
		  {
		  cout<<setw(13)<<setiosflags(ios::left)<<"����"<<setw(13)<<setiosflags(ios::left)<<"����"<<setw(13)<<setiosflags(ios::left)<<"��λ����" 
			<<setw(13)<<setiosflags(ios::left)<<"н������"<<setw(13)<<setiosflags(ios::left)<<"ְ�����" <<setw(13)<<setiosflags(ios::left)<<"��Ч����"
			<<setw(13)<<setiosflags(ios::left)<<"Ӧ������"<<setw(13)<<setiosflags(ios::left)<<"��������˰"<<setw(13)<<setiosflags(ios::left)<<"ʵ������"<<endl;
		  cout<<setw(13)<<setiosflags(ios::left)<<zggz[i].num<<setw(13)<<setiosflags(ios::left)<<zggz[i].name<<setw(13)<<setiosflags(ios::left)<<zggz[i].gwgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[i].xjgz<<setw(13)<<setiosflags(ios::left)<<zggz[i].zwjt<<setw(13)<<setiosflags(ios::left)<<zggz[i].jxgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[i].yfgz<<setw(13)<<setiosflags(ios::left)<<zggz[i].grsds1<<setw(13)<<setiosflags(ios::left)<<zggz[i].sfgz<<endl; 
			break;
		   }
		  if(i==n)//�����ҵ���n+1��ʱ����
		  {
		  	cout<<"���ִ���û��������š�"<<endl;
		   } 
	    }
	cout<<endl;
}

/***************************************************************************
Function:list����             // ��������
Description:�˺�������������й��ʳ�Ա������                // �������ܡ����ܵȵ�����
Calls:����                   // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input: ����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return: ����        // ��������ֵ��˵��
Others: ����       // ����˵��
***************************************************************************/
int list()//���ְ���������ݺ���systerm("cls")systerm("pause")
{
	cout<<"ȫ��ְ���������£�"<<endl;
	if(n!=0)   //���n������0����� 
	{
		cout<<setw(13)<<setiosflags(ios::left)<<"����"<<setw(13)<<setiosflags(ios::left)<<"����"<<setw(13)<<setiosflags(ios::left)<<"��λ����" 
			<<setw(13)<<setiosflags(ios::left)<<"н������"<<setw(13)<<setiosflags(ios::left)<<"ְ�����" <<setw(13)<<setiosflags(ios::left)<<"��Ч����"
			<<setw(13)<<setiosflags(ios::left)<<"Ӧ������"<<setw(13)<<setiosflags(ios::left)<<"��������˰"<<setw(13)<<setiosflags(ios::left)<<"ʵ������"<<endl;
	} 
	for(int i=0;i<n;i++)         //ѭ��������ݡ� 
	{

		cout<<setw(13)<<setiosflags(ios::left)<<zggz[i].num<<setw(13)<<setiosflags(ios::left)<<zggz[i].name<<setw(13)<<setiosflags(ios::left)<<zggz[i].gwgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[i].xjgz<<setw(13)<<setiosflags(ios::left)<<zggz[i].zwjt<<setw(13)<<setiosflags(ios::left)<<zggz[i].jxgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[i].yfgz<<setw(13)<<setiosflags(ios::left)<<zggz[i].grsds1<<setw(13)<<setiosflags(ios::left)<<zggz[i].sfgz<<endl; 
	}
	cout<<endl;
	system("cls");
	system("pause");
	return 0;
}

/***************************************************************************
Function:modify����             // ��������
Description:�˺��������޸�ְ���������ݣ�ͨ���ж��������߹�����ɸѡ��ָ�������ݡ�                // �������ܡ����ܵȵ�����
Calls��grsds����������                   // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input: ����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return: ����        // ��������ֵ��˵��
Others: ����       // ����˵��
***************************************************************************/
int modify()//�޸�ְ�����ʵĺ�����
{
	int i,j,xuhao;
	char ghname[10];    //���� ���Ż����� 
	cout<<"�����빤��:"<<endl;
	cin>>ghname;
	for(i=0;i<=n;i++)
		{
		if(strcmp(zggz[i].num,ghname)==0||strcmp(zggz[i].name,ghname)==0)//�ȽϹ��Ż������Ƿ���ͬ��
		  {   j=i;
		      cout<<"��������Ҫ�޸Ĳ�����ţ�1������  2����λ����  3��н������  4��ְ�����  5����Ч����  6��ȫ���޸� 7���˳�"<<endl;
			  cin>>xuhao;
			  if(xuhao==1)                               //����ŵ���1ʱ�޸����֡� 
			  {
		          cout<<"�������޸ĵ�������"<<endl;
				  cin>>zggz[i].name;
				  break;
			  }
			  else if(xuhao==2)                          //����ŵ���2ʱ�޸ĸ�λ���ʡ�
			  {
				  cout<<"�������޸ĵĸ�λ���ʣ�"<<endl;
				  cin>>zggz[i].gwgz;
				  break;
			  }
			  else if(xuhao==3)                           //����ŵ���3ʱ�޸�н�����ʡ�
			  {
				  cout<<"�������޸ĵ�н�����ʣ�"<<endl;
				  cin>>zggz[i].xjgz;
				  break;
			  }
			  else if(xuhao==4)                            //����ŵ���4ʱ�޸�ְ������� 
			  {
				  cout<<"�������޸ĵ�ְ�������"<<endl;
				  cin>>zggz[i].zwjt;
				  break;
			  }
			  else if(xuhao==5)                            //����ŵ���5ʱ�޸ļ�Ч���ʡ�
			  {
				  cout<<"�������޸ĵļ�Ч���ʣ�"<<endl;
				  cin>>zggz[i].jxgz;
				  break;
			  }
			  else  if(xuhao==6)                            //����ŵ���6ʱ�޸�ȫ���� 
			  {
				  cout<<"�������޸ĵ�������"<<endl;
				  cin>>zggz[i].name;
				  cout<<"�������޸ĵĸ�λ���ʣ�"<<endl;
				  cin>>zggz[i].gwgz;
				  cout<<"�������޸ĵ�н�����ʣ�"<<endl;
				  cin>>zggz[i].xjgz;
				   cout<<"�������޸ĵ�ְ�������"<<endl;
				  cin>>zggz[i].zwjt;
				  cout<<"�������޸ĵļ�Ч���ʣ�"<<endl;
				  cin>>zggz[i].jxgz;
				  break;
			  }
			  else if(xuhao==7)                              //����ŵ���7ʱ�˳��޸ġ�
			  {
				  break;
			  }
			  zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz,
			  zggz[i].grsds1=grsds(i),zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds1;//�޸ĵ����ݡ�
			  cout<<endl;
		}
		if(i==n)        //�����ҵ���n+1��ʱ����
		  {
		  	cout<<"���ִ���û��������š�"<<endl;
			cout<<endl;
		  } 
	    }
	return 0;		
}

/***************************************************************************
Function:del����             // ��������
Description:�˺�������ɾ����ѡ�����ݡ�                // �������ܡ����ܵȵ�����
Calls:����                   // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input: ����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return: ����        // ��������ֵ��˵��
Others: ����       // ����˵��
***************************************************************************/
int del()//ɾ��ְ���������ݺ���
{
	int i,a;     //����i����ѭ������������a���ڴ洢0��1�� 
	char ghname[10];         //���幤�Ż����� 
	cout<<"������Ҫɾ����ְ���Ĺ��ţ�";
	cin>>ghname;     //���빤�Ż����֡� 
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].num,ghname)==0||strcmp(zggz[i].name,ghname)==0)  // �Ϲ��Ż������Ƿ���ͬ��
	  {
		  cout<<"�Ƿ�ɾ����ȷ��ɾ����ظ�1��ȡ��ɾ����ظ�0"<<endl;
		  cin>>a;
		  if(a==1)       //ȷ��ɾ����
		   {
			   for(int j=i;j<=n;j++)
			   {
                   zggz[j]=zggz[j+1];//ɾ���˹��ŵ�ְ���������ݡ�
			   } 
		      n=n-1;
			  cout<<"�ѳɹ�ɾ����"<<endl;
			  cout<<endl;
		   }
		  if(a==0)               //ȡ��ɾ��
			  {
			  	break;
			  }
		  break;
	  }
		if(i==n)
		{
		cout<<"���ִ���û�г��ִ˹��ţ�"<<endl;
		cout<<endl;
		}
	}
	return 0;
}

/***************************************************************************
Function:add����             // ��������
Description:�˺�����������ְ��������Ϣ��                // �������ܡ����ܵȵ�����
Calls:����                   // �����������õĺ����嵥
Called By:main()������                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input: ����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return: ����        // ��������ֵ��˵��
Others: ����       // ����˵��
***************************************************************************/
int add()//���ְ���������ݺ�����
{
	   if(n>100||n==100)
	   {
		   cout<<"�Բ������ݱ�����������"<<endl;
		   return 0;
	   }
	   cout<<"������Ա���Ļ�������"<<endl;
	   cout<<"  ���ţ�";          //������������Ϣ��
	   cin>>zggz[n].num;          //���빤�š�
	   for(int i=0;i<n;i++)
	  {
		  if(strcmp(zggz[n].num,zggz[i].num)==0)//�жϹ����Ƿ���ڣ���������������빤�š�
	    {
		   cout<<"�����Ѵ��ڣ����������빤�ţ�";
		   cin>>zggz[n].num;
		   i=0;
	    }
	   }
	   cout<<"  ������";
	   cin>>zggz[n].name;         //�������� 
	   cout<<"  ��λ���ʣ�";
	   cin>>zggz[n].gwgz;         //�����λ����
	   cout<<"  н�����ʣ�";
	   cin>>zggz[n].xjgz;         //����н������
	   cout<<"  ְ�������";
	   cin>>zggz[n].zwjt;         //����ְ�����
	   cout<<"  ��Ч���ʣ�";
	   cin>>zggz[n].jxgz;        //���뼨Ч����
	   zggz[n].yfgz=zggz[n].gwgz+zggz[n].xjgz+zggz[n].zwjt+zggz[n].jxgz;      //����Ӧ������ 
	   zggz[n].grsds1=grsds(n);	   //����grsds���������������˰ 
	   zggz[n].sfgz=zggz[n].yfgz-zggz[n].grsds1;    //����ʵ������ 
	    cout<<setw(13)<<setiosflags(ios::left)<<"����"<<setw(13)<<setiosflags(ios::left)<<"����"<<setw(13)<<setiosflags(ios::left)<<"��λ����" 
			<<setw(13)<<setiosflags(ios::left)<<"н������"<<setw(13)<<setiosflags(ios::left)<<"ְ�����" <<setw(13)<<setiosflags(ios::left)<<"��Ч����"
			<<setw(13)<<setiosflags(ios::left)<<"Ӧ������"<<setw(13)<<setiosflags(ios::left)<<"��������˰"<<setw(13)<<setiosflags(ios::left)<<"ʵ������"<<endl;
		cout<<setw(13)<<setiosflags(ios::left)<<zggz[n].num<<setw(13)<<setiosflags(ios::left)<<zggz[n].name<<setw(13)<<setiosflags(ios::left)<<zggz[n].gwgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[n].xjgz<<setw(13)<<setiosflags(ios::left)<<zggz[n].zwjt<<setw(13)<<setiosflags(ios::left)<<zggz[n].jxgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[n].yfgz<<setw(13)<<setiosflags(ios::left)<<zggz[n].grsds1<<setw(13)<<setiosflags(ios::left)<<zggz[n].sfgz<<endl; 
		cout<<endl;
		n=n+1;
		return 0;
}

/***************************************************************************
Function:grsds()             // ��������
Description:�˺������������������˰��                // �������ܡ����ܵȵ�����
Calls:                   // �����������õĺ����嵥
Called By:add������modify������                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input:����Ĳ���a�Ǵ���ڼ���Ա����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return: ���ؼ���õĸ�������˰��        // ��������ֵ��˵��
Others: ����       // ����˵��
***************************************************************************/
float grsds(int a)//�����������˰
{
	float yfgz,grsds;   //����ֲ������������ڴ洢Ӧ�����ʺ͸�������˰�� 
	yfgz=zggz[a].gwgz+zggz[a].xjgz+zggz[a].zwjt+zggz[a].jxgz;  //����Ӧ�����ʡ� 
	if(yfgz<=500)
	{
		grsds=yfgz*0.05;   //����500�ڵĸ�������˰��
	} 	                      
	else if(500<yfgz&&yfgz<=2000)
	{
		grsds=(yfgz-500)*0.1+500*0.05;   // ����500-2000�ĸ�������˰��
	}                  
	else if(2000<yfgz&&yfgz<=5000)  
	{
		grsds=(yfgz-2000)*0.15+1500*0.1+500*0.05;               //����2000-5000�ڵĸ�������˰��
	}                                                                              
	else if(5000<yfgz&&yfgz<=20000)
	{
		grsds=(yfgz-5000)*0.2+3000*0.15+1500*0.1+500*0.05;                     //����5000-20000�ڵĸ�������˰��
	} 
	else if(20000<yfgz&&yfgz<=40000)
	{
		grsds=(yfgz-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                   //����20000-40000�ڵĸ�������˰��
	} 	
	else if(40000<yfgz&&yfgz<=60000)
	{
		grsds=(yfgz-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                  //����40000-60000�ڵĸ�������˰��
	} 
	else if(60000<yfgz&&yfgz<=80000)
	{
		grsds=(yfgz-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;             //����60000-80000�ڵĸ�������˰��
	} 
	else if(80000<yfgz&&yfgz<=100000)
	{
		grsds=(yfgz-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;           //����80000-100000�ڵĸ�������˰��
	} 
	else if(100000<yfgz)
	{
		grsds=(yfgz-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;         //����100000���ϵĸ�������˰��
	} 	
	return grsds;
}

/***************************************************************************
Function:main����             // ��������
Description:������������ʵ�ָ��ֲ��������ø����������в�����                // �������ܡ����ܵȵ�����
Calls:add(),del(),fin(),fin(),list(),modify(),read(),write().                   // �����������õĺ����嵥
Called By:�ޡ�                   // ���ñ������ĺ����嵥
Table Accessed: �ṹ��zggz��          // �����ʵı����������ǣ�������ݿ�����ĳ���
Table Updated: ����                     // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input: ����              // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ�� 
Output: ����             // �����������˵����
Return: ����        // ��������ֵ��˵��
Others: ����       // ����˵��
***************************************************************************/
int main()
{
	int b;//������������
	read();//����read�����ĺ�������ȡ�ļ��е����ݴ����ṹ���С�
	do//ѭ������ֱ���뵽exit��0���˳���������
	{
	  cout<<"*************************��ӭʹ��ְ�����ʲ���ϵͳ��**************************"<<endl;
	  cout<<"*"<<"                                                                           "<<"*"<<endl;
	  cout<<"*"<<"                       1.��ѯ  2.�޸�  3.���  4.ɾ��                      "<<"*"<<endl;
	  cout<<"*"<<"                           5.����  6.���  7.�˳�                          "<<"*"<<endl;
	  cout<<"***************************************************************************** "<<endl;
	  cout<<"���������ϲ�������ţ�"<<endl;
	  cin>>b;
	  if(b==1)
	  {
	  	fin();//����fin�����������в��ҡ�
	  }   
	  if(b==2)
	  {
	  	modify();//����modify�������������޸ġ�
	  }   
	  if(b==3)
	  {
	  	add();//����add���������������ְ���������ݡ�
	  } 	  
	  if(b==4)
	  {
	  	del();//����del������������ְ�����ݵ�ɾ����
	  }   
	  if(b==5)
	  {
	  	write();//����write������������ְ���������ݵı��档
	  } 
	  if(b==6)
	  {
	  	list();//����list���������������е����������
	  }   
	  if(b==7)
	  {
	  	cout<<"****************лл����ʹ�ã�����ӭ�´μ���ʹ�ã��ټ�������*****************"<<endl;
	  	exit(0);//�˳�����
	  } 	 
	}while(b!=7);
   return 0;
}