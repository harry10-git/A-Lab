#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr;
	int tos;
	int size;
} STACK;

typedef struct {
	int n;
	int **mat;
} graph;

STACK* initialize_stack(int);
void push(STACK*, int);
int pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);

graph* initgraph(int);
void insertedge(graph*, int, int);
void DFS(graph*);
void dfs(graph*, int, int*);

int main() {
	int vert, edges, u, v;

	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	graph* g = initgraph(vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &edges);

	printf("Enter the edges as the ordered pairs (u, v):\n");
	for(int i=0; i<edges; i++) {
		scanf("%d %d", &u, &v);
		insertedge(g, u, v);
	}
	printf("\n");

	DFS(g);

	return 0;
}

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->size = size;
	stack->arr = (int*) calloc(size, sizeof(int));
	stack->tos = -1;
	return stack;
}

void push(STACK* stack, int ele) {
	stack->arr[++stack->tos] = ele;
}

int pop(STACK* stack) {
	return stack->arr[stack->tos--];
}

int isEmpty(STACK* stack) {
	return stack->tos == -1;
}

int atTop(STACK* stack) {
	return stack->arr[stack->tos];
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}

graph* initgraph(int v) {
	graph* g = (graph*) malloc(sizeof(graph));

	g->n = v;

	g->mat = (int**) calloc(v, sizeof(int*));

	for(int i=0; i<v; i++) {
		g->mat[i] = (int*) calloc(v, sizeof(int));
	}

	return g;
}

void insertedge(graph* g, int u, int v) {
	g->mat[u][v] = 1;
	g->mat[v][u] = 1;
}

void DFS(graph* g) {
	int *visited = (int*) calloc(g->n, sizeof(int));

	printf("The DFS traversal of the given graph is ");
	for(int i=0; i<g->n; i++) {
		if(visited[i] == 0) {
			dfs(g, i, visited);
		}
	}
	printf("\n");
}

void dfs(graph* g, int vert, int* visited) {
	visited[vert] = 1;

	STACK* stack = initialize_stack(g->n);

	push(stack, vert);
	printf("%d ", vert);

	int flag;

	while (!isEmpty(stack)) {
		vert = atTop(stack);

		flag = 0;

		for(int i=0; i<g->n; i++) {
			if(g->mat[vert][i] == 1 && visited[i] == 0) {
				push(stack, i);
				visited[i] = 1;
				printf("%d ", i);
				flag = 1;
				break;
			}
		}

		if(!flag) {
			pop(stack);
		}
	}
}