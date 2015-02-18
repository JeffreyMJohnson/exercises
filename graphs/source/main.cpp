#include "Graph.h"
#include <iostream>

using namespace std;

void PrintGraph();
void PrintNeighbors(GraphNode* a_Node);
void PrintNode(GraphNode* a_node);
bool IsNeighbor(GraphNode* node1, GraphNode* node2);

Graph myGraph;
void main()
{

	GraphNode* node0 = new GraphNode(0);
	GraphNode* node1 = new GraphNode(1);
	GraphNode* node2 = new GraphNode(2);
	GraphNode* node3 = new GraphNode(3);
	GraphNode* node4 = new GraphNode(4);
	GraphNode* node5 = new GraphNode(5);

	Edge e0;
	e0.mStart = node0;
	e0.mEnd = node1;
	node0->mEdges.push_back(e0);

	Edge e1;
	e1.mStart = node0;
	e1.mEnd = node5;
	node0->mEdges.push_back(e1);
	myGraph.AddNode(node0);

	Edge e2;
	e2.mStart = node1;
	e2.mEnd = node2;
	node1->mEdges.push_back(e2);
	myGraph.AddNode(node1);

	Edge e3;
	e3.mStart = node2;
	e3.mEnd = node0;
	node2->mEdges.push_back(e3);

	Edge e4;
	e4.mStart = node2;
	e4.mEnd = node3;
	node2->mEdges.push_back(e4);
	myGraph.AddNode(node2);

	Edge e5;
	e5.mStart = node3;
	e5.mEnd = node4;
	node3->mEdges.push_back(e5);
	myGraph.AddNode(node3);

	myGraph.AddNode(node4);

	Edge e6;
	e6.mStart = node5;
	e6.mEnd = node3;
	node5->mEdges.push_back(e6);

	Edge e7;
	e7.mStart = node5;
	e7.mEnd = node4;
	node5->mEdges.push_back(e7);
	myGraph.AddNode(node5);

	PrintGraph();

	cout << "node3 connected to node5: " << myGraph.SearchDFS(node3, node5)<<endl;

	system("pause");
}

void PrintGraph()
{

	for (auto node : myGraph.mNodes)
	{
		cout << "node: " << node->m_NodeNumber << " - " << node << endl;
		for (auto edge : node->mEdges)
		{
			cout << "\tedge: start -  " << edge.mStart << "(node " << edge.mStart->m_NodeNumber << ")";
			cout << " end - " << edge.mEnd << "(node " << edge.mEnd->m_NodeNumber << ")";
			cout << endl;
		}
	}
}

bool IsNeighbor(GraphNode* node1, GraphNode* node2)
{
	for (auto edge : node1->mEdges)
	{
		if (edge.mEnd == node2)
			return true;
	}
	for (auto edge : node2->mEdges)
	{
		if (edge.mEnd == node1)
			return true;
	}
	return false;
}

void PrintNode(GraphNode* a_node)
{
	cout << "node: " << a_node->m_NodeNumber << " - " << a_node << endl;
	for (auto edge : a_node->mEdges)
	{
		cout << "\tedge: start -  " << edge.mStart << "(node " << edge.mStart->m_NodeNumber << ")";
		cout << " end - " << edge.mEnd << "(node " << edge.mEnd->m_NodeNumber << ")";
		cout << endl;
	}
}

void PrintNeighbors(GraphNode* a_Node)
{
	for (auto edge : a_Node->mEdges)
	{
		PrintNode(edge.mEnd);
	}
}