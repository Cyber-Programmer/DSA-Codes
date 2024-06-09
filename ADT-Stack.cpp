
#include <iostream>
#include <conio.h>
using namespace std;

struct Stack
{
	int top;
	int size;
	int* ptr;
};
void createStack(struct Stack* stc)
{
	cout<<"Enter the size of Stack you want to create: ";
	cin>>stc->size;
	stc->ptr=new int[stc->size];
	stc->top = -1;
	cout<<"Stack created. \n";
}
bool isEmpty(struct Stack* stc){
	if(stc->top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
}
bool isFull(struct Stack* stc){
	if(stc->top == stc->size-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void display(struct Stack* stc)
{
	if(isEmpty(stc))
	{
		cout<<"Stack is empty. Nothing to show. \n";
	}
	else{
		for(int i =0;i<=stc->top;i++)
		{
			cout<<stc->ptr[i]<<" ";
		}
		cout<<endl;	
	}
	
}
void insertion(struct Stack* stc)
{
	if(isFull(stc))
	{
		cout<<"Stack is full. \n";
	}
	else{
		stc->top = stc->top+1;
		cout<<"Enter Value to be inserted: ";
		cin>>stc->ptr[stc->top];
		display(stc);	
	}
}
int deletion(struct Stack* stc)
{
	if(isEmpty(stc))
	{
		cout<<"Stack is empty. \n";
	}
	else{
		int temp = stc->ptr[stc->top];
		stc->top = stc->top-1;	
		return temp;
	}
}
void peek(struct Stack* stc)
{
	if(isEmpty(stc))
	{
		cout<<"Stack is empty. \n";
	}
	else{
		int value;
		cout<<"Enter the value you want to peek: ";
		cin>>value;
			for(int i =0;i<=stc->top;i++)
		{
			if(stc->ptr[stc->top] == value)
			{
				cout<<value<<" found at index "<<i<<endl;
				break;
			}
		}
	}
}

int main()
{
	int opt;
	struct Stack stk;
	createStack(&stk);
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Push \n 2)Pop \n 3)Display Stack \n 4)Is Full \n 5)Is empty \n 6)Peek \n 7)Quit \n Choose: ";	
		cin>>opt;
		
		if (opt == 1)
		{
			insertion(&stk);
		}
		else if(opt == 2)
		{
			int value = deletion(&stk);
			cout<<value<<endl;
		}
		else if(opt == 3)
		{
			display(&stk);
		}
		else if(opt == 4)
		{
			if(isFull(&stk))
			{
				cout<<"Stack is full.";
			}
			else{
				cout<<"You have "<<stk.size-stk.top-1<<" spaces available for insertion. \n";
			}
		}
		else if(opt == 5)
		{
			if(isEmpty(&stk))
			{
				cout<<"Stack is empty.";
			}
			else{
				cout<<"You have occupied "<<stk.top+1<<" spaces for insertion. \n";
			}
		}
		else if(opt == 6)
		{
			peek(&stk);
		}
		else if(opt == 7)
		{
			break;
		}
	
	}

	
	
	return 0;
	
}
