struct treeNode{
	int data;
	treeNode *left, *right;
};
/*
int getMaxHeight(treeNode *root){
	if(root == NULL)
		return 0;
	else
		return max(getHeight(root->left), getHeight(root->right))+1;
}

int getMinHeight(treeNode *root){
	if(root == NULL)
		return 0;
	else
		return min(getHeight(root->left), getHeight(root->right))+1;	
}

bool isBalanced(treeNode *root){
	if(root == NULL)
		return true;
	return ((getMaxHeight(root))-getMinHeight(root) <= 1)
}
*/
int getHeight(treeNode *node) {
	if(node == NULL){
		return 0;
	}
	return max(getHeight(node->left), getHeight(node->right)) + 1;
}

bool isBalanced(treeNode *root) {
	if(root == NULL) {
		return true;
	}
	int heightDiff = abs(getHeight(root->left) - getHeight(root->right));
	if(heightDiff > 1){
		return false;
	}
	else{
		return (isBalanced(root->left) && isBalanced(root->right));
	}
}