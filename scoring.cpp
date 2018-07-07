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
	
	
	int n=-1;/*记录学生人数 */
	int i=0,j=0,l=0;
	int a[10][10];	
	string stu[13][100];
	int judge[6][100];
	int score[100];
	int jud[10];
	double sum[100]; 
	
	
ifstream fin("C:/Users/LXH/Desktop/SCORING SYS/SCORING-SYS/studentdata.csv");
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
//  cout <<  stu[0][i] << "\t" <<  stu[1][i] << "\t" <<  stu[2][i] << "\t" <<  stu[3][i] << "\t" <<  stu[4][i] << "\t" <<  stu[5][i] << "\t" <<  stu[10][i] <<     endl;
  i++;
  j++;
  n++;
}
//读取CSV文件中的数据 

cout<<n<<endl;

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
cout<<endl;
}
//将string类型数据转换成int类型 

for(l=0;l<n;l++)
{
	for (i=0;i<5-1;i++)
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
    sum[i]=0;
	for(j=1;j<5-1;j++)
 {
	
	sum[i]=sum[i]+a[i][j];
 }
 sum[i]=sum[i]/3;
}
//cout<<sum[0]<<" "<<sum[1]<<endl;
//得到每个同学的去掉一个最高分和一个最低分最后的得分 

    return 0;
}
