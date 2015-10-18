struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
BinaryTreeNode* KthNodeCore(BinaryTreeNode* root,unsigned int k)
{
	BinaryTreeNode* target = nullptr;
	if(root->left!=nullptr)target = KthNodeCore(root->left,k);
	if(target==nullptr)
	{
		if(k==1)
		{
			target = root;
			k--;
		}
	}
	if(target==nullptr&&root->right!=nullptr)
	{
		target = KthNodeCore(root->right,k);
	}
	return target;
}
BinaryTreeNode* KthNode(BinaryTreeNode* root,unsigned int k)
{
	if(root==nullptr||k==0)return nullptr;
	return KthNodeCore(root,k);
}
