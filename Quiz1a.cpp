#include <iostream>
#include <conio.h>
using namespace std;

void mergeSort(int arr1[],int arr2[],int size)
{
	int arr[size+size];
	int j = 0;
	int k = 0;
	int ctr = 0;
	for(int i = 0;i<(size+size);i++)
	{
		if(arr1[j]<arr2[k])
		{
			arr[ctr] = arr1[j];
			j++;
			ctr++;
		}
		else if(arr1[j]>arr2[k])
		{
			arr[ctr] = arr2[k];
			k++;
			ctr++;
		}
		else if(arr1[j]==arr2[k])
		{
			arr[ctr] = arr2[k];
			ctr++;
			arr[ctr] = arr1[j];
			k++;
			j++;
			ctr++;
		
		}
//		else if(ctr == size*2)
//		{
//			break;
//		}		
	}
	cout<<"Sorted. \n";
	for(int m = 0;m<size*2;m++)
	{
		cout<<arr[m]<<" "; 
	}
	cout<<endl;
	
}

int main()
{
	int size;
	cout<<"Enter size of arrays: ";
	cin>>size;
	int array1[size];
	int array2[size];
	for(int i = 0; i<size;i++)
	{
		cout<<"Enter "<<i+1<<" element for Array 1: ";
		cin>>array1[i];
		cout<<endl;
	
	}
	for(int a = 0;a<size;a++)
	{
		cout<<"Enter "<<a+1<<" element for Array 2: ";
		cin>>array2[a];
		cout<<endl;
	}
	for(int l = 0;l<size;l++)
	{
		cout<<array1[l]<<" "; 
	}
	cout<<endl;
	for(int n = 0;n<size;n++)
	{
		cout<<array2[n]<<" "; 
	}
	cout<<endl;
	mergeSort(array1,array2,size);	
}
