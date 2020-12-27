# Topics in Competitive Coding for IITK Placements

Here are some topics which I think are essential for the coding tests conducted during placements. 
[CP-Algorithms](https://cp-algorithms.com/) is a good place to study these topics and I have given links to the few topics which are not available there. 


##  Dynamic Programming
Solve [AtCoder's educational DP contest](https://atcoder.jp/contests/dp). Errichto has a [5 hour-long video](https://www.youtube.com/watch?v=FAQxdm0bTaw&ab_channel=Errichto) on YouTube in which he solves all the questions. See the full video even if you solved the questions. You might leave a few DP problems at the end but most of them are quite useful.

- [Digit DP](https://codeforces.com/blog/entry/53960) (**Remind me to add few Digit DP codes in the folder**). 
- Prefix sum trick (AtCoder DP contest).
- Space optimization (Necessary in certain knapsack variants).


## Number Theory

It's a good idea to go through the theory behind these algorithms as they are sometimes useful in quant problems.

- GCD and Extended GCD.
- Sieve of Eratosthenes.
- Modular inverse.
- Linear congruence equation.
- Factorial modulo a prime `p`.

## Graphs

In this section, I will list down the topics for general graphs (both directed and undirected). Trees will be covered in another section as it is a huge topic on its own. 

- BFS and DFS.
- Connected component of an undirected graph (can be done with both BFS and DFS but very important concept).
- Strongly connected components. 
- Topological Sorting (Standard and [Kahn's Algorithm](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)).
- Bridges and articulation points.
- Shortest paths
  - Dijkstra and **0-1 BFS** (Rare but very easy once you have seen it),
  - Bellman-Ford,
  - Floyd-Warshall.
- Minimum Spanning Tree
  - Prim,
  - Kruskal (with DSU).
- Cycle Finding (Both directed and undirected).

## Trees

In coding tests, you will be given trees as a general graph and all the regular graph algorithms apply in that case. Binary trees (nodes with left and right pointers) are more common in interviews and have their own set of algorithms. 

### Binary Trees
**TO BE FILLED**

### General Trees
**TO BE FILLED**

## Disjoint Set Union

DSU is a very powerful structure which can be used to solve a variety of graph problems. The page on DSU at CP-algorithms has a comprehensive list of variations of DSU which can be used to tackle such problems.

## Strings

KMP is probably the only important algorithm in this topic but there are several ad hoc problem asked from this topic, so try to do a lot of questions from this topic. 

- Prefix function (KMP).
- Trie.

## Backtracking

There is nothing much to prepare here. Just solve all the problems available at GeeksForGeeks, InterviewBit and the inter-IIT Placement doc and it should be more than enough.

## Advanced

These are some advanced topics which are rarely asked by the companies. Study them only when you have completed everything above. I am listing them in the order of their relevance

- Fenwick tree / Binary indexed tree.
- Segment tree.
- Flows.
- Lazy propagation.
