struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
int TreeDepth(BinaryTreeNode* root)
{
	if(root==nullptr)return 0;
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	return left>right?left+1:right+1;
}
bool IsBalanced(BinaryTreeNode* root,int* depth)
{
	if(root==nullptr)
	{
		*depth = 0;
		return true;
	}
	int left = 0;
	int right = 0;
	if(IsBalanced(root->left,&left)&&IsBalanced(root->right,&right))
	{
		int dif = left-right;
		if(dif<=1&&dif>=-1)
		{
			*depth = left>right?left+1:right+1;
			return true;
		}
	}
	return false;
}
bool BalanceTree(BinaryTreeNode* root)
{
	int depth = 0;
	return IsBalanced(root,&depth);
}
