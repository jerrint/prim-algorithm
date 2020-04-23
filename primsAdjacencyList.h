#ifndef PRIMSADJACENCYLIST_H
#define PRIMSADJACENCYLIST_H
#include<vector>
#include <bits/stdc++.h>
class primsAdjacencyList{
public:
	void addEdge(std::vector<std::pair<int,int>> adjacent[], int src, int dest, int weight);
	std::vector<int> prims(std::vector<std::pair<int,int>>adjacent[], int numV);
};
#endif

