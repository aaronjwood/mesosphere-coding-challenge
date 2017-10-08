#include <list>
#include <random>
#include <iostream>
#include <scheduler.hpp>

const int clusterSize = 2000;
const int numJobs = 5000;

// Generates nodes in our cluster.
std::list<Node> generateNodes() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> resources(4, 48); // Between 4 and 48 CPUs.
    std::list<Node> nodes;
    for (int i = 0; i < clusterSize; i++) {
        nodes.emplace_back(i, resources(rng));
    }

    return nodes;
}

// Generates jobs that will be submitted to our scheduler.
std::vector<Job> generateJobs() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> resources(1, 10);
    std::uniform_int_distribution<int> steps(1, 5);
    std::vector<Job> jobs;
    for (int i = 0; i < numJobs; i++) {
        jobs.emplace_back(std::make_pair(resources(rng), steps(rng)));
    }

    return jobs;
}

// Creates the scheduler, generates jobs, and schedules jobs onto nodes.
int main() {
    std::list<Node> nodes = generateNodes();
    std::vector<Job> jobs = generateJobs();

    // Starts the scheduler and "connects" all the nodes in our cluster.
    Scheduler scheduler(nodes);

    // We assume these jobs are being submitted to our scheduler from some sort of stream.
    for (std::vector<int>::size_type i = 0; i != jobs.size(); i++) {
        std::pair<bool, int> scheduled = scheduler.schedule(jobs[i]);
        if (!scheduled.first) {
            std::cout << "Insufficient resources to run job " << i << std::endl;
        } else {
            std::cout << "Scheduled job " << i << " on node " << scheduled.second << std::endl;
        }
    }

    return 0;
}