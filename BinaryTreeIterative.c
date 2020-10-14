// Binary Tree - Create using Queue, Traversals (preorder, inorder, postorder)

/* 
Algorithm:

1. Create root tree node.
    1.1 Accept value for root node.
    1.2 Allocate memory for root node.
    1.3 Save data in the root node.
    1.4 Set left and right children of the root node to NULL.

2. Enqueue root node.

3. Do the following till queue is empty:
    3.1 Dequeue node from the queue
    3.2 Accept value for left child
    3.3 If value != -1, create a node (same as 1.1 to 1.4) and make it left child of the dequeued node
    3.4 Accept value for right child
    3.5 If value != -1, create a node (same as 1.1 to 1.4) and make it right child of the dequeued node
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int info;
    struct TreeNode *left;
    struct TreeNode *right;
} *root = NULL;

struct Queue {
    struct TreeNode *node;
    struct Queue *next;
} *front = NULL, *rear = NULL;

void enqueue(struct TreeNode *tree_node){
    struct Queue * fresh = (struct Queue *) malloc(sizeof(struct Queue));

    fresh->node = tree_node;
    fresh->next = NULL;

    if (rear == NULL){
        front = rear = fresh;
    } else {
        rear->next = fresh;
        rear = fresh;
    }
}

void display() {
    struct Queue * current = front;

    while (current != NULL) {
        printf("%d ", current->node->info);
        current = current->next;
    }
}

struct TreeNode * dequeue(){
    struct Queue * current = front;

    if (front == rear){
        front = rear = NULL;
    } else {
        front = front->next;
    }

    struct TreeNode *t = current->node;

    free (current);

    return t;
}


int isEmpty() {
    return front == NULL;
}

void createTreeIterative(){
    int x;

    printf("Enter value for root: ");
    scanf("%d", &x);

    root = (struct TreeNode *) malloc (sizeof(struct TreeNode));

    root->info = x;
    root->left = root->right = NULL;

    enqueue(root);

    struct TreeNode * temp = NULL;

    while (!isEmpty()){
        temp = dequeue();

        printf("Enter value for left child of %d: ", temp->info);
        scanf("%d", &x);

        if (x != -1){
            struct TreeNode * fresh = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            fresh->info = x;
            fresh->left = fresh->right = NULL;
            temp->left = fresh;
            enqueue(fresh);
        }

        printf("Enter value for right child of %d: ", temp->info);
        scanf("%d", &x);

        if (x != -1){
            struct TreeNode * fresh = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            fresh->info = x;
            fresh->left = fresh->right = NULL;
            temp->right = fresh;
            enqueue(fresh);
        }
    }
}

void preOrder (struct TreeNode * root){
    if (root == NULL){
        return;
    }

    printf("%d ", root->info);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder (struct TreeNode * root){
    if (root == NULL){
        return;
    }

    inOrder(root->left);
    printf("%d ", root->info);
    inOrder(root->right);
}

void postOrder (struct TreeNode * root){
    if (root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->info);
}

int main()
{
    createTreeIterative();

    printf("Pre-order: ");
    preOrder(root);

    printf("\nIn-order: ");
    inOrder(root);

    printf("\nPost-order: ");
    postOrder(root);
}

/*
Execution:

Enter value for root: 10
Enter value for left child of 10: 20
Enter value for right child of 10: 30
Enter value for left child of 20: 40
Enter value for right child of 20: 50
Enter value for left child of 30: -1
Enter value for right child of 30: -1
Enter value for left child of 40: -1
Enter value for right child of 40: -1
Enter value for left child of 50: -1
Enter value for right child of 50: -1

Pre-order: 10 20 40 50 30
In-order: 40 20 50 10 30
Post-order: 40 50 20 30 10

*/
