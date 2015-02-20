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
	static float Magnitude(const Position& pos1, const Position& pos2)
	{
		return sqrtf(((pos2.x - pos1.x) * (pos2.x - pos1.x)) + ((pos2.y - pos1.y) * (pos2.y - pos1.y)));
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
	float mFscore = 0;
	Position mPosition;
	bool mIsVisited;
	EdgeList mEdges;

};

#endif