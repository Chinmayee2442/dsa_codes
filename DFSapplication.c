#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int stack[MAX_NODES];
int top = -1;

void push(int node) {
    stack[++top] = node;
}

int pop() {
    return stack[top--];
}

int isStackContains(int node) {
    int i;
    for (i = 0; i <= top; i++) {
        if (stack[i] == node) {
            return 1;
        }
    }
    return 0;
}

void displayCycle(int startNode, int endNode) {
    int i;
    printf("Cycle: ");
    for (i = top; i >= 0; i--)
        {
        printf("%d ", stack[i]);
        if (stack[i] == startNode)
         {
            break;
        }
    }
    printf("\n");
}

int hasCycleDFS(int currentNode) {
    visited[currentNode] = 1;
    push(currentNode);

    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (adjMatrix[currentNode][i]) {
            if (!visited[i]) {
                if (hasCycleDFS(i)) {
                    return 1;
                }
            } else if (isStackContains(i)) {
                displayCycle(i, currentNode);
                return 1;
            }
        }
    }

    pop();
    return 0;
}

int hasCycle(int numNodes) {
    int i;
    for (i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int numNodes, numEdges, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source -> destination):\n");
    for (i = 0; i < numEdges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        adjMatrix[source][destination] = 1;
    }

    if (hasCycle(numNodes)) {
        printf("The graph contains cycles.\n");
    } else {
        printf("The graph does not contain cycles.\n");
    }

    return 0;
}
