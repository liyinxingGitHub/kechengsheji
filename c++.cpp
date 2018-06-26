/***************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: 设计.cpp
Author:李银兴   Version :1.01   Date:2018.06.24
Description: // 模块描述
Version: 1.01版// 版本信息
Function List: // 主要函数及其功能
1.main（）函数主要是根据用户的指令调用各个功能函数。
2.read()函数主要是读取职工工资数据。
3.write()函数主要是保存职工工资数据。
4.void fin()函数主要是查询职工工资数据。
5.list()函数主要是浏览职工工资数据。
6.modify()函数主要是修改职工工资。
7.del()函数主要是删除职工工资数据。
8.add()函数主要是添加职工工资数据。
9.grsds(int a)函数主要是计算个人所得税
History: // 历史修改记录
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
struct zggz{               //定义职工工资结构体；     
       char num[10];       //工号
	   char name[10];      //名字
	   float gwgz;        //岗位工资
	   float xjgz;        //薪级工资
	   float zwjt;        //职务工资
	   float jxgz;        //绩效工资
	   float yfgz;        //应发工资
	   float grsds1;      //个人所得税
	   float sfgz;        //实发工资
}zggz[100];

/***************************************************************************
Function:read（）             // 函数名称
Description:用来读取文件“gx.dat”中的数据，并存到结构体zggz中                  // 函数功能、性能等的描述
Calls:  暂无                    // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 文件“gx.dat”          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input: 暂无              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return:暂无          // 函数返回值的说明
Others:暂无          // 其它说明
***************************************************************************/
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
		in>>zggz[i].num>>zggz[i].name>>zggz[i].gwgz>>zggz[i].xjgz>>zggz[i].zwjt>>zggz[i].jxgz>>zggz[i].yfgz>>zggz[i].grsds1>>zggz[i].sfgz;//将文件中的数据逐一读入结构体 
		n=n+1;
		}
		else break;//如果文件已经到末尾则结束循环 
	}n=n-1;         //去掉空。 
	in.close();   //关闭文件 
	return 0;
}

/***************************************************************************
Function:write（）             // 函数名称
Description:用来将结构体中的数据保存至文件“gx.dat”中。                  // 函数功能、性能等的描述
Calls:  暂无                    // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 文件“gx.dat”          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input:暂无               // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output:暂无              // 对输出参数的说明。
Return:暂无          // 函数返回值的说明
Others:暂无          // 其它说明
***************************************************************************/
int write()      //保存职工工资数据的函数
{
		fstream out("gx.dat",ios::out|ios::binary);//打开二进制文件
	if(!out)
	{
		cout<<"Cannot open input file.\n";
		abort();          //退出程序，
	}
	for(int i=0;i<n;i++)
		if(!out.eof())          //检查文件是否到达末位置。
	    {
		out<<zggz[i].num<<"  "<<zggz[i].name<<"  "<<zggz[i].gwgz<<"  "<<zggz[i].xjgz<<"  "
		<<zggz[i].zwjt<<"  "<<zggz[i].jxgz<<"  "<<zggz[i].yfgz<<"  "<<zggz[i].grsds1<<"  "<<zggz[i].sfgz<<"  "<<endl;   //数据逐一保存到文件中。 
       	}
	out.close();   //关闭文件 
	cout<<"文件已保存！"<<endl;
	return 0;
}

/***************************************************************************
Function:fin（）             // 函数名称
Description:此数用来进行通过工号或者名字查询对应人的工资数据。                // 函数功能、性能等的描述
Calls: 暂无                   // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input:暂无               // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output:暂无              // 对输出参数的说明。
Return:暂无          // 函数返回值的说明
Others:暂无          // 其它说明
***************************************************************************/
void fin()//查询职工工资数据函数。
{
	int i;
	char ghname[10];//用于保存输入的工号或名字。 
	cout<<"请输入工号或者名字:"<<endl;
	cin>>ghname;       //输入工号或名字 
	for(i=0;i<=n;i++)       //循环输输出。 
		{
		if(strcmp(zggz[i].num,ghname)==0||strcmp(zggz[i].name,ghname)==0)//比较工号或名字是否相同。
		  {
		  cout<<setw(13)<<setiosflags(ios::left)<<"工号"<<setw(13)<<setiosflags(ios::left)<<"名字"<<setw(13)<<setiosflags(ios::left)<<"岗位工资" 
			<<setw(13)<<setiosflags(ios::left)<<"薪级工资"<<setw(13)<<setiosflags(ios::left)<<"职务津贴" <<setw(13)<<setiosflags(ios::left)<<"绩效工资"
			<<setw(13)<<setiosflags(ios::left)<<"应发工资"<<setw(13)<<setiosflags(ios::left)<<"个人所得税"<<setw(13)<<setiosflags(ios::left)<<"实发工资"<<endl;
		  cout<<setw(13)<<setiosflags(ios::left)<<zggz[i].num<<setw(13)<<setiosflags(ios::left)<<zggz[i].name<<setw(13)<<setiosflags(ios::left)<<zggz[i].gwgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[i].xjgz<<setw(13)<<setiosflags(ios::left)<<zggz[i].zwjt<<setw(13)<<setiosflags(ios::left)<<zggz[i].jxgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[i].yfgz<<setw(13)<<setiosflags(ios::left)<<zggz[i].grsds1<<setw(13)<<setiosflags(ios::left)<<zggz[i].sfgz<<endl; 
			break;
		   }
		  if(i==n)//当查找到第n+1个时报错。
		  {
		  	cout<<"出现错误：没有这个工号。"<<endl;
		   } 
	    }
	cout<<endl;
}

/***************************************************************************
Function:list（）             // 函数名称
Description:此函数用来浏览所有工资成员的数据                // 函数功能、性能等的描述
Calls:暂无                   // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input: 暂无              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return: 暂无        // 函数返回值的说明
Others: 暂无       // 其它说明
***************************************************************************/
int list()//浏览职工工资数据函数systerm("cls")systerm("pause")
{
	cout<<"全部职工工资如下："<<endl;
	if(n!=0)   //如果n不等于0则输出 
	{
		cout<<setw(13)<<setiosflags(ios::left)<<"工号"<<setw(13)<<setiosflags(ios::left)<<"名字"<<setw(13)<<setiosflags(ios::left)<<"岗位工资" 
			<<setw(13)<<setiosflags(ios::left)<<"薪级工资"<<setw(13)<<setiosflags(ios::left)<<"职务津贴" <<setw(13)<<setiosflags(ios::left)<<"绩效工资"
			<<setw(13)<<setiosflags(ios::left)<<"应发工资"<<setw(13)<<setiosflags(ios::left)<<"个人所得税"<<setw(13)<<setiosflags(ios::left)<<"实发工资"<<endl;
	} 
	for(int i=0;i<n;i++)         //循环输出数据。 
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
Function:modify（）             // 函数名称
Description:此函数用来修改职工工资数据，通过判断姓名或者工号来筛选出指定的数据。                // 函数功能、性能等的描述
Calls：grsds（）函数。                   // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input: 暂无              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return: 暂无        // 函数返回值的说明
Others: 暂无       // 其它说明
***************************************************************************/
int modify()//修改职工工资的函数。
{
	int i,j,xuhao;
	char ghname[10];    //定义 工号或名字 
	cout<<"请输入工号:"<<endl;
	cin>>ghname;
	for(i=0;i<=n;i++)
		{
		if(strcmp(zggz[i].num,ghname)==0||strcmp(zggz[i].name,ghname)==0)//比较工号或名字是否相同。
		  {   j=i;
		      cout<<"请输入您要修改部分序号：1、名字  2、岗位工资  3、薪级工资  4、职务津贴  5、绩效工资  6、全部修改 7、退出"<<endl;
			  cin>>xuhao;
			  if(xuhao==1)                               //当序号等于1时修改名字。 
			  {
		          cout<<"请输入修改的姓名："<<endl;
				  cin>>zggz[i].name;
				  break;
			  }
			  else if(xuhao==2)                          //当序号等于2时修改岗位工资。
			  {
				  cout<<"请输入修改的岗位工资："<<endl;
				  cin>>zggz[i].gwgz;
				  break;
			  }
			  else if(xuhao==3)                           //当序号等于3时修改薪级工资。
			  {
				  cout<<"请输入修改的薪级工资："<<endl;
				  cin>>zggz[i].xjgz;
				  break;
			  }
			  else if(xuhao==4)                            //当序号等于4时修改职务津贴。 
			  {
				  cout<<"请输入修改的职务津贴："<<endl;
				  cin>>zggz[i].zwjt;
				  break;
			  }
			  else if(xuhao==5)                            //当序号等于5时修改绩效工资。
			  {
				  cout<<"请输入修改的绩效工资："<<endl;
				  cin>>zggz[i].jxgz;
				  break;
			  }
			  else  if(xuhao==6)                            //当序号等于6时修改全部。 
			  {
				  cout<<"请输入修改的姓名："<<endl;
				  cin>>zggz[i].name;
				  cout<<"请输入修改的岗位工资："<<endl;
				  cin>>zggz[i].gwgz;
				  cout<<"请输入修改的薪级工资："<<endl;
				  cin>>zggz[i].xjgz;
				   cout<<"请输入修改的职务津贴："<<endl;
				  cin>>zggz[i].zwjt;
				  cout<<"请输入修改的绩效工资："<<endl;
				  cin>>zggz[i].jxgz;
				  break;
			  }
			  else if(xuhao==7)                              //当序号等于7时退出修改。
			  {
				  break;
			  }
			  zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz,
			  zggz[i].grsds1=grsds(i),zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds1;//修改的数据。
			  cout<<endl;
		}
		if(i==n)        //当查找到第n+1个时报错。
		  {
		  	cout<<"出现错误：没有这个工号。"<<endl;
			cout<<endl;
		  } 
	    }
	return 0;		
}

/***************************************************************************
Function:del（）             // 函数名称
Description:此函数用来删除所选定数据。                // 函数功能、性能等的描述
Calls:暂无                   // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input: 暂无              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return: 暂无        // 函数返回值的说明
Others: 暂无       // 其它说明
***************************************************************************/
int del()//删除职工工资数据函数
{
	int i,a;     //定义i用于循环变量，定义a用于存储0或1。 
	char ghname[10];         //定义工号或名字 
	cout<<"请输入要删除的职工的工号：";
	cin>>ghname;     //输入工号或名字。 
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].num,ghname)==0||strcmp(zggz[i].name,ghname)==0)  // 较工号或名字是否相同。
	  {
		  cout<<"是否删除，确认删除请回复1，取消删除请回复0"<<endl;
		  cin>>a;
		  if(a==1)       //确认删除。
		   {
			   for(int j=i;j<=n;j++)
			   {
                   zggz[j]=zggz[j+1];//删除此工号的职工工资数据。
			   } 
		      n=n-1;
			  cout<<"已成功删除！"<<endl;
			  cout<<endl;
		   }
		  if(a==0)               //取消删除
			  {
			  	break;
			  }
		  break;
	  }
		if(i==n)
		{
		cout<<"出现错误！没有出现此工号！"<<endl;
		cout<<endl;
		}
	}
	return 0;
}

/***************************************************************************
Function:add（）             // 函数名称
Description:此函数用来增加职工工资信息。                // 函数功能、性能等的描述
Calls:暂无                   // 被本函数调用的函数清单
Called By:main()函数。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input: 暂无              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return: 暂无        // 函数返回值的说明
Others: 暂无       // 其它说明
***************************************************************************/
int add()//添加职工工资数据函数。
{
	   if(n>100||n==100)
	   {
		   cout<<"对不起，数据表已满！！！"<<endl;
		   return 0;
	   }
	   cout<<"请输入员工的基本数据"<<endl;
	   cout<<"  工号：";          //输入新增的信息。
	   cin>>zggz[n].num;          //输入工号。
	   for(int i=0;i<n;i++)
	  {
		  if(strcmp(zggz[n].num,zggz[i].num)==0)//判断工号是否存在，如果存在重新输入工号。
	    {
		   cout<<"工号已存在，请重新输入工号：";
		   cin>>zggz[n].num;
		   i=0;
	    }
	   }
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
	    cout<<setw(13)<<setiosflags(ios::left)<<"工号"<<setw(13)<<setiosflags(ios::left)<<"名字"<<setw(13)<<setiosflags(ios::left)<<"岗位工资" 
			<<setw(13)<<setiosflags(ios::left)<<"薪级工资"<<setw(13)<<setiosflags(ios::left)<<"职务津贴" <<setw(13)<<setiosflags(ios::left)<<"绩效工资"
			<<setw(13)<<setiosflags(ios::left)<<"应发工资"<<setw(13)<<setiosflags(ios::left)<<"个人所得税"<<setw(13)<<setiosflags(ios::left)<<"实发工资"<<endl;
		cout<<setw(13)<<setiosflags(ios::left)<<zggz[n].num<<setw(13)<<setiosflags(ios::left)<<zggz[n].name<<setw(13)<<setiosflags(ios::left)<<zggz[n].gwgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[n].xjgz<<setw(13)<<setiosflags(ios::left)<<zggz[n].zwjt<<setw(13)<<setiosflags(ios::left)<<zggz[n].jxgz
			<<setw(13)<<setiosflags(ios::left)<<zggz[n].yfgz<<setw(13)<<setiosflags(ios::left)<<zggz[n].grsds1<<setw(13)<<setiosflags(ios::left)<<zggz[n].sfgz<<endl; 
		cout<<endl;
		n=n+1;
		return 0;
}

/***************************************************************************
Function:grsds()             // 函数名称
Description:此函数用来计算个人所得税。                // 函数功能、性能等的描述
Calls:                   // 被本函数调用的函数清单
Called By:add（）、modify（）。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input:传入的参数a是代表第几个员工。              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return: 返回计算好的个人所得税。        // 函数返回值的说明
Others: 暂无       // 其它说明
***************************************************************************/
float grsds(int a)//计算个人所得税
{
	float yfgz,grsds;   //定义局部变量用于用于存储应发工资和个人所得税。 
	yfgz=zggz[a].gwgz+zggz[a].xjgz+zggz[a].zwjt+zggz[a].jxgz;  //计算应发工资。 
	if(yfgz<=500)
	{
		grsds=yfgz*0.05;   //计算500内的个人所得税。
	} 	                      
	else if(500<yfgz&&yfgz<=2000)
	{
		grsds=(yfgz-500)*0.1+500*0.05;   // 计算500-2000的个人所得税。
	}                  
	else if(2000<yfgz&&yfgz<=5000)  
	{
		grsds=(yfgz-2000)*0.15+1500*0.1+500*0.05;               //计算2000-5000内的个人所得税。
	}                                                                              
	else if(5000<yfgz&&yfgz<=20000)
	{
		grsds=(yfgz-5000)*0.2+3000*0.15+1500*0.1+500*0.05;                     //计算5000-20000内的个人所得税。
	} 
	else if(20000<yfgz&&yfgz<=40000)
	{
		grsds=(yfgz-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                   //计算20000-40000内的个人所得税。
	} 	
	else if(40000<yfgz&&yfgz<=60000)
	{
		grsds=(yfgz-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                  //计算40000-60000内的个人所得税。
	} 
	else if(60000<yfgz&&yfgz<=80000)
	{
		grsds=(yfgz-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;             //计算60000-80000内的个人所得税。
	} 
	else if(80000<yfgz&&yfgz<=100000)
	{
		grsds=(yfgz-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;           //计算80000-100000内的个人所得税。
	} 
	else if(100000<yfgz)
	{
		grsds=(yfgz-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;         //计算100000以上的个人所得税。
	} 	
	return grsds;
}

/***************************************************************************
Function:main（）             // 函数名称
Description:利用主函数来实现各种操作，调用各个函数进行操作。                // 函数功能、性能等的描述
Calls:add(),del(),fin(),fin(),list(),modify(),read(),write().                   // 被本函数调用的函数清单
Called By:无。                   // 调用本函数的函数清单
Table Accessed: 结构体zggz。          // 被访问的表（此项仅对于牵扯到数据库操作的程序）
Table Updated: 暂无                     // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input: 暂无              // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。 
Output: 暂无             // 对输出参数的说明。
Return: 暂无        // 函数返回值的说明
Others: 暂无       // 其它说明
***************************************************************************/
int main()
{
	int b;//定义输入的序号
	read();//调用read（）的函数，读取文件中的数据存至结构体中。
	do//循环操作直至入到exit（0）退出整个程序。
	{
	  cout<<"*************************欢迎使用职工工资操作系统：**************************"<<endl;
	  cout<<"*"<<"                                                                           "<<"*"<<endl;
	  cout<<"*"<<"                       1.查询  2.修改  3.添加  4.删除                      "<<"*"<<endl;
	  cout<<"*"<<"                           5.保存  6.浏览  7.退出                          "<<"*"<<endl;
	  cout<<"***************************************************************************** "<<endl;
	  cout<<"请输入以上操作的序号："<<endl;
	  cin>>b;
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
	  	cout<<"****************谢谢您的使用！！欢迎下次继续使用，再见！！！*****************"<<endl;
	  	exit(0);//退出程序。
	  } 	 
	}while(b!=7);
   return 0;
}