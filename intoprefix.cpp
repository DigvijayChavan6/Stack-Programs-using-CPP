//Conversion of Infix to Prefix expression using Stack
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
    int i=0,j=0,k=0;
	char ch,reverse[50],infix[50],prefix[50];
    stack *rev,*oprand,*operater,ad1,ad2,ad3,obj;
    oprand=&ad1;
    operater=&ad2;
	rev=&ad3;
    obj.create(oprand);
    obj.create(operater);
	obj.create(rev);
    cout<<"\nEnter any Prefix Expression=";
    cin>>infix;
    while(infix[k]!='\0'){
		obj.push(rev,infix[k]);
		k++;
	}
	while(rev->top!=-1){
		reverse[i]=obj.pop(rev);
		i++;
	}
	reverse[i]='\0';
	i=0;
    while(infix[i]!='\0'){
        if(reverse[i]==')'||reverse[i]=='~'||reverse[i]=='!'||reverse[i]=='@'||reverse[i]=='#'||reverse[i]=='$'||reverse[i]=='%'||reverse[i]=='^'||reverse[i]=='&'||reverse[i]=='&'||reverse[i]=='*'||reverse[i]=='/'||reverse[i]=='-'||reverse[i]=='+'||reverse[i]=='>'||reverse[i]=='<'||reverse[i]=='?'){
            obj.push(operater,reverse[i]);
        }
        else if(reverse[i]=='('){
			while(operater->top!=-1){
				ch=obj.pop(operater);
				if(ch!=')'){
					obj.push(oprand,ch);
				}
			}
		}
		else{
			obj.push(oprand,reverse[i]);
		}
		i++;
	}
	while(operater->top!=-1){
		ch=obj.pop(operater);
		if(ch!=')'){
			obj.push(oprand,ch);
		}
	}
	while(oprand->top!=-1){
		prefix[j]=obj.pop(oprand);
		j++;
	}
	prefix[j]='\0';
	cout<<"\nPrefix Expression="<<prefix<<"\n\n\n\n";
    return 0;
}    
