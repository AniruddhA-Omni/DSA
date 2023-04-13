#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, * right;
};

void inorder(Node* root){
    if (root) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    }
}

void preorder(Node* root){
    if (root) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(Node* root){
    if (root) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    }
}

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
  
Node* insertLevelOrder(int arr[], int i, int n){
      Node *root = nullptr;
    if (i < n)
    {
        root = newNode(arr[i]);

        root->left = insertLevelOrder(arr,
                   2 * i + 1, n);

        root->right = insertLevelOrder(arr,
                  2 * i + 2, n);
    }
    return root;
}
 
int main(){
    int arr[] = {14,12,3,5,9,7,5,4,12,13,22};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = insertLevelOrder(arr, 0, n);
    cout<<"Inorder: ";
    inorder(root);
    cout << endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<< endl;
    cout<<"Postorder: ";
    postorder(root);
 
    return 0;
}