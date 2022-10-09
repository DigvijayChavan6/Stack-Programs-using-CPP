//Conversion of Infix to Postfix expression using Stack
#include<iostream>
#define max 50
using namespace std;
class stack{
	public:
	int item[max],top;
	void create(stack*);
	void push(stack*,int);
	int pop(stack*);
};
void stack::create(stack *point){
	point->top=(-1);
}
void stack::push(stack *point,int ele){
	if(point->top==max-1){
		cout<<"\nStack Overflows....";
	}
	else{
		++point->top;
		point->item[point->top]=ele;
	}
}
int stack::pop(stack *point){
	if(point->top==-1){
		cout<<"\nSatck Underflows....";
		return 0;
	}
	else{
		return(point->item[point->top--]);
	}
}
int main(){
	int i=0,j=0;
	char infix[50],postfix[50];
	stack *p,ad,obj;
	p=&ad;
	obj.create(p);
	cout<<"\nEnter any Infix expression=";
	cin>>infix;
	while(infix[i]!='\0'){	
		if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='<'||infix[i]=='>'||infix[i]=='!'||infix[i]=='~'||infix[i]=='@'||infix[i]=='#'||infix[i]=='$'||infix[i]=='%'||infix[i]=='^'||infix[i]=='&'||infix[i]=='('){
			obj.push(p,infix[i]);
		}
		else if(infix[i]==')'){
			while(p->item[p->top]!='('){
				postfix[j]=obj.pop(p);
				j++;
			}
			obj.pop(p);
		}
		else{
			postfix[j]=infix[i];
			j++;
		}
		i++;
	}
	while(p->top!=-1){
		postfix[j]=obj.pop(p);
		j++;
	}
	postfix[j]='\0';
	cout<<"\nPostfix expression="<<postfix<<"\n\n\n\n";
	return 0;
}




