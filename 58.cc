struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;
};
BinaryTreeNode* GetNext(BinaryTreeNode* node)
{
	if(node==nullptr)return nullptr;
	BinaryTreeNode* next = nullptr;
	if(node->right!=nullptr)
	{
		BinaryTreeNode* right = node->right;
		while(right->left!=nullptr)right = right->left;
		next = right;
	}
	else if(node->parent!=nullptr)
	{
		BinaryTreeNode* current = node;
		BinaryTreeNode* parent = node->parent;
		while(parent!=nullptr&&current==parent->right)
		{
			current = parent;
			parent = current->parent;
		}
		next = parent;
	}
	return next;
}
