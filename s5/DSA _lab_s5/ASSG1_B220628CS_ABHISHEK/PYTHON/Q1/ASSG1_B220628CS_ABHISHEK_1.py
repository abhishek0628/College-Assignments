# problem
'''
1. Given an inorder and a preorder traversals of a binary tree, construct the unique binary tree T
corresponding to these traversals. The binary tree contains non-negative integers.
The program should include the following functions:
(a) main(): Repeatedly reads an input character from the menu list through the terminal and
executes menu driven operations accordingly.
(b) P ostOrder(T ): Prints the post order traversal of the binary tree T.
(c) ZIG ZAG(T ): Prints the Zig zag traversal (Definition is given below) of the binary tree T.
(d) LevelM ax(T ): Prints the nodes with maximum value at each level of the binary tree T.
(e) Diameter(T ): Prints the diameter (Definition is given below) of the binary tree T.
(f) RightLeaf Sum(T ): Prints the sum of the values of right leaf nodes(Definition is given below).
Definitions:
• Depth of a node: The length (number of edges) of the unique simple path from the root to
the node.
• Level of a tree: Level i (i varies from 0 to max depth) of a binary tree contains all nodes at
depth i (level 0 contains only root node).
• Zig zag Traversal: Level-order traversal of the binary tree where nodes are printed in a
zig-zag pattern in a single line. Specifically, at even levels (where level numbering starts from
0), nodes are printed from right to left and at odd levels, nodes are printed from left to right.
• Diameter of a tree: The diameter/width of a tree is defined as the number of nodes on the
longest simple path between any two leaf nodes.
• Right Leaf Node: A leaf node that is present as a right child to its parent node.
Input Format:
• The first line contains an integer n ∈[1, 106] indicating the number of nodes in the tree.
• The second line contains a space-separated sequence of n integers representing the IN ORDER
traversal of the tree T with key values ∈[1, 106].
• The third line contains a space-separated sequence of n integers representing the P REORDER
traversal of the tree T with key values ∈[1, 106].
• Each subsequent line contains a character from the set {‘p’, ‘z’, ‘m’, ‘d’, ‘s’, ‘e’}.
– Character ‘p’ calls P ostorder(T ) - to print the postorder traversal of the tree.
– Character ‘z’ calls ZIG ZAG(T ) - to print the Zig zag traversal of the tree.
– Character ‘m’ calls LevelM ax(T ) - to print the nodes with maximum value at each level.
– Character ‘d’ calls Diameter(T ) - to print the diameter of the binary tree.
– Character ‘s’ calls RightLeaf Sum(T ) - to print the sum of the values of all right leaf
nodes.
– Input ‘e’ terminates the execution of the program.
Output Format:
• The output of each command should be printed on a separate line.
• For option ‘p’, print the postorder traversal of T . Each node’s value is separated by a space.
• For option ‘z’, print the Zig zag traversal of T . Each node’s value is separated by a space.
• For option ‘m’, print the nodes with the maximum value at each level. Each node’s value is
separated by a space.
• For option ‘d’, print the diameter of T.
• For option ‘s’, print the sum of the values of all right leaf nodes.
Test Case 1
Input:
5
4 2 1 3 5
1 2 4 3 5
p
z
m
d
s
e
Output:
4 2 5 3 1
1 2 3 5 4
1 3 5
5
5
Test Case 2
Input:
7
4 2 5 1 6 3 7
1 2 4 5 3 6 7
p
z
m
d
s
e
Output:
4 5 2 6 7 3 1
1 2 3 7 6 5 4
1 3 7
5
12
'''

# solution

class treeNode:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
class Tree:
    def build(self,l,h,preindex,inorder,preorder,size):
        key=preorder[preindex]
        preindex+=1
        root=treeNode(key)
        if l==h:
            return root
        for i in range(size):
            if inorder[i]==key:
                break
        root.left=self.build(l,i-1,preindex,preorder,size)
        root.right=self.build(i+1,r,preindex,preorder,inorder,size)
    def postorder(self,root):
        if root is None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.data)

if __name__=="__main__":
    T=Tree()
    inorder=[4,2,1,3,5]
    preorder=[1,2,4,3,5]
    preindex=0
    root=T.build(0,4,preindex,inorder,preorder,5)
    T.postorder(root)

       
