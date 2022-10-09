//Reverse the inputed String using Stack
#include<iostream>
#define max 50
using namespace std;
class stack{
    public:
    int top,item[max];
    void create(stack*);
    void push(stack*,int);
    int pop(stack*);
};
void stack::create(stack *p){
    p->top=-1;
}
void stack::push(stack *p,int chr){
    if(p->top==max-1){
        cout<<"\nStack Overflows....";
    }
    else{
        ++p->top;
        p->item[p->top]=chr;
    }
}
int stack::pop(stack *p){
    if(p->top==-1){
        cout<<"\nStack Underflows....";
        return 0;
    }
    else{
        return(p->item[p->top--]);
    }
}
int main(){
    int i=0,j=0;
    char str[50],rev[50];
    stack *point,ad,obj;
    point=&ad;
    obj.create(point);
    cout<<"\nEnter any String=";
    cin>>str;
    while(str[i]!='\0'){
        obj.push(point,str[i]);
        i++;
    }
    while(point->top!=-1){
        rev[j]=obj.pop(point);
        j++;
    }
    rev[j]='\0';
    cout<<"\nReverse String="<<rev<<"\n\n\n\n";
    return 0;
}