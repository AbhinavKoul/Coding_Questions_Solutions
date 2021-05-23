#include<iostream>
using namespace std;
 
class Test
{
    // static char x;
    // int *ptr;
      char c,c1,c2,c3;
    int x;
  
};

// char Test :: x;

// Test a, b;
 
int main()
{
    Test t;
    cout << sizeof(t) << " ";
    cout << sizeof(Test *);
    cout << endl;
    // cout << sizeof(a) << " " << sizeof(b) << endl;
    // cout << Test::x << endl;
}