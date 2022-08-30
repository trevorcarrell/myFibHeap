/* File that includes the struct for the fibHeapNode which is to be used in
 * the myFibHeap datastructure.
 */
#include <iostream>


using namespace std;


/* Struct of the fibHeapNode which includes the value of the node, as well 
 * as pointers to its children.
 */
struct fibHeapNode {

    // var::value stores the value of the node.
    int value;

    // var::numChildren gives the number of child in the tree (degree of tree).
    int numChildren;

    // var:parent is a pointer to the parent node of the curren node.
    struct fibHeapNode *parent = nullptr;

    // var:children is a pointer to the child(ren) of the current node.
    struct fibHeapNode *children = nullptr;

    /* IMPORTANT: var::left and var::right aren't children of the current node, but
     * children of the parent node. Children are connected together through a 
     * cyclic doubly linked list, we can access this list through var::children.
     */
    struct fibHeapNode *left = nullptr;
    struct fibHeapNode *right = nullptr;

    /* var::lostChild is used for decrease key. 
     *
     * If var::lostChild is true, that means a child from that node has been cut from the node. 
     * Thus, if another child were to cut from the node, we make sure to remove that child, 
     * then remove its parent. 
     * 
     * Once we remove a child or parent, if var:lostChild is true, we update it to be false.
     */
    bool lostChild = false;
};