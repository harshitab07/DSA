/*
? Question Link : https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

? Question Title:  Normal BST To Balanced BST
*/


/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inOrder(TreeNode<int>* root, vector<int> &in) {
    if(root == NULL) return;

    inOrder(root -> left, in);
    in.push_back(root -> data);
    inOrder(root -> right, in);
}

TreeNode<int>* inOrderToBst(int s, int e, vector<int> v) {
    if(s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(int(v[mid]));

    root -> left = inOrderToBst(s, mid - 1, v);
    root -> right = inOrderToBst(mid + 1, e, v);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    inOrder(root, v);
    // for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    int s = 0;
    int e = v.size() - 1;
    return inOrderToBst(s, e, v);
}
