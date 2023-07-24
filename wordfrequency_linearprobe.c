
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

struct WordFrequency {
    char word[50];
    int count;
};

struct WordFrequency wordfrq[SIZE];

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += tolower(key[i]);
    }
    return sum % SIZE;
}

void insert(char* word) {
    int index = hash(word);

    while (wordfrq[index].word[0] != '\0') {
        if (strcmp(wordfrq[index].word, word) == 0) {
            wordfrq[index].count++;
            return;
        }
        index = (index + 1) % SIZE; // Linear probing
    }

    strcpy(wordfrq[index].word, word);
    wordfrq[index].count = 1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (wordfrq[i].word[0] != '\0') {
            printf("Word: %s, Frequency: %d\n", wordfrq[i].word, wordfrq[i].count);
        }
    }
}

int main() {
    int n;
    char word[50];

    printf("Enter the number of words: ");
    scanf("%d", &n);
    getchar(); // Clear the input buffer

    printf("Enter the words:\n");
    for (int i = 0; i < n; i++) {
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0'; // Remove the newline character

        insert(word);
    }

    printf("\nWord Frequencies:\n");
    display();

    return 0;
}
