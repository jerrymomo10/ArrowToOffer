#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	};
void FindPath(BinaryTreeNode* root,int sum,vector<int> path,int current);
void FindPath(BinaryTreeNode* root,int sum)
{
	if(root==nullptr)return;
	vector<int> path;
	int currentsum = 0;
	FindPath(root,sum,path,currentsum);
	}
void FindPath(BinaryTreeNode* root,int sum,vector<int> path,int current)
{
	current += root->value;
	path.push_back(root->value);
	
	bool isleft = root->left==nullptr&&root->right==nullptr;
	if(isleft==true&&current==sum)
	{
		cout<<"A path is found: ";
		auto i = path.cbegin();
		while(i!=path.cend())
		{
			cout<<*i<<'\t';
			i++;
		}
		cout<<endl;
	}
	if(root->left!=nullptr)
	{
		FindPath(root->left,sum,path,current);
	}
	if(root->right!=nullptr)
	{
		FindPath(root->right,sum,path,current);
	}
	path.pop_back();
}
