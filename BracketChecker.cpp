#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct Stack
{
	int top;
	int size;
	char* ptr;
};
void createStack(struct Stack* stc,int size){
	stc->size = size;
	stc->ptr=new char[stc->size];
	stc->top = -1;
}
bool isEmpty(struct Stack* stc){
	if(stc->top == -1)
	{return true;}
	else{return false;}
}
bool isFull(struct Stack* stc){
	if(stc->top == stc->size-1)
	{return true;}
	else{return false;}
}
void push(struct Stack* stc,char chr){
	if(isFull(stc))
	{cout<<"Stack is full. \n";}
	else{stc->top = stc->top+1;
		stc->ptr[stc->top] = chr;}
}
char pop(struct Stack* stc){
	if(isEmpty(stc))
	{cout<<"Stack is empty. \n";}
	else{int temp = stc->ptr[stc->top];
		stc->top = stc->top-1;	
		return temp;}
}
int getLength(string str){
	int len1=0;
	int len2=0;
	for(int i = 0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
		{len1++;}
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{len2++;}
	}
	if(len1==len2)
	{return len1;}
	else{return 0;}
}
void SequenceDetector(string str){
	int bar = 0;
	int curly = 0;
	int Round = 0;
	for(int i = 0;i<str.length();i++){
		if(bar==0 && curly==0 && Round==0 && str[i]=='['){
			bar++;
		}
		else if(bar==0 && curly==0 && Round==0 && str[i]=='{'){
			curly++;
		}
		else if(bar==1 && curly==0 && Round==0 && str[i]=='{'){
			curly++;
		}
		else if(bar==0 && curly==0 && Round>=0 && str[i]=='('){
			Round++;
		}
		else if(bar==1 && curly==1 && Round>=0 && str[i]=='('){
			Round++;
		}
		else if(bar==0 && curly==1 && Round>=0 && str[i]=='('){
			Round++;
		}
		else if(str[i]==']'){
			bar--;
		}
		else if(str[i]==')'){
			Round--;
		}
		else if(str[i]=='}'){
			curly--;
		}
		else{
			cout<<"Math Error Occured!"<<endl;
			cout<<"Brackets aren't in sequence."<<endl;
			break;
		}
	}
}

void BracketChecker(string str,int size){
	struct Stack stc;
	createStack(&stc,size);	
	int i;
	int index;
	int check = 0;
	for(i = 0;i<str.length();i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '['){
			push(&stc,str[i]);
			check++;}
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(check!=0)
			{
			char chr = pop(&stc);	
			if((chr == '(' && str[i] == ')') || (chr == '{' && str[i] == '}') || (chr == '[' && str[i] == ']'))
			{check--;}
			else{cout<<"Misplaced Brackets. \n";
				cout<<str[i]<<" is at wrong position at index "<<i<<endl;
				return;}
			}				
		}	
	}
	if(check == 0)
	{
	cout<<"Perfectly Balanced Brackets. \n";
	SequenceDetector(str);
	}
	else
	{
	cout<<"Mismatched Brackets. \n";
	}	
}


int main()
{	while(true)
	{string str;
	cout<<"Enter String: ";
	cin>>str;
	int length = getLength(str);
	if(length != 0)
	{BracketChecker(str,length);}
	else{cout<<"Missing brackets. \n";}
	}
}
