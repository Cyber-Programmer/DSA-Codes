#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};
//self referencing pointer points towards the same node

void display(struct node* hp)
{	
		if(hp==NULL)
		{
			cout<<"Linked List is empty. \n";
		}
		else
		{
			while(hp->next != NULL)
			{
				cout<<hp->data<<endl;
				hp = hp->next;	
			}
			cout<<hp->data<<endl;	
		}
	
	
}

struct node* insertatstart(struct node* hp){
	if(hp == NULL){
		hp = new node;
		cout<<"Enter the data: ";
		cin>>hp->data;
		hp->next = NULL;
		return hp;
	}
	else
	{
		struct node* temp;
		temp = new node;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next = hp;
		return temp;	
	}
}

void insertatend(struct node* hp)
	{
		if(hp==NULL)
		{
			cout<<"Linked List is empty. \n";
		}
		else
		{
			while(true)
			{
				
				if(hp->next == NULL)
				{
					struct node* temp;
					temp = new node;
					cout<<"Enter the data: ";
					cin>>temp->data;
					temp->next = NULL;		
					hp->next = temp;
					break;	
				}
				hp = hp->next;
			}
		}
	}
	
void insert_atposition(struct node* hp)
{
	struct node* prev;
	struct node* temp;
	int opt;
	cout<<"Enter the index for insertion: ";
	cin>>opt;
	cout<<endl;
	int ctr = 0;
	while(ctr < opt)
	{
		prev = hp;
		hp = hp->next;
		ctr++;
	}
	temp = new node;
	cout<<"Enter the data: ";
	cin>>temp->data;
	temp->next = hp;
	prev->next = temp;
}

struct node* deleteatstart(struct node* hp)
{
	struct node* temp;
	temp = hp->next;
	delete hp;
	cout<<"Head Deleted. \n";
	display(temp);
	return temp;	
}
void deleteatend(struct node* hp)
{
	struct node* temp;
	while(hp->next != NULL)
	{
		temp = hp;
		hp = hp->next;
	}
	delete hp;
	temp->next = NULL;
	hp = temp;
}
void delete_atindex(struct node* hp)
{
	struct node* prev;
	int opt;
	cout<<"Enter the index for deletion: ";
	cin>>opt;
	cout<<endl;
	int ctr = 0;
	while(ctr < opt)
	{
		prev = hp;
		hp = hp->next;
		ctr++;
	}
	prev->next = hp->next;
	delete hp;
	hp = prev;
}
void search(struct node* hp)
{
	int ctr = 0;
	int opt;
	cout<<"Enter an integer to search: ";
	cin>>opt;
	while(hp->next != NULL)
	{
		ctr++;
		if(hp->data == opt)
		{
			ctr--;
			cout<<"Element found at index "<<ctr<<endl;
			break;
		}
		hp = hp->next;
		
	}
}

void sort_node(struct node* hp)
{
	struct node* reset;
	reset = hp;
	struct node* tempo = hp;
	int check = 1;
	while(tempo->next!=NULL)
	{
		if(check == 1)
		{
			check = 0;
			while(hp->next!=NULL)
			{
				if(hp->data>hp->next->data)
				{
					int temp = hp->data;
					hp->data = hp->next->data;
					hp->next->data=temp;
					check = 1;
					
				}
				hp = hp->next;
			}
			hp = reset;
		}
		else
		{
			cout<<"Sorted. \n";
			break;
		}
		tempo = tempo->next;
	}
	
	
}


int main()
{
	
	struct node* head = NULL;
	int opt;
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Insert at head \n 2)Insert at tail \n 3)Insert at provided position \n 4)Delete at head \n 5)Delete at tail \n 6)Delete at provided position \n 7)Traversal \n 8)Search for a particular value in list and return its index \n 9)Sort \n 10)Exit \n Choose: ";	
		cin>>opt;
		if(opt == 1)
		{
			head = insertatstart(head);
		}
		else if(opt == 2)
		{
			insertatend(head);	
		}
		else if(opt == 3)
		{
			insert_atposition(head);
		}
		else if(opt == 4)
		{
			head = deleteatstart(head);
		}
		else if(opt == 5)
		{
			deleteatend(head);
		}
		else if(opt == 6)
		{
			delete_atindex(head);
		}
		else if(opt == 7)
		{
			display(head);
		}
		else if(opt == 8)
		{
			search(head);
		}
		else if(opt == 9)
		{
			sort_node(head);
		}
		else if(opt == 10)
		{
			break;
		}
		
	}
	return 0;
	
	
	
	
}
