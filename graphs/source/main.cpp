#include "Graph.h"
#include "glm/glm.hpp"

#include <iostream>

using namespace std;

void PrintGraph(Graph* a_graph);
void PrintNeighbors(GraphNode* a_Node);
void PrintNode(GraphNode* a_node);
bool IsNeighbor(GraphNode* node1, GraphNode* node2);
Graph* GenerateGrid(int width, int height);
GraphNode* ClosestNode(Graph* a_graph, glm::vec3 position);

Graph myGraph;
void main()
{

	GraphNode* node0 = new GraphNode(Position(0, 0));
	GraphNode* node1 = new GraphNode(Position(1, 1));
	GraphNode* node2 = new GraphNode(Position(2, 2));
	GraphNode* node3 = new GraphNode(Position(3, 3));
	GraphNode* node4 = new GraphNode(Position(4, 4));
	GraphNode* node5 = new GraphNode(Position(5, 5));

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

	Graph* grid = GenerateGrid(5, 5);
	
	glm::vec3 position(4,4, 0);
	GraphNode* closest = ClosestNode(grid, position);
	cout << "nearest node to position (4,4) - ";
	PrintNode(closest);

	myGraph.SearchDijk(nullptr, nullptr);

	system("pause");
}

Graph* GenerateGrid(int width, int height)
{
	//generate grid of nodes
	Graph* r = new Graph;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			GraphNode* node = new GraphNode(Position(row, col));
			GraphNode* north = new GraphNode(Position(row - 1, col));
			GraphNode* south = new GraphNode(Position(row + 1, col));
			GraphNode* east = new GraphNode(Position(row, col + 1));
			GraphNode* west = new GraphNode(Position(row, col - 1));

			if (row - 1 >= 0)
			{
				Edge e;
				e.mStart = node;
				e.mEnd = north;
				node->mEdges.push_back(e);
			}
			else
			{
				delete north;
			}

			if (row + 1 < height)
			{
				Edge e;
				e.mStart = node;
				e.mEnd = south;
				node->mEdges.push_back(e);
			}
			else
			{
				delete south;
			}

			if (col + 1 < width)
			{
				Edge e;
				e.mStart = node;
				e.mEnd = east;
				node->mEdges.push_back(e);
			}
			else
			{
				delete east;
			}

			if (col - 1 >= 0)
			{
				Edge e;
				e.mStart = node;
				e.mEnd = west;
				node->mEdges.push_back(e);
			}
			else
			{
				delete west;
			}

			r->AddNode(node);
		}
	}
	return r;
}

GraphNode* ClosestNode(Graph* a_graph, glm::vec3 position)
{
	float shortestDx = -1;
	GraphNode* result = nullptr;
	for (auto node : a_graph->mNodes)
	{
		float dx = glm::distance(position, glm::vec3(node->mPosition.x, node->mPosition.y, 0));
		if (shortestDx == -1)
		{
			shortestDx = dx;
			result = node;
		}
		else if (dx < shortestDx)
		{
			shortestDx = dx;
			result = node;
		}

	}
	return result;


}

void PrintGraph(Graph* a_graph)
{

	for (auto node : a_graph->mNodes)
	{
		cout << "node: " << "(" << node->mPosition.x << ", " << node->mPosition.y << ")" << " - " << node << endl;
		for (auto edge : node->mEdges)
		{
			cout << "\tedge: start -  " << edge.mStart << "(node " << "(" << edge.mStart->mPosition.x << ", " << edge.mStart->mPosition.y << ")";
			cout << " end - " << edge.mEnd << "(node " << "(" << edge.mEnd->mPosition.x << ", " << edge.mEnd->mPosition.y << ")";
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
	cout << "node: " << "(" << a_node->mPosition.x << ", " << a_node->mPosition.y << ")" << " - " << a_node << endl;
	for (auto edge : a_node->mEdges)
	{
		cout << "\tedge: start -  " << edge.mStart << "(node " << "(" << edge.mStart->mPosition.x << ", " << edge.mStart->mPosition.y << ")";
		cout << " end - " << edge.mEnd << "(node " << "(" << edge.mEnd->mPosition.x << ", " << edge.mEnd->mPosition.y << ")";
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