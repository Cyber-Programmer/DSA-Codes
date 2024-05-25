#include <iostream>
#include <conio.h>

using namespace std;


void delete_element(int arr[],int size);
void reversal(int arr[],int size);
void traverse_array(int arr[],int size);
void inserting(int arr[],int size);
void updation(int arr[],int size);
int algorithm(int arr[],int leng);
int binary_search(int arr[],int size,int val);
int linear_search(int arr[],int size,int val);
void max_sub(int arr[],int size);


int main()
{
	int leng = 5;
	int arr[5] = {9,7,0,0,2 };
	// int leng;
	// cout<<"Enter Length Of Array: ";
	// cin>>leng;
	// int arr[leng];
//	 for(int i = 0;i < leng;i++)
//	 {
//	 	cout<<"Enter Element "<<i+1<<" : ";
//	 	cin>>arr[i];
//	 }
	// cout<<"Your Array: ";
	// traverse_array(arr,leng);


	while(true){
	
	cout<< "Choose:\n1. Traversal\n2. Insertion\n3. Deleting\n4. Updation\n5. Reverse\n6. Apply algorithm\n7. Max sub Array\n";
	int opt;
	cin>>opt;
	if(opt==1){
		traverse_array(arr,leng);
	}
	else if(opt==2){
		inserting(arr,leng);
	}
	else if(opt==3){
		delete_element(arr,leng);
	}
	else if(opt==4){
		updation(arr,leng);
	}
	else if(opt==5){
		reversal(arr,leng);
	}
	else if(opt==6){
		algorithm(arr,leng);
	}
	else if(opt==7){
		max_sub(arr,leng);
	}
}

		 
		
return 0 ;	 	
	}
	
	
void traverse_array(int arr[],int size)
{	
	for(int i = 0;i < size;i++)
	{
		cout<<arr[i]<<" ";
	
	}
	cout<<endl;	
}

int linear_search(int arr[],int size,int val)
{
	
	for(int i = 0; i< size;i++)
		{
			if(arr[i] == val)
			{
				cout<<" Element Found at Index "<<i<<endl;
				return 0;
			}
		}
		cout<<" Element Not Found"<<endl;
	
}


int binary_search(int arr[],int size,int val)
{
		int first = 0;
		int last = size -1;
		for(int i = first; i <= last; i++)
		{
			int mid = first + (last - first)/2;
			if(arr[mid] == val)
			{
				cout<<" Element Found at Index "<<mid<<endl;
				return 0;
			}
			else if(arr[mid] < val)
			{
				first = mid + 1;
			}
			else if(arr[mid] > val)
			{
				last = mid -1;
			}
			
		}
		cout<<"Element Not Found"<<endl;
	
}

	

	
	
void inserting(int arr[],int size)
{
	
	int leng = size;
	int val;
	int ind;
	cout<<"Enter An Integer To Insert: ";
	cin>>val;
	cout<<"Enter Index of Array:(0 - "<<leng-1<<")";
	cin>>ind;
	if(size>ind&&ind>=0)
	{
		for(int i = 0; i < size;i++)
		{
			if(arr[i] == 0)
			{
			if (arr[ind] == 0)
		{
			arr[ind] = val;
			traverse_array(arr,leng);
			break;
		}
		else
		{
			if(ind == leng -1)
			{
				int temp = arr[leng-1];
				arr[leng-1] = val;
				val = temp;
	
				for (int i = leng - 2; i >= 0; --i)
					{
	                	arr[i] = arr[i - 1];
	            	}
	
	            arr[0] = val;
	       		traverse_array(arr,leng);
	      		break;
			}
			else
			{
				
				for (int i = leng - 1; i > ind; --i)
				{
	                arr[i] = arr[i - 1];
	            }
	            arr[ind] = val;
	        	traverse_array(arr,leng);
	        	break;
			}		
			
     	}	
				}
				else{
					cout<<"Can't Insert List Not Empty\n";
					break;
				}	
		}
		
    }
	else
	{
		cout<<"Invalid Index.";
	}
	
	
	

}
	
	
void delete_element(int arr[],int size)
{
	int ind;
	cout<<"Enter An Index to delete(0 - "<<size-1<<"): ";
	cin>>ind;
	int leng = size;
	if(size>ind&&ind>=0)
	{
		if (arr[ind] == 0)
	{
		cout<<"Already Empty Index.";
		traverse_array(arr,leng);
	}
	else
	{
		if(ind == leng -1){
			
            arr[leng - 1] = 0;
       		traverse_array(arr,leng);
        
		}
		else{
			arr[ind] = 0;
			for (int i = ind; i < leng; i++) {
                arr[i] = arr[i + 1];
            }

            arr[leng-1] = 0;
        	traverse_array(arr,leng);
        
		}	
	}
		
		
	}
	else
	{
		cout<<"Invalid Index.";
	}
	
	
	
	
}

void updation(int arr[],int size)
{
	int index;
	int value;
	cout<<"Enter The Index You Want To Update: ("<<0<<" to "<<size-1<<")";	
	cin>>index;
	cout<<"Enter The Value: ";
	cin>>value;
	arr[index] = value;
	traverse_array(arr,size);
	
	
}


void reversal(int arr[],int size)
{
	int mid = size/2;
	
	
	for(int i = 0;i<=mid;i++)
	{
		int temp = arr[size-(i+1)];
		arr[size-(i+1)] = arr[i];
		arr[i] = temp;
	}
	traverse_array(arr,size);
	
	
	
}


		
int algorithm(int arr[],int leng)
{
	int opt;
	int val;
	cout<<"Choose Algorithm:\n 1)Linear Search\n 2)Binary Search\n 3)Automatically Choose Suitable Algorithm\n";
	cin>>opt;
	cout<<"Enter The Element You Want To Search: ";
	cin>>val;
	if (opt == 1)
	{
		linear_search(arr,leng,val);	
	}
	else if (opt == 2)
	{
		int size = leng;
		int choose;
		cout<<"Do you want to sort the array first and then apply binary search or not?(1/0): ";
		cin>>choose;
		if (choose == 1)
		{
			int checker = 1;

	for(int i = 1;i < size;i++)
	{
		
		if(checker == 1)
		{
			
			checker = 0;
			
			for(int j = 0; j < size - i;j++)
			{
			
				if(arr[j]>arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					checker = 1;		
				}
				
			}
			
		}
		else
		
		{
			cout<<"Sorted.";
			break;
		}
		
	}
			binary_search(arr,leng,val);
		}
		else if(choose == 2)
		{
			binary_search(arr,leng,val);	
		}
		
	}
	else if(opt == 3)
	{
		
		int checker = 1;

	for(int i = 1;i < leng;i++)
	{
		
		if(checker == 1)
		{
			
			checker = 0;
			
			for(int j = 0; j < leng - i;j++)
			{
			
				if(arr[j]>arr[j+1])
				{
					
					checker = 1;		
				}
				
			}
		
		}
		else
		{
			break;
		}	
				

	}
	if (checker == 0)
		{
		cout<<"Using Binary Search As list is sorted.";
		binary_search(arr,leng,val);		
		}
		else if(checker == 1)
		{
			cout<<"Using Linear Search As list is unsorted.";
			
		linear_search(arr,leng,val);	
		}	
	}
	
	
	
	
	
}


void max_sub(int arr[],int size)
{
	int max = arr[0];
	int current;
	int end;
	int sin = 0;
	int ein = 0;
	for(int i = 0;i < size;i++)
	{
		current = arr[i];
		if( i != 0)
		{
			end = size;
		}
		else
		{
			end = size - 1;
		}
		for(int k = i+1;k<end;k++)
		{
			current+=arr[k];
			if(current>max)
			{
				max = current;
				sin = i;
				ein = k;
			}
		}
	}
	cout<<"Max Sum Of Sub Array is: "<<max<<endl;
	cout<<"Sub Array: ";
	for(int j = sin; j <= ein;j++)
	{
		cout<<arr[j]<<" ";
	}
	cout<<endl;
}

