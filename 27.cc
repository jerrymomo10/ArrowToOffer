#include <cstddef>
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList);
BinaryTreeNode* Convert(BinaryTreeNode* root)
{
	BinaryTreeNode* pLastNodeInList = nullptr;
	ConvertNode(root,&pLastNodeInList);
	
	//return the head
	while(pLastNodeInList!=nullptr&&pLastNodeInList->left!=nullptr)
	{
		pLastNodeInList = pLastNodeInList->left;
	}
	return pLastNodeInList;
	
}
void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
	if(pNode==nullptr)return;
	BinaryTreeNode* pCurrent = pNode;
	if(pCurrent->left!=nullptr)
	{
		ConvertNode(pCurrent->left,pLastNodeInList);
	}
	pCurrent->left = *pLastNodeInList;
	if(*pLastNodeInList!=nullptr)
	{
		(*pLastNodeInList)->right = pCurrent;
	}
	*pLastNodeInList = pCurrent;
	if(pCurrent->right!=nullptr)
	{
		ConvertNode(pCurrent->right,pLastNodeInList);
	}
}
