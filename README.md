To compile: make all
To run: make run
Data Structures Used:
	Priority Queue for prim adjacency list (standard implementation from c++ library)
	Vectors in all cpp files (standard implementation from c++ library)
	Arrays (c++ implementation)
	Pair (Standard c++ library)
Computation Time for primMatrix
	O(V) for smallest vertex 
	O(V * log|E|) but E = |V| for adjacency matrix therfore thr time complexity becomes O(V^2)
Computation Time for primAdjacencyList
	O(logV) for pop function loop happens V times so complexity becmoes O(VlogV)
	O(logV) to make a new pair and push to the priority queue loop happens E times so complexity becomes O(ElogV)
	Total complexity = O(VlogV) + O(ElogV) = O((E+V)logV) = O(ElogV)
Computation Time for prim.cpp
	Constant time because the for loops do not rely on any inputs 
	Each for loop occurs a set amount of time and is not dependent on any input
Classes Used:
	primMatrix- Matrix representation without priority queue 
	primAdjacency List - Adjacency List representation with priority queue 

