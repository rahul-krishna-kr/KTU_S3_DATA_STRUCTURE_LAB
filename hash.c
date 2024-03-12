#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayHashTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d:", i);
        if (hashTable[i] == NULL) {
            printf(" Empty\n");
        } else {
            struct Node* temp = hashTable[i];
            while (temp != NULL) {
                printf("%d -->", temp->data);
                temp = temp->next;
            }
            printf(" NULL\n");
        }
    }
}

int main() {
    initHashTable();
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1.Insert an element    2.Display hash table    3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("\n__Hash Table__:\n");
                displayHashTable();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}


