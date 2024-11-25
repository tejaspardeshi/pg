#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->prev = insert(root->prev, data);
    }
    else
    {
        root->next = insert(root->next, data);
    }
    return root;
}

int min(struct Node* root)
{
    struct Node* temp = root;
    while (temp && temp->prev != NULL)
    {
        telmp = temp->prev;
    }
    return temp->data;
}

int max(struct Node* root)
{
    struct Node* temp = root;
    while (temp && temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->prev, key);
    }
    return search(root->next, key);
}

int main()
{
    struct Node* root = NULL;
    int numbers[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, numbers[i]);
    }

    printf("Minimum value in the BST: %d\n", min(root));
    printf("Maximum value in the BST: %d\n", max(root));

    int searchKey = 17;
    struct Node* foundNode = search(root, searchKey);
    if (foundNode != NULL)
    {
        printf("Value %d found in the BST.\n", searchKey);
    }
    else
    {
        printf("Value %d not found in the BST.\n", searchKey);
    }

    return 0;
}
