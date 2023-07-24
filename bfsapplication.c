#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node** adjList;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjList = (Node**)malloc(numNodes * sizeof(Node));
    for (int i = 0; i < numNodes; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void printPath(int* parent, int v) {
    if (parent[v] == -1) {
        printf("%d ", v);
        return;
    }
    printPath(parent, parent[v]);
    printf("%d ", v);
}

void printShortestPath(int* distance, int* parent, int startNode, int endNode) {
    printf("Shortest path distance: %d\n", distance[endNode]);
    printf("Shortest path: ");
    printPath(parent, endNode);
    printf("\n");
}

void BFS(Graph* graph, int startNode, int endNode) {
    int* visited = (int*)calloc(graph->numNodes, sizeof(int));
    int* distance = (int*)calloc(graph->numNodes, sizeof(int));
    int* parent = (int*)malloc(graph->numNodes * sizeof(int));
    for (int i = 0; i < graph->numNodes; ++i) {
        parent[i] = -1;
    }

    visited[startNode] = 1;
    distance[startNode] = 0;
    parent[startNode] = -1;

    Node* queue = createNode(startNode);
    while (queue != NULL) {
        int currNode = queue->data;
        queue = queue->next;

        if (currNode == endNode) {
            printShortestPath(distance, parent, startNode, endNode);
            return;
        }

        Node* adjNode = graph->adjList[currNode];
        while (adjNode != NULL) {
            int neighbor = adjNode->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                distance[neighbor] = distance[currNode] + 1;
                parent[neighbor] = currNode;
                Node* newNode = createNode(neighbor);
                if (queue == NULL) {
                    queue = newNode;
                } else {
                    Node* temp = queue;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            adjNode = adjNode->next;
        }
    }

    printf("No path found from node %d to node %d\n", startNode, endNode);
}

void destroyGraph(Graph* graph) {
    if (graph == NULL) {
        return;
    }

    for (int i = 0; i < graph->numNodes; ++i) {
        Node* curr = graph->adjList[i];

        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(graph->adjList);
    free(graph);
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    Graph* graph = createGraph(numNodes);

    for (int i = 0; i < numNodes; ++i) {
        int numNeighbors;
        printf("Enter the number of neighbors for node %d: ", i);
        scanf("%d", &numNeighbors);

        for (int j = 0; j < numNeighbors; ++j) {
            int neighbor;
            printf("Enter the neighbor %d of node %d: ", j + 1, i);
            scanf("%d", &neighbor);
            addEdge(graph, i, neighbor);
        }
    }

    int startNode, endNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);
    printf("Enter the end node: ");
    scanf("%d", &endNode);

    BFS(graph, startNode, endNode);

    destroyGraph(graph);

    return 0;
}
/*
7
3
1
2
3
1
4
1
5
1
6
2
1
5
2
2
6
2
5
6
0
4
*/
