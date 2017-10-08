#ifndef MESOSPHERE_CODING_CHALLENGE_NODE_HPP
#define MESOSPHERE_CODING_CHALLENGE_NODE_HPP

// Represents a single node in a larger cluster of nodes.
class Node {

private:

    // Node number.
    // Uniquely identifies the node.
    int number;

    // Number of resource units that this node has.
    int resources;

public:

    // Constructs a new node, setting its number and amount of resources.
    Node(int number, int resources);

    // Returns the node's number.
    int getNumber();

    // Gets the remaining resources of this node.
    int getResources();

    // Allocates resources from this node.
    bool allocateResources(int allocation);

};

#endif //MESOSPHERE_CODING_CHALLENGE_NODE_HPP
