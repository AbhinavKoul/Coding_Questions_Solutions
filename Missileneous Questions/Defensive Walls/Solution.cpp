#include<iostream>
#include<vector>
#include<algorithm>
#define v vector
using namespace std;

struct eq
{
    int val;
    int low;
    int high;

    //returns true if a is greater than b and thus will sort in descending  order
    static bool compare(const eq& a,const eq& b) 
    { 
        return a.val > b.val; 
    }
    //constructor
    eq(int x,int l,int h) : val(x), low(l), high(h) {}
};
v<eq> x,y;

void areaWithoutOverlap(int x0,int y0,int x1,int y1,int area[1000][1000],int& area_val)
{
    int i,j;
    for(i = x0;i<x1;i++)
        for(j = y0;j<y1;j++)
            if(!area[i][j])
                area[i][j] = area_val+=1;

}

int maxProtectedArea(v<eq> x,v<eq> y)
{
    int area[1000][1000] = {0};
    int area_val = 0;

    int x_min_ptr, x_max_ptr;

    for(auto i : y)
    {
        //intitialize
        x_min_ptr = x.size() - 1; 
        x_max_ptr = 0;
        int y1 = i.val;
        int y0 = 0;
        //get range [x1,x2] for y1
        while ((i.low > x[x_min_ptr].val) || (x[x_min_ptr].high < y1))
        {
            x_min_ptr--;
        }
        while ((i.high < x[x_max_ptr].val ) || (x[x_max_ptr].high < y1))
        {
            x_max_ptr++;
        } 

        if(x_max_ptr < x_min_ptr)        
        {   
            int x0 = x[x_min_ptr].val; 
            int x1 = x[x_max_ptr].val;
            y0 = max(x[x_min_ptr].low,x[x_max_ptr].low);

            int y_min_ptr = y.size() - 1;
            while ((y[y_min_ptr].val < y0) || (y[y_min_ptr].low > x0) || (y[y_min_ptr].high < x1))
            {
                y_min_ptr--;
                if(y[y_min_ptr].val >= i.val)
                    break;
            }
            
            if(y[y_min_ptr].val < i.val)
            {    
                y0 = y[y_min_ptr].val;

                areaWithoutOverlap(x0,y0,x1,y1,area,area_val);
            }
            
        }
    
    }

    return area_val;

}

int main()
{
    int N;
    cin>>N;

    while (N)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        if(x1 == x2)
        {
            x.push_back(eq(x1,y1,y2));
        }

        if(y1 == y2)
        {
            y.push_back(eq(y1,x1,x2));
        }
        N--;
    }
    
    sort(x.begin(),x.end(),eq::compare);
    sort(y.begin(),y.end(),eq::compare);

    cout<<endl;
    for(auto i : x)
    {
        cout<<"eq : "<<i.val<<" low : "<<i.low<<" high : "<<i.high;
    }

    cout<<endl;
    for(auto i : y)
    {
        cout<<"eq : "<<i.val<<" low : "<<i.low<<" high : "<<i.high;
    }

    cout<<"\nArea is: "<< maxProtectedArea(x,y);

    return 0;
}