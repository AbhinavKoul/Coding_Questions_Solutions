#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#define map unordered_map
using namespace std;

int romanToInteger(string roman)
{
    map<char,int> converter = {
                        {'I',1},
                        {'V',5},
                        {'X',10},
                        {'L',50},
                        {'C',100},
                        {'D',500},
                        {'M',1000}
    };
    // converter['I'] = 1;
    // converter['V'] = 5;
    // converter['X'] = 10;
    // converter['L'] = 50;
    // converter['C'] = 100;
    // converter['D'] = 500;
    // converter['M'] = 1000;
    
    int result = 0;
    int n = roman.size() - 1;
    for(int i = n; i>=0 ;i--)
    {
        char character = roman[i];
        if(i == n)
            result += converter[character];

        else
        {
            if(converter[character] < converter[roman[i+1]])
                result -= converter[character];
            else
                result += converter[character];
        }
    }

    return result;

}
int main()
{

    cout<<"hello world :  "<<romanToInteger("MMMCMXCIX");
    return 0;
}