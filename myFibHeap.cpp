#include <iostream>
#include "myFibHeap.h"

using namespace std;


myFibHeap::myFibHeap() {
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