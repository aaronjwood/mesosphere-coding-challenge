#include "job.hpp"

// Construct a new job.
Job::Job(std::pair<int, int> requirements) : requirements(std::move(requirements)) {}

// Return the requirements for this job.
// Requirements consist of resource units and time steps.
std::pair<int, int> Job::getRequirements() {
    return requirements;
}

// Execute the job on the provided node.
// Return true if the job is successfully run, otherwise false.
bool Job::run(Node &node) {
    return node.allocateResources(requirements.first);
}
