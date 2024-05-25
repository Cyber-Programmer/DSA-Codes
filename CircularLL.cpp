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
		struct node* temp = hp;
		if(hp==NULL)
		{
			cout<<"Linked List is empty. \n";
		}
		else
		{
		while(true)
		{
			if(hp->next==temp)
			{
				cout<<hp->data<<endl;
				break;
			}
			cout<<hp->data<<endl;
			hp = hp->next;
		}
//			cout<<hp->data<<endl;	
		}
	
	
}

struct node* insertatstart(struct node* hp){
	struct node* lead = hp;
	if(hp == NULL){
		hp = new node;
		cout<<"Enter the data: ";
		cin>>hp->data;
		hp->next = hp;
		display(hp);
		return hp;
	}
	else if(hp->next == hp)
	{
		struct node* temp;
		temp = new node;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next = hp;
		hp->next = temp;
		display(temp);
		return temp;
	}
	else
	{
		struct node* tail;
		while(true)
		{
			if(hp->next==lead)
			{
				tail=hp;
				break;
			}
			hp = hp->next;
		}
				
		struct node* temp;
		temp = new node;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next = lead;
		tail->next = temp;
		display(temp);
		return temp;	
	}
	
}

void insertatend(struct node* hp)
	{
		struct node* lead = hp;
		struct node* tempo = hp;
		if(hp==NULL)
		{
			cout<<"Linked List is empty. \n";
		}
		else
		{
			while(true)
			{
				
				if(hp->next == tempo)
				{
					struct node* temp;
					temp = new node;
					cout<<"Enter the data: ";
					cin>>temp->data;
					temp->next = tempo;		
					hp->next = temp;
					display(lead);
					break;	
				}
				hp = hp->next;
			}
		}
	}
	
void insert_atposition(struct node* hp)
{
	struct node* lead = hp;
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
	display(lead);
}

struct node* deleteatstart(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is Empty.";
	}
	else if(hp->next == hp)
	{
		delete hp;
		hp = NULL;
		return hp;
	}
	else
	{
	struct node* temp;
	struct node* lead = hp;
	struct node* tail;
	while(true)
		{
			if(hp->next==lead)
			{
				tail=hp;
				break;
			}
			hp = hp->next;
		}
				
	temp = lead->next;
	tail->next = temp;
	delete lead;
	cout<<"Head Deleted. \n";
	display(temp);
	return temp;	
	}
}
struct node* deleteatend(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is empty. \n";
	}
	else if(hp->next == hp)
	{
		delete hp;
		hp = NULL;
		return hp;
	}
	else
	{
	struct node* tempo = hp;
	struct node* temp;
	while(hp->next != tempo)
	{
		temp = hp;
		hp = hp->next;
	}
	delete hp;
	temp->next = tempo;
	hp = temp;
	cout<<"Tail Deleted. \n";
	display(tempo);	
	}
	
}
struct node* delete_atindex(struct node* hp)
{
	if (hp == NULL)
	{
		cout<<"Linked List is Empty. \n";
	}
	else if(hp->next == hp)
	{
		cout<<"There's only 1 element in the linked-list. Deleting it----- \n";
		delete hp;
		hp = NULL;
		cout<<"Element deleted. \n";
		return hp;
	}
	else
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
	
}
void search(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is Empty. \n";
	}
	else
	{
	struct node* tempo;
	int ctr = 0;
	int opt;
	bool check = true;
	cout<<"Enter an integer to search: ";
	cin>>opt;
	while(hp->next != tempo)
	{
		ctr++;
		if(hp->data == opt)
		{
			ctr--;
			cout<<"Element found at index "<<ctr<<endl;
			check = false;
			break;
		}
		hp = hp->next;
		
	}
	if (check)
	{
		cout<<"Element not found. \n";
	}
	}
}

void sort_node(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is empty. \n";
	}
	else
	{
	struct node* tempq;
	struct node* reset;
	reset = hp;
	struct node* tempo = hp;
	int check = 1;
	while(true)
	{
		if(check == 1)
		{
			check = 0;
			while(hp->next!=reset)
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
			display(reset);
			break;
		}
	}
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
			head = deleteatend(head);
		}
		else if(opt == 6)
		{
			head = delete_atindex(head);
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
