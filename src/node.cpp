#include "node.hpp"

// Construct a new node.
Node::Node(int number, int resources) : number(number), resources(resources) {}

// Return the node's number.
int Node::getNumber() {
    return number;
}

// Return the remaining resources of this node.
int Node::getResources() {
    return resources;
}

// Allocate resources from this node.
// Returns false if the node does not have enough resources, true if we are able to deduct resources.
bool Node::allocateResources(int allocation) {
    if (resources - allocation < 0) {
        return false;
    }

    resources -= allocation;

    return true;
}