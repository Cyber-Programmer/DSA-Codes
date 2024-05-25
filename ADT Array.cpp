#include<iostream>
#include<conio.h>
using namespace std;

struct myArray
{
	int t_size;
	int u_size;
	int* ptr;
};
void createarray(struct myArray* ar)
{
	cout<<"Enter the size of array you want to create: ";
	cin>>ar->t_size;
	ar->ptr=new int[ar->t_size];
	
}
void resize(struct myArray* ar)
{
	int n_size = ar->t_size*2;
	int* p = new int[n_size];
	
	for(int i = 0;i<ar->u_size;i++)
	{
		p[i] = ar->ptr[i];
	}
	delete[] ar->ptr ;
	ar->ptr = p;
	ar->t_size = n_size;
	cout<<"Array Resized. \n";
	
}
void display(struct myArray* ar)
{
	for(int i=0; i<ar->t_size ;i++)
	{
		cout<<ar->ptr[i]<<" ";
	}
	cout<<endl;
}

int insert(struct myArray* ar,int count)
{	
	int ctr = count;
	if(ctr == 0)
	{
	cout<<"Enter the number of elements you want to add: ";
	cin>>ar->u_size;
	if(ar->u_size > ar->t_size)
	{
		cout<<"Array overflow ";
		return ctr;
	}
	else
	{
	for(int i=ctr;i<ar->u_size+count;i++)
	{
		cin>>ar->ptr[i];
		if(i == 0.7*ar->t_size)
		{
			resize(ar);
			//ctr = ar->u_size;
		}
		
		ctr++;
	}
	ar->u_size=ctr;
	display(ar);
	return ctr;
}	
	}
	else
	{
		
	int value, ind;
		cout<<"What you want to insert in the array?\n";
		cin>>value;
		cout<<"At what index?\n";
		cin>>ind;
		if(ind>ar->t_size)
		{
			cout<<"Index out of range.\n";
		}
		else{
			ar->ptr[ind]=value;
			ctr++;
			if(ctr>=0.7*ar->t_size){
			resize(ar);
			}
			
		}
	return ctr;	
		
		
		
	}
}

void update(struct myArray* ar,int ind,int val)
{
	ar->ptr[ind] = val;
	display(ar);
}

void sort(struct myArray* ar)
{
	int checker = 1;

	for(int i = 1;i < ar->u_size;i++)
	{
		
		if(checker == 1)
		{
			
			checker = 0;
			
			for(int j = 0; j < ar->u_size - i;j++)
			{
			
				if(ar->ptr[j]>ar->ptr[j+1])
				{
					int temp = ar->ptr[j];
					ar->ptr[j] = ar->ptr[j+1];
					ar->ptr[j+1] = temp;
					checker = 1;		
				}
				
			}
	
		}
		else
		
		{
			cout<<"Sorted. \n";
			display(ar);
			break;
		}
		
	}
		
}

void delete_element(struct myArray* ar)
{
	int ind;
	cout<<"Enter An Index to delete(0 - "<<ar->u_size-1<<"): ";
	cin>>ind;
	int leng = ar->u_size;
	if(ar->u_size>ind&&ind>=0)
	{
		if (ar->ptr[ind] == 0)
	{
		cout<<"Already Empty Index.";
		display(ar);
	}
	else
	{
		if(ind == leng -1){
			
            ar->ptr[leng - 1] = 0;
       		display(ar);
        
		}
		else{
			ar->ptr[ind] = 0;
			for (int i = ind; i < leng; i++) {
                ar->ptr[i] = ar->ptr[i + 1];
            }

            ar->ptr[leng-1] = 0;
        	display(ar);
        
		}	
	}
		
		
	}
	else
	{
		cout<<"Invalid Index.";
	}
	
	
	
	
}

int binary_search(struct myArray* ar,int size,int val)
{
		int first = 0;
		int last = size -1;
		for(int i = first; i <= last; i++)
		{
			int mid = first + (last - first)/2;
			if(ar->ptr[mid] == val)
			{
				cout<<" Element Found at Index "<<mid<<endl;
				return 0;
			}
			else if(ar->ptr[mid] < val)
			{
				first = mid + 1;
			}
			else if(ar->ptr[mid] > val)
			{
				last = mid -1;
			}
			
		}
		cout<<"Element Not Found"<<endl;
	
}

int linear_search(struct myArray* ar,int val)
{
	
	for(int i = 0; i< ar->u_size;i++)
		{
			if(ar->ptr[i] == val)
			{
				cout<<" Element Found at Index "<<i<<endl;
				return 0;
			}
		}
		cout<<" Element Not Found"<<endl;
	
}


int algorithm(struct myArray* ar)
{
	int leng = ar->u_size;
	int opt;
	int val;
	cout<<"Choose Algorithm:\n 1)Linear Search\n 2)Binary Search\n 3)Automatically Choose Suitable Algorithm\n";
	cin>>opt;
	cout<<"Enter The Element You Want To Search: ";
	cin>>val;
	if (opt == 1)
	{
		linear_search(ar,val);	
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
			
				if(ar->ptr[j]>ar->ptr[j+1])
				{
					int temp = ar->ptr[j];
					ar->ptr[j] = ar->ptr[j+1];
					ar->ptr[j+1] = temp;
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
			binary_search(ar,leng,val);
		}
		else if(choose == 0)
		{
			binary_search(ar,leng,val);	
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
			
				if(ar->ptr[j]>ar->ptr[j+1])
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
		binary_search(ar,leng,val);		
		}
		else if(checker == 1)
		{
			cout<<"Using Linear Search As list is unsorted.";
			
		linear_search(ar,val);	
		}	
	}
}

void reversal(struct myArray* ar)
{
	int size = ar->u_size;
	int mid = size/2;
	
	
	for(int i = 0;i<=mid;i++)
	{
		int temp = ar->ptr[size-(i+1)];
		ar->ptr[size-(i+1)] = ar->ptr[i];
		ar->ptr[i] = temp;
	}
	display(ar);
	
	
	
}


int main ()
{
	int opt;
	int check;
	struct myArray arr;
	createarray(&arr);
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Insert Elements \n 2)Update Array \n 3)Delete Elements \n 4)Display Array \n 5)Sort Array \n 6)Search \n 7)Reverse \n 8)Quit \n Choose: ";	
		cin>>opt;
		
		if (opt == 1)
		{
			check=insert(&arr,check);
		}
		else if(opt == 2)
		{
			int index;
			int value;
			
			while(true)
			{
				cout<<"Enter the index where you want to insert value: ";
				cin>>index;
				cout<<endl;
				if(index>arr.t_size)
				{
					cout<<"Invalid Index. Enter A Valid Index. \n";
				}
				else
				{
					cout<<"Enter the value you want to insert: ";
					cin>>value;
				 	update(&arr,index,value);	
				 	cout<<"Array Updated. \n";
				 	break;
				}

			}
		}
		else if(opt == 3)
		{
			delete_element(&arr);
		}
		else if(opt == 4)
		{
		
			display(&arr);
		
		}
		else if(opt == 5)
		{
			sort(&arr);
		}
		else if(opt == 6)
		{
			algorithm(&arr);
		}
		else if(opt == 7)
		{
			reversal(&arr);
		}
		else if(opt == 8)
		{
			break;
		}
	
	}

	
	
	return 0;
}
