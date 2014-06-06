#include "graph.h"

void DepthSearch(Graph* G)
{
	Vertex* V = G->Vertices;

	if (V == NULL)
		return;

	Edge* E = V->AdjacencyList;
	while (V->AdjacencyList != NULL) {
	}
}
