#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <vector>
#include "Edge.h"

typedef std::vector<Edge> EdgeList;

class GraphNode
{
public:
	GraphNode(int a_nodeNum)
	{
		m_NodeNumber = a_nodeNum;
		mIsVisited = false;
	}

	int m_NodeNumber;
	bool mIsVisited;
	EdgeList mEdges;

};

#endif