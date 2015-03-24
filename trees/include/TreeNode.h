#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

#include <list>
#include <iostream>
#include <algorithm>

class TreeNode
{
public:
	TreeNode(){};
	TreeNode(int data)
	{
		mData = data;
	}
	~TreeNode(){};

	void Process()
	{
		std::cout << "Data: " << mData << std::endl;
	}

	void PreOrderTraverse();
	void PostOrderTraverse();

	void AttachNode(TreeNode* a_node);

	int GetData()
	{
		return mData;
	}

	void SetData(int data)
	{
		mData = data;
	}

	void SetParent(TreeNode* parent)
	{
		mParent = parent;
	}

	TreeNode* GetParent()
	{
		return mParent;
	}


	std::list<TreeNode*>& GetChildren()
	{
		return mChildren;
	}

private:
	TreeNode* mParent;
	std::list<TreeNode*> mChildren;
	int mData = 0;
};


#endif