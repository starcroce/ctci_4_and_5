struct treeNode{
	int data;
	treeNode *left, *right, *parent;
};

void printPath(treeNode *dst, int level){
	vector<int> vNode;
	for(int i=0; i<level; i++){
		vNode.push_back(dst->data);
		dst = dst->parent;
	}
	while(!vNode.empty()){
		cout<<vNode.back()<<"-";
		vNode.pop_back();
	}
	cout<<endl;
}

// rather than asking "does this node start a path with the sum", we ask "does this node complete a path with the sum?"
void findSum(treeNode *node, int sum){
	if(node == NULL){
		return;
	}
	treeNode *n = node;
	int tmp = 0;
	for(int i=0; n != NULL; i++){
		tmp += n->data;
		if(tmp == sum){
			printPath(head, i);
		}
		n = n->parent;
	}
	findSum(node->left, sum);
	findSum(node->right, sum);
}