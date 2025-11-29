#include <iostream>
#include <vector>
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

// Build tree from preorder with -1 as NULL marker
Node *buildTree(const vector<int> &preorder)
{
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    Node *root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHt = height(root->left);
    int rytHt = height(root->right);

    return max(leftHt, rytHt) + 1;
}

int nodeCount(Node *root)
{
    if (root == NULL)
        return 0;
    int leftCount = nodeCount(root->left);
    int rightCount = nodeCount(root->right);

    return leftCount + rightCount + 1;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    cout << "Height : " << height(root) << endl;
    cout << "Count : " << nodeCount(root) << endl;

    return 0;
}
