#include<iostream>
#include<vector>
#include<algorithm>
#include<string> // std::string, std::stoll
using namespace std;

bool compare(int& x, int& y)
{
    //stoll for string to long long
    long long int xy=stoll(to_string(x)+to_string(y));
    long long int yx=stoll(to_string(y)+to_string(x));
    return xy>=yx;
}
string largestNumber(const vector<int>& A)
{
    /*
        time : O(Nlog(N))
        Space: O(N)
    */
    string ans="";
    // copy vector A in vector B
    vector<int> B(A);
    // sort as per the condition we found
    sort(B.begin(),B.end(),compare);
    // add sorted B elements one by one to output string
    for(auto val:B)
        ans+=to_string(val);
    // If 1st char has 0 which means this is highest and thus answer can only be 0
    return (ans[0]=='0')?"0":ans;
}
// --------------------------- OFFICIAL SOLUTION ----------------

bool mycompare_editorial(string a, string b){
    string ab=a.append(b);
    string ba=b.append(a);
    return ab.compare(ba)>0?1:0;
}

string largestNumber_editorial(const vector<int> &A) {
    /*
        time : O(Nlog(N))
        Space: O(N)
    */
    // initialize another vector having same size as A but of string type
    vector<string> arr(A.size());
    // to keep count of zeroes
    int count=0;
    // transverse the riginal int vector
    for(int i=0; i<A.size(); i++){
        if(A[i]==0)
            count++;
        //convert to string and keep in a diffirent vector
        arr[i]=to_string(A[i]);
    }
    // if whole array only has 0
    if(count==A.size())
        return "0";
    sort(arr.begin(),arr.end(),mycompare_editorial);    //Nlog(N)
    
    // since vertor is sorted as per needs, thus print it in lenier fastion
    string ans=arr[0];
    for(int i=1; i<arr.size(); i++)
        ans=ans+arr[i];
    return ans;
}
// ----------------------Main ---------------------
int main()
{
    vector <int> A = {1,5,2,4,35,41,9,8,96,97,999};
    cout<< largestNumber(A);
    cout<< largestNumber_editorial(A);
    // Output : 99999796854413521
    return 0;
}