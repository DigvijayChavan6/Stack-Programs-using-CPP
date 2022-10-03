//Static implementation of stack i.e. Implementation of stack by using array
#include<iostream>
#define max 50
using namespace std;
class stack{
  public:
  	int top;
	char item[max];
  	void create(stack*);
  	void isempty(stack*);
  	void isfull(stack*);
  	void push(stack*,char);
  	char pop(stack*);
  	void display(stack*);
};
void stack::create(stack *point){
	point->top=-1;
	cout<<"\nStack is created....";
}
void stack::isempty(stack *point){
	if(point->top==-1){
	    cout<<"\nStack is empty....";
	}
	else{
	    cout<<"\nStack is Not empty....";
	}
}
void stack::isfull(stack *point){
	if(point->top==max-1){
	     cout<<"\nStack is full....";
	}
	else{
	     cout<<"\nStack is Not full....";
	}
}
void stack::push(stack *point,char chr){
	if(point->top==max-1){
	     cout<<"\nStack Overflows....";
	}
	else{
	     ++point->top;
	     point->item[point->top]=chr;
	     cout<<"\nElement is pushed....";
	}
}
char stack::pop(stack *point){
	if(point->top==-1){
	    cout<<"\nStack underflows....";
	    return 0;
	}
	else{
	    return(point->item[point->top--]);
	}
}
void stack::display(stack *point){
	int j;
	for(j=point->top;j>=0;j--){
	     cout<<"\n"<<point->item[j];
	}
}
int  main(){
	int choise;
	char ch,puselem,popelem;
	stack *p,ad,obj;
	p=&ad;
	do{
	    cout<<"\n\n1:Create\n2:Isempty\n3:Isfull\n4:Push\n5:Pop\n6:Display\n7:Exit\nEnter your choise=";
	    cin>>choise;
	    switch(choise){
	             case 1:
	             		obj.create(p);
	             		break;
	             case 2:
	             		obj.isempty(p);
	             		break;
	             case 3:
	             		obj.isfull(p);
	             		break;
	             case 4:
	                        cout<<"\nEnter element for adding into stack=";
	                        cin>>puselem;
	             		obj.push(p,puselem);
	             		break;
	             case 5:
	             		popelem=obj.pop(p);
	             		cout<<"\nPoped element="<<popelem;
	             		break;
	             case 6:
	             		obj.display(p);
	             		break;
	             case 7:
	             		exit(2);
	             		break;
	             default:
	             		cout<<"\nInvalid Choise....";
	      }
	   }while(choise!=7);
	   return 0;
}

