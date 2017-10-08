#ifndef MESOSPHERE_CODING_CHALLENGE_JOB_HPP
#define MESOSPHERE_CODING_CHALLENGE_JOB_HPP

#include <tuple>
#include "node.hpp"

// Jobs are sent from our scheduler.
class Job {

private:

    // Requirements to run the job.
    // Resources and durations are required for any job to run.
    std::pair<int, int> requirements;

public:

    // Constructs a new job.
    explicit Job(std::pair<int, int> requirements);

    // Returns the requirements for this job.
    std::pair<int, int> getRequirements();

    // Runs the job on the specified node.
    // Returns true if the job is successfully run, otherwise false.
    bool run(Node &node);
};


#endif //MESOSPHERE_CODING_CHALLENGE_JOB_HPP
