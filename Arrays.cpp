#include<iostream>
#include<conio.h>
using namespace std;

int max(int arr[], int size);

int main()
{
	int arr[5] = {1,2,3,4,5};
	cout<<&arr<<endl;
	cout<<&arr[3]<<endl; //to get memory address of specific index of array
	cout<<"Maximum: "<<max(arr,5);
	
	
}



int max(int arr[], int size)
{
	int maxim = arr[0];
	for(int i = 1;i < size;i++)
	{
		if(maxim<arr[i])
		{
			maxim = arr[i];
		}
		
		
		
	}
	return maxim;
	
}
