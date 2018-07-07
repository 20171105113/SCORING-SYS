#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string Trim(string& str)
{
 str.erase(0,str.find_first_not_of(" \t\r\n"));

 str.erase(str.find_last_not_of(" \t\r\n") + 1);

 return str;
}

int main()
{
	int n,i=0,j=0;
	string stu[13][100];
	int judge[6][100];
	cout<<"请输入学生人数："<<endl;
	cin>>n;
 ifstream fin("C:/Users/LXH/Desktop/scoring/studentdata.csv");

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
  stu[11][i] = Trim(fields[11]);
  cout <<  stu[0][i] << "\t" <<  stu[1][i] << "\t" <<  stu[2][i] << "\t" <<  stu[3][i] << "\t" <<  stu[4][i] << "\t" <<  stu[5][i] << "\t" <<  stu[6][i] <<     endl;
  i++;
  j++;
}
    
    return 0;
}
