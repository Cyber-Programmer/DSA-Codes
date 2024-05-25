#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
	string Text;
	ifstream readFile("dictionary.txt");
	while(getline(readFile,Text))
	{
		cout<<Text<<endl;
	}
	readFile.close();
}
