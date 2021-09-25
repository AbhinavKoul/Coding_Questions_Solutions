#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
// using namespace std;
#define v vector
using namespace std;

class naryTree {
	public:
		int value;
		bool isLocked;
		bool isLockable;
		int lockedByUserId;
		int lockedChildren;
		naryTree* parent;
		vector<naryTree*> children;

		naryTree(int val) {
			isLocked = false;
			isLockable = true;
			value = val;
			parent = NULL;
			lockedChildren = 0;
			lockedByUserId = -1;
		}

		naryTree(naryTree* parent, int val) {
			isLocked = false;
			isLockable = true;
			value = val;
			lockedChildren = 0;
			lockedByUserId = -1;
			this->parent = parent;
		}
};

bool isLocked(naryTree* node) {
	return node->isLocked;
}

bool Lock(naryTree* node, int userId) {
	if(node->isLockable == false) {
		return false;
	}

	naryTree* tempNode = node;
	bool flag = false;
	
	// check for ancestors if the
	while(tempNode != NULL) {
		if(tempNode->isLocked == true) {
			flag = true;
			break;
		}
		tempNode = tempNode->parent;
	}

	if(flag) {
		return false;
	}
	else{	
		node->isLocked = true;
		node->lockedByUserId = userId;
		tempNode = node->parent;

		while(tempNode != NULL) {
			tempNode->lockedChildren = tempNode->lockedChildren + 1;
			tempNode->isLockable = false;
			tempNode = tempNode->parent;
		}
	}
	return true;	// use bfs and make all children isLockable falsae as its ancestor is now locked!
}

bool unLock(naryTree* node, int userId) {
	if(node->isLocked == false) {
		return false;
	}

	naryTree* tempNode = node->parent;
	if(node->lockedByUserId == userId && node->lockedByUserId != -1) {
		node->isLocked = false;
		
		node->lockedByUserId = -1;
		while(tempNode != NULL) {
			tempNode->lockedChildren = tempNode->lockedChildren - 1;
			
			if(tempNode->lockedChildren == 0)
				tempNode->isLockable = true;
			
			tempNode = tempNode->parent;
		}
		return true;
	}
	
	return false;


	// node->isLocked = false;
	// node->lockedByUserId = -1;
	// while(tempNode != NULL) {
	// 	tempNode->isLockable = true;
	// 	tempNode = tempNode->parent;
	// }
	// return true;	
}

// upgrade --> use dfs and check for UID!

bool upgradeLock(naryTree* node, int userId) {
	if(node->isLockable == true) {	//no decendant is locked!
		return false;
	}	
	
	bool flag = true;
	bool doneLocking = false;
	bool doneUnlocking = false;
	int count = 0;

	queue<naryTree*> Q;

	Q.push(node);

	while(!Q.empty())
	{
		naryTree* currChild = Q.front(); Q.pop();
		if(currChild->isLocked == true) 
		{
			if(currChild->lockedByUserId == userId)
			{
				doneUnlocking = unLock(currChild, userId);
				if(doneUnlocking == false) 
				{
					flag = false;	
					break;
				}
			}
			else
			{
				flag = false;	
				break;
			}		
		}

		int childrenSize = currChild->children.size();
		for(int i=0; i<childrenSize; i++) 
		{
			Q.push(currChild->children[i]);
		}
	}
	
	if(flag) {
		doneLocking = Lock(node, userId);
	}

	if(doneLocking) return true;
	return false;
}

int main() {
	int n,c,q;
	cin>>n>>c>>q;

	vector<string> places;
	unordered_map<string, int> placeToIndex;
	unordered_map<int, naryTree*> indexToNodeMap;
	queue<naryTree*> que;

	for(int i=0; i<n; i++){
		string temp;
		cin>>temp;
		placeToIndex[temp] = i;
		places.push_back(temp);
	}

	naryTree* root = new naryTree(0);
	indexToNodeMap[0] = root;
	que.push(root);

	for(int i = 1; i < n;) {
		naryTree* currParent = que.front();
		que.pop();

		for(int j=0; j<c; j++){
			naryTree* tempNode = new naryTree(currParent, i);
			que.push(tempNode);
			currParent->children.push_back(tempNode);
			indexToNodeMap[i] = tempNode;
			i++;
		}
	}

	vector<bool> result;

	for(int i=0; i<q; i++) {
		int command, userId;
		string placeName;
		cin>>command>>placeName>>userId;

		if(command == 1) {
			int index = placeToIndex[placeName];
			naryTree* node = indexToNodeMap[index];
			bool ans = Lock(node, userId);
			result.push_back(ans);
		}
		else if(command == 2) {
			int index = placeToIndex[placeName];
			naryTree* node = indexToNodeMap[index];
			bool ans = unLock(node, userId);
			result.push_back(ans);
		}
		else if(command == 3) {
			int index = placeToIndex[placeName];
			naryTree* node = indexToNodeMap[index];
			bool ans = upgradeLock(node, userId);
			result.push_back(ans);
		}
	}

	for(int i=0; i<result.size(); i++) {
		if(result[i] == 1) cout<<"true"<<endl;
		else if(result[i] == 0) cout<<"false"<<endl;
	}

	return 0;
}