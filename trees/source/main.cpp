
#include "Tree.h"

Tree myTree;
TreeNode n8(8);
TreeNode n5(5);
TreeNode n4(4);
TreeNode n1(1);
TreeNode n9(9);
TreeNode n6(6);
TreeNode n10(10);
TreeNode n14(14);
TreeNode n13(13);
TreeNode n15(15);
TreeNode n7(7);
TreeNode n11(11);
TreeNode n16(16);
TreeNode n2(2);
TreeNode n3(3);
TreeNode n12(12);
void InitTree()
{
	myTree.InsertNode(&n8, nullptr, nullptr);
	myTree.InsertNode(&n5, &n8, nullptr);
	myTree.InsertNode(&n4, &n8, &n5);
	myTree.InsertNode(&n1, &n8, &n4);
	myTree.InsertNode(&n9, &n5, nullptr);
	myTree.InsertNode(&n6, &n4, nullptr);
	myTree.InsertNode(&n10, &n4, &n6);
	myTree.InsertNode(&n14, &n1, nullptr);
	myTree.InsertNode(&n13, &n1, &n14);
	myTree.InsertNode(&n15, &n6, nullptr);
	myTree.InsertNode(&n7, &n6, &n15);
	myTree.InsertNode(&n11, &n10, nullptr);
	myTree.InsertNode(&n16, &n10, &n11);
	myTree.InsertNode(&n2, &n10, &n16);
	myTree.InsertNode(&n3, &n16, nullptr);
	myTree.InsertNode(&n12, &n16, &n3);
}


void main()
{
	InitTree();
	//myTree.PostOrderTraverse(&n8);
	myTree.PreOrderTraverse(&n8);
	system("pause");
}