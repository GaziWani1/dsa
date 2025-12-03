#include <iostream>
#include <queue>
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

void inorderTraveral(Node *root)˝
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
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << "  ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}

int main()
{
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
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
    cout << endl
         << "LEVEL TRAVERSE" << endl;
    levelTraverse(root);

    return 0;
}
