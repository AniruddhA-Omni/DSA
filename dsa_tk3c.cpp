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


Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
  
Node* insert(Node* node, int key){
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}


Node* minValueNode(Node* node){
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node* root, int key){
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else{
        // node with only one child or no child
        if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = minValueNode(root->right);
 
        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
int main(){
    int arr[] = {11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 31};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = nullptr;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    
    cout<<"Inorder: ";
    inorder(root);
    cout << endl;
    cout<<"Delete 0 children: ";
    root = deleteNode(root, 4);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
    cout << endl;
    cout<<"Delete 1 children: ";
    root = deleteNode(root, 6);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
    cout << endl;
    cout<<"Delete 2 children: ";
    root = deleteNode(root, 19);
    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);
    cout << endl;
    return 0;
}