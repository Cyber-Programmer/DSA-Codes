#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int data;
	node* next;	
};
void traversal(struct node* hp)
{
	while(true)
	{
		if(hp->next == NULL)
		{
			cout<<hp->data<<endl;
			break;
		}
		cout<<hp->data<<" ";
		hp = hp->next;
	}
	
}
void revArray(struct node* hp)
{
	struct node* temp = hp;
	int ctr = 0;
	while(true)
	{
		if(hp->next == NULL)
		{
			break;
		}
		ctr++;
		hp = hp->next;
	}
	int arr[ctr];
	int i = 0;
	while(true)
	{
		
		if(temp->next == NULL)
		{
			arr[i] = temp->data;
			break;
		}
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}
	for(int j = 0;j<=ctr;j++)
	{
		cout<<arr[ctr-j]<<" ";
	}
	cout<<endl;
}

void display(struct node* hp)
{
	if(hp->next == NULL)
	{
		cout<<"Linked list is empty. \n";
	}
	else
	{
		int opt;
	cout<<"1)Traversal \n 2)Reversal \n Choose: ";
	cin>>opt;
	if(opt == 1)
	{
		traversal(hp);
	}
	else if(opt == 2)
	{
		int choose;
		cout<<"Reversal via: \n 1)Recursion \n 2)Array \n Choose: ";
		cin>>choose;
		if(choose == 1)
		{
			
		}
		else if(choose == 2)
		{
			revArray(hp);
		}
	}
	}
}

struct node* createHead(struct node* hp)
{
	if(hp == NULL)
	{
		struct node* temp = new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		temp->next = NULL;
		cout<<"Head created. \n";
		return temp;
	}
	else
	{
		struct node* temp = new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		temp->next = hp;
		return temp;
	}
}
struct node* createTail(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is empty. Insert head first. \n";
		createHead(hp);
	}
	else
	{
		while(true)
		{
			if(hp->next == NULL)
			{
				break;
			}
			hp = hp->next;
		}
		struct node* temp = new node;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next = NULL;
		hp->next = temp;
	}
}
struct node* deleteHead(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is empty. No head :P \n";
	}
	else if(hp->next == NULL)
	{
		delete hp;
		hp == NULL;
		return hp;
	}
	else
	{
		struct node* temp = hp->next;
		delete hp;
		return temp;	
	}
}
struct node* deleteTail(struct node* hp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is empty. No head :P \n";
	}
	else if(hp->next == NULL)
	{
		delete hp;
		hp == NULL;
		return hp;
	}
	else
	{
		while(true)
		{
			if(hp->next->next == NULL)
			{
				break;
			}
			hp = hp->next;	
		}
		struct node* temp = hp->next;
		hp->next == NULL;
		delete temp;	
	}
}
int main()
{
	int op;
	struct node* head = NULL;
	while(true)
	{
		cout<<"Choose: \n 1)Insert head \n 2)Insert tail \n 3)Delete head \n 4)Delete tail \n 5)Display \n 6)Quit \n";
		cin>>op;
		if(op == 1)
		{
			head = createHead(head);
		}
		else if(op == 2)
		{
			head = createTail(head);
		}
		else if(op == 3)
		{
			head = deleteHead(head);
		}
		else if(op == 4)
		{
			head = deleteTail(head);
		}
		else if(op == 5)
		{
			display(head);
		}
		else if(op == 6)
		{
			break;
		}
	}
	
	
	
}
