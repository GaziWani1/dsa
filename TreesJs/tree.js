class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

const root = new TreeNode('a');
const nodeB = new TreeNode('b');
const nodeC = new TreeNode('c');
const nodeD = new TreeNode('d');
const nodeE = new TreeNode('e');
const nodeF = new TreeNode('f');

root.left = nodeB;
root.right = nodeC;
nodeB.left = nodeD;
nodeB.right = nodeE;
nodeC.left = nodeF;

const depthFirstTraversal = (r) => {
    if (!r) return [];

    const result = [];
    const stack = [];

    stack.push(r);
    while (stack.length > 0) {
        const current = stack.pop();

        result.push(current.value);

        if (current.right) {
            stack.push(current.right)
        }
        if (current.left) {
            stack.push(current.left)
        }
    }

    return result;
}

const res = depthFirstTraversal(root);
console.log(res);

