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

Node *buildTree(int preorder[], int n)
{
    idx++;
    if (idx >= n || preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder, n);
    root->right = buildTree(preorder, n);

    return root;
}

void preorderTraveral(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "  ";
    preorderTraveral(root->left);
    preorderTraveral(root->right);
}

void inorderTraveral(Node *root)
{
    if (root == NULL)
        return;
    inorderTraveral(root->left);
    cout << root->data << "  ";
    inorderTraveral(root->right);
}

void postOrderTra(Node *root)
{
    if (root == NULL)
        return;
    postOrderTra(root->left);
    postOrderTra(root->right);
    cout << root->data << "  ";
}

void levelTraverse(Node *root)
{
    
}

int main()
{
    int preorder[] = {1, 2, -1, 3, 4, -1, -1, 5, -1, -1};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    Node *root = buildTree(preorder, n);
    cout << "PRE ORDER" << endl;
    preorderTraveral(root);
    cout << endl
         << "IN ORDER" << endl;
    inorderTraveral(root);
    cout << endl
         << "POST ORDER" << endl;
    postOrderTra(root);
    return 0;
}
