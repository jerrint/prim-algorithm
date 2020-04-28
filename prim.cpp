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
	int numVertices[] = {100,200,300,400,500,600,700,800,900,1000};

	vector<primMatrix> matrixg(20);
	vector<primsAdjacencyList> Lists(20);
	for(unsigned int i =0 ; i < matrixg.size(); i++) {
		primMatrix aMatrix;
		primsAdjacencyList aList;
		matrixg.push_back(aMatrix);
		Lists.push_back(aList);
	}

	/* = 	  { { 0, 2, 0, 6, 0 },
		   	    { 2, 0, 3, 8, 5 },
		   	    { 0, 3, 0, 0, 7 },
		   	    { 6, 8, 0, 0, 9 },
		   	    { 0, 5, 7, 9, 0 } };
		   	 */
	vector<vector<vector<int>>> sparseinputs (10);
	vector<vector<vector<int>>> denseinputs (10);

	//SPARSE GRAPH TESTS
	for(unsigned int i = 0; i < sparseinputs.size(); i++){
		vector<vector<int>> matrix(numVertices[i]);
		int valcopy;
		for(int j = 0; j < numVertices[i]-1; j++){
			vector<int> row(numVertices[i],0);	
			if(j>0) row.at(j-1) = valcopy;
			int random = (rand() %10) +1;
			row.at(j+1) = random;
			valcopy = random;
			matrix.push_back(row);
		}
		sparseinputs.push_back(matrix);
	}
	//DENSE GRAPH TESTS assign top right diagonal values
	for(unsigned int i = 0; i < denseinputs.size(); i++){
		vector<vector<int>> matrix(numVertices[i]);
		for(int j = 0; j < numVertices[i]-1; j++){
			vector<int> row(numVertices[i],0);
			for(int k = j+1; k < numVertices[i]; k++){
				int random = (rand() %10) +1;
				row.at(k) = random;
			}	
			matrix.push_back(row);
		}
		denseinputs.push_back(matrix);
	}
	//mirror the top right vaues to bottom left diagonal (undirected mutual weight graph)
	for(unsigned int i = 0; i < denseinputs.size(); i++){
		for(int j = 0; j < numVertices[i] -1; j++){
			for(int k = j+1; k < numVertices[i]; k++){
				denseinputs.at(i).at(k).at(j) = denseinputs.at(i).at(j).at(k);
			}
		}
	}
	
	vector<vector<vector<int>>> mat(20); //g1, g2, g3, g4, g5, g6, g7, g8;
	vector<pair<int,int>> adjacent1[numVertices[0]], adjacent2[numVertices[1]], adjacent3[numVertices[2]], adjacent4[numVertices[3]], adjacent5[numVertices[4]], adjacent6[numVertices[5]], adjacent7[numVertices[6]], adjacent8[numVertices[7]], adjacent9[numVertices[8]], adjacent10[numVertices[9]], adjacent11[numVertices[0]], adjacent12[numVertices[1]], adjacent13[numVertices[2]], adjacent14[numVertices[3]], adjacent15[numVertices[4]], adjacent16[numVertices[5]], adjacent17[numVertices[6]], adjacent18[numVertices[7]], adjacent19[numVertices[8]], adjacent20[numVertices[9]]; 
	
	for (unsigned int i=0; i<mat.size(); i++) {
		vector<vector<int>> v;
		for (int j=0; j<numVertices[i]; j++) {
			vector<int> row;
			for(int k = 0; k < numVertices[i]; k++){
				if(i < 10){
					row.push_back(sparseinputs.at(i).at(j).at(k));
					if(j!=k && sparseinputs.at(i).at(j).at(k) != 0){
						if(i == 0) Lists.at(i).addEdge(adjacent1 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==1) Lists.at(i).addEdge(adjacent2 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==2) Lists.at(i).addEdge(adjacent3 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==3) Lists.at(i).addEdge(adjacent4 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==4) Lists.at(i).addEdge(adjacent5 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==5) Lists.at(i).addEdge(adjacent6 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==6) Lists.at(i).addEdge(adjacent7 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==7) Lists.at(i).addEdge(adjacent8 , j , k, sparseinputs.at(i).at(j).at(k));
						else if(i ==8) Lists.at(i).addEdge(adjacent9 , j , k, sparseinputs.at(i).at(j).at(k));
						else Lists.at(i).addEdge(adjacent10 , j , k, sparseinputs.at(i).at(j).at(k));
					}
				}
				else {
					row.push_back(denseinputs.at(i-10).at(j).at(k));
					if(j!=k && denseinputs.at(i).at(j).at(k)!= 0){
						if(i == 0) Lists.at(i).addEdge(adjacent11 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==1) Lists.at(i).addEdge(adjacent12 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==2) Lists.at(i).addEdge(adjacent13 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==3) Lists.at(i).addEdge(adjacent14 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==4) Lists.at(i).addEdge(adjacent15 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==5) Lists.at(i).addEdge(adjacent16 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==6) Lists.at(i).addEdge(adjacent17 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==7) Lists.at(i).addEdge(adjacent18 , i , j, denseinputs.at(i).at(j).at(k));
						else if(i ==8) Lists.at(i).addEdge(adjacent19 , i , j, denseinputs.at(i).at(j).at(k));
						else Lists.at(i).addEdge(adjacent20 , i , j, denseinputs.at(i).at(j).at(k));
					}
				}

			}
			v.push_back(row);
		}
		mat.push_back(v);
	}
	/*
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
	
	for(int i = 0; i<numVertices-1; i++){
		if(i == 0) printf("====================\nADJACENCY LIST REPRESENTATION WITH PRIORITY QUEUE\n====================\n");
		printf("Parent: %d Vertex: %d\n", adjacentSolution[i+1], i+1);
	}
	
	cout<<"====================\nADJACENCY LIST REPRESENTATION WITH PRIORITY QUEUE\n====================\n";
	cout << "Sparse Graph1: Duration in microseconds=" << duration8.count() << endl;
	cout << "Sparse Graph2: Duration in microseconds=" << duration9.count() << endl;
	cout << "Sparse Graph3: Duration in microseconds=" << duration10.count() << endl;
	cout << "Sparse Graph4: Duration in microseconds=" << duration11.count() << endl;
	cout << "Dense Graph1: Duration in microseconds=" << duration12.count() << endl;
	cout << "Dense Graph2: Duration in microseconds=" << duration13.count() << endl;
	cout << "Dense Graph3: Duration in microseconds=" << duration14.count() << endl;
	cout << "Dense Graph4: Duration in microseconds=" << duration15.count() << endl;
	*/
	return 0;
}
