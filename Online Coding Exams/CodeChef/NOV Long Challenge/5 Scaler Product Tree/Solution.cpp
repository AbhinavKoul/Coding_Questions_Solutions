#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define v vector
#define um unordered_map
#define mod 4294967296
#define LS ListNode
#define endl "\n"
#define all(x)	x.begin(),x.end()
#define fileopen freopen("input.txt", "rt", stdin);
#define fileclose freopen("output.txt", "wt", stdout);
#define Fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hash visited.max_load_factor(0.25);visited.reserve(512)
using namespace std;

v<int> weights = {0,5,4,3,2,1};

struct ListNode 
{
   int val;
   ListNode *next;     
   ListNode(int x) : val(weights[x]), next(nullptr) {}

};
LS *head = nullptr,*ptr = nullptr;

long long int scalerDotProduct(int q1,int q2,const v<LS*>& adjList)
{
    LS* top1 = adjList[q1];
    LS* top2 = adjList[q2];

    long long int result = 0;

    while (top1!=nullptr && top2!=nullptr)
    {
        long long int singleDotProduct = 1;
        singleDotProduct = ((singleDotProduct%mod) * (top1->val%mod) *(top2->val%mod))%mod;

        result = ((result%mod) + singleDotProduct);
        top1 = top1->next;
        top2 = top2->next;
    }
    
    return result;
}

void addEdge(signed int src,signed int dest,v<LS*>& adjList)
{

    if(adjList[src]!=nullptr)
    {
        ptr = new LS(dest);
        ptr->next = adjList[src];
        adjList[dest] = ptr;
    }
    else
    {
        LS* ptr1 = new LS(src),*ptr2 = new LS(dest);
        ptr2->next = adjList[src] = ptr1;
        adjList[dest] = ptr2;

    }
    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int N = 5;
    // v<LS*> adjList(N+1,nullptr);
    // head = ptr = new LS(0);
    // // add 1 before 0
    // ptr = new LS(1);
    // ptr->next = head;
    // adjList[1] = head = ptr;

    // v<pair<int,int>> arr= {
    //     {1,2},
    //     {1,3},
    //     {2,4},
    //     {2,5},
    // };

    // for(auto i : arr)
    // {
    //     int src = i.first;
    //     int dest = i.second;

    //     if(adjList[src]!=nullptr)
    //     {
    //         ptr = new LS(dest);
    //         ptr->next = adjList[src];
    //         adjList[dest] = ptr;
    //     }
    // }

    // cout<<"HELLO :   "<<scalerDotProduct(4,5,adjList);

    int N,Q;
    cin>>N>>Q;
    v<signed int> weights(N+1);
    for(signed int i = 1; i <= N; i++)
        cin>>weights[i];

    v<LS*> adjList(N+1,nullptr);
    head = ptr = new LS(0);
    // add 1 before 0
    ptr = new LS(1);
    ptr->next = head;
    adjList[1] = head = ptr;

    int edges = N-1;
    while (edges)
    {
        signed int src,dest;
        cin>>src>>dest;
        addEdge(src,dest,adjList);

        edges--;
    }
    
    while (Q)
    {
        signed int q1,q2;
        cin>>q1>>q2;
        cout<<scalerDotProduct(q1,q2,adjList)<<endl;

        Q--;
    }
    
    return 0;
}