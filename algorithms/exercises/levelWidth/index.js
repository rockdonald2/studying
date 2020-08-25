// --- Directions
// Given the root node of a tree, return
// an array where each element is the width
// of the tree at each level.
// --- Example
// Given:
//     0
//   / |  \
// 1   2   3
// |       |
// 4       5
// Answer: [1, 3, 2]

function levelWidth(root) {
    let widths = [0];
    let arr = [root, undefined];

    while (arr.length > 1) {
        const curr = arr.shift();

        if (curr === undefined) {
            arr.push(curr);
            widths.push(0);
        } else {
            arr.push(...curr.children);
            widths[widths.length - 1]++;
        }
    }

    return widths;
}

module.exports = levelWidth;