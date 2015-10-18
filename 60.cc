#include <cstdio>
#include <queue>
using namespace std;
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
void Print(BinaryTreeNode* root)
{
	if(root==nullptr)return;
	queue<BinaryTreeNode*>nodes;
	nodes.push(root);
	int nextlevel = 0;
	int tobeprint = 1;
	while(!nodes.empty())
	{
		BinaryTreeNode* node = nodes.front();
		printf("%d\t",node->value);
		if(node->left!=nullptr)
		{
			nodes.push(node->left);
			nextlevel++;
		}
		if(node->right!=nullptr)
		{
			nodes.push(node->right);
			nextlevel++;
		}
		nodes.pop();
		tobeprint--;
		if(tobeprint==0)
		{
			printf("\n");
			tobeprint = nextlevel;
			nextlevel = 0;
		}
	}
}
