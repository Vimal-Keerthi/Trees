#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;


Node* createNode(int val){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void display(Node* root) {
    if(root!=NULL){
        display(root->left);
        printf("%d ", root->val);
        display(root->right);
    }
}

Node* insert(Node *root, int val) {
    if(root==NULL){
        Node* tmp = createNode(val);
        root = tmp;
        return root;
    }
    else{
        if(val>root->val)
            root->right = insert(root->right, val);
        else
            root->left = insert(root->left, val);
        return root;
    }
}

Node* findMax(Node* root) {
    if(root==NULL) return NULL;
    else if(root->right==NULL) return root;
    else return findMax(root->right);
}

Node* delete(Node* root, int val){
    if(root==NULL) return NULL;
    else {
        if(val>root->val){
            root->right = delete(root->right, val);
        }
        else if(val<root->val){
            root->left = delete(root->left, val);
        }
        else{
            if(root->left!=NULL && root->right!=NULL){
                Node* tmp = findMax(root->left);
                root->val = tmp->val;
                root->left = delete(root->left, tmp->val);
            }
            else if(root->left==NULL){
                Node* tmp = root;
                root = root->right;
                free(tmp);
            }
            else{
                Node* tmp = root;
                root = root->left;
                free(tmp);
            }
        }
        return root;
    }
}

Node* search(Node* root, int val){
    if(root==NULL) {
        return NULL;
    }
    else{
        if(val>root->val) return search(root->right, val);
        else if(val<root->val) return search(root->left, val);
        else return root;
    }
}

int main(){
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,6);
    root = insert(root,7);
    root = insert(root,8);
    root = insert(root,13);
    root = insert(root,16);
    root = insert(root,15);
    display(root);
    root = delete(root, 6);
    printf("\n");
    display(root);
    root = delete(root, 13);
    printf("\n");
    display(root);
    root = delete(root, 10);
    printf("\n");
    display(root);
    printf("\n");
    Node* tmp = search(root, 16);
    if(tmp==NULL) printf("Key not found\n");
    else printf("Key found\n");
    return 0;
}
