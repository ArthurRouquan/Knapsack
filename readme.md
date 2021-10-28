# 0/1 Knapsack Problem Algorithms

Implementation in C++20 of algorithms to solve the 0/1 [Knapsack Problem](https://www.wikiwand.com/en/Knapsack_problem). It was made for educational purposes.

## Usage

This project uses CMake. To run the executable you need to pass an instance folder. If you don't, it runs a minimal example.

```
$ knapsack ../instances/large/
/* ... */

$ knapsack
Minimal example:
Items: [ (6,2) (5,3) (8,6) (9,7) (6,5) (7,9) (3,4) ] 
Capacity: 15

Solution: [ 1 0 1 1 0 0 0 ]
Profit: 23
Weight: 15
```

## Implemented Algorithms

* `bellman` solves an instance with dynamic programming scheme. Items doesn't have to be sorted. Doesn't build the entire table, only works with one column.
* `bb_best_first_seach` solves an instance using a primal Branch & Bound, Best First Search. Items are expected to be sorted by increasing efficiency. It uses two tricks to speed up the process:
  * Nodes whose the residual capacity is strictly less than the minimum weight among the remaining items are eluded.
  * The upper bound is calculated in quasi-linear time with a dichotomic search.

## References

1. Hans Kellerer, Ulrich Pferschy, David Pisinger, *Knapsack Problems* https://www.doi.org/10.1007/978-3-540-24777-7 (2004)
