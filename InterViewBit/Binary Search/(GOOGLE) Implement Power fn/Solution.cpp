/*
SEEMS EASY ?
jUst jump into overflow conditions for values:

    a = 71045970;
    b = 41535484;
    c = 64735492;
    
==> world will fall apart here!

=> So what will the MASTER DO

1. long long wouldnt help still
2. need to utilize % d to keep in check that value falls under long long!

*/
#include<iostream>
#include<vector>
using namespace std;

int myPow(int x, int n, int d)
{   
    if(n==0)
        return 1;
    
    if(n==1)
    return x%d;
    
    if(n%2==0)
        return (myPow((x*x)%d,n/2,d))%d;
    
    return (x%d)*(myPow((x*x)%d,n/2,d))%d;
}

int pow(int x, int n, int d) {
    if(myPow(x,n,d)<0)
        return (myPow(x,n,d)+d)%d;
    
    return myPow(x,n,d)%d;

}
int main()
{
    int a,b,c;
    a = 71045970;
    b = 41535484;
    c = 64735492;
    cout<<"HEELO:  "<< pow(a,b,c);
}