#include <iostream>
#include "myFibHeap.h"

using namespace std;


myFibHeap::myFibHeap() {
    _roots = nullptr;
    _numRoots = 0;
    _numNodes = 0;
    
    return;
}


myFibHeap::~myFibHeap() {
    deleteFibHeap(_minRoot);
    return; 
    // will probably need to make a function that goes through the entire
    // tree and delete everything.
}


/* Function: createNode(int value)
 * 
 * @param value The integer value to be set as the fibHeapNode's value.
 * 
 * @returns The address of the newly created node with the specified value and numChildren
 * eqaul to zero.
 */
fibHeapNode *myFibHeap::createNode(int value) {
    fibHeapNode newNode = {.value = value, .numChildren = 0};
    return &newNode;
}


/* Function: updateMin(fibHeapNode *node)
 *
 * @param node The node whose value we are comparing to our _minRoot's value.
 * 
 * @returns Nothing, updated _minRoot if value of node is less than value of _minRoot. Prints accordingly.
 */
void myFibHeap::updateMin(fibHeapNode *node) {
    if (node->value < _minRoot->value) {
        cout << "_minRoot updated! " << node->value << " is less than " << _minRoot->value << "." << endl;
        _minRoot = node;
    }
}


/* Function: linkNode(fibHeapNode *node)
 *
 * @param node A fibHeapNode * to be linked into our _roots list.
 * 
 * @returns Nothing, prints out that a new node was added - alternative depending on case.
 */ 
void myFibHeap::linkNode(fibHeapNode *node) {
    // If this is the first node we enter, add it to list.
    if (!_roots) {
        _roots = node;
        _minRoot = node;

        // Rewire node to maintain cyclic property.
        node->left = node;
        node->right = node;

        _numRoots++;
        cout << "First node in heap; set as minimum root and head of _roots list." << endl;
        return;
    }
    
    // Otherwise, we link node into list. Easiest way is to link to node at _roots pointer.

    // First, connect new node.
    node->right = _roots->right;
    node->left = _roots->right->left;

    // Second, rewire _roots and right neighbor to new node.
    _roots->right = node;
    node->right->left = node;

    // Increment _numRoots and check if we need to update our minimum.
    _numRoots++;
    cout << "Node added and rewired." << endl;
    updateMin(node);
    return;
}


/* Function: insert(fibHeapNode *node)
 *
 * @param node A pointer to the fibHeap node that we want to insert into our fibonacci heap.
 *
 * @returns Nothing, fibonacci heap is updated without returning. Prints out that node was
 * was added to fibonacci heap.
 */
void myFibHeap::insert(fibHeapNode *node) {
    cout << "Node " << node << "added to heap!" << endl;
    return;
}


/* Function: findMin()
 * 
 * @returns A pointer to _minRoot.
 */
fibHeapNode *myFibHeap::findMin() {
    return _minRoot;
}


void myFibHeap::deleteMin() {
    return;
}


void myFibHeap::decreaseKey(fibHeapNode *node, int newValue) {
    return;
}


void myFibHeap::deleteFibHeap(fibHeapNode *root) {
    return;
}