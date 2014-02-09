struct treeNode{
	int data;
	treeNode *left, *right;
};

// same to leetcode
treeNode addToTree(int array[], int startIndex, int endIndex){
	if(endIndex < startIndex)
		return NULL;
	int midIndex = (startIndex+endIndex)/2;
	treeNode root = new treeNode(array[midIndex]);
	// be careful about the start and end index
	root.left = addToTree(array, startIndex, midIndex-1);
	root.right = addToTree(array, midIndex+1, endIndex);
	return root;
}

treeNode creatMinBST(int array[]){
	return addToTree(array, 0, array.length-1);
}