#include <iostream>
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2);
bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	bool result = false;
	if(pRoot1!=NULL&&pRoot2!=NULL)
	{
		if(pRoot1->value == pRoot2->value)
		{
			result = DoseTree1HaveTree2(pRoot1,pRoot2);
		}
		if(result==false)
		{
			result = HasSubtree(pRoot1->left,pRoot2);
		}
		if(result==false)
		{
			result = HasSubtree(pRoot1->right,pRoot2);
		}		
	}
	return result;
}
bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	if(pRoot1==NULL)return false;
	if(pRoot2==NULL)return true;
	if(pRoot1->value!=pRoot2->value)return false;
	return DoseTree1HaveTree2(pRoot1->left,pRoot2->left)&&DoseTree1HaveTree2(pRoot1->right,pRoot2->right);
	}
