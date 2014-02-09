struct treeNode{
	int data;
	treeNode *left, *right, *parent;
};

// find the minimal child of the given node
treeNode* findMinimalNode(treeNode *node){
	if(node == NULL){
		return NULL;
	}
	while(node->left){
		node = node->left;
	}
	return node;
}

/* 
 * if X has a right child, the successor must be on the right side of X
 * else we go to X's parent called P
 * if P.left = X, P is the successor of X
 * else we call P
 */
treeNode* inOrderSuccessor(treeNode *node){
	if(node == NULL){
		return NULL;
	}
	if(node->right){
		return findMinimalNode(node->right);
	}
	treeNode *pn = node->parent;
	// till the parent is the left child of the parent's parent
	while(pn && pn->right == node){
		node = pn;
		pn = pn->parent;
	}
	return pn;
}