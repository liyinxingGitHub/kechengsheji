#include<string>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include"string.h"
#include<fstream>
float grsds(int a);         //����grsds()����
int n=0;                   //����ȫ�ֱ���������ʼ����
using namespace std;
struct zggz{               //����ְ�����ʽṹ�壻     
       char num[10];       //����
	   char name[10];      //����
	   float gwgz;        //��λ����
	   float xjgz;        //н������
	   float zwjt;        //ְ����
	   float jxgz;        //��Ч����
	   float yfgz;        //Ӧ������
	   float grsds;      //��������˰
	   float sfgz;        //ʵ������
};
int read()//����ְ���������ݵĺ���																					//�ļ���ȡģ��
{
	
	cout<<"��ȡ�ļ���!"<<endl;
	zggz worker,*q;
	FILE *fp;
	char ch;
	int i;
	q=&worker;
	if((fp=fopen("gx.dat","rb"))==NULL)
	{
		cout<<"Can't open this file!";
		getch();
		exit(-1);
	}
	for(i=0;i<100;i++)
	{
		fseek(fp,i*sizeof(struct zggz),0);
		fread(q,sizeof(struct zggz),1,fp);
		//printf("%s%s%f%f%f%f%f%f%f",q->num,q->name,q->gwgz,q->xjgz,q->zwjt,q->jxgz,q->yfgz,q->grsds,q->sfgz);
		cout<<q->num<<" "<<q->name<<" "<<q->gwgz<<" "<<q->xjgz<<" "<<q->zwjt<<" "<<q->jxgz<<" "<<q->yfgz<<" "<<q->grsds<<" "<<q->sfgz<<endl;
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("��ǰ�ļ�Ϊ�ս�����ǰ��ȡ\n");
			break;
		}
	}
	   fclose(fp);
       return 0;
}

int write()
{
	
	return 0;
}
int fin()//��ѯְ���������ݺ�����
{
	
	return 0;
}
int list()//���ְ���������ݺ���
{
	
	return 0;
}
int modify()//�޸�ְ�����ʵĺ�����
{
	
	return 0;
}
int del()//ɾ��ְ���������ݺ���
{
	
	return 0;
}
void add()//���ְ���������ݺ�����
{
	

}
float grsds(int a)//����˰��
{
	
	return 0;
}
int main()
{
	int b;//������������
	read();//����read�����ĺ�������ȡ�ļ��е����ݴ����ṹ���С�
	printf("��ӭʹ��ְ�����ʲ���ϵͳ��\n");
	do//ѭ������ֱ���뵽exit��0���˳���������
	{
	  printf("1.��ѯ  2.�޸�  3.���  4.ɾ��  5.����  6.���  7.�˳�\n");
	  printf("���������ϲ�������ţ�\n");
	  scanf("%d",&b);
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
           exit(0);//�˳�����
	  }
		  
	}while(b!=7);
   return 0;
}