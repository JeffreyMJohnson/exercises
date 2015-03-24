#include "TreeNode.h"

void TreeNode::AttachNode(TreeNode* a_node)
{
	a_node->mParent = this;
	mChildren.push_back(a_node);
}

//process node and then traverse children
void TreeNode::PreOrderTraverse()
{
	Process();
	for (auto node : mChildren)
	{
		node->PreOrderTraverse();
	}
}

//process node after traversing children
void TreeNode::PostOrderTraverse()
{
	for (auto node : mChildren)
	{
		node->PostOrderTraverse();
	}
	Process();
}