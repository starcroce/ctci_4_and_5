struct treeNode{
	int data;
	treeNode *left, *right, *parent;
};

// is node1 is the parent of node2?
bool isParent(treeNode *node1, treeNode *node2){
	if(node1 == NULL){
		return false;
	}
	else if(node1 == node2){
		return true;
	}
	else{
		bool ans = isParent(node1->left, n2) || isParent(node1->right, node2);
		return ans;
	}
}

// with link to parent
treeNode* firstCommonAncestor(treeNode *node1, treeNode *node2){
	if(node1 == NULL || node2 == NULL){
		return NULL;
	}
	while(node1){
		if(isParent(node1, node2)){
			return node1;
		}
		node1 = node1->parent;
	}
}

// without link to parent
treeNode* firstCommonAncestor(treeNode *node1, treeNode *node2, treeNode *root) {
	if(root == NULL){
		return NULL;
	}
	if(root == node1 || root == node2) {	
		return root;
	}
	// if in the different side
	if(isParent(root.left, node1) != isParent(root.left, node2)){
		return root;
	}
	// if both in the left side
	else if(isParent(root.left, node1)) {
		return firstCommonAncestor(node1, node2, root.left);
	}
	// if both in the right side
	else {
		return firstCommonAncestor(node1, node2, root.right);
	}
}

// if it is a BST
treeNode* firstCommonAncestor(treeNode *root, treeNode *node1, treeNode *node2) {
	if(root == NULL) {
		return NULL;
	}
	if(root == node1 || root == node2) {
		return root;
	}
	treeNode *tmp = root;
	while(tmp != NULL) {
		if(node1->data > tmp->data && node2->data > tmp->data) {
			tmp	= tmp->right;
		}
		if(node1->data < tmp->data && node2->data < tmp->data) {
			tmp = tmp->left;
		}
		else{
			break;
		}
	}
	return tmp;
}