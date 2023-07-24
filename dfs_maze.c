#include <stdio.h>

#define SIZE 6

// Function to check if a given cell is valid and can be visited
int validcell(int maze[SIZE][SIZE], int row, int col, int visited[SIZE][SIZE]) {
    // Check if the cell is within the maze bounds and is not a wall (0) or already visited
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && maze[row][col] == 1 && visited[row][col] == 0);
}

// Function to recursively solve the maze using depth-first search
int mazeee(int maze[SIZE][SIZE], int row, int col, int visited[SIZE][SIZE]) {
    // Check if we have reached the goal (bottom-right cell)
    if (row == SIZE - 1 && col == SIZE - 1) {
        visited[row][col] = 1;
        return 1;  // Maze is solved
    }

    // Mark the current cell as visited
    visited[row][col] = 1;

    // Check all possible directions (up, down, left, right) to explore
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        // Check if the new cell is valid and not visited
        if (validcell(maze, newRow, newCol, visited)) {
            // Recursive call to explore the next cell
            if (mazeee(maze, newRow, newCol, visited)) {
                return 1;  // Maze is solved
            }
        }
    }

    // If no path is found, mark the current cell as unvisited
    visited[row][col] = 0;

    return 0;  // Maze is unsolvable
}

// Function to print the solved maze
void printMaze(int maze[SIZE][SIZE]) {
   // printf("Solved Maze:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[SIZE][SIZE] = {
        {1, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1}
    };

    int visited[SIZE][SIZE] = {0};

    printf("Original Maze:\n");
    printMaze(maze);

    // Start solving the maze from the top-left corner (cell 0,0)
    if (mazeee(maze, 0, 0, visited)) {
        printf("\nsolved maze\n");
        printMaze(visited);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}
