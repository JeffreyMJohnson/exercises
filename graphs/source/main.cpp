#include "Graph.h"



void main()
{
	Graph myGraph;
	for (int i = 0; i < 10; i++)
	{
		GraphNode* node = new GraphNode(i);
		GraphNode* node2 = new GraphNode(i + 10);
		Edge e1;
		e1.mStart = node;
		e1.mEnd = node2;
		node->mEdges.push_back(e1);
		myGraph.AddNode(node);
	}

	

}