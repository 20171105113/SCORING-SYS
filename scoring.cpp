#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
string Trim(string& str)
{
 str.erase(0,str.find_first_not_of(" \t\r\n"));
 str.erase(str.find_last_not_of(" \t\r\n") + 1);
 return str;
}

int main()
{
	int n=-1;        //记录学生人数,因需要从行名（num,name,sex,dob等）开始记数，所以从-1开始计数
	int i=0,j=0,l=0; //循环控制变量
	int a[10][10];	
	int judge[6][100];
	int score[100];
	int jud[10];
	double sum[100][100]; 
 	string stu[13][100]; 
	string stu1[13][100];
	string stu2[13][100];
	
ifstream fin("C:/Users/LXH/Desktop/SCORING SYS/SCORING-SYS/studentdata.csv"); //打开csv类型文件
string line; 
while (getline(fin, line)) 
{

  istringstream sin(line); 
  vector<string> fields; 
  string field;
while (getline(sin, field, ',')) 
{
   fields.push_back(field); 
}

  stu[0][i] = Trim(fields[0]); 
  stu[1][i] = Trim(fields[1]); 
  stu[2][i] = Trim(fields[2]); 
  stu[3][i] = Trim(fields[3]);
  stu[4][i] = Trim(fields[4]);
  stu[5][i] = Trim(fields[5]);
  stu[6][i] = Trim(fields[6]);
  stu[7][i] = Trim(fields[7]);
  stu[8][i] = Trim(fields[8]);
  stu[9][i] = Trim(fields[9]);
  stu[10][i] = Trim(fields[10]);
//  cout <<  stu[0][i] << "\t" <<  stu[1][i] << "\t" <<  stu[2][i] << "\t" <<  stu[3][i] << "\t" <<  stu[4][i] <<"\t"<<stu[5][i]<<"\t"<<stu[10][i]<<endl;
  i++;
  j++;
  n++;
}
//读取CSV文件中的数据 

//cout<<n<<endl;

for(i=0;i<n;i++)
{
	for(j=0;j<5;j++)
	{
	stringstream aa;
	aa<<stu[j+6][i+1];
	aa>>a[i][j];
//	cout<<a[i][j];
//	cout<<"~"<<endl;
	}
//	cout<<endl;
}
//将string类型数据转换成int类型 

for(l=0;l<n;l++)
{
	for (i=0;i<5-1;i++)
	{
		for (j=0;j<5-i-1;j++)
		{
			if (a[l][j]<a[l][j+1])
			{
				int temp;
				temp=a[l][j];
				a[l][j]=a[l][j+1];
				a[l][j+1]=temp;
			}
		}
	}

}
//for(i=0;i<5;i++)
//{
//	cout<<a[0][i]<<endl;
//}
//for(i=0;i<5;i++)
//{
//	cout<<a[1][i]<<endl;
//}
//  冒泡排序将裁判给每个人的成绩进行从大到小排序

for(i=0;i<n;i++)
{
    sum[i][i]=0;
	for(j=1;j<5-1;j++)
 {
	
	sum[i][i]=sum[i][i]+a[i][j];
 }
 sum[i][i]=sum[i][i]/3;
}

//for(i=0;i<n;i++)
//{
//	for(j=0;j<n;j++)
//	{
//		cout<<sum[i][j]<<"~~~";
//	}
//	cout<<endl;
//}cout<<endl;
//得到每个同学的去掉一个最高分和一个最低分最后的得分 


double temp=0;
double sum1[100][100];
double sum2[100][100];
double sum3[100];
for(i=0;i<n;i++)
{
	sum1[0][i]=sum[i][i];
} 
for(i=0;i<n-1;i++)
{
	for (j=0;j<n-i-1;j++)
	{
		if (sum1[0][j]<sum1[0][j+1])
		{
				temp=sum1[0][j];
				sum1[0][j]=sum1[0][j+1];
				sum1[0][j+1]=temp;
		}
	}
}

//
//for(i=0;i<n;i++)
//{
//	for(j=0;j<n;j++)
//	{
//		cout<<sum1[i][j]<<"~~~";
//	}
//	cout<<endl;
//}cout<<endl;


for(i=0;i<n;i++)
{

for(j=0;j<n;j++)
{
	if(sum[i][i]==sum1[0][j])
	{
		sum2[i][j]=sum1[0][j];
	}
}
}
//将最终分数做上初始顺序和排名顺序标记，用于最后的写入文件 
//for(i=0;i<n;i++)
//{
//	for(j=0;j<n;j++)
//	{
//		cout<<sum2[i][j]<<"~~~";
//	}
//	cout<<endl;
//}cout<<endl;


for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(sum2[j][i]!=0)
		{
			sum3[i]=sum2[j][i];
		}
	};
}


for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(sum2[j][i]!=0)
		{
			stu1[0][i+1]=stu[0][j+1];
			stu1[1][i+1]=stu[1][j+1];
			stu1[2][i+1]=stu[2][j+1];
			stu1[3][i+1]=stu[3][j+1];
			stu1[4][i+1]=stu[4][j+1];
			stu1[5][i+1]=stu[5][j+1];
		}
	}
}
//
//for(i=0;i<n;i++)
//{
//cout<<stu1[0][i+1]<<" "<<stu1[1][i+1]<<" "<<stu1[2][i+1]<<" "<<stu1[3][i+1]<<" "<<stu1[4][i+1]<<" "<<stu1[5][i+1]<<" "<<endl;
//}
//

ofstream ofile;

ofile.open("C:/Users/LXH/Desktop/SCORING SYS/SCORING-SYS/studentdataout.csv",ios::out | ios::trunc);
//判断.csv文件是否存在，不存在则建立

ofile<<"Number,Name,Sex,Date of birth,Major,Phone number,Final score"<<endl;                                                                                                                                           



for(i=0;i<=n-1;i++)

{

          ofile<<stu1[0][i+1];
    for(j=1;j<=5;j++)
    {
           ofile<<","<<stu1[j][i+1];
    }
    ofile<<","<<sum3[i];
    ofile<<endl; 
}
ofile.close();
cout<<"数据已处理，表格文件已保存,请到 C:/Users/LXH/Desktop/SCORING SYS/SCORING-SYS 目录下查看"<<endl; 
    return 0;
}
