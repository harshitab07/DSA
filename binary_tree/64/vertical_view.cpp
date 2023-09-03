#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        this -> data = x;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree (Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data <<endl;
    root->right = buildTree(root->right);

    return root;
}

vector<int> verticalView(Node* &root) {
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node*, pair<int, int> > > q;

    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0) ) );

    while(!q.empty()) {
        pair<Node*, pair<int, int> > temp = q.front();
        q.pop();

        Node* frontNode = temp.first;

        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode -> data);

        if (frontNode -> left) {
            q.push(make_pair(frontNode -> left, make_pair(hd - 1, lvl + 1)));
        }

        if (frontNode -> right) {
            q.push(make_pair(frontNode -> right, make_pair(hd + 1, lvl + 1)));
        }
    }

    for(auto i : nodes) {
        for(auto j : i.second) {
            for(auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}


int main() { 
    Node* root = NULL;

    root = buildTree(root);

    cout << root << endl;

    return 0;
}