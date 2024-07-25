#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//ptr
//struct

//define the strurcture for the Node
struct Node{
    int val;
    struct Node *left, *right;
};

//Function to create a new Node
struct Node* newNode(int val){
    struct Node* root = new Node;
    root->val = val;
    root->right = NULL;
    root->left = NULL;

    return root;

}

/*Take root node and key value 
and inserts node with value as  
key.
returns the modified tree (or root node)*/

struct Node* insert(Node* root, int insertVal){
    //case 1: root is null
    //case 2:root enter in left subtree is null
    //case 3:root enter in right subtree could be null

    if(root == NULL){
        return newNode(insertVal);
    }
    if(root->val > insertVal){
        root->left = insert(root->left, insertVal);
    }
    else if(root->val < insertVal){
        root->right = insert(root->right, insertVal);
    }
    
    // Return the unchanged root node
    return root;

}

// Function to search fot a value in the BST
bool search(Node* root, int searchVal){

    //Base case: root is null or value is found
    if(root != NULL || root->val == searchVal){
        return true;
    }
    else if(root->val > searchVal){                //Search in the left subtree
        return search(root->left, searchVal);
    }
    else if (root->val<searchVal){                  // Search in the right subtree
        return search(root->right, searchVal);
    }
    return false;
    
}
struct Node* deleteNode(Node* root, int deleteVal){
    if(root == NULL){
        return NULL;
    }

    if(root->val > deleteVal){
        return deleteNode(root->left, deleteVal);
    }
    else if(root->val < deleteVal){
        return deleteNode(root->right, deleteVal);
    }

    //Step 1 - find x ==> completed

    // 0 child
    // 1 child
    // 2 child

    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }


// //if X is a leaf Node node
    if(root->right == NULL && root->left == NULL){
       return NULL;//Delete current node as it is the leaf node.
    }


    //step 2 - find Y such that Y is just greater than x
    Node* parent = root;
    Node* y = parent-> right;
    while(y->left != NULL){
        parent = y;
        y - y->left;


    }
    //when right child of root is null
    if(y == NULL){
        return root->left;
    }

    // Y has been found
    root->val = y->val;

    if(parent->left == y){
         parent->left = y->right;

    }
    else{
        parent->right = y->right;

    }
    return root;


}

    


//sorted order of nodes
void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}




int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n; cin >> n;
    struct Node* root = NULL;
    for(int i=0; i<n; i++){
        int val; cin >> val;
        root = insert(root, val);
    }

    inorder(root);
    cout<<endl;

    int del; cin >> del;
    root = deleteNode(root, del);
    cout << "after deleting : " << del << endl;
    inorder(root);
    cout << endl;
    return 0;

}