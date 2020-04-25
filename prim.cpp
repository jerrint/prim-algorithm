#include<iostream>
#include "primMatrix.h"
#include "primsAdjacencyList.h"
#include<stdlib.h>
#include<time.h>
#include <chrono>
using namespace std;
using namespace std::chrono; 

int main(){
	srand(time(0));
	int numVertices1 = 5;
	int numVertices2 = 50;
	int numVertices3 = 100;
	int numVertices4 = 1000;
	primMatrix aGraph1, aGraph2, aGraph3, aGraph4, aGraph5, aGraph6, aGraph7, aGraph8;
	primsAdjacencyList aList1, aList2, aList3, aList4, aList5, aList6, aList7, aList8;
	/* = 	  { { 0, 2, 0, 6, 0 },
		   	    { 2, 0, 3, 8, 5 },
		   	    { 0, 3, 0, 0, 7 },
		   	    { 6, 8, 0, 0, 9 },
		   	    { 0, 5, 7, 9, 0 } };
		   	 */
	int sparsegraph1[numVertices1][numVertices1] = {0};		   	    
	int sparsegraph2[numVertices2][numVertices2] = {0};
	int sparsegraph3[numVertices3][numVertices3] = {0};
	int sparsegraph4[numVertices4][numVertices4] = {0};
	int densegraph1[numVertices1][numVertices1] = {0};
	int densegraph2[numVertices2][numVertices2] = {0};
	int densegraph3[numVertices3][numVertices3] = {0};
	int densegraph4[numVertices4][numVertices4] = {0};
	
	//SPARSE GRAPH TESTS
	for(int i = 0; i < numVertices1 -1; i++){
		int random = (rand() % 10) +1;
		sparsegraph1[i][i+1] = random;
		sparsegraph1[i +1][1] = random;
	}
	for(int i = 0; i < numVertices2 -1; i++){
		int random = (rand() % 10) +1;
		sparsegraph2[i][i+1] = random;
		sparsegraph2[i +1][1] = random;
	}
	for(int i = 0; i < numVertices3-1; i++){
		int random = (rand() % 10) +1;
		sparsegraph3[i][i+1] = random;
		sparsegraph3[i +1][1] = random;
	}
	for(int i = 0; i < numVertices4-1; i++){
		int random = (rand() % 10) +1;
		sparsegraph4[i][i+1] = random;
		sparsegraph4[i +1][1] = random;
	}
	//DENSE GRAPHS TESTS
	for(int i = 0; i < numVertices1; i++){
		for(int j = i+1; j < numVertices1; j++){		
			int random = (rand() %10) +1;
			densegraph1[i][j]	= random;
			densegraph1[j][i] = random;
		}
	}
	for(int i = 0; i < numVertices2; i++){
		for(int j = i+1; j < numVertices2; j++){		
			int random = (rand() %10) +1;
			densegraph2[i][j]	= random;
			densegraph2[j][i] = random;
		}
	}
	for(int i = 0; i < numVertices3-1; i++){
		for(int j = i+1; j < numVertices3; j++){		
			int random = (rand() %10) +1;
			densegraph3[i][j]	= random;
			densegraph3[j][i] = random;
		}
	}
	for(int i = 0; i < numVertices4; i++){
		for(int j = i+1; j < numVertices4; j++){		
			int random = (rand() %10) +1;
			densegraph4[i][j]	= random;
			densegraph4[j][i] = random;
		}
	}
	
	vector<vector<int>> g1, g2, g3, g4, g5, g6, g7, g8;
	vector<pair<int,int>> adjacent1[numVertices1], adjacent2[numVertices2], adjacent3[numVertices3], adjacent4[numVertices4], adjacent5[numVertices1], adjacent6[numVertices2], adjacent7[numVertices3], adjacent8[numVertices4];

	for (int i=0; i<numVertices1; i++) {
		vector<int> v;
		for (int j=0; j<numVertices1; j++) {
			v.push_back(sparsegraph1[i][j]);
			if(i!=j && sparsegraph1[i][j]!= 0){
				aList1.addEdge(adjacent1 , i , j, sparsegraph1[i][j]);
			}
		}
		g1.push_back(v);
	}
	for (int i=0; i<numVertices2; i++) {
		vector<int> v;
		for (int j=0; j<numVertices2; j++) {
			v.push_back(sparsegraph2[i][j]);
			if(i!=j && sparsegraph2[i][j]!= 0){
				aList2.addEdge(adjacent2 , i , j, sparsegraph2[i][j]);
			}
		}
		g2.push_back(v);
	}
	for (int i=0; i<numVertices3; i++) {
		vector<int> v;
		for (int j=0; j<numVertices3; j++) {
			v.push_back(sparsegraph3[i][j]);
			if(i!=j && sparsegraph3[i][j]!= 0){
				aList3.addEdge(adjacent3 , i , j, sparsegraph3[i][j]);
			}
		}
		g3.push_back(v);
	}
	for (int i=0; i<numVertices4; i++) {
		vector<int> v;
		for (int j=0; j<numVertices4; j++) {
			v.push_back(sparsegraph4[i][j]);
			if(i!=j && sparsegraph4[i][j]!= 0){
				aList4.addEdge(adjacent4 , i , j, sparsegraph4[i][j]);
			}
		}
		g4.push_back(v);
	}
	for (int i=0; i<numVertices1; i++) {
		vector<int> v;
		for (int j=0; j<numVertices1; j++) {
			v.push_back(densegraph1[i][j]);
			if(i!=j && densegraph1[i][j]!= 0){
				aList5.addEdge(adjacent5 , i , j, densegraph1[i][j]);
			}
		}
		g5.push_back(v);
	}
	for (int i=0; i<numVertices2; i++) {
		vector<int> v;
		for (int j=0; j<numVertices2; j++) {
			v.push_back(densegraph2[i][j]);
			if(i!=j && densegraph2[i][j]!= 0){
				aList6.addEdge(adjacent6 , i , j, densegraph2[i][j]);
			}
		}
		g6.push_back(v);
	}
	for (int i=0; i<numVertices3; i++) {
		vector<int> v;
		for (int j=0; j<numVertices3; j++) {
			v.push_back(densegraph3[i][j]);
			if(i!=j && densegraph3[i][j]!= 0){
				aList7.addEdge(adjacent7 , i , j, densegraph3[i][j]);
			}
		}
		g7.push_back(v);
	}
	for (int i=0; i<numVertices4; i++) {
		vector<int> v;
		for (int j=0; j<numVertices4; j++) {
			v.push_back(densegraph4[i][j]);
			if(i!=j && densegraph4[i][j]!= 0){
				aList8.addEdge(adjacent8 , i , j, densegraph4[i][j]);
			}
		}
		g8.push_back(v);
	}
	printf("====================\nADJACENCY MATRIX REPRESENTATION WITHOUT PRIORITY QUEUE\n====================\n");
	auto start = high_resolution_clock::now(); 
	aGraph1.primMatrixWithoutPriorityQ(g1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Sparse Graph1: Duration in microseconds=" << duration.count() << endl;
	
	auto start1 = high_resolution_clock::now(); 
	aGraph2.primMatrixWithoutPriorityQ(g2);
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
	cout << "Sparse Graph2: Duration in microseconds=" << duration1.count() << endl;
	
	auto start2 = high_resolution_clock::now(); 
	aGraph3.primMatrixWithoutPriorityQ(g3);
	auto stop2 = high_resolution_clock::now(); 
	auto duration2 = duration_cast<microseconds>(stop2 - start2); 
	cout << "Sparse Graph3: Duration in microseconds=" << duration2.count() << endl;

	auto start3 = high_resolution_clock::now(); 
	aGraph4.primMatrixWithoutPriorityQ(g4);
	auto stop3 = high_resolution_clock::now(); 
	auto duration3 = duration_cast<microseconds>(stop3 - start3); 
	cout << "Sparse Graph4: Duration in microseconds=" << duration3.count() << endl;
	
	auto start4 = high_resolution_clock::now(); 
	aGraph5.primMatrixWithoutPriorityQ(g5);
	auto stop4 = high_resolution_clock::now(); 
	auto duration4 = duration_cast<microseconds>(stop4 - start4); 
	cout << "Dense Graph1: Duration in microseconds=" << duration4.count() << endl;
	
	auto start5 = high_resolution_clock::now(); 
	aGraph6.primMatrixWithoutPriorityQ(g6);
	auto stop5 = high_resolution_clock::now(); 
	auto duration5 = duration_cast<microseconds>(stop5 - start5); 
	cout << "Dense Graph2: Duration in microseconds=" << duration5.count() << endl;
	
	auto start6 = high_resolution_clock::now(); 
	aGraph7.primMatrixWithoutPriorityQ(g7);
	auto stop6 = high_resolution_clock::now(); 
	auto duration6 = duration_cast<microseconds>(stop6 - start6); 
	cout << "Dense Graph3: Duration in microseconds=" << duration6.count() << endl;
	
	auto start7 = high_resolution_clock::now(); 
	aGraph8.primMatrixWithoutPriorityQ(g8);
	auto stop7 = high_resolution_clock::now(); 
	auto duration7 = duration_cast<microseconds>(stop7 - start7); 
	cout << "Dense Graph4: Duration in microseconds=" << duration7.count() << endl;
	

	vector<int> adjacentSolution;
	auto start8 = high_resolution_clock::now(); 
	adjacentSolution = aList1.prims(adjacent1, numVertices1);
	auto stop8 = high_resolution_clock::now(); 
	auto duration8 = duration_cast<microseconds>(stop8 - start8); 

	auto start9 = high_resolution_clock::now(); 
	adjacentSolution = aList2.prims(adjacent2, numVertices2);
	auto stop9 = high_resolution_clock::now(); 
	auto duration9 = duration_cast<microseconds>(stop9 - start9); 
	
	auto start10 = high_resolution_clock::now(); 
	adjacentSolution = aList3.prims(adjacent3, numVertices3);
	auto stop10 = high_resolution_clock::now(); 
	auto duration10 = duration_cast<microseconds>(stop10 - start10);
	 
	auto start11 = high_resolution_clock::now(); 
	adjacentSolution = aList4.prims(adjacent4, numVertices4);
	auto stop11 = high_resolution_clock::now(); 
	auto duration11 = duration_cast<microseconds>(stop11 - start11); 
	
	auto start12 = high_resolution_clock::now(); 
	adjacentSolution = aList5.prims(adjacent5, numVertices1);
	auto stop12 = high_resolution_clock::now(); 
	auto duration12 = duration_cast<microseconds>(stop12 - start12); 

	auto start13 = high_resolution_clock::now(); 
	adjacentSolution = aList6.prims(adjacent6, numVertices2);
	auto stop13 = high_resolution_clock::now(); 
	auto duration13 = duration_cast<microseconds>(stop13 - start13); 

	auto start14 = high_resolution_clock::now(); 
	adjacentSolution = aList7.prims(adjacent7, numVertices3);
	auto stop14 = high_resolution_clock::now(); 
	auto duration14 = duration_cast<microseconds>(stop14 - start14); 
	
	auto start15 = high_resolution_clock::now(); 
	adjacentSolution = aList8.prims(adjacent8, numVertices4);
	auto stop15 = high_resolution_clock::now(); 
	auto duration15 = duration_cast<microseconds>(stop15 - start15); 	
	/*
	for(int i = 0; i<numVertices-1; i++){
		if(i == 0) printf("====================\nADJACENCY LIST REPRESENTATION WITH PRIORITY QUEUE\n====================\n");
		printf("Parent: %d Vertex: %d\n", adjacentSolution[i+1], i+1);
	}
	*/
	cout<<"====================\nADJACENCY LIST REPRESENTATION WITH PRIORITY QUEUE\n====================\n";
	cout << "Sparse Graph1: Duration in microseconds=" << duration8.count() << endl;
	cout << "Sparse Graph2: Duration in microseconds=" << duration9.count() << endl;
	cout << "Sparse Graph3: Duration in microseconds=" << duration10.count() << endl;
	cout << "Sparse Graph4: Duration in microseconds=" << duration11.count() << endl;
	cout << "Dense Graph1: Duration in microseconds=" << duration12.count() << endl;
	cout << "Dense Graph2: Duration in microseconds=" << duration13.count() << endl;
	cout << "Dense Graph3: Duration in microseconds=" << duration14.count() << endl;
	cout << "Dense Graph4: Duration in microseconds=" << duration15.count() << endl;
	return 0;
}
