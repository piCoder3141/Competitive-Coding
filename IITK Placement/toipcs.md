# Topics in Competitive Coding for IITK Placements

Here are some topics which I think are essential for the coding tests conducted during placements. 
[CP-Algorithms](https://cp-algorithms.com/) is a good place to study these topics and I have given links to the few topics which are not available there. 


##  Dynamic Programming
Solve [AtCoder's educational DP contest](https://atcoder.jp/contests/dp). Errichto has a [5 hour-long video](https://www.youtube.com/watch?v=FAQxdm0bTaw&ab_channel=Errichto) on YouTube in which he solves all the questions. See the full video even if you solved the questions. You might leave a few DP problems at the end but most of them are quite useful. 
- [Digit DP](https://codeforces.com/blog/entry/53960) (**Remind me to add few Digit DP codes in the folder**). 
- Prefix sum trick (AtCoder DP contest).
- Space optimization (Necessary in certain knapsack variants).


## Number Theory

[CP-Algorithms](https://cp-algorithms.com/) is a good place to study these topics. 

- GCD and Extended GCD.
- Sieve of Eratosthenes.
- Modular inverse.
- Linear congruence equation.
- Factorial modulo a prime `p`.

## Graph

In this section, I will list down the topics for general graphs (both directed and undirected). Trees will be covered in another section as it is a huge topic on its own. 

- BFS and DFS.
- Connected component of an undirected graph (can be done with both BFS and DFS but very important concept).
- Strongly connected components. 
- Topological Sorting (Standard and [Kahn's Algorithm](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/))
- Bridges and articulation points.
- Shortest paths
  - Dijkstra and **0-1 BFS** (Rare but very easy once you have seen it),
  - Bellman-Ford,
  - Floyd-Warshall.
- Minimum Spanning Tree
  - Prim,
  - Kruskal (with DSU).
- Cycle Finding (Both directed and undirected).

## Strings

KMP is probably the only important algorithm in this topic but there are several ad hoc problem asked from this topic, so try to do a lot of questions from this topic. 

- Prefix function (KMP).
- Trie.

## Backtracking

There is nothing much to prepare here. Just solve all the problems available at GeeksForGeeks, InterviewBit and the Inter-IIT Placement doc and it should be more than enough.

## Advanced

These are some advanced topics which are rarely asked by the companies. Study them only when you have completed everything above. I am listing them in the order of their relevance

- Fenwick tree / Binary indexed tree.
- Segment tree.
- Flows.
- Lazy propagation.
