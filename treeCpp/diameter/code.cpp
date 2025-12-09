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

static int ans = 0;

int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHt = diameter(root->left);
    int rytHt = diameter(root->right);

    ans = max(ans, leftHt + rytHt);
    return max(leftHt, rytHt) + 1;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    diameter(root);
    cout << "Diamater : " << ans << endl;

    return 0;
}
