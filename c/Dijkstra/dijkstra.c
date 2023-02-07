#include <stdio.h>
#include <stdlib.h>

#define INF 9999;

typedef struct Edge Edge;
typedef struct Graph Graph;
typedef struct Node Node;

// struct pour les arètes
struct Edge
{
    int temps;
    int end;
    struct Edge *suivant;
};

// struct du Graphe
struct Graph
{
    int index;
    struct Edge **list;
};

// struct pour les Noeuds
//  struct Node
//  {
//  	int pos;
//  	Node *suivant;
//  };

// initialisation d'une arète
Edge *init_Edge(int temps, int end)
{
    Edge *edge = malloc(sizeof(Edge));
    edge->temps = temps;
    edge->end = end;
    edge->suivant = NULL;
    return edge;
}

// initialisation du Graphe -> choix de la taille
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

// initialisation d'un noeud
//  Node *init_node(int pos)
//  {
//  	Node *node = malloc(sizeof(Node));
//  	node->pos = pos;
//  	node->suivant = NULL;
//  	return node;
//  }

// ajouter une arètes-> graphe non orienté
void addEdge(Graph *graph, int start, int end, int temps)
{
    Edge *edge = init_Edge(temps, end);
    edge->suivant = graph->list[start];
    graph->list[start] = edge;
}

// voir les arètes de tous  les noeuds
void seeEdge(Graph *graph, int index)
{
    Edge *edge = graph->list[index];
    printf("Noeud [(%03d): ", index);
    while (edge != NULL)
    {
        printf(" ->[%d (%d)]", edge->end, edge->temps);
        edge = edge->suivant;
    }
    printf(" \n");
}

// vérifier la présence d'une arète dans un noeud
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

// choix de la plus petite distance entre 2 noeuds
int minDistance(Graph *grph, int dist[], int access[])
{
    int n = grph->index;
    int min = INF;
    int min_index;
    int i;
    for (int i = 0; i < n; i++)
        if (access[i] == 0 && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

// voir le chemin emprunté
void show_chemin(int index, int tab[], Graph *g)
{
    if (tab[index] == -1)
    {
        printf("\t");
        return;
    }
    show_chemin(tab[index], tab, g);
    printf("|%d|", index);
}

void print_dist(int *tab, int taille, int s, int *chemin, Graph *g)
{
    printf("Sommets : \t \t");
    for (int i = 0; i < g->index; i++)
    {
        printf("%d\t\t", i);
    }
    printf("\n");
    printf("Dist. depuis [(%d)]: \t", s);
    for (int i = 0; i < g->index; i++)
    {
        printf("%d\t\t", tab[i]);
    }
    printf("\n");
    printf("Chemin. depuis [(%d):", s);
    for (size_t i = 0; i < g->index; i++)
    {
        show_chemin(i, chemin, g);
        printf("\t");
    }
    printf("\n");
}

void dijkstra(Graph *graph, int src)
{
    int n = graph->index;
    int *dist = malloc(n * sizeof(int));
    int *acces = malloc(n * sizeof(int));
    int chemin[n];

    for (int i = 0; i < n; ++i)
    {
        chemin[i] = -1;
        dist[i] = INF;
        acces[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; ++count)
    {
        int u = minDistance(graph, dist, acces);
        acces[u] = 1;
        for (int j = 0; j < n; ++j)
        {
            if (acces[j] == 0 && is_edge_in_adjlist(graph, u, j) != 0 && dist[u] + is_edge_in_adjlist(graph, u, j) < dist[j])
            {
                dist[j] = dist[u] + is_edge_in_adjlist(graph, u, j);
                chemin[j] = u;
            }
        }
    }

    print_dist(dist, n, src, chemin, graph);
    free(dist);
    free(acces);
}

int main()
{
    srand(time(NULL));
    Graph *graph = init_Graph(5);
    for (int i = 0; i < 10; i++)
    {
        int s = rand() % 5;
        int f = rand() % 5;
        int p = rand() % 20;
        while (s == f)
        {
            s = rand() % 5;
            f = rand() % 5;
        }

        addEdge(graph, s, f, p);
    }

    dijkstra(graph, 1);

    return 0;
}