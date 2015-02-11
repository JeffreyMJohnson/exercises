#include "GraphNode.h"


class Graph
{
	typedef std::vector<GraphNode*> NodeList;
public:
	//create empty graph
	Graph();

	//create graph with given num of nodes
	Graph(unsigned int a_nodeCount);

	void AddNode(GraphNode* a_node)
	{
		mNodes.push_back(a_node);
	}
	void RemoveNode(GraphNode* a_node)
	{
		//loop through vector
		for (NodeList::iterator it = mNodes.begin(); it != mNodes.end(); it++)
		{
			GraphNode* n = *it;
			//loop through every edge
			for (EdgeList::iterator eIt = (*it)->mEdges.begin(); eIt != (*it)->mEdges.end(); eIt++)
			{
				//is current edge node are removing
				if (eIt->mStart == a_node)
				{
					//remove edge
					(*it)->mEdges.erase(eIt);
				}
			}
		}
	}

private:
	NodeList mNodes;
};