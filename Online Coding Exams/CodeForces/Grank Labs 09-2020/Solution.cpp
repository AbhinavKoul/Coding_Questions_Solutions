#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Location
{
    int x;
    int y;
};

int main()
{
    int n,m;
    // cin>>n>>m;
    n = 2;
    m = 3;
    vector<Location> robber = {{1,6},{6,1}};
    vector<Location> search = {{10,1},{1,10},{7,7}};

    // for(int i = 0;i<n;i++)
    //     cin>>robber[i].x>>robber[i].y;

    // for(int i = 0;i<m;i++)
    //     cin>>search[i].x>>search[i].y;
    

    int steps = 0;
    for(int i =0;i<n;i++)
    {
        int max_x = -1,max_y = -1;
        for(int j=0;j<m;j++)
        {
            if((robber[i].x <= search[j].x) &&(robber[i].y <= search[j].y))
            {
                if(search[j].x > max_x)
                    max_x = search[j].x;
                if(search[j].y > max_y)
                    max_y = search[j].y;
            }
        }
        
        int x_shift = max_x - robber[i].x;
        int y_shift = max_y - robber[i].y;
        
        steps += (min(x_shift,y_shift) + 1);
    }
    return 0;
}