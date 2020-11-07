#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define v vector
using namespace std;

int timeToCook(v<int> time,int N)
{
    /*
    Time : O(NlogN)
    
    */
    if(N == 1)
        return time[0];
    if(N == 2)
        return max(time[0],time[1]);


    sort(time.begin(),time.end());

    int i = N-2,j = N-1;
    int count = 0;
    while (i >= 0  && j >= 0)
    {
        if(time[i] < time[j])
        {
            count += time[i];
            time[j] -= time[i];
            time[i] = 0;
            if(i<j)
                i--;
            else
                i = j - 1;
        }
        else if(time[j] < time[i])
        {
            count += time[j];
            time[i] -= time[j];
            time[j] = 0;
            if(j<i)
                j--;
            else
                j = i - 1;
        }
        else
        {
            count += time[i];
            time[i] = 0;
            time[j] = 0;
            if(i<j)
            {
                j = i - 1;
                i = j - 1;
            }
            else if(j<i)
            {
                i = j - 1;
                j = i - 1;
            }
        }
        
    }

    if(i >= 0)
        if(time[i])
            count += time[i];
    
    if(j >=0)
        if(time[j])
            count += time[j];
    
    return count;
    
}

int main()
{
    int test;
    cin>>test;

    while (test)
    {
        int N;
        cin>>N;
        v<int> time(N);
        for(int i=0;i<N;i++)
            cin>>time[i];

        cout<<timeToCook(time,N)<<endl;
        test--;
    }
    
    return 0;
}