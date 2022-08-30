#include <iostream>
#include "string.h"
#include "fibHeapNode.h"


using namespace std;


class myFibHeap {
    public:
        // Constructor for myFibHeap
        myFibHeap();

        // Destructor for myFibHeap
        ~myFibHeap();

        /* insert() method for a Fibonacci Heap, simply takes in a new fibHeapNode *
         * and inserts it as a new root into the heap.
         */
        void insert(fibHeapNode *node);

        /* findMin() method for a Fibonacci Heap, simply returns our minimum fibHeapNode;
         * we keep track of this constantly, so we just return it immediately.
         */
        fibHeapNode *findMin();

        /* deleteMin() method for a Fibonacci Heap, deletes the marked var::_minRoot and puts its children
         * into the root list as their own trees, while simutaneously linking them into the var::_roots
         * linked list.
         * 
         * We then search through var::_roots for a var::_minRoot. After found, we want to
         * consolidate the trees so that don't have any trees with the same degree (or same number of
         * children), consolidating trees that have the same degree. To do so, we create an array from 
         * 0 to var::_maxDegree, and consolidate when two trees have the same degree.
         * 
         * To maintain heap property, we always add the higher value noode as a child to the lower value node.
         * Once we've looped through all trees (no more trees with the same degree exist).
         */
        void deleteMin();

        /* decreaseKey() method for a Fibonacci Heap, decreases the value of a given node, but there are
         * a few cases:

         *  1.) we can decrease without violating heap property -> just update node value.
         *  2.) we can't decrease without violating heap property... (new value is smaller than parent value)
         *
         * If we run into 2.), then we mark the parent as losing a child, then cut the child tree out from the
         * parent, putting it into the root list and updating accordingly - making sure to check if we've 
         * got a new minimum.
         * 
         * If we cut from a parent who has already lost a child, we also cut the parent out and put it into
         * the root list, making sure to unmark it (this is done recursively for all ancestors that have
         * lost a child).
         */
        void decreaseKey(fibHeapNode *node, int newValue);

        // deleteFibHeap() method goes through the entire fibonacci heap and deletes all data.
        void deleteFibHeap(fibHeapNode *root);


    private:
        // var::_numRots is the number of nodes in our root list (or number of trees)
        int _numRoots;

        // var::_numNodes is the number of nodes in our fibonacci heap.
        int _numNodes;

        // var::_numMarked is the number of nodes which have lost children.
        int _numMarked;

        // var::_maxDegree is number representing the max degree of our trees
        int _maxDegree;

        /* var::_roots is a private member function where the roots of the fibonacci heap are
         * stored. The parent of these nodes is always null. Again, like other nodes, they're
         * connected through a cyclic, doubly linked list.
         */ 
        fibHeapNode *_roots;

        /* var::_minRoot is a private member function that stores the minimum root, which is the
         * minimum value in the the fibonacci heap.
         */
        fibHeapNode *_minRoot;

        // createNode() method creates a node than can be used for our fibonacci heap.
        fibHeapNode *createNode(int value);

        // linkNodes() method links two nodes together in a doubly linked list.
        void linkNode(fibHeapNode *node);
};
