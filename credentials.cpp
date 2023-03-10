#include <iostream>
#include<fstream>
using namespace std;
string names[100], passwords[100];
int ages[100];
float cgpa[100];
int idx = 0;
int index = 0;
int isPresent(string name, string password);
void displayOutput(int index);
int isPresent(string name, string password);
void readData();

main()
{
readData();
// string name, password;
// cout << "Enter Name: ";
// getline(cin, name);
// cout << "Enter Password: ";
// getline(cin, password);
//int index = isPresent(name, password);
// if(index == -1)
// {
// //cout << "User Not Present";
// displayOutput(index);
// }
// else
// {
// //displayOutput(index);
// }
displayOutput(index);
}

int isPresent(string name, string password)
{
int index = -1;
for(int x = 0; x < idx; x++)
{
if(name == names[x] && password == passwords[x])
{
index = x;
}
}
return index;
}

string getField(string record, int field)
{
int commaCount = 1;
string item;
for (int x = 0; x < record.length(); x++)
{
if (record[x] == ',')
{
commaCount = commaCount + 1;
}
else if (commaCount == field)
{
item = item + record[x];
}
}
return item;
}

void readData()
{
string record;
fstream data;
data.open("credentials.txt", ios::in);
while (!(data.eof()))
{
getline(data, record);
names[idx] = getField(record, 1);
passwords[idx] = getField(record, 2);
ages[idx] = stoi(getField(record, 3));
cgpa[idx] = stof(getField(record, 4));
idx = idx + 1;
}
}

void displayOutput(int index)
{
 cout << "Name \t Age \t CGPA \t Password" << endl;   
    for(int i =0 ;i < idx ; i++)
    {

cout << names[index] << " \t " << ages[index];
cout << " \t " << cgpa[index];
cout << " \t " <<passwords[index];
cout<<endl;
index++;
 
    }
     
  
}
