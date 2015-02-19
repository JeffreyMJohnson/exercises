#include "GraphNode.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <limits>

#include <algorithm>

bool NodeCompare(const GraphNode* lhs, const GraphNode* rhs)
{
	return (lhs->mGScore < rhs->mGScore);
}

class Graph
{
	typedef std::vector<GraphNode*> NodeList;
public:
	NodeList mNodes;
	//create empty graph
	Graph(){};

	//create graph with given num of nodes
	Graph(unsigned int a_nodeCount)
	{
		for (int i = 0; i < a_nodeCount; i++)
		{
			GraphNode* n = new GraphNode(Position(i, i));
			mNodes.push_back(n);
		}
	}



	void AddNode(GraphNode* a_node)
	{
		mNodes.push_back(a_node);
	}


	void ResetVisited()
	{
		for (auto node : mNodes)
		{
			node->mIsVisited = false;
		}
	}

	std::list<GraphNode*> ProcessGraphForDijkstra(GraphNode* start, GraphNode* end)
	{
		std::list<GraphNode*> priorityQ;
		ResetNodelist();
		priorityQ.push_front(start);
		start->mGScore = 0;
		start->mParent = start;

		while (!priorityQ.empty())
		{
			//sort so first node always lowest g score
			priorityQ.sort(NodeCompare);
			GraphNode* current = priorityQ.front();
			priorityQ.pop_front();

			current->mIsVisited = true;

			for (auto edge : current->mEdges)
			{
				if (!edge.mEnd->mIsVisited)
				{
					int cost = current->mGScore + edge.mCost;
					if (cost < edge.mEnd->mGScore)
					{
						edge.mEnd->mParent = current;
						edge.mEnd->mGScore = cost;
						std::find(priorityQ.begin(), priorityQ.end(), edge.mEnd);
						if ((std::find(priorityQ.begin(), priorityQ.end(), edge.mEnd)) == priorityQ.end())
						{
							priorityQ.push_back(edge.mEnd);
						}
					}
				}
			}
		}
		std::list<GraphNode*> result;
		result.push_front(end);
		GraphNode* parent = end->mParent;
		while (parent != start)
		{
			result.push_front(parent);
			parent = parent->mParent;
		}
		result.push_front(parent);
		return result;

	}

	bool IsInList(std::list<GraphNode*>& list, GraphNode* node)
	{
		for (std::list<GraphNode*>::iterator it = list.begin(); it != list.end(); ++it)
		{
			if (*it = node)
				return true;
		}
		return false;
	}

	void ResetNodelist()
	{
		for (auto node : mNodes)
		{
			node->mParent = nullptr;
			node->mGScore = INT_MAX;
			node->mIsVisited = false;
		}
	}

	bool SearchDFS(GraphNode* a_start, GraphNode* a_end)
	{
		std::stack<GraphNode*> nodeStack;
		nodeStack.push(a_start);

		//keep looping until stack is empty
		//this means all is checked.
		while (!nodeStack.empty())
		{
			GraphNode* current = nodeStack.top();
			nodeStack.pop();
			if (current->mIsVisited)
			{
				continue;
			}
			current->mIsVisited = true;
			if (current == a_end)
			{
				return true;
			}
			for (auto edge : current->mEdges)
			{
				nodeStack.push(edge.mEnd);
			}
		}

		return false;
	}

	bool SearchBFS(GraphNode* a_start, GraphNode* a_end)
	{
		std::queue<GraphNode*> nodeQueue;
		nodeQueue.push(a_start);

		while (!nodeQueue.empty())
		{
			GraphNode* current = nodeQueue.front();
			nodeQueue.pop();
			if (current->mIsVisited)
				continue;
			if (current == a_end)
			{
				return true;
			}
			current->mIsVisited = true;

			for (auto edge : current->mEdges)
			{
				if (!edge.mEnd->mIsVisited)
				{
					nodeQueue.push(edge.mEnd);
				}
			}
		}
		return false;
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
					eIt = (*it)->mEdges.erase(eIt);
				}
				if (eIt->mEnd == a_node)
				{
					//remove edge
					eIt = (*it)->mEdges.erase(eIt);
				}
			}
			if (n = a_node)
			{
				it = mNodes.erase(it);
			}
		}
	}


};