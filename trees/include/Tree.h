#ifndef _TREE_H_
#define _TREE_H_

#include "TreeNode.h"
#include <assert.h>

typedef std::list<TreeNode*>::iterator ListIter;

class Tree
{
public:
	Tree()
	{
		mRoot = nullptr;
	}

	void InsertNode(TreeNode* nodeToInsert, TreeNode* parent, TreeNode* sibling)
	{
		if (mRoot == nullptr)
		{
			mRoot = nodeToInsert;
			
			return;
		}
		assert(parent != nullptr);
		nodeToInsert->SetParent(parent);

		if (parent->GetChildren().empty())
		{
			parent->GetChildren().push_back(nodeToInsert);
		}

		for (ListIter it = parent->GetChildren().begin(); it != parent->GetChildren().end(); it++)
		{
			if (*it == sibling)
			{
				parent->GetChildren().insert(it, nodeToInsert);
			}
		}
	}


	void PreOrderTraverse(TreeNode* current)
	{
		current->PreOrderTraverse();
	}


	void PostOrderTraverse(TreeNode* current)
	{
		current->PostOrderTraverse();
	}


private:
	TreeNode* mRoot;
};

#endif