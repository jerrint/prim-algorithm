#include<iostream>
#include "primMatrix.h"
#include "primsAdjacencyList.h"
#include <chrono>
using namespace std;
using namespace std::chrono; 

int main(){
	int numVertices = 5;
	primMatrix aGraph;
	primsAdjacencyList aList;
	int graph[numVertices][numVertices] = { { 0, 2, 0, 6, 0 },
		   	    { 2, 0, 3, 8, 5 },
		   	    { 0, 3, 0, 0, 7 },
		   	    { 6, 8, 0, 0, 9 },
		   	    { 0, 5, 7, 9, 0 } };
	vector<vector<int>> g;
	

	vector<pair<int,int>> adjacent[numVertices];
	
	for (int i=0; i<numVertices; i++) {
		vector<int> v;
		for (int j=0; j<5; j++) {
			v.push_back(graph[i][j]);
			if(i!=j && graph[i][j]!= 0){
				aList.addEdge(adjacent , i , j, graph[i][j]);
			}
		}
		g.push_back(v);
	}
	printf("====================\nADJACENCY MATRIX REPRESENTATION WITHOUT PRIORITY QUEUE\n====================\n");
	auto start = high_resolution_clock::now(); 
	aGraph.primMatrixWithoutPriorityQ(g);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Duration in microseconds=" << duration.count() << endl;
	
	
	vector<int> adjacentSolution;
	auto start1 = high_resolution_clock::now(); 
	adjacentSolution = aList.prims(adjacent, numVertices);
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
	

	for(int i = 0; i<numVertices-1; i++){
		if(i == 0) printf("====================\nADJACENCY LIST REPRESENTATION WITH PRIORITY QUEUE\n====================\n");
		printf("Parent: %d Vertex: %d\n", adjacentSolution[i+1], i+1);
	}
	cout << "Duration in microseconds=" << duration1.count() << endl;
	return 0;
}
