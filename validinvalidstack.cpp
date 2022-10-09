//Check entered Infix expression is Valid or Invalid using Stack
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
    int i=0,termin=0;
    char infix[50],ch;
    stack *poi,ad,obj;
    poi=&ad;
    obj.create(poi);
    cout<<"\nEnter any Infix Expression=";
    cin>>infix;
    while(infix[i]!='\0'){
        if(infix[i]=='('||infix[i]=='['||infix[i]=='{'){
            obj.push(poi,infix[i]);
        }
        else if(infix[i]==')'||infix[i]==']'||infix[i]=='}'){
            if(poi->top==-1){
                goto cut;
            }
            ch=obj.pop(poi);
            if((ch=='('&&infix[i]!=')')||(ch=='['&&infix[i]!=']')||(ch=='{'&&infix[i]!='}')){
                termin=1;
                break;
            }
        }
        i++;
    }
    if(poi->top!=-1||termin==1){
        cut:
        cout<<"\nEntered Infix expression is Invalid"<<"\n\n\n\n";
    }
    else{
        cout<<"\nEntered Infix expression is Valid"<<"\n\n\n\n";
    }
    return (0);
}