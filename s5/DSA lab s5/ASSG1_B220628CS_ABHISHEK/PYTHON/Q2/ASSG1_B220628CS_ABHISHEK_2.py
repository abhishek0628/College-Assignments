# problem
'''
2. We are using a Binary Search Tree (BST) to store car details for a car showroom,
where each car is represented by its model number, model name, and price. The
BST is created based on the model number, which is unique for each car.
The BST data structure should support various dynamic-set operations and should
be implemented with the following specifications:
• BST Structure
Each node in the BST contains a model number (positive integer), model name
(string), and price (positive integer). In addition to these key attributes, each
node contains pointers to its left child, right child, and parent. If a child or the
parent is missing, the appropriate pointer should be set to NIL. The root node
is the only node in the tree whose parent is NIL.
• BST Property
Let x be a node in a BST. If y is a node in the left subtree of x, then y.key <
x.key. If y is a node in the right subtree of x, then y.key ≥x.key.
• Operations
(a) M ain(): Creates an empty BST and repeatedly reads a character from the
console to perform the following operations until ’e’ (exit) is entered:
– ‘a’ : Add a new car detail.
– ‘d’ : Delete an existing car detail.
– ‘s’ : Search for a car by model number.
– ‘i’ : Perform an inorder traversal of the BST and print car details.
– ‘p’ : Perform a preorder traversal of the BST and print car details.
– ‘t’ : Perform a postorder traversal of the BST and print car details.
– ‘m’ : Modify the price of an existing car.
(b) Create N ode(model number, model name, price): Creates a new node with
the given car details and returns a pointer to the new node. All pointer at-
tributes of the new node should be set to N IL.
(c) Add(T, x): Inserts the node x into the BST T . Here x is a pointer to the
new node returned by the Create N ode() function.
(d) Delete(T, x): Deletes the node x from the BST T . Here x is a pointer to the
node to be deleted returned by the Search() function to locate the node x.
(e) Search(T, model number): Searches for a node with the given model num-
ber in T and returns a pointer to the node if it exists; otherwise, it returns
N IL.
(f) Inorder(T ): Performs recursive inorder traversal of the BST T and prints
the car details in the nodes of T in inorder.
(g) P reorder(T ): Performs recursive preorder traversal of the BST T and prints
the car details in the nodes of T in preorder.
(h) P ostorder(T ): Performs recursive postorder traversal of the BST T and
prints the car details in the nodes of T in postorder.
(i) M odif y(T, model number, new price): Modifies the price of a car with the
given model number to the new price.
Input Format
• Each line contains a character from {‘a’, ‘d’, ‘s’, ‘i’, ‘p’, ‘t’, ‘m’, ‘e’}followed by
the arguments required for the corresponding operation.
– Character ‘a’ is followed by a positive integer n, a string s, and a positive
integer p separated by a space. Perform Add(T, x) operation.
– Character ‘d’ is followed by a positive integer n separated by a space. Per-
form Delete(T, x) operation
– Character ‘s’ is followed by a positive integer n separated by a space. Perform
Search(T, model number) operation.
– Character ‘i’ is to perform inorder traversal of T.
– Character ‘p’ is to perform preorder traversal of T.
– Character ‘t’ is to perform postorder traversal of T.
– Character ‘m’ is followed by two positive integers separated by a space.
Perform M odif y(T, model number, new price) operation.
– Character ‘e’ is to ‘exit’ from the program.
Output Format
• The output (if any) of each command should be printed on a separate line.
• For option ‘d’, print the deleted car’s details in the order: model number, model
name, price separated by a space. If a node with the entered model number is
not present in T , then print -1.
• For option ‘s’, If a node with entered model number is present in T , then print all
the details of that car in the order: model number, model name, price separated
by a space. If a node with the entered model number is not present in T , then
print -1.
• For options ‘i’, ‘p’, ‘t’, print the data in the nodes of T obtained from the
corresponding traversal. Each car’s details are written on a separate line in the
order: model number, model name, price separated by a space.
• For option ‘m’, print the modified car’s details in the order: model number,
model name, and updated price separated by a space. If a node with the entered
model number is not present in T , then print -1.
Test Case
Input:
a 1 Toyota 20000
a 2 Honda 18000
a 3 Ford 25000
s 2
i
p
t
m 2 19000
s 2
d 3
s 3
i
e
Output:
2 Honda 18000
1 Toyota 20000
2 Honda 18000
3 Ford 25000
2 Honda 18000
1 Toyota 20000
3 Ford 25000
1 Toyota 20000
3 Ford 25000
2 Honda 18000
2 Honda 19000
2 Honda 19000
3 Ford 25000
-1
1 Toyota 20000
2 Honda 19000
'''

# solution
class TreeNode:
    def __init__(self,model_num,model_name,price):
        self.model_num=model_num
        self.model_name=model_name
        self.price=price
        self.left=None
        self.right=None
class BST:
    def Add(self,root,model_num,model_name,price):
        if root is None:
            return TreeNode(model_num,model_name,price)
        if root.price>price:
            root.left=self.Add(root.left,model_num,model_name,price)
        elif root.price<price:
            root.right=self.Add(root.right,model_num,model_name,price)
        return root
    def Search(self,root,model_num):
        if root is None:
            return root
        if root.model_num==model_num:
            return root
        if root.model_num>model_num:
            return self.Search(root.left,model_num)
        elif root.model_num<model_num:
            return self.Search(root.right,model_num)
    def minvalue(self,root):
        curr=root
        while curr and curr.left is not None:
            curr=curr.left
        return curr
        
    def delete(self,root,model_num):
        if root is None:
            return root
        if root.model_num>model_num:
            root.left=self.delete(root.left,model_num)
        elif root.model_num<model_num:
            root.right=self.delete(root.right,model_num)
        else:
            if root.left is None:
                temp=root.right
                return temp
            elif root.right is None:
                temp=root.left
                return temp
            else:
                temp=self.minvalue(root.right)
                root.model_num=temp.model_num
                root.model_name=temp.model_name
                root.price=temp.price
                root.right=self.delete(root.right,temp.model_num)
        return root
        
    def modify(self,root,model_num,price):
        if root is None:
            return root
        temp=self.Search(root,model_num)
        if temp is None:
            return None
        temp.price=price
        return temp
        
    def inorder(self,root):
        if root is None:
            return
        self.inorder(root.left)
        print(root.model_num," ",root.model_name," ",root.price)
        self.inorder(root.right)
    
    def postorder(self,root):
        if root is None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.model_num," ",root.model_name," ",root.price)

    
    def preorder(self,root):
        if root is None:
            return
        print(root.model_num," ",root.model_name," ",root.price)
        self.preorder(root.left)
        self.preorder(root.right)

     

if __name__ == "__main__":
    root = None
    B = BST()

    while True:
        parts = input().strip().split()

        if not parts:
            continue

        cmd = parts[0]

        if cmd == 'a':
            model_num = int(parts[1])
            model_name = parts[2]
            price = int(parts[3])
            root = B.Add(root, model_num, model_name, price)

        elif cmd == 'd':
            model_num = int(parts[1])
            root = B.delete(root, model_num)

        elif cmd == 's':
            model_num = int(parts[1])
            temp = B.Search(root, model_num)
            if temp is not None:
                print(temp.model_num, temp.model_name, temp.price)
            else:
                print("-1")

        elif cmd == 'i':
            B.inorder(root)

        elif cmd == 'p':
            B.preorder(root)

        elif cmd == 't':
            B.postorder(root)
        elif cmd=='m':
            model_num=int(parts[1])
            price=int(parts[2])
            temp=B.modify(root,model_num,price)
            if temp:
                print(temp.model_num, temp.model_name, temp.price)
            else:
                print("-1")
            
        elif cmd == 'e':
            break 


        
        
    