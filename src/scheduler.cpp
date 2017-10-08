#include "scheduler.hpp"

// Construct the scheduler.
// Here we "connect" all of the available nodes in our cluster.
Scheduler::Scheduler(std::list<Node> &nodes) : freeNodes(nodes) {}

// Takes a job from the stream and schedules it for execution.
// Return true and the node number if the job was successfully scheduled and run, otherwise false and -1.
std::pair<bool, int> Scheduler::schedule(Job &job) {
    auto node = std::begin(freeNodes);
    while (node != std::end(freeNodes)) {

        // If our job's resource requirement is more than the resources on this node then skip to the next node.
        if (node->allocateResources(job.getRequirements().first)) {
            return std::make_pair(job.run(*node), node->getNumber());
        }

        usedNodes.emplace_back(*node);
        node = freeNodes.erase(node);

    }

    // Ideally we should not stop here.
    // Outside of a timed coding challenge there would be logic to release resources back to nodes as jobs complete.
    // As nodes become available in our pool we would be able to continually schedule new incoming jobs.
    return std::make_pair(false, -1);
}
