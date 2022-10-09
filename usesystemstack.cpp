//Application of stack,system stack used for recursion(Subroutine call)
#include<iostream>
using namespace std;
int fact(int);
int fact(int num){
    if(num==1||num==0){
        return(1);
    } 
    else{
    return(num*fact(num-1));
    }
}
int main(){
    int n,factorial;
    cout<<"\nEnter any number for finding factorial=";
    cin>>n;
    factorial=fact(n);
    cout<<"\nFactorial of entered number="<<factorial<<"\n\n\n\n";
    return 0;
}