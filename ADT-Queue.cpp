
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

struct Queue
{
	int fp;
	int rp;
	int size;
	int* ptr;
};
void createQueue(struct Queue* q)
{
	cout<<"Enter the size of Queue you want to create: ";
	cin>>q->size;
	q->ptr = new int[q->size];
	q->fp = -1;
	q->rp = -1;
}
bool isEmpty(struct Queue* q){
	if(q->fp == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
}
bool isFull(struct Queue* q){
	if((q->rp + 1)%q->size== q->fp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void display(struct Queue* q)
{
	if(isEmpty(q))
	{
		cout<<"Queue is empty. Nothing to show. \n";
	}
	else{
		int i = q->fp;
    	while(true)
    	{
    	if(i == q->rp)
    	{
    		cout << q->ptr[i] << " ";
    		break;
		}
		cout << q->ptr[i] << " ";
		i = (i + 1) % q->size;
		}
    cout << endl;
	}
}
int enqueue(struct Queue* q, int counter)
{
	int ctr = counter;
	if(isFull(q))
	{
		cout<<"Queue is full. \n";
	}
	else{
		if(q->fp == -1)
		{
			q->fp = 0;
			q->rp = 0;
		}
		else
		{
			q->rp = (q->rp +1)%q->size;	
		}
		int value;
	    cout<<"Enter the value: ";
	    cin>>value;
	    q->ptr[q->rp] = value;
	    cout << value << " Enqueued!" << endl;
	    ctr++;
	    return ctr;
	}
}
int dequeue(struct Queue* q,int counter)
{
	int ctr = counter;
	if(isEmpty(q))
	{
		cout<<"Queue is empty. \n";
	}
	else{
		int temp = q->ptr[q->fp];

    if (q->fp == q->rp) {  
        q->fp = q->rp = -1;
    } else {
        q->fp = (q->fp + 1) % q->size;
    }
    cout<<temp<<" has been dequeued . \n";
	}
	ctr--;
	return ctr;
}

 peek(struct Queue* q)
{
	if(isEmpty(q))
	{
		cout<<"Stack is empty. \n";
	}
	else{
		int index;
        cout << "Enter the index you want to peek at: ";
        cin >> index;
        if (index >= q->fp && index <= q->rp) {
            cout << q->ptr[index] << endl;
        } else {
            cout << "Invalid index" << endl;
        }
	}
}
void FirstElement(struct Queue* q) {
    if (!isEmpty(q)) {
        cout << "The First in the line is " << q->ptr[q->fp] << endl;
    }
    else{
    	return;
	}
}

void LastElement(struct Queue* q) {
    if (!isEmpty(q)) {
        int last_index = (q->rp + q->size) % q->size;
        cout << "The Last in the line is " << q->ptr[last_index] << endl;
    } else {
        return;
    }
}


int main()
{
	int cotr = 0;
	int opt;
	struct Queue Q;
	createQueue(&Q);
	while(true)
	{
		cout<<"Choose What You Want To Do: \n 1)Enqueue \n 2)Dequeue \n 3)Display Queue \n 4)Is Full \n 5)Is empty \n 6)Peek \n 7)View First Element \n 8)View Last Element \n 9)Quit \n Choose: ";	
		cin>>opt;
		
		if (opt == 1)
		{
			cotr = enqueue(&Q,cotr);
		}
		else if(opt == 2)
		{
			cotr = dequeue(&Q,cotr);

		}
		else if(opt == 3)
		{
			display(&Q);
		}
		else if(opt == 4)
		{
			if(isFull(&Q))
			{
				cout<<"Queue is full.";
			}
			else{
				cout<<"You have "<<Q.size-abs(cotr)<<" spaces available for insertion. \n";
			}
		}
		else if(opt == 5)
		{
			if(isEmpty(&Q))
			{
				cout<<"Stack is empty.";
			}
			else{
				cout<<"You have occupied "<<Q.rp+1-Q.fp<<" spaces for insertion. \n";
			}
		}
		else if(opt == 6)
		{
			peek(&Q);
		}
		else if(opt == 7)
		{
			FirstElement(&Q);
		}
		else if(opt == 8)
		{
			LastElement(&Q);
		}
		else if(opt == 9)
		{
			break;
		}
	
	}

	
	
	return 0;
	
}
