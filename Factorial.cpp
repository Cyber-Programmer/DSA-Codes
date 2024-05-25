#include<iostream>
#include<conio.h>
using namespace std;
int fact(int a);

int main()
{
	
	int a;
	cout<<"Enter the number: ";
	cin>>a;
	cout<<"Factorial: "<<fact(a);	
	
}


int fact(int a)
{
	int f = 1;
	for(int i = 1;i<= a;i++)
	{
		f = f * i;
	}
	
	return f;
}
