#include<iostream>
#include<string>
#include"string.h"
#include<fstream>
double grsds(int a);
int n=0;
using namespace std;
struct zggz{               //����ְ�����ʽṹ�壻     
       char num[10];       //����
	   char name[10];      //����
	   double gwgz;        //��λ����
	   double xjgz;        //н������
	   double zwjt;        //ְ����
	   double jxgz;        //��Ч����
	   double yfgz;        //Ӧ������
	   double grsds1;      //��������˰
	   double sfgz;        //ʵ������
}zggz[100];
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
		in>>zggz[i].num>>zggz[i].name>>zggz[i].gwgz>>zggz[i].xjgz>>zggz[i].zwjt>>zggz[i].jxgz>>zggz[i].yfgz>>zggz[i].grsds1>>zggz[i].sfgz;
	    /*in.seekp(sizeof(zggz)*i);
		in.read((char*) &zggz,sizeof(zggz));*/
		 cout<<"���ţ�"<<zggz[i].num<<"   ���֣� "<<zggz[i].name<<"  ��λ���ʣ� "//���ְ���������ݡ�
			<<zggz[i].gwgz<<"  н�����ʣ�"<<zggz[i].xjgz<<"  ְ�������"
			<<zggz[i].zwjt<<"  ��Ч���ʣ�"<<zggz[i].jxgz<<"  Ӧ�����ʣ�"
			<<zggz[i].yfgz<<"  ��������˰��"<<zggz[i].grsds1<<"  ʵ�����ʣ�"
			<<zggz[i].sfgz<<endl;
		n=n+1;}
		else break;
	}
	in.close();
	return 0;
}
int write()//����ְ���������ݵĺ���
{
		fstream out("gx.dat",ios::out|ios::binary);//�򿪶������ļ�
	if(!out)
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳�����
	}
	for(int i=0;i<n;i++)
	out.write((char*) &zggz[i],sizeof(zggz));//****************************************���������⣬��ͷ������ơ�
	out.close();
	return 0;
}
int fin()//��ѯְ���������ݺ�����
{
	int i;
	char gonghao[10];
	cout<<"�����빤��:"<<endl;
	cin>>gonghao;
	for(i=0;i<=n;i++)
		{if(strcmp(zggz[i].num,gonghao)==0)//�ȽϹ����Ƿ���ͬ��
		  {
			cout<<"���ţ�"<<zggz[i].num<<"   ���֣� "<<zggz[i].name<<"  ��λ���ʣ� "//���ְ���������ݡ�
			<<zggz[i].gwgz<<"  н�����ʣ�"<<zggz[i].xjgz<<"  ְ�������"
			<<zggz[i].zwjt<<"  ��Ч���ʣ�"<<zggz[i].jxgz<<"  Ӧ�����ʣ�"
			<<zggz[i].yfgz<<"  ��������˰��"<<zggz[i].grsds1<<"  ʵ�����ʣ�"
			<<zggz[i].sfgz<<endl;
			break;
		   }
		  else//�����ҵ���n+1��ʱ����
			cout<<"���ִ���û��������š�"<<endl;
	    }
	return 0;	
}
int list()//���ְ���������ݺ���
{
	cout<<"ȫ��ְ���������£�"<<endl;
	for(int i=0;i<n;i++)         //ѭ��������ݡ� 
	{
		    cout<<"���ţ�"<<zggz[i].num<<"   ���֣� "<<zggz[i].name<<"  ��λ���ʣ� "//���ְ���������ݡ�
			<<zggz[i].gwgz<<"  н�����ʣ�"<<zggz[i].xjgz<<"  ְ�������"
			<<zggz[i].zwjt<<"  ��Ч���ʣ�"<<zggz[i].jxgz<<"  Ӧ�����ʣ�"
			<<zggz[i].yfgz<<"  ��������˰��"<<zggz[i].grsds1<<"  ʵ�����ʣ�"
			<<zggz[i].sfgz<<endl;
	}
	return 0;
}
int modify()//�޸�ְ�����ʵĺ�����
{
	   char num1[10];
	   char name1[10];
	   double gwgz1;
	   double xjgz1;
	   double zwjt1;
	   double jxgz1;
	int i,j;
	char gonghao[10];
	cout<<"�����빤��:"<<endl;
	cin>>gonghao;
	for(i=0;i<=n;i++)
		{if(strcmp(zggz[i].num,gonghao)==0)//�ȽϹ����Ƿ���ͬ��
		  {   j=i;
			  cout<<"���������������Ϣ"<<endl;//���������޸���Ϣ��
			  cout<<"  ���ţ�";
			  cin>>num1;
		      cout<<"  ������";
			  cin>>name1;
			  cout<<"  ��λ���ʣ�";
			  cin>>gwgz1;
			  cout<<"  н�����ʣ�";
			  cin>>xjgz1;
			  cout<<"  ְ�������";
			  cin>>zwjt1;
			  cout<<"  ��Ч���ʣ�";
			  cin>>jxgz1;
			 
			strcpy(zggz[i].num,num1),strcpy(zggz[i].name,name1),
			zggz[i].gwgz=gwgz1,zggz[i].xjgz=xjgz1,zggz[i].zwjt=zwjt1,
			zggz[i].jxgz=jxgz1,zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz,
			zggz[i].grsds1=grsds(i),zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds1;//�޸ĵ����ݡ�
		   }
		else//�����ҵ���n+1��ʱ����
			cout<<"���ִ���û��������š�"<<endl;
	    }
	return 0;	
}
int del()//ɾ��ְ���������ݺ���
{
	int i,a;
	char gonghao[10];
	cout<<"������Ҫɾ����ְ���Ĺ��ţ�";
	cin>>gonghao;
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].num,gonghao)==0)
	  {
		  cout<<"�Ƿ�ɾ����ȷ��ɾ����ظ�1��ȡ��ɾ����ظ�0";
		  cin>>a;
		  if(a==1)       //ȷ��ɾ����
		   {
			  for(int j=i;j<n;j++)
			    zggz[j]=zggz[j+1];//ɾ���˹��ŵ�ְ���������ݡ�
		      n=n-1;
		   }
		  if(a==0)               //ȡ��ɾ��
			  break;
	  }
		else
			cout<<"���ִ���û�г��ִ˹��ţ�"<<endl;
	}
	return 0;
}
void add()//���ְ���������ݺ�����
{
	cout<<"������Ա���Ļ�������";
	n=n+1;
	   cout<<"  ���ţ�";          //������������Ϣ��
	   cin>>zggz[n].num;          //���빤�š� 
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
		 cout<<"���ţ�"<<zggz[n].num<<"   ���֣� "<<zggz[n].name<<"  ��λ���ʣ� "//���ְ���������ݡ�
			<<zggz[n].gwgz<<"  н�����ʣ�"<<zggz[n].xjgz<<"  ְ�������"
			<<zggz[n].zwjt<<"  ��Ч���ʣ�"<<zggz[n].jxgz<<"  Ӧ�����ʣ�"
			<<zggz[n].yfgz<<"  ��������˰��"<<zggz[n].grsds1<<"  ʵ�����ʣ�"
			<<zggz[n].sfgz<<endl;
}
double grsds(int a)
{
	double yfgz,grsds;
	yfgz=zggz[a].gwgz+zggz[a].xjgz+zggz[a].zwjt+zggz[a].jxgz;
	if(yfgz<=500)
		grsds=yfgz*0.05;                        //����500�ڵĸ�������˰�� 
	else if(500<yfgz&&yfgz<=2000)
		grsds=(yfgz-500)*0.1+500*0.05;                     // ����500-2000�ĸ�������˰��
	else if(2000<yfgz&&yfgz<=5000)                                                                                
		grsds=(yfgz-2000)*0.15+1500*0.1+500*0.05;               //����2000-5000�ڵĸ�������˰��
	else if(5000<yfgz&&yfgz<=20000)
		grsds=(yfgz-5000)*0.2+3000*0.15+1500*0.1+500*0.05;                     //����5000-20000�ڵĸ�������˰��
	else if(20000<yfgz&&yfgz<=40000)
		grsds=(yfgz-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                   //����20000-40000�ڵĸ�������˰��
	else if(40000<yfgz&&yfgz<=60000)
		grsds=(yfgz-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                  //����40000-60000�ڵĸ�������˰��
	else if(60000<yfgz&&yfgz<=80000)
		grsds=(yfgz-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;             //����60000-80000�ڵĸ�������˰��
	else if(80000<yfgz&&yfgz<=100000)
		grsds=(yfgz-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;           //����80000-100000�ڵĸ�������˰��
	else if(100000<yfgz)
		grsds=(yfgz-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;         //����100000���ϵĸ�������˰��
	return grsds;
}
int main()
{
	int b;//������������
	read();//����read�����ĺ�������ȡ�ļ��е����ݴ����ṹ���С�
	cout<<"��ӭʹ��ְ�����ʲ���ϵͳ��"<<endl;
	do//ѭ������ֱ���뵽exit��0���˳���������
	{
	  cout<<"1.��ѯ  2.�޸�  3.���  4.ɾ��  5.����  6.���  7.�˳�"<<endl;
	  cout<<"���������ϲ�������ţ�"<<endl;
	  cin>>b;
	  if(b==1)
		  fin();//����fin�����������в��ҡ�
	  if(b==2)
		  modify();//����modify�������������޸ġ�
	  if(b==3)
		  add();//����add���������������ְ���������ݡ�
	  if(b==4)
		  del();//����del������������ְ�����ݵ�ɾ����
	  if(b==5)
		  write();//����write������������ְ���������ݵı��档
	  if(b==6)
		  list();//����list���������������е����������
	  if(b==7)
		  exit(0);//�˳�����
	}while(b!=7);
   return 0;
}
