/*
? Find if a given element is present in BST
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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            } 
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

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

// recursive approach
void isElementPresent(Node* root, int x) {
    if (root == NULL) {
        cout << false;
        return;
    }
    if(root -> data == x) {
        cout << true;
        return;
    } else if(root -> data > x){
        isElementPresent(root -> left, x);
    } else {
        isElementPresent(root -> right, x);
    }
}

// iterative approach
void searchElement(Node* root, int x) {

    Node* temp = root;
    while(temp != NULL) {
        if (temp->data == x) {
            cout <<  true;
            return;
        } else if (temp->data > x) {
            temp = temp -> left;
        } else {
            temp = temp -> right;
        }
    }

    cout << false;
}

int main() {
    Node *root = NULL;

    cout << "Enter data (enter -1 to stop) :"<< endl;
    takeInput(root);

    cout << "BST : "<< endl;
    levelOrderTraversal(root);

    cout << "20 present? ";
    isElementPresent(root, 20);
    cout << endl;

    cout << "29 present? ";
    isElementPresent(root, 29);
    cout << endl;

    cout << "8 present? ";
    searchElement(root, 8);
    cout << endl;

    cout << "18 present? ";
    searchElement(root, 18);
    cout << endl;

    return 0;
}