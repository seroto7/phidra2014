#include "graph.h"

Graph* CreateGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	graph->Vertices = NULL;
	graph->VertexCount = 0;

	return graph;
}

void DestroyGraph(Graph* G)
{
	while (G->Vertices != NULL) {
		Vertex* Vertices = G->Vertices->Next;
		DestroyVertex(G->Vertices);
		G->Vertices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(ElementType Data)
{
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));

	vertex->Data = Data;
	vertex->Visited = NotVisited;
	vertex->Index = -1;

	vertex->Next = NULL;
	vertex->AdjacencyList = NULL;

	return vertex;
}

void DestroyVertex(Vertex* V)
{
	while (V->adjacencyList != NULL) {
		Edge* edge = V->adjacencyList->Next;
		DestroyEdge(V->adjacencyList);
		V->adjacencyList = edge;
	}

	free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int weight)
{
	Edge* edge = (Edge*)malloc(sizeof(Edge));

	edge->Weight = weight;
	edge->Next = NULL;
	edge->From = From;
	edge->Target = Target;

	return edge;
}
void DestroyEdge(Edge* E)
{
	free(E);
}

void AddVertex(Graph* G, Vertex* V)
{
	Vertex* VertexList = G->Vertices;

	if (VertexList == NULL)
		G->Vertices = V;
	else {
		while (VertexList->Next != NULL)
			VertexList = VertexList->Next;

		VertexList->Next = V;
	}

	V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
	if (V->AdjacencyList == NULL) {
		V->AdjacencyList = E;
	} else {
		Edge* AdjacencyList = V->AdjacencyList;

		while (AdjacencyList->Next != NULL)
			AdjacencyList = AdjacencyList->Next;

		AdjacencyList->Next = E;
	}
}

void PrintEdge(Graph* G)
{
	Vertex* V = NULL;
	Edge* E = NULL;

	if ((V = G->Vertices) == NULL)
		return;

	while (V != NULL) {
		printf("%c : ", V->Data);

		if ((E = V->AdjacencyList) == NULL) {
			V = V->Next;
			printf("\n");
			continue;
		}

		while (E != NULL) {
			printf("%c[%d] ", E->Target->Data, E->Weight);
			E = E->Next;
		}

		printf("\n");

		V = V->Next;
	}

	printf("\n");
}
