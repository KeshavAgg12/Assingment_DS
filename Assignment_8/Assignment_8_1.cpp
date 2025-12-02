#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int x){
    if(root == NULL) return new Node(x);
    if(x < root->data) root->left = insert(root->left, x);
    else if(x > root->data) root->right = insert(root->right, x);
    return root;
}

/*1. TREE TRAVERSALS */

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/*2(a) SEARCH */

Node* searchRec(Node* root, int key){
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchItr(Node* root, int key){
    Node* cur = root;
    while(cur != NULL){
        if(cur->data == key) return cur;
        if(key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return NULL;
}

/*2(b) MAX */

Node* findMax(Node* root){
    if(root == NULL) return NULL;
    while(root->right != NULL) root = root->right;
    return root;
}

/* 2(c) MIN */

Node* findMin(Node* root){
    if(root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

/* 2(d) INORDER SUCCESSOR */
Node* inorderSuccessor(Node* root, int key){
    Node* target = searchItr(root, key);
    if(!target) return NULL;

    if(target->right) return findMin(target->right);

    Node* succ = NULL;
    Node* cur = root;

    while(cur){
        if(key < cur->data){
            succ = cur;
            cur = cur->left;
        } else if(key > cur->data){
            cur = cur->right;
        } else break;
    }
    return succ;
}

/* 2(e) INORDER PREDECESSOR */
Node* inorderPredecessor(Node* root, int key){
    Node* target = searchItr(root, key);
    if(!target) return NULL;

    if(target->left) return findMax(target->left);

    Node* pred = NULL;
    Node* cur = root;

    while(cur){
        if(key > cur->data){
            pred = cur;
            cur = cur->right;
        } else if(key < cur->data){
            cur = cur->left;
        } else break;
    }
    return pred;
}

/* MAIN */

int main(){
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for(int x : arr) root = insert(root, x);

    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\n";

    cout << "Search Recursive 40: " 
         << (searchRec(root,40) ? "Found" : "Not Found") << endl;

    cout << "Search Iterative 90: " 
         << (searchItr(root,90) ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    int key = 30;
    Node* s = inorderSuccessor(root, key);
    Node* p = inorderPredecessor(root, key);

    cout << "Successor of " << key << ": " 
         << (s ? to_string(s->data) : "None") << endl;

    cout << "Predecessor of " << key << ": " 
         << (p ? to_string(p->data) : "None") << endl;

    return 0;
}
