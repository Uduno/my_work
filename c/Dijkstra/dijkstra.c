#include <stdio.h>
#include <stdlib.h>

#define INF 999999;

typedef struct Edge Edge;
typedef struct Graph Graph;
typedef struct Node Node;

struct Edge
{
	int temps;
	int end;
	struct Edge *suivant;
};

struct Graph
{
	int index;
	struct Edge **list;
};

struct Node
{
	int pos;
	Node *suivant;
};


int main(){

    return 0;
}