// Data in left subtree < root node
// data in right subtree > root node
/*
? Delete a node from BST ::
* In order traversal (LNR) of BT gives sorted values

         * Case 1 : 0 child
        -> delete node;
        -> return NULL

        * Case 2 : 1 child
        -> delete node
        -> return node -> left
        OR 
        -> node -> right

        * Case 3 : 2 child
        -> Either : 
        - find max value from left
        - replace it with root value
        - then delete that value
        - return root
        -> Or, 
        - find min value from right
        - replace it with root value
        - then delete that value
        - return root

*/

#include <iostream>
#include <queue>
using namespace std;

class Node {

    public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        this -> data = x;
        this -> right = NULL;
        this -> left = NULL;
    }
};

Node* insertInBst(Node* &root, int data) {
// base case 
if (root == NULL) {
    root = new Node(data);
    return root;
}

if (data > root -> data) {
    root -> right = insertInBst(root -> right, data);
} else {
    root -> left = insertInBst(root -> left, data);
}

return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        insertInBst(root, data);
        cin >> data;
    }
}

void inOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

int minValue(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp->data;
}

int maxValue(Node* root) {
    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp->data;
}

Node* deleteNode(Node* &root, int x) {
    if(root == NULL) {
        return root;
    }

    if(root -> data == x) {
        // delete

        if (root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        } else if ( root -> left != NULL && root -> right == NULL ) {
            Node* temp = root -> left;
            delete root;
            return temp;
        } else if ( root -> left == NULL && root -> right != NULL ) {
            Node* temp = root -> right;
            delete root;
            return temp;
        } else if ( root -> left != NULL && root -> right != NULL ) {
            // int minVal = minValue(root -> right);
            // root -> data = minVal;
            // root -> right = deleteNode(root -> right, minVal);

            int maxVal = maxValue(root -> left);
            root -> data = maxVal;
            root -> right = deleteNode(root -> left, maxVal);
            return root;
        }
    } else if(root -> data > x) {
        root -> left = deleteNode(root -> left, x);
        return root;
    }
        
    root -> right = deleteNode(root -> right, x);
    return root;
}

int main() {
    Node *root = NULL;

    cout << "Enter data (enter -1 to stop) :"<< endl;
    takeInput(root);

    cout << "Minimum value: " << minValue(root) << endl;

    cout << "Maximum value: " << maxValue(root) << endl;

    cout << "BST before deletion : ";
    inOrderTraversal(root); 
    cout << endl;

    deleteNode(root, 20);

    cout << "BST after deletion : ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}