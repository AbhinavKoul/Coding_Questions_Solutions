#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

template<typename K, typename V>
void print_map(std::unordered_map<K,V> const &m)
{
	for (auto const& pair: m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}

//function to print the queue
void printQueue(queue<int> q)
{
	//printing content of queue 
	while (!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
	cout<<endl;
}

template<typename K>
void printVector(vector<K> arr)
{
    cout<<endl;
    for(auto i : arr)
        cout<<i<<" ";
}