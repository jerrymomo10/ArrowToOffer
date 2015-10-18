struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
bool isSymmetrical(BinaryTreeNode* root1,BinaryTreeNode* root2);
bool isSymmetrical(BinaryTreeNode* root)
{
	return isSymmetrical(root->left,root->right);
}
bool isSymmetrical(BinaryTreeNode* left,BinaryTreeNode* right)
{
	if(left==nullptr&&right==nullptr)return true;
	if(left==nullptr||right==nullptr)return false;
	if(left->value!=right->value)return false;
	return isSymmetrical(left->left,right->right)&&isSymmetrical(left->right,right->left);
}
