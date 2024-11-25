#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int HashTable[SIZE];

// Function to initialize the hash table
void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
        {
        HashTable[i] = -1; // Use -1 to indicate an empty slot
    }
}

// Hash function
int HashFunction(int key) {
    return key % SIZE;
}

// Linear probing to find an appropriate index
int LinearProbing(int key) {
    int index = HashFunction(key);
    int i = 0;

    while (HashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            return -1; // Table is full
        }
    }
    return (index + i) % SIZE;
}

// Function to insert a key into the hash table
void insert(int key) {
    int index = LinearProbing(key);
    if (index == -1) {
        printf("Hash table is full\n");
    } else {
        HashTable[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    }
}

// Function to search for a key in the hash table
int Search(int key) {
    int index = HashFunction(key);
    int i = 0;

    while (HashTable[(index + i) % SIZE] != -1) {
        if (HashTable[(index + i) % SIZE] == key) {
            return (index + i) % SIZE;
        }
        i++;
        if (i == SIZE) {
            break; // Key not found after full table traversal
        }
    }
    return -1;
}

// Function to delete a key from the hash table
void Delete(int key) {
    int index = Search(key);
    if (index != -1) {
        HashTable[index] = -1; // Mark the slot as empty
        printf("Key %d deleted from index %d\n", key, index);
    } else {
        printf("Key %d is not found in the hash table\n", key);
    }
}

// Function to display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (HashTable[i] != -1) {
            printf("Index %d: %d\n", i, HashTable[i]);
        } else {
            printf("Index %d: [empty]\n", i);
        }
    }
}

int main() {
    int choice, key;

    initializeTable();

    do {
        printf("\nMENU\n1. Insert Key\n2. Search Key\n3. Delete Key\n4. Display Hash Table\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int result = Search(key);
            if (result != -1) {
                printf("Key %d found at index %d\n", key, result);
            } else {
                printf("Key %d not found\n", key);
            }
            break;

        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            Delete(key);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
