# Mesosphere Distributed Systems Engineer Challenge

## Overview

This challenge consists of four major pieces:

* Scheduler
* Job
* Node
* Driver

The scheduler is responsible for taking in job requests from our "stream", finding a node with available resources, and running the job on that node.
Due to the time constraint on this challenge a few assumptions were made.
First, the stream of requests is mimicked by the driver (`main.cpp`).
Second, the scheduler is handed over a pool of nodes to simulate an environment where many nodes are connecting to the scheduler.
The nodes and jobs also have their state randomly generated to simulate a more realistic environment.
With more time some threading concepts could be introduced, allowing the jobs to update the scheduler when work is done and to trigger the release of node resources.
Additionally, jobs could be structured a bit differently with this model.
For example, a hash map could be used to store a list of jobs with the key being the unique node identifier.
A more event-based model could be used as well for notifications to the scheduler and for resource releases.

## Building

`mkdir build && cd build && cmake .. && make`

## Scenario
As a fearless distributed systems engineer at Mesosphere, you have a great idea for a new resource-scheduling algorithm for large-scale data centers.
Assume that the current scheduler is a simple first-come, first-served model which doesn’t always yield optimal results.
To convince your co-workers of the merits of your new scheduler, you must write a simulator that demonstrates how your scheduler outperforms the default on at least one set of test data.

## INPUTS
Available resources can be represented as a stream of tuples, for example:

(2 3) (7 1) (1 23) (8 5) (2 8)

Which should be interpreted as:

3 resource units are available on compute node #2,

1 resource unit is available on compute node #7,

23 resource units are available on compute node #1,

and so on.

Resource units from a single compute node may appear multiple times in the stream.

As these resources become available, the scheduler assigns them to incoming jobs of various sizes and durations.
For example, a job of size two requires two units from the resource stream to run.
Incoming job requests can be represented as an stream of tuples, for example:

(3 4) (1 4) (4 7) (1 3) (5 4) (9 3)

Which should be interpreted as:

Job #1 needs 3 resource units for 4 time steps,

Job #2 needs 1 resource units for 4 time steps,

Job #3 needs 4 resource units for 7 time steps,

and so on. Note that job requests cannot span compute nodes.

## OUTPUT
To prove that your scheduling algorithm satisfies its objective, print out the final schedule and any useful statistics under way. 
That may be enough to convince your co-workers, but please elaborate on how to interpret the simulator output.
