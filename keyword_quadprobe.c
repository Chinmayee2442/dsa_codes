#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

struct Keyword {
    char word[50];
    char info[100];
};

struct Keyword key[SIZE];

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += tolower(key[i]);
    }
    return sum % SIZE;
}

void insert(char* word, char* info) {
    int index = hash(word);
    int offset = 1;
    int qp = 1;

    while (key[index].word[0] != '\0') {
        if (strcmp(key[index].word, word) == 0) {
            printf("Keyword already exists.\n");
            return;
        }
        index = (index + offset * qp) % SIZE; // Quadratic probing
        qp++;
    }

    strcpy(key[index].word, word);
    strcpy(key[index].info, info);
    printf("Keyword and information added successfully.\n");
}

void search(char* word) {
    int index = hash(word);
    int offset = 1;
    int qp = 1;

    while (key[index].word[0] != '\0') {
        if (strcmp(key[index].word, word) == 0) {
            printf("Information: %s\n", key[index].info);
            return;
        }
        index = (index + offset * qp) % SIZE; // Quadratic probing
        qp++;
    }

    printf("Keyword not found.\n");
}

int main() {
    int choice;
    char word[50];
    char info[100];

    while (1) {
        printf("1. Insert keyword and information\n");
        printf("2. Search for keyword\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the keyword: ");
                scanf("%s", word);
                printf("Enter the information: ");
                getchar(); // Clear the input buffer
                fgets(info, sizeof(info), stdin);
                info[strcspn(info, "\n")] = '\0'; // Remove the newline character
                insert(word, info);
                printf("\n");
                break;
            case 2:
                printf("Enter the keyword to search: ");
                scanf("%s", word);
                search(word);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
