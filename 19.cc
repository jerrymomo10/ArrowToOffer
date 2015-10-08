#include <cstddef>
#include <stack>
using namespace std;
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
void MirrorRecursively(BinaryTreeNode* root)
{
	if(root==NULL)return;
	if(root->left==NULL&&root->right==nullptr)return;
	BinaryTreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	MirrorRecursively(root->left);
	MirrorRecursively(root->right);
	}
void MirrorLoop(BinaryTreeNode* root)
{
	if(root==nullptr)return;
	stack<BinaryTreeNode*> StackTreeNode;
	StackTreeNode.push(root);
	while(StackTreeNode.size()!=0)
	{
		BinaryTreeNode* temp = StackTreeNode.top();
		StackTreeNode.pop();
		if(temp->left!=nullptr||temp->right!=nullptr)
		{
			BinaryTreeNode* t = temp->left;
			temp->left = temp->right;
			temp->right = t;
		}
		if(temp->left!=nullptr)
		{
			StackTreeNode.push(temp->left);
		}
		if(temp->right!=nullptr)
		{
			StackTreeNode.push(temp->left);
		}
	}
	}
