#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct StackNode {
  int data;
  struct StackNode* next;
};

struct Stack {
  struct StackNode* top;
};

struct node* createNode(int v);
struct StackNode* createStackNode(int data);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int data);
int pop(struct Stack* stack);

struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};

// DFS algo
void DFS(struct Graph* graph, int startVertex) {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->top = NULL;

  push(stack, startVertex);
  graph->visited[startVertex] = 1;

  while (!isEmpty(stack)) {
    int currentVertex = pop(stack);
    printf("Visited %d\n", currentVertex);

    struct node* adjList = graph->adjLists[currentVertex];
    struct node* temp = adjList;

    while (temp != NULL) {
      int connectedVertex = temp->vertex;

      if (graph->visited[connectedVertex] == 0) {
        push(stack, connectedVertex);
        graph->visited[connectedVertex] = 1;
      }
      temp = temp->next;
    }
  }

  free(stack);
}


// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create stack node
struct StackNode* createStackNode(int data) {
  struct StackNode* newNode = malloc(sizeof(struct StackNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
  return stack->top == NULL;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
  struct StackNode* newNode = createStackNode(data);
  newNode->next = stack->top;
  stack->top = newNode;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow!\n");
    return -1;
  }
  struct StackNode* poppedNode = stack->top;
  int poppedData = poppedNode->data;
  stack->top = stack->top->next;
  free(poppedNode);
  return poppedData;
}

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int k, m, n, q, r;
  printf("NO OF VERTICES\n");
  scanf("%d", &m);
  struct Graph* g = createGraph(m);

  while (1) {
    printf("\t 1: add edge 2: DFS \n");
    scanf("%d", &k);
    switch (k) {
      case 1:
        printf("SOURCE AND DESTINATION\n");
        scanf("%d%d", &n, &q);
        addEdge(g, n, q);
        break;
      case 2:
        printGraph(g);
        printf("GET Depth First Traversal starting from vertex \n");
        scanf("%d", &r);
        DFS(g, r);
        break;
    }
  }

  return 0;
}

