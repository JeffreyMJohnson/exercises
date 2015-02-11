#include "GraphNode.h"

class GraphNode;

struct Edge
{
	GraphNode* mStart;
	GraphNode* mEnd;

	float mCost;
};