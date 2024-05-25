
#include <iostream>
#include <conio.h>
#include <string>
#include<stack>

using  namespace std;

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
	{
	
	}
	else{stc->top = stc->top+1;
		stc->ptr[stc->top] = chr;}
}
char pop(struct Stack* stc){
	if(isEmpty(stc))
	{
	
	}
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

int getpreced(struct Stack* exp)
{
	char data;
	int weight;
	data = pop(exp);
	if(data=='+' || data == '-'){
		weight = 1;
	}
	else if(data=='*' || data == '/'){
		weight = 2;
	}
	else if(data=='(' || data=='{' || data=='['){
		weight = 3;
	}
	push(exp,data);
	return weight;
}
int evaluation(string s){

	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch(s[i]){
				case'+':
					st.push(op1+op2);
					break;	
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case'/':
					if (op2 == 0)
					{
						cout<<"Zero Division Not Possible";
						break;
					}
					else if(op1 == 0)
					{
						st.push(0);
					}
					else{
						st.push(op1/op2);
					break;
					}
					
			}
		}
	}
	return st.top();
}

string postfix_maker(string str)
{
	int wt = 0;
	char temp;
	struct Stack stk;
	createStack(&stk,str.length());
	int len = str.length();
	char arr[len]; 
	int ctr = 0;
	for(int i = 0;i<len;i++)
	{
		if(isEmpty(&stk))
		{
			if(str[i] == '(' || '{' || '[' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				push(&stk,str[i]);
			}
			else{
				arr[ctr] = str[i];
				ctr++;
			}	
		}
		else if(!isEmpty(&stk))
		{
			if(str[i] == '(' || str[i]=='{' || str[i]=='[')
		{
			push(&stk,str[i]);
		}
		else if(str[i] == '+' || str[i] == '-')
		{
			wt = getpreced(&stk);
			if(wt==3){
				push(&stk,str[i]);
			} 
			else{
				while(!isEmpty(&stk)){
					temp = pop(&stk);
					if(temp!= '(' && temp!='{' && temp!='['){
						arr[ctr] = temp;
						ctr++;
					}
				}
				push(&stk,str[i]);
			}
		}
		else if(str[i] == '*' || str[i] == '/')
		{
			wt = getpreced(&stk); 
			if(wt==2){
				temp = pop(&stk);
				arr[ctr] = str[i];
				ctr++;
				push(&stk,str[i]);
			}
			else{
				push(&stk,str[i]);
			}
		}
		else if(str[i] == ')')
		{
			do{
				temp = pop(&stk);
				if(temp!='(')
				{
					arr[ctr] = temp;
					ctr++;
				}
			}while(temp!='(' && !isEmpty(&stk));	
		}
		else if(str[i]=='}'){
			do{
				temp = pop(&stk);
				if(temp!='{'){
					arr[ctr]=temp;
					ctr++;
				}
			}
			while(temp!='{' && !isEmpty(&stk));
		}
		else if(str[i]==']'){
			do{
				temp = pop(&stk);
				if(temp!='['){
					arr[ctr]=temp;
					ctr++;
				}
			}
			while(temp!='[' && !isEmpty(&stk));
		}	
		else
		{
			arr[ctr] = str[i];
			ctr++;		
		}
		
	}
	
}
while(!isEmpty(&stk))
{
	temp = pop(&stk);
	arr[ctr] = temp;
	ctr++;
}
string s = "";
for(int k = 0; k<ctr;k++)
	{
		cout<<arr[k]<<"";
		s+=arr[k];
	}
	cout<<endl;
	return s;
}
void SequenceDetector(string str){
	int bar = 0;
	int curly = 0;
	int Round = 0;
	string es;
	for(int i = 0;i<str.length();i++){
		if(bar==0 && curly==0 && Round==0 && str[i]=='['){
			bar++;
		}
		else if(bar==0 && curly==0 && Round==0 && str[i]=='{'){
			curly++;
		}
		else if(bar==1 && curly>=0 && Round==0 && str[i]=='{'){
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
//		else if(isdigit(str[i])){
//			
//		}
//		else
//		{
//				cout<<"Math Error Occured!"<<endl;
//			cout<<"Brackets aren't in sequence."<<endl;
//			break;
//		}
	}
	if(bar == 0 && curly == 0 && Round == 0)
	{
		cout<<"Brackets are Mathematically Correct. \n";
		es = postfix_maker(str);
		cout<<"Result: ";
		cout<<evaluation(es)<<endl;
	}
	else{
			cout<<"Math Error Occured!"<<endl;
			cout<<"Brackets aren't in sequence."<<endl;
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
{	
	
	cout<<"---------Expression Evaluator---------\n";
	string es;
	while(true)
	{string str;
	int choose;
	cout<<"What do you want to do: \n1)Infix to Postfix\n2)Postfix Evaluation\n3)Exit\nChoose: ";
	cin>>choose;
	if(choose == 1)
	{
		cout<<"\nEnter Expression: ";
	cin>>str;
	int opt;
	cout<<"With Brackets or Without?:1/2 ";
	cin>>opt;
	if(opt == 1)
	{
		int length = getLength(str);
	if(length != 0)
	{	BracketChecker(str,length);
	}
	else{cout<<"Missing brackets. Can't Evaluate. \n";}
	}
	else if(opt == 2)
	{
		es = postfix_maker(str);
		cout<<"Result: ";
		cout<<evaluation(es)<<endl;
	}
	}
	else if(choose == 2)
	{
		cout<<"\nEnter Expression: ";
	    cin>>str;
		cout<<"Result: ";
		cout<<evaluation(str)<<endl;
	}
	else if(choose == 3)
	{
		break;
	}
	else
	{
		cout<<"Enter Valid Option.\n";
	}
	
	}
}
