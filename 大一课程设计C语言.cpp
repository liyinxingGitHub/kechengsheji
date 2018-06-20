#include<string>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include"string.h"
#include<fstream>
float grsds(int a);         //定义grsds()函数
int n=0;                   //定义全局变量，并初始化。
using namespace std;
struct zggz{               //定义职工工资结构体；     
       char num[10];       //工号
	   char name[10];      //名字
	   float gwgz;        //岗位工资
	   float xjgz;        //薪级工资
	   float zwjt;        //职务工资
	   float jxgz;        //绩效工资
	   float yfgz;        //应发工资
	   float grsds;      //个人所得税
	   float sfgz;        //实发工资
};
int read()//保存职工工资数据的函数																					//文件读取模块
{
	
	cout<<"读取文件中!"<<endl;
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
			printf("当前文件为空结束当前读取\n");
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
int fin()//查询职工工资数据函数。
{
	
	return 0;
}
int list()//浏览职工工资数据函数
{
	
	return 0;
}
int modify()//修改职工工资的函数。
{
	
	return 0;
}
int del()//删除职工工资数据函数
{
	
	return 0;
}
void add()//添加职工工资数据函数。
{
	

}
float grsds(int a)//计算税率
{
	
	return 0;
}
int main()
{
	int b;//定义输入的序号
	read();//调用read（）的函数，读取文件中的数据存至结构体中。
	printf("欢迎使用职工工资操作系统：\n");
	do//循环操作直至入到exit（0）退出整个程序。
	{
	  printf("1.查询  2.修改  3.添加  4.删除  5.保存  6.浏览  7.退出\n");
	  printf("请输入以上操作的序号：\n");
	  scanf("%d",&b);
	  if(b==1)
	  {
		  fin();//调用fin（）函数进行查找。
	  }     
	  if(b==2)
	  { 
		  modify();//调用modify（）函数进行修改。
	  }
	  if(b==3)
	  {
          add();//调用add（）函数进行添加职工工资数据。
	  }
		  
	  if(b==4)
	  {
          del();//调用del（）函数进行职工数据的删除。
	  }
		  
	  if(b==5)
	  {
		  write();//调用write（）函数进行职工工资数据的保存。
	  }
	  if(b==6)
	  {
		  list();//调用list（）函数进行所有的数据浏览。
	  }
		  
	  if(b==7)
	  {
           exit(0);//退出程序。
	  }
		  
	}while(b!=7);
   return 0;
}