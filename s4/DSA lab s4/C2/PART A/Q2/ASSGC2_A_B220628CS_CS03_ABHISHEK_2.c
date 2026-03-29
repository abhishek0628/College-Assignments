//problem
/*
2. You are tasked with implementing a data structure that mimics the functionality of an ordered
map using an AVL Tree. An ordered map, also known as a map or dictionary, is a data structure
that stores a collection of key-value pairs. Unlike a regular hash map, an ordered map maintains
the keys in sorted order, allowing efficient retrieval of elements in a sorted sequence based on their
keys. Your main() function shall read the choice from the console and call the following functions
appropriately:
(a) insert(AVLTree *root, key, value): Inserts a key-value pair into the AVL Tree. If the key
already exists, update the corresponding value.
(b) lower bound(AVLTree *root, key): Prints the key-value pair of the first element with not less
than the given key, otherwise print -1.
(c) find(AVLTree *root, key): Searches for a key in the AVL Tree and print the key-value pair if
found, otherwise print -1.
(d) size(AVLTree *root): Prints the number of key-value pairs in the AVL Tree.(0 if empty).
(e) empty(AVLTree *root):Prints 1 if the AVLTree is empty, otherwise prints 0.
(f) printElements(AVLTree *root): Prints the keys in the AVL Tree in ascending order, (-1 if
empty).
Input Format:
All the inputs in a line are separated by space.
Each line of input starts with a character from the menu list [’i’,’l’,’f’,’s’,’e’,’p’,’t’] and may be
followed by one or two integers, which specify the key(and value), respectively.
• Input ‘i’ followed by two integers key and value calls the function insert(AVLTree *root, key,
value).
• Input ‘l’ followed by an integer key calls the function lower bound(AVLTree *root, key).
• Input ’f’ followed by an integer key calls the function find(AVLTree *root, key).
• Input ‘s’ calls the function size(AVLTree *root).
• Input ‘e’ calls the function empty(AVLTree *root).
• Input ‘p’ calls the function printElements(AVLTree *root).
• Input ‘t’ terminates the execution of the program.
Output Format:
• The output of the result of any menu is printed in a new line with a space between each
integer.
• A line may contain -1.
Sample Input1:
i 1 10
i 2 20
i 3 30
i 4 40
l 3
l 5
f 35
e
f 1
s
p
i 1 100
i 10 1
f 1
s
p
t
Sample Output1:
3 30
-1
-1
0
1 10
4
1 2 3 4
1 100
5
1 2 3 4 10
Sample input 2:
e
i 5 50
i 3 30
i 7 70
i 1 10
l 6
f 3
i 9 99
s
p
e
f 10
t
Sample output 2:
1
7 70
3 30
5
0
-1
*/

//solution
#include<stdio.h>
