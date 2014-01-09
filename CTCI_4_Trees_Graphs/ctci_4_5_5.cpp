bool isValidBST(treeNode *root){
	return isValidBST(root, INT_MIN, INT_MAX);
}

bool isValidBST(treeNode *node, int min, int max){
	if(node == NULL){
		return true;
	}
	if(node->val > min && node->val < max && isValidBST(node->left, min, node->val) && isValidBST(node->right, node->val, max)){
		return true;
	}
	return false;
}