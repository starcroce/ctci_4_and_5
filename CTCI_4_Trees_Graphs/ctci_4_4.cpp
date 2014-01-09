struct treeNode{
	int data;
	treeNode *left, *right;
};

vector<list<treeNode*>> findLevelLinkedLists(treeNode *root){
	vector<list<treeNode*>> allLinkedLists;
	int level = 0;
	list<treeNode*> rootLinkedList;
	rootLinkedList.push_back(root);
	allLinkedLists.push_back(rootLinkedList);
	while(!allLinkedLists[level].empty()){
		list<treeNode*> levelLinkedList;
		for(list<treeNode*>::iterator it, it = allLinkedLists[level].begin(); it != allLinkedLists[level].end(); it++){
			treeNode *node = *it;
			if(node->left){
				levelLinkedList.push_back(node->left);
			}
			if(node->right){
				levelLinkedList.push_back(node->right);
			}
			level++;
			allLinkedLists.push_back(levelLinkedList);
		}
	}
	return allLinkedLists;
}

int findNodeLevel(treeNode *root, treeNode *dst) {
	if(root == dst){
		return 1;
	}
	int level = 1;
	queue<treeNode*> q;
	q.push(root);
	while(!q.empty()) {
		treeNode *tmp = q.front();
		q.pop();
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
		level++;
		if(tmp->left == dst || tmp->right == dst) {
			return level;
		}
	}
	return -1;
}