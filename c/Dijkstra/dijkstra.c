#include <stdio.h>
#include <stdlib.h>

#define INF 999999;

typedef struct Edge Edge;
typedef struct Graph Graph;
typedef struct Node Node;

//struct pour les arètes
struct Edge
{
	int temps;
	int end;
	struct Edge *suivant;
};

//struct du Graphe
struct Graph
{
	int index;
	struct Edge **list;
};

//struct pour les Noeuds
struct Node
{
	int pos;
	Node *suivant;
};

//initialisation d'une arète
Edge *init_Edge(int temps, int end)
{
	Edge *edge = malloc(sizeof(Edge));
	edge->temps = temps;
	edge->end = end;
	edge->suivant = NULL;
	return edge;
}

//initialisation du Graphe -> choix de la taille
Graph *init_Graph(int taille)
{
	Graph *graph = malloc(sizeof(Graph));
	graph->index = taille;
	graph->list = malloc(taille * sizeof(Edge));
	for (int i = 0; i < taille; ++i)
	{
		graph->list[i] = NULL;
	}
	return graph;
}

//initialisation d'un noeud
Node *init_node(int pos)
{
	Node *node = malloc(sizeof(Node));
	node->pos = pos;
	node->suivant = NULL;
	return node;
}

//ajouter une arètes-> graphe non orienté
void addEdge(Graph *graph, int start, int end, int temps)
{
	Edge *edge = init_Edge(temps, end);
	edge->suivant = graph->list[start];
	graph->list[start] = edge;
}

//voir les arètes de tous  les noeuds
void seeEdge(Graph *graph,int index)
{
	Edge *edge = graph->list[index];
	printf("Noeud [(%03d): ");
	while (edge != NULL)
	{
		printf(" ->[%d (%d)]", edge->end,edge->temps);
		edge = edge->suivant;
	}
	printf(" \n");
}

//vérifier la présence d'une arète dans un noeud
int is_edge_in_adjlist(Graph *graph, int u, int j)
{
	int test = 0;
	Edge *edge = graph->list[u];
	while (edge != NULL && test == 0)
	{
		if (edge->end == j)
		{
			test = edge->temps;
		}
		edge = edge->suivant;
	}
	return test;
}



int main(){

    return 0;
}