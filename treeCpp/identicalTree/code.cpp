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

bool isIdentical(Node *p, Node *q)
{

    if (q == NULL || p == NULL)
        return p == q;
    bool isLeftSame = isIdentical(p->left, q->left);
    bool isRightSame = isIdentical(p->right, q->right);

    return isLeftSame && isRightSame && p->data == q->data;
}

int main()
{
    vector<int> preorder = {
        1,
        2,
        -1,
        -1,
        3,
    };

    Node *root1 = buildTree(preorder);
    idx = -1;
    Node *root2 = buildTree(preorder);
    cout << "Is Identical : " << isIdentical(root1, root2) << endl;
    return 0;
}