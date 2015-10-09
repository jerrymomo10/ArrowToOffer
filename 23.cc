#include <cstddef>
#include <queue>
#include <cstdio>
using namespace std;
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
void PrintFRomTopToBottom(BinaryTreeNode* root)
{
	if(root==nullptr)return;
	queue<BinaryTreeNode*> treenodes;
	treenodes.push(root);
	while(!treenodes.empty())
	{
		BinaryTreeNode* temp = treenodes.front();
		treenodes.pop();
		
		printf("%d\t",temp->value);
		if(temp->left!=nullptr)treenodes.push(temp->left);
		if(temp->right!=nullptr)treenodes.push(temp->right);
	}
}
