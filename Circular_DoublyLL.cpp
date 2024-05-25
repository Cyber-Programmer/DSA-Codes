#include<iostream>
#include<conio.h>
using namespace std;
struct CDnode
{
	int data;
	struct CDnode* next;  
	struct 	CDnode* prev;
};
void Traversal(struct CDnode* head,struct CDnode* tail)
{
	struct CDnode* hp = head;
	struct CDnode* tp = tail;
	int opt;
	if(head==NULL)
	{
		cout<<"Can't traverse Linked list is empty"<<endl;
	}
	else
	{
		cout<<"1)Traverse forward \n 2)Traverse backward \n"<<endl;
		cin>>opt;
		if(opt == 1)
		{
			cout<<"Traversing..."<<endl;
			while(head->next != hp)
			{
			cout<<head->data<<endl;
			head = head->next;
			}
			cout<<head->data<<endl;			
		}
		else if(opt == 2)
		{
			cout<<"Traversing..."<<endl;
			while(tail->prev != tp)
			{
			cout<<tail->data<<endl;
			tail = tail->prev;
			}
			cout<<tail->data<<endl;	
		}
		else
		{
			cout<<"Wrong option!!"<<endl;
		}
	}
}
struct CDnode* insert_atStart(struct CDnode* head)
{
	if(head==NULL)
	{
		head = new CDnode;
		cout<<"Enter the data: ";
		cin>>head->data;
		head->next = head;
		head->prev = head;
		return head;
	}
	else
	{
		struct CDnode* temp;
		temp = new CDnode;
		cout<<"Enter the data: ";
		cin>>temp->data;
		temp->next=head;
		temp->prev = head->prev;
		struct CDnode* tempq = head->prev;
		tempq->next = temp;
		head->prev = temp;
		return temp;
	}
}
struct CDnode* delete_head(struct CDnode* head)
{	
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else if(head->next==head){
		delete head;
		head = NULL;
		return head;
	}
	else
	{
		struct CDnode* temp = head->next;
		temp->prev = head->prev;
		head->prev->next = temp;
		delete head;
		cout<<"Head Deleted"<<endl;
		return temp;
	}
}
struct CDnode* insert_atEnd(struct CDnode* head,struct CDnode* tail)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		if(tail->next==head)
		{
			struct CDnode* temp = new CDnode;
			cout<<"Enter the data: ";
			cin>>temp->data;
			temp->prev = tail;
			temp->next= head;
			head->prev = temp;
			tail->next = temp;
			return temp;
		}
	}	
}
struct CDnode* delete_tail(struct CDnode* head,struct CDnode* tail)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else if(tail->prev==tail)
	{
		delete tail;
		tail = NULL;
		return tail;
	}
	else
	{
		struct CDnode* temp = tail->prev;
		temp->next=tail->next;
		head->prev = temp;
		delete tail;
		cout<<"Tail Deleted\n";
		return temp;
	}
}
void insert_atPosition(struct CDnode* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{	
		int index;
		cout<<"Enter node no: ";
		cin>>index;
		int counter;
		while(counter < index-1)
		{
			head=head->next;
			counter++;
		}
		struct CDnode* temp = new CDnode;
		cout<<"Enter the data: ";
		cin>>temp->data;
		struct CDnode* fnext = head->next;
		temp->next = fnext;
		head->next = temp;
		temp->prev = head;
		fnext->prev = temp;
	}
}
void delete_atPosition(struct CDnode* head)
{
	if(head==NULL)
	{
		cout<<"Linked List is empty"<<endl;
	}
	else
	{
		int index;
		cout<<"Enter the node no: ";
		cin>>index;
		int counter;
		while(counter < index-1)
		{
			head=head->next;
			counter++;
		}
		struct CDnode* todel = head->next;
		head->next = todel->next;
		struct CDnode* link = todel->next;
		link->prev = head;
		delete todel;
	}
}
void search(struct CDnode* head)
{
	int value,ind;
	cout<<"Enter the data to search: ";
	cin>>value;
	while(true)
	{
		ind++;
		if(head->data==value){
			ind--;
			cout<<value<<" found at node "<<ind<<endl;
			break;
		}
		head=head->next;
	}
}

void sort_node(struct CDnode* hp,struct CDnode* tp)
{
	if(hp == NULL)
	{
		cout<<"Linked List is empty. \n";
	}
	else
	{
	struct CDnode* reset;
	reset = hp;
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
			Traversal(reset,tp);
			break;
		}
	}
	}
	
	
}

int main()
{
	struct CDnode* head = NULL;
	struct CDnode* tail = NULL;
	int opt;
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Insert at head \n 2)Insert at tail \n 3)Insert at provided position \n 4)Delete at head \n 5)Delete at tail \n 6)Delete at provided position \n 7)Traversal \n 8)Search \n 9)Sort \n 10)Exit \n Choose: ";	
		cin>>opt;
		if(opt == 1)
		{
			if(head==NULL){
				head = insert_atStart(head);
				tail = head;
				Traversal(head,tail);
			}
			else{
				head = insert_atStart(head);
				Traversal(head,tail);
			}
		}
		else if(opt == 2)
		{
			tail = insert_atEnd(head,tail);
			Traversal(head,tail);
		}
		else if(opt == 3)
		{
			insert_atPosition(head);
			Traversal(head,tail);
		}
		else if(opt == 4)
		{
			if(head->next==head){
				head = delete_head(head);
				tail = head;
				Traversal(head,tail);
			}
			else{
				head = delete_head(head);
				Traversal(head,tail);
			}
			
		}
		else if(opt == 5)
		{
			if(tail->prev==tail){
				tail = delete_tail(head,tail);
				head = tail;
				Traversal(head,tail);
			}
			else{
				tail = delete_tail(head,tail);
				Traversal(head,tail);
			}
		}
		else if(opt == 6)
		{
			delete_atPosition(head);
			Traversal(head,tail);
		}
		else if(opt == 7)
		{
			Traversal(head,tail);
		}
		else if(opt == 8)
		{
			search(head);
		}
		else if(opt == 9)
		{
			sort_node(head,tail);
		}
		else if(opt == 10)
		{
			break;
		}
	}
	return 0;
}
