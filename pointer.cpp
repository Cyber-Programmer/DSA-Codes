#include <iostream>
#include <conio.h>

using namespace std;

int* modify(int* pt){

	*pt = 1000;
	return pt+1;


}



int main(){
	
	int ax = 30;
	int* p1;
	p1 = &ax;

	cout<<ax<<endl;
	cout<<&ax<<endl;
	cout<<p1<<endl;
	cout<<&p1<<endl;
	cout<<*p1<<endl;
	cout<<sizeof(p1);

	*p1 = 200; //changing value using pointer
	cout<<ax<<endl;
	cout<<&ax<<endl;
	
	int ex = 20;
	int y = 30;
	int* x_pt;
	int* y_pt;
	x_pt = &ex;
	y_pt = &y;
	
	cout<<*x_pt<<endl;
	cout<<*y_pt<<endl;

	int* temp;
	temp = x_pt;
	x_pt = y_pt;
	y_pt = temp;
	
	cout<<*x_pt<<endl;
	cout<<*y_pt<<endl;


int zx = 20;
int* pt2 = &zx;
int**p2 = &pt2;
cout<<pt2<<endl;
cout<<p2<<endl;
cout<<sizeof(p2)<<endl;
cout<<&pt2<<endl;
cout<<p2<<endl;

int a[5] = {1,2,3,4,5};
cout<<a<<endl;
cout<<&a[0]<<endl;

int* pqt = a;
cout<<pqt<<endl;
cout<<pqt +1<<endl;

int* pqtr = new int[5];  // initializing dynamic array in heap memory
cout<<pqtr<<endl;
cout<<*pqtr<<endl;
cout<<&pqtr<<endl;

for(int i = 0;i<5;i++)
{
	cout<<i<<" Index value "<<*(pqtr+i)<<" and its address is "<<pqtr+i<<endl;

}

int arr[5] = {1,2,3,4,5};
int* p = arr;
cout<<*p<<endl;
p = modify(p);
cout<<*p<<endl;
cout<<*(p-1)<<endl;



}
