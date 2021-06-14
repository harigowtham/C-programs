#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct graph {
  int numVertices;
  struct node **adjmat;
};

struct node *create_node(int data) {
  struct node *node = malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  return node;
}

struct graph *create_graph(int v) {
  struct graph *graph = malloc(sizeof(struct graph));
  graph->numVertices = v;
  graph->adjmat = malloc(v*sizeof(struct node));
  for (int i = 0; i < v; i++) {
    graph->adjmat[i] = NULL;
  }
  return graph;
}

void addedge(struct graph *g, int src, int dst) {
  struct node *new = create_node(dst);
  new->next = g->adjmat[src];
  g->adjmat[src] = new;

  /* removing this will make in 1 directional
  new = create_node(src);
  new->next = g->adjmat[dst];
  g->adjmat[dst] = new;
  */
}

void print(struct graph *g){
  if (g == NULL)
    return;
  struct node *tmp;
  for(int i = 0; i < g->numVertices; i++) {
    tmp = g->adjmat[i];
    printf("for vertex:%d\n", i);
    while(tmp!= NULL) {
      printf("%d ", tmp->data);
      tmp = tmp->next;
    }
    printf("\n");
  }
}

int main() {
  struct graph *graph = create_graph(3);
  addedge(graph, 1,2);
  //addedge(graph, 2,1);
  print(graph);
}
