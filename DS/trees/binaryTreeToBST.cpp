// https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
// given implementation does not work with duplicate values in given tree

// 1) traverse given binary tree in any way & store all nodes in a array
// 2) sort the array
// 3) traverse the input binary tree again in inorder fashion & while traversing change the node values with array sequentially, here tree is traversed inorder & array sequentially simultaneously 