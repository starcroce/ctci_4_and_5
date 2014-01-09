struct treeNode{
	int data;
	treeNode *left, *right;
};

bool containsTree(treeNode *node1, treeNode *node2){
	if(node2 == NULL){
		return true;
	}
	else{
		return subtree(node1, node2);
	}
}

bool subtree(treeNode *node1, treeNode *node2){
	if(node1 == NULL){
		return false; // tree1 is empty
	}
	else if(node1->data == node2->data){
		return matchTree(node1, node2);
	}
	else{
		return subtree(node1->left, node2) || subtree(node1->right, node2);
	}
}

bool matchTree(treeNode *node1, treeNode *node2){
	if(node1 == NULL && node2 == NULL){
		return true;
	}
	else if(node1 == NULL || node2 == NULL){
		return false;
	}
	else if(node1->data != node2->data){
		return false;
	}
	else{
		return matchTree(node1->left, node2) && matchTree(node1->right, node2);
	}
}