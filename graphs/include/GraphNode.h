#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <vector>
#include "Edge.h"

typedef std::vector<Edge> EdgeList;

struct Position
{
	float x;
	float y;
	Position()
	{
		x = 0;
		y = 0;
	}
	Position(float a_x, float a_y)
	{
		x = a_x;
		y = a_y;
	}
};

class GraphNode
{
public:
	GraphNode(Position a_position)
	{
		mIsVisited = false;
		mPosition = a_position;
	}

	GraphNode* mParent;
	int mGScore;
	Position mPosition;
	bool mIsVisited;
	EdgeList mEdges;

};

#endif