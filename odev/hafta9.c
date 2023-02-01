#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};
typedef struct Node avl;
avl *root = NULL;
avl* insert(avl*, int);
avl* delete(avl*, int);
avl* rRotate(avl*);
avl* lRotate(avl*);
avl* minN(avl*);
int height(avl*);
int gbalance(avl*);
int max(int, int);
void preorder(avl*);
int main(){
    root = insert(root, 27);
    root = insert(root, 9);
    root = insert(root, 19);
    root = insert(root, 91);
    root = insert(root, 90);
    root = insert(root, 72);
    preorder(root);
    printf("\n");
    root = delete(root, 9);
    root = delete(root, 72);
    preorder(root);
    printf("\n");
    root = insert(root, 1);
    root = insert(root, 2709);
    preorder(root);
    printf("\n");
    return 0;
}
avl* insert(avl *node, int data){
    if(node == NULL){
        avl *temp = (avl*)malloc(sizeof(avl));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    }
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = gbalance(node);
    if(balance > 1 && data < node->left->data)
        return rRotate(node);
    if(balance < -1 && data > node->right->data)
        return lRotate(node);
    if(balance > 1 && data > node->left->data){
        node->left = lRotate(node->left);
        return rRotate(node);
    }
    if(balance < -1 && data < node->right->data){
        node->right = rRotate(node->right);
        return lRotate(node);
    }
    return node;
}
avl* delete(avl *root, int data){
    if (root == NULL)
        return root;
    if(data < root->data)
        root->left = delete(root->left, data);
    else if(data > root->data)
        root->right = delete(root->right, data);
    else{
        if((root->left == NULL) || (root->right == NULL)){
            avl *temp = root->left ? root->left : root->right;
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else{
            avl *temp = minN(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    if(root == NULL)
        return 0;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = gbalance(root);
    if(balance > 1 && gbalance(root->left) >= 0)
        return rRotate(root);
    if(balance > 1 && gbalance(root->left) < 0){
        root->left = lRotate(root->left);
        return rRotate(root);
    }
    if(balance < -1 && gbalance(root->right) <= 0)
        return lRotate(root);
    if(balance < -1 && gbalance(root->right) > 0){
        root->right = rRotate(root->right);
        return lRotate(root);
    }
    return root;
}
avl* rRotate(avl *temp1){
    avl *temp2 = temp1->left;
    avl *temp3 = temp2->right;
    temp2->right = temp1;
    temp1->left = temp3;
    temp1->height = max(height(temp1->left), height(temp1->right))+1;
    temp2->height = max(height(temp2->left), height(temp2->right))+1;
    root = temp2;
}
avl* lRotate(avl *temp1){
    avl *temp2 = temp1->right;
    avl *temp3 = temp2->left;
    temp2->left = temp1;
    temp1->right = temp3;
    temp1->height = max(height(temp1->left), height(temp1->right))+1;
    temp2->height = max(height(temp2->left), height(temp2->right))+1;
    root = temp2;
}
int height(avl *N){
    if(N == NULL)
        return 0;
    return N->height;
}
int gbalance(avl *N){
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
int max(int a, int b){
    return (a > b)? a : b;
}
avl* minN(avl *node){
    avl *temp = node;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}
void preorder(avl *temp){
    if(temp != NULL){
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}