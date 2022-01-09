#include <iostream>
#include <queue>
using namespace std;

typedef struct node {
    int val;
    struct node *left, *right, *parent;
}Node;

Node* createNode(int val) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    return tmp;
}

Node* insert(Node *root, int val) {
    Node *t = createNode(val);
    if(root == NULL) {
        root = t;
        return root;
    }
    else{
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *tmp = q.front();
            q.pop();
            if(tmp->left==NULL){
                tmp->left = t;
                t->parent = tmp;
                break;
            }
            else if(tmp->right==NULL){
                tmp->right = t;
                t->parent = tmp;
                break;
            }
            else{
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return root;
    }
}

void display(Node* root){
    if(root == NULL) return;
    else{
        queue<Node*> q;
        q.push(root);
        cout<<"Node\tParent\n";
        while(!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            if(tmp->parent!=NULL)
            cout<<tmp->val<<"\t"<<tmp->parent->val<<endl;
            else cout<<tmp->val<<"\t"<<"NULL"<<endl;
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
        }
    }
}

Node* search(Node* root, int val) {
    if(root == NULL) return NULL;
    else{
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            if(tmp->val==val) return tmp;
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
        }
        return NULL;
    }
}

Node* deleteNode(Node* root, int val) {
    if(root == NULL) return NULL;
    else{
        queue<Node*> q;
        Node* tmp = NULL;
        q.push(root);
        while(!q.empty()) {
            tmp = q.front();
            q.pop();
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
        }
        Node* delNode = search(root, val);
        delNode->val = tmp->val;
        if(tmp->parent->left==tmp) tmp->parent->left = NULL;
        else tmp->parent->right = NULL;
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    display(root);
    root = deleteNode(root, 5);
    display(root);
    return 0;
}
