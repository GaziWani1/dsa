#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(int preOrder[])
{
    idx++;
    if (preOrder[idx] == -1)
        return NULL;

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);  // LEFT
    root->right = buildTree(preOrder); // RIGHT

    return root;
}

void preOrderV(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderV(root->left);
    preOrderV(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int preOrder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrder);
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    preOrderV(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}