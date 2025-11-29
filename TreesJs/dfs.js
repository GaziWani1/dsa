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

const bfs = (r) => {
    if (!r) return [];
    const queue = [r];
    const result = []
    while (queue.length > 0) {
        const current = queue.shift();
        result.push(current.value);

        if (current.left) queue.push(current.left)
        if (current.right) queue.push(current.right)
    }
    return result
}

const res = bfs(root);
console.log(res);