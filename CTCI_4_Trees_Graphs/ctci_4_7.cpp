// T1 has millions of nodes, T2 has hundreds of nodes
// check match, then check if sub, then check if contain
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

// check if node2 tree is subtree of node1 tree
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

// check two tree with root as node1 and node2 are the same
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
		return matchTree(node1->left, node2->left) && matchTree(node1->right, node2->right);
	}
}

// check same tree with iterative soluion
bool isSameTree(TreeNode *p, TreeNode *q) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(p);
    q2.push(q);
    while(!q1.empty() && !q2.empty()){
        TreeNode* n1 = q1.front();
        TreeNode* n2 = q2.front();
        q1.pop();
        q2.pop();
        if(n1==NULL && n2==NULL) {
            continue;
        }
        if(n1==NULL || n2==NULL) {
            return false;
        }
        if( n1->val != n2->val) {
            return false;
        }
        q1.push(n1->left);
        q1.push(n1->right);
        q2.push(n2->left);
        q2.push(n2->right);
    }
    return q1.empty() && q2.empty();
}