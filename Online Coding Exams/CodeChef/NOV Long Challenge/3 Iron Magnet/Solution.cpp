#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
using namespace std;

int k;
int power(int i,int j,int S)
{
    return (k+1-abs(j-i)-S);
}

int minMagnets(const string& arr,int low,int high)
{
    queue<int> mag,iron;
    um<int,int> wall;
    int wall_count = 0;
    int res = 0;
        

    for(int i = low;i<high;i++)
    {
        if(arr[i] == 'I')
            iron.push(i);
        else if (arr[i] == 'M')
            mag.push(i);
        else if(arr[i] == ':')
        {
            wall_count++;
            wall[i] = wall_count;
        }
        else if(arr[i] == 'X')
        {
            res += minMagnets(arr,i+1,high);
            break;
        }
        
        wall[i] = wall_count; 
    }

    while (!mag.empty() && !iron.empty())
    {
        if(mag.front() < iron.front())
        {
            if(power(mag.front(),iron.front(),abs(wall[mag.front()] - wall[iron.front()])) > 0)
            {
                res++;
                iron.pop();
            }
            mag.pop();
        }
        else
        {
            if(power(mag.front(),iron.front(),abs(wall[mag.front()] - wall[iron.front()])) > 0)
            {
                res++;
                mag.pop();
            }
            iron.pop();
        }
    }          
    return res;
}

int main()
{

    int test;
    cin>>test;

    while(test)
    {
        int N;
        cin>>N>>k;

        string arr;
        cin>>arr;

        cout<<minMagnets(arr,0,N)<<endl;
        test--;
    }
    
    return 0;
}