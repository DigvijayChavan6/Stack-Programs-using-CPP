//Evaluation of Postficx expression(Finding value of postfix expression)
#include<iostream>
#define max 50
using namespace std;
class  stack{
    public:
    int item[max],top;
    void create(stack*);
    void push(stack*,int);
    int pop(stack*);
};
void stack::create(stack *p){
    p->top=-1;
}
void stack::push(stack *p,int x){
    if(p->top==max-1){
        cout<<"\nStack Overflows....";
    }
    else{
        ++p->top;
        p->item[p->top]=x;
    }
}
int stack::pop(stack *p){
    if(p->top==-1){
        cout<<"\nStack Underflows....";
        return(0);
    }
    else{
        return(p->item[p->top--]);
    }
}
int main(){
    int i=0;
    float val,op1,op2;
    char postfix[50];
    stack *poi,ad,obj;
    poi=&ad;
    obj.create(poi);
    cout<<"\nEnter any Postfix Expression=";
    cin>>postfix;
    while(postfix[i]!='\0'){
        if(postfix[i]=='+'||postfix[i]=='*'||postfix[i]=='-'||postfix[i]=='/'){
            op2=obj.pop(poi);
            op1=obj.pop(poi);
            switch(postfix[i]){
                case '+':
                    val=op1+op2;
                    break;
                 case '-':
                    val=op1-op2;
                    break;
                 case '*':
                    val=op1*op2;
                    break;
                 case '/':
                    val=op1/op2;
                    break;
            } 
            obj.push(poi,val);
        }
        else{
            obj.push(poi,postfix[i]-48);
        }
        i++;
    }
    val=obj.pop(poi);
    cout<<"\nValue of enterd Postfix expression="<<val<<"\n\n\n\n\n";
    return 0;
}