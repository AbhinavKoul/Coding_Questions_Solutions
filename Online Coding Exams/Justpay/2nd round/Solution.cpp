#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<queue>
// using namespace std;
#define v vector
using namespace std;

class Tree {
	public:
		int value;
		bool isLocked;
		bool isLockable;
		int lockedByUserId;
		int lockedChildren;
		Tree* parent;
		vector<Tree*> children;

		Tree(int val) {
			isLocked = false;
			isLockable = true;
			value = val;
			parent = NULL;
			lockedChildren = 0;
			lockedByUserId = -1;
		}

		Tree(Tree* parent, int val) {
			isLocked = false;
			isLockable = true;
			value = val;
			lockedChildren = 0;
			lockedByUserId = -1;
			this->parent = parent;
		}
};

bool isLocked(Tree* node) {
	return node->isLocked;
}

bool Lock(Tree* node, int userId) {
	if(node->isLockable == false) {
		return false;
	}

	Tree* tempNode = node;
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

bool unLock(Tree* node, int userId) {
	if(node->isLocked == false) {
		return false;
	}

	Tree* tempNode = node->parent;
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
}

// upgrade --> use dfs and check for UID!

bool upgradeLock(Tree* node, int userId) {
	if(node->isLockable == true) {	//no decendant is locked!
		return false;
	}	
	
	bool flag = true;
	bool doneLocking = false;
	bool doneUnlocking = false;
	int count = 0;

	queue<Tree*> Q;

	Q.push(node);
	v<Tree*> unlockCandidates;
	while(!Q.empty())
	{
		Tree* currChild = Q.front(); Q.pop();
		if(currChild->isLocked == true) 
		{
			if(currChild->lockedByUserId == userId)
			{
				unlockCandidates.push_back(currChild);
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

	if(flag)
	{
		for(auto cur : unlockCandidates)
		{
			doneUnlocking = unLock(cur, userId);
			if(doneUnlocking == false) 
			{
				flag = false;	
				break;
			}
		}

		doneLocking = Lock(node, userId);
	}
	
	
	// if(flag) {
		
	// }

	if(doneLocking) return true;
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	unsigned int n,c,q;
	cin>>n>>c>>q;

	v<string> places;
	unordered_map<string, int> placeIndexMapping;
	unordered_map<int, Tree*> indexNodeMapping;
	queue<Tree*> Q;

	for(int i=0; i<n; i++)
	{
		string temp;
		cin>>temp;

		placeIndexMapping[temp] = i;
		places.push_back(temp);
	}

	Tree* root = new Tree(0);
	indexNodeMapping[0] = root;
	Q.push(root);

	for(int i = 1; i < n;) 
	{
		Tree* currParent = Q.front();
		Q.pop();

		for(int j=0; j<c; j++){
			Tree* tempNode = new Tree(currParent, i);
			Q.push(tempNode);
			currParent->children.push_back(tempNode);
			indexNodeMapping[i] = tempNode;
			i++;
		}
	}

	vector<bool> result;

	for(int i=0; i<q; i++) {
		int command, userId;
		string placeName;
		cin>>command>>placeName>>userId;

		if(command == 1) {
			int index = placeIndexMapping[placeName];
			Tree* node = indexNodeMapping[index];
			bool ans = Lock(node, userId);
			result.push_back(ans);
		}
		else if(command == 2) {
			int index = placeIndexMapping[placeName];
			Tree* node = indexNodeMapping[index];
			bool ans = unLock(node, userId);
			result.push_back(ans);
		}
		else if(command == 3) {
			int index = placeIndexMapping[placeName];
			Tree* node = indexNodeMapping[index];
			bool ans = upgradeLock(node, userId);
			result.push_back(ans);
		}
	}

	for(int i=0; i<result.size(); i++) {
		if(result[i] == 1) cout<<"true\n";
		else if(result[i] == 0) cout<<"false\n";
	}

	return 0;
}