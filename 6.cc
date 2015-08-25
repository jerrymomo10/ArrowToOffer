#include <cstdio>
#include <exception>
using namespace std;
struct BinaryNode
{
	int value;
	BinaryNode* left;
	BinaryNode* right;	
};
BinaryNode* ConstructCore(int* preorderbegin,int* preorderend,int* inorderbegin,int* inorderend)
{
	int rootvalue = preorderbegin[0];
	BinaryNode* root = new BinaryNode();
	root->value = rootvalue;
	root->left = root->right = NULL;
	
	if(preorderbegin==preorderend)
	{
		if(inorderbegin==inorderend&&*preorderbegin==*preorderend)
		{
			return root;
		}
		else
		{
			throw exception();
		}
		int* rootinorder = inorderbegin;
		while(rootinorder<=inorderend&&*rootinorder!=*preorderbegin)rootinorder++;
		if(rootinorder==inorderend&&*rootinorder!=*preorderbegin)throw exception();
		int leftlength = rootinorder-inorderbegin;
		int* leftpreorderend = preorderbegin+leftlength;
		if(leftlength>0)
		{
			root->left = ConstructCore(preorderbegin+1,leftpreorderend,inorderbegin,rootinorder-1);
		}
		if(leftlength<preorderend-preorderbegin)
		{
			root->right = ConstructCore(leftpreorderend+1,preorderend,rootinorder+1,inorderend);
		}
	}
		return root;
}
BinaryNode* Construct(int* preorder,int* inorder,int length)
{
	if(preorder==NULL||inorder==NULL||length<=0)
	{
		return NULL;
	}
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}
