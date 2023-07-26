# PracticaArbolesABB
Introduction:

This repository contains a C program that implements a binary search tree (BST). The program allows users to perform various operations on the BST, such as adding nodes, printing the tree using the inorder traversal method, searching for a node, counting the number of leaves, finding the height of the tree, and deleting nodes.

Getting Started:

To run the program, you need a C compiler and a development environment installed on your computer. You can use popular IDEs like Code::Blocks, Visual Studio, or simply compile the code using a command-line compiler.

Code Overview:

The main C file is named main.c and includes the following functionalities:

-Data Structures: The program defines a binary search tree (BST) data structure using a structure named sTdato, which represents a node in the BST. The tree is implemented using pointers.

-Function Prototypes: The code defines prototypes for all the functions used in the program.

-Menu Function: The menu() function presents a user-friendly menu that allows users to choose from various operations on the BST.

-Adding Nodes: The program allows users to add new nodes to the BST. The function addDatos() creates a new node and addTree() inserts it into the BST in a proper position based on its value.

-Printing the Tree: The function preorder() is used to print the BST in ascending order using the inorder traversal method.

-Searching for a Node: The function BuscarArbol() is used to search for a node with a given value in the BST.

-Counting Leaves: The function conthojas() counts the number of leaf nodes in the BST.

-Finding Tree Height: The function contaltura() calculates the height of the BST.

-Deleting Nodes: The function BorrarNodo() allows users to delete a node with a specific value from the BST.



How to Use

1.Compile the code using a C compiler.

2.Run the compiled executable.

3.Follow the on-screen instructions to perform various operations on the binary search tree.



Notes

The program is set to handle integers as data in the BST. If you want to use other data types, modifications to the code are necessary.

Make sure to handle memory deallocation properly if you modify the program or use dynamic memory allocation for other data types.

Contributors
This program was created by Orlando Sanchez. If you wish to contribute or report any issues, feel free to open an issue or create a pull request.

License
This program is opensource
