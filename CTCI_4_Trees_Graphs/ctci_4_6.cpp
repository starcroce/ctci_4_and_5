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
	if(isParent(root->left, node1) != isParent(root->left, node2)){
		return root;
	}
	// if both in the left side
	else if(isParent(root->left, node1)) {
		return firstCommonAncestor(node1, node2, root->left);
	}
	// if both in the right side
	else {
		return firstCommonAncestor(node1, node2, root->right);
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

// non-recursive solution, can get the path
bool getNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path) {
	if(root == node) {
		path.push_back(root);
		return true;
	}
	if(root == NULL) {
		return false;
	}
	path.push_back(root);
	bool find = false;
	find = getNodePath(root->left, node, path);
	if(find == false) {
		find = getNodePath(root->right, node, path);
	}
	if(find == false) {
		path.pop_back();
	}
	return find;
}

TreeNode *getFirstCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2) {
	if(root == NULL) {
		return NULL;
	}
	if(node1 == NULL) {
		return node2;
	}
	if(node2 == NULL) {
		return node1;
	}
	vector<TreeNode *> path1;
	vector<TreeNode *> path2;
	bool result1 = getFirstCommonAncestor(root, node1, path1);
	bool result2 = getFirstCommonAncestor(root, node2, path2);
	if(result1 == false || result2 == false) {
		return NULL;
	}
	TreeNode *res = NULL;
	int i = 0;
	while(path1[i] == path2[i]) {
		res = path1[i];
		i++;
	}
	return res;
	// distance is path1.size() + path2.size() - 2*i
}