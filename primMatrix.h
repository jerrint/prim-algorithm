#ifndef PRIMMATRIX_H
#define PRIMMATRIX_H
#include<vector>
#include <bits/stdc++.h>
class primMatrix{
public:
	int smallestVertex(std::vector<int> key, std::vector<bool> mst);
	void printMST(std::vector<int> key, std::vector<int> parent);
	void primMatrixWithoutPriorityQ(std::vector<std::vector<int>> Graph);
};
#endif

