#include<iostream>
#include<conio.h>
using namespace std;

void EO(int a);

int main()
{
	int a;
	cout<<"Enter a number: ";
	cin>>a;
	EO(a);
	
	
	
}

void EO(int a)
{
	if(a%2==0)
	{
		cout<<a<<" is even";
		
	}
	else
	{
		cout<<a<<" is odd";
	}
}
