#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10
#define max 10

struct KeyValue {
    int key;
    int value;
};
struct KeyValue hasht[size];

int hash1(int key) {
    return key % size;
}

int hash2(int key) {
    // Custom hash function for demonstration purposes
    return (key / size) % size;
}

void insert(int key, int value) {
    int k = key;
    int currentValue = value;
    int iterations = 0;

    while (iterations < max) {
        int index1 = hash1(k);
        int index2 = hash2(k);

        // Check if index1 is available
        if (hasht[index1].key == -1) {
            hasht[index1].key = k;
            hasht[index1].value = currentValue;
            printf("Key-value pair (%d, %d) inserted successfully.\n", k, currentValue);
            return;
        }

        // Check if index2 is available
        if (hasht[index2].key == -1) {
            hasht[index2].key = k;
            hasht[index2].value = currentValue;
            printf("Key-value pair (%d, %d) inserted successfully.\n", k, currentValue);
            return;
        }

        // Perform displacement
        int abcd = hasht[index1].key;
        int efgh = hasht[index1].value;

        hasht[index1].key = k;
        hasht[index1].value = currentValue;

        k = abcd;
        currentValue = efgh;

        iterations++;
    }

    printf("Insertion failed. Maximum iterations reached.\n");
}

int lookup(int key) {
    int index1 = hash1(key);
    int index2 = hash2(key);

    if (hasht[index1].key == key) {
        return hasht[index1].value;
    }

    if (hasht[index2].key == key) {
        return hasht[index2].value;
    }

    return -1; // Key not found
}

int main() {
    // Initialize hash table
    for (int i = 0; i < size; i++) {
        hasht[i].key = -1; // -1 represents an empty slot
        hasht[i].value = -1;
    }

    int numPairs;
    printf("Enter the number of key-value pairs to insert: ");
    scanf("%d", &numPairs);

    int key, value;
    for (int i = 0; i < numPairs; i++) {
        printf("Enter key-value pair %d: ", i + 1);
        scanf("%d %d", &key, &value);
        insert(key, value);
    }

    int num;
    printf("Enter the number of lookups to perform: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter the key to lookup: ");
        scanf("%d", &key);
        int result = lookup(key);
        if (result != -1) {
            printf("Value for key %d: %d\n", key, result);
        } else {
            printf("Key %d not found.\n", key);
        }
    }

    return 0;
}
