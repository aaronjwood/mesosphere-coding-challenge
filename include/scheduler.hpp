#ifndef MESOSPHERE_CODING_CHALLENGE_SCHEDULER_HPP
#define MESOSPHERE_CODING_CHALLENGE_SCHEDULER_HPP

#include "job.hpp"
#include <list>

// A scheduler takes incoming job requests and schedules jobs on nodes that have the appropriate resources.
class Scheduler {

private:

    // Pool of nodes known to the scheduler that have free resources.
    // Here we assume that each node has registered with the scheduler.
    // The scheduler is now able to keep track of the amount of resources from each node.
    // We use a linked list here so that insertions and removals are O(1).
    std::list<Node> freeNodes;

    // Pool of nodes that have all of their resources used up.
    // We can use this list later when we need to watch for completed jobs.
    // As jobs are completed we can add used nodes back into the free pool.
    // We use a linked list here so that insertions and removals are O(1).
    std::list<Node> usedNodes;

public:

    // Constructs the scheduler, "connecting" all of the cluster nodes to it.
    explicit Scheduler(std::list<Node> &nodes);

    // Schedules a new job.
    // Returns true and the node number if the job was successfully scheduled and run, otherwise false and -1.
    std::pair<bool, int> schedule(Job &job);

};

#endif //MESOSPHERE_CODING_CHALLENGE_SCHEDULER_HPP
