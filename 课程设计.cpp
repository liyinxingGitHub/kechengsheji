#include<iostream>
#include<string>
#include"string.h"
#include<fstream>
double grsds(int a);
int n=0;
using namespace std;
struct zggz{               //定义职工工资结构体；     
       char num[10];       //工号
	   char name[10];      //名字
	   double gwgz;        //岗位工资
	   double xjgz;        //薪级工资
	   double zwjt;        //职务工资
	   double jxgz;        //绩效工资
	   double yfgz;        //应发工资
	   double grsds1;      //个人所得税
	   double sfgz;        //实发工资
}zggz[100];
int read()//读取职工工资数据的函数。
{
	fstream in("gx.dat",ios::in|ios::binary);//打开二进制文件
	if(!in)
	{
		cout<<"Cannot open input file.\n";
		abort();//退出程序，
	}
	for(int i=0;i<100;i++)
	{
		if(!in.eof())//检查文件是否到达末位置。
	    {
		in>>zggz[i].num>>zggz[i].name>>zggz[i].gwgz>>zggz[i].xjgz>>zggz[i].zwjt>>zggz[i].jxgz>>zggz[i].yfgz>>zggz[i].grsds1>>zggz[i].sfgz;
	    /*in.seekp(sizeof(zggz)*i);
		in.read((char*) &zggz,sizeof(zggz));*/
		 cout<<"工号："<<zggz[i].num<<"   名字： "<<zggz[i].name<<"  岗位工资： "//输出职工工资数据。
			<<zggz[i].gwgz<<"  薪级工资："<<zggz[i].xjgz<<"  职务津贴："
			<<zggz[i].zwjt<<"  绩效工资："<<zggz[i].jxgz<<"  应发工资："
			<<zggz[i].yfgz<<"  个人所得税："<<zggz[i].grsds1<<"  实发工资："
			<<zggz[i].sfgz<<endl;
		n=n+1;}
		else break;
	}
	in.close();
	return 0;
}
int write()//保存职工工资数据的函数
{
		fstream out("gx.dat",ios::out|ios::binary);//打开二进制文件
	if(!out)
	{
		cout<<"Cannot open input file.\n";
		abort();//退出程序，
	}
	for(int i=0;i<n;i++)
	out.write((char*) &zggz[i],sizeof(zggz));//****************************************这里有问题，回头重新设计。
	out.close();
	return 0;
}
int fin()//查询职工工资数据函数。
{
	int i;
	char gonghao[10];
	cout<<"请输入工号:"<<endl;
	cin>>gonghao;
	for(i=0;i<=n;i++)
		{if(strcmp(zggz[i].num,gonghao)==0)//比较工号是否相同。
		  {
			cout<<"工号："<<zggz[i].num<<"   名字： "<<zggz[i].name<<"  岗位工资： "//输出职工工资数据。
			<<zggz[i].gwgz<<"  薪级工资："<<zggz[i].xjgz<<"  职务津贴："
			<<zggz[i].zwjt<<"  绩效工资："<<zggz[i].jxgz<<"  应发工资："
			<<zggz[i].yfgz<<"  个人所得税："<<zggz[i].grsds1<<"  实发工资："
			<<zggz[i].sfgz<<endl;
			break;
		   }
		  else//当查找到第n+1个时报错。
			cout<<"出现错误：没有这个工号。"<<endl;
	    }
	return 0;	
}
int list()//浏览职工工资数据函数
{
	cout<<"全部职工工资如下："<<endl;
	for(int i=0;i<n;i++)         //循环输出数据。 
	{
		    cout<<"工号："<<zggz[i].num<<"   名字： "<<zggz[i].name<<"  岗位工资： "//输出职工工资数据。
			<<zggz[i].gwgz<<"  薪级工资："<<zggz[i].xjgz<<"  职务津贴："
			<<zggz[i].zwjt<<"  绩效工资："<<zggz[i].jxgz<<"  应发工资："
			<<zggz[i].yfgz<<"  个人所得税："<<zggz[i].grsds1<<"  实发工资："
			<<zggz[i].sfgz<<endl;
	}
	return 0;
}
int modify()//修改职工工资的函数。
{
	   char num1[10];
	   char name1[10];
	   double gwgz1;
	   double xjgz1;
	   double zwjt1;
	   double jxgz1;
	int i,j;
	char gonghao[10];
	cout<<"请输入工号:"<<endl;
	cin>>gonghao;
	for(i=0;i<=n;i++)
		{if(strcmp(zggz[i].num,gonghao)==0)//比较工号是否相同。
		  {   j=i;
			  cout<<"请重新输入基本信息"<<endl;//重新输入修改信息。
			  cout<<"  工号：";
			  cin>>num1;
		      cout<<"  姓名：";
			  cin>>name1;
			  cout<<"  岗位工资：";
			  cin>>gwgz1;
			  cout<<"  薪级工资：";
			  cin>>xjgz1;
			  cout<<"  职务津贴：";
			  cin>>zwjt1;
			  cout<<"  绩效工资：";
			  cin>>jxgz1;
			 
			strcpy(zggz[i].num,num1),strcpy(zggz[i].name,name1),
			zggz[i].gwgz=gwgz1,zggz[i].xjgz=xjgz1,zggz[i].zwjt=zwjt1,
			zggz[i].jxgz=jxgz1,zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz,
			zggz[i].grsds1=grsds(i),zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds1;//修改的数据。
		   }
		else//当查找到第n+1个时报错。
			cout<<"出现错误：没有这个工号。"<<endl;
	    }
	return 0;	
}
int del()//删除职工工资数据函数
{
	int i,a;
	char gonghao[10];
	cout<<"请输入要删除的职工的工号：";
	cin>>gonghao;
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].num,gonghao)==0)
	  {
		  cout<<"是否删除，确认删除请回复1，取消删除请回复0";
		  cin>>a;
		  if(a==1)       //确认删除。
		   {
			  for(int j=i;j<n;j++)
			    zggz[j]=zggz[j+1];//删除此工号的职工工资数据。
		      n=n-1;
		   }
		  if(a==0)               //取消删除
			  break;
	  }
		else
			cout<<"出现错误！没有出现此工号！"<<endl;
	}
	return 0;
}
void add()//添加职工工资数据函数。
{
	cout<<"请输入员工的基本数据";
	n=n+1;
	   cout<<"  工号：";          //输入新增的信息。
	   cin>>zggz[n].num;          //输入工号。 
	   cout<<"  姓名：";
	   cin>>zggz[n].name;         //输入名字 
	   cout<<"  岗位工资：";
	   cin>>zggz[n].gwgz;         //输入岗位工资
	   cout<<"  薪级工资：";
	   cin>>zggz[n].xjgz;         //输入薪级工资
	   cout<<"  职务津贴：";
	   cin>>zggz[n].zwjt;         //输入职务津贴
		cout<<"  绩效工资：";
		cin>>zggz[n].jxgz;        //输入绩效工资
		zggz[n].yfgz=zggz[n].gwgz+zggz[n].xjgz+zggz[n].zwjt+zggz[n].jxgz;      //计算应发工资 
		zggz[n].grsds1=grsds(n);	   //调用grsds（）计算个人所得税 
		zggz[n].sfgz=zggz[n].yfgz-zggz[n].grsds1;    //计算实发工资 
		 cout<<"工号："<<zggz[n].num<<"   名字： "<<zggz[n].name<<"  岗位工资： "//输出职工工资数据。
			<<zggz[n].gwgz<<"  薪级工资："<<zggz[n].xjgz<<"  职务津贴："
			<<zggz[n].zwjt<<"  绩效工资："<<zggz[n].jxgz<<"  应发工资："
			<<zggz[n].yfgz<<"  个人所得税："<<zggz[n].grsds1<<"  实发工资："
			<<zggz[n].sfgz<<endl;
}
double grsds(int a)
{
	double yfgz,grsds;
	yfgz=zggz[a].gwgz+zggz[a].xjgz+zggz[a].zwjt+zggz[a].jxgz;
	if(yfgz<=500)
		grsds=yfgz*0.05;                        //计算500内的个人所得税。 
	else if(500<yfgz&&yfgz<=2000)
		grsds=(yfgz-500)*0.1+500*0.05;                     // 计算500-2000的个人所得税。
	else if(2000<yfgz&&yfgz<=5000)                                                                                
		grsds=(yfgz-2000)*0.15+1500*0.1+500*0.05;               //计算2000-5000内的个人所得税。
	else if(5000<yfgz&&yfgz<=20000)
		grsds=(yfgz-5000)*0.2+3000*0.15+1500*0.1+500*0.05;                     //计算5000-20000内的个人所得税。
	else if(20000<yfgz&&yfgz<=40000)
		grsds=(yfgz-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                   //计算20000-40000内的个人所得税。
	else if(40000<yfgz&&yfgz<=60000)
		grsds=(yfgz-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                  //计算40000-60000内的个人所得税。
	else if(60000<yfgz&&yfgz<=80000)
		grsds=(yfgz-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;             //计算60000-80000内的个人所得税。
	else if(80000<yfgz&&yfgz<=100000)
		grsds=(yfgz-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;           //计算80000-100000内的个人所得税。
	else if(100000<yfgz)
		grsds=(yfgz-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;         //计算100000以上的个人所得税。
	return grsds;
}
int main()
{
	int b;//定义输入的序号
	read();//调用read（）的函数，读取文件中的数据存至结构体中。
	cout<<"欢迎使用职工工资操作系统："<<endl;
	do//循环操作直至入到exit（0）退出整个程序。
	{
	  cout<<"1.查询  2.修改  3.添加  4.删除  5.保存  6.浏览  7.退出"<<endl;
	  cout<<"请输入以上操作的序号："<<endl;
	  cin>>b;
	  if(b==1)
		  fin();//调用fin（）函数进行查找。
	  if(b==2)
		  modify();//调用modify（）函数进行修改。
	  if(b==3)
		  add();//调用add（）函数进行添加职工工资数据。
	  if(b==4)
		  del();//调用del（）函数进行职工数据的删除。
	  if(b==5)
		  write();//调用write（）函数进行职工工资数据的保存。
	  if(b==6)
		  list();//调用list（）函数进行所有的数据浏览。
	  if(b==7)
		  exit(0);//退出程序。
	}while(b!=7);
   return 0;
}
