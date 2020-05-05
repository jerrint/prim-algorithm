#include<iostream>
#include "primMatrix.h"
#include "primsAdjacencyList.h"
#include<stdlib.h>
#include<time.h>
#include <chrono>
#include<typeinfo>
using namespace std;
using namespace std::chrono; 
//TESTER
int main(){
	//builds 10 sparse and 10 dense graphs and tests them on both implementations with same randomized values for both implementations
	srand(time(0));
	int numVertices[10] = {100,200,300,400,500,600,700,800,900,1000}; //10 hardcoded sizes

	vector<primMatrix> matrixg; 
	vector<primsAdjacencyList> Lists;
	for(unsigned int i =0 ; i < 20; i++) {
		primMatrix aMatrix;
		primsAdjacencyList aList;
		matrixg.push_back(aMatrix);
		Lists.push_back(aList);
	}
	
	vector<vector<vector<int>>> sparseinputs;
	vector<vector<vector<int>>> denseinputs;

	//SPARSE GRAPH TESTS
	for(unsigned int i = 0; i < 10; i++){
		vector<vector<int>> matrix;
		int valcopy;
		for(int j = 0; j < numVertices[i]; j++){
			vector<int> row(numVertices[i],0);
			if(j>0) row.at(j-1) = valcopy;
			if (j == numVertices[i]-1){
				matrix.push_back(row);
				break;
			}	
			int random = (rand() %10) +1;
			row.at(j+1) = random;
			valcopy = random;
			matrix.push_back(row);
		}
		sparseinputs.push_back(matrix);
	}
	
	//DENSE GRAPH TESTS assign top right diagonal values
	for(unsigned int i = 0; i < 10; i++){
		vector<vector<int>> matrix;
		for(int j = 0; j < numVertices[i]; j++){
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
	for(unsigned int i = 0; i < 10; i++){
		for(int j = 0; j < numVertices[i]- 1; j++){
			for(int k = j+1; k < numVertices[i]; k++){
				denseinputs.at(i).at(k).at(j) = denseinputs.at(i).at(j).at(k);
			}
		}
	}
	
	vector<vector<vector<int>>> mat; //g1, g2, g3, g4, g5, g6, g7, g8;
	vector<pair<int,int>> adjacent1[numVertices[0]], adjacent2[numVertices[1]], adjacent3[numVertices[2]], adjacent4[numVertices[3]], adjacent5[numVertices[4]], adjacent6[numVertices[5]], adjacent7[numVertices[6]], adjacent8[numVertices[7]], adjacent9[numVertices[8]], adjacent10[numVertices[9]], adjacent11[numVertices[0]], adjacent12[numVertices[1]], adjacent13[numVertices[2]], adjacent14[numVertices[3]], adjacent15[numVertices[4]], adjacent16[numVertices[5]], adjacent17[numVertices[6]], adjacent18[numVertices[7]], adjacent19[numVertices[8]], adjacent20[numVertices[9]]; 
	//PUSHES the edges onto the corresponding implementaitons 
	int check = 0;
	for (unsigned int i=0; i<20; i++) {
		vector<vector<int>> v;
		for (int j=0; j<numVertices[check]; j++) {
			vector<int> row;
			for(int k = 0; k < numVertices[check]; k++){
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
					if(j!=k && denseinputs.at(i-10).at(j).at(k)!= 0){
						if(i == 10) Lists.at(i).addEdge(adjacent11 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==11) Lists.at(i).addEdge(adjacent12 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==12) Lists.at(i).addEdge(adjacent13 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==13) Lists.at(i).addEdge(adjacent14 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==14) Lists.at(i).addEdge(adjacent15 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==15) Lists.at(i).addEdge(adjacent16 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==16) Lists.at(i).addEdge(adjacent17 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==17) Lists.at(i).addEdge(adjacent18 , j , k, denseinputs.at(i-10).at(j).at(k));
						else if(i ==18) Lists.at(i).addEdge(adjacent19 , j , k, denseinputs.at(i-10).at(j).at(k));
						else Lists.at(i).addEdge(adjacent20 , j , k, denseinputs.at(i-10).at(j).at(k));
					}
				}

			}
			v.push_back(row);
		}
		mat.push_back(v);
		if(i ==9) check = -1;
		check++;
	}
	//PRINTS OUT HOW LONG IT TAKES
	vector<high_resolution_clock::time_point> starttimes;
	vector<high_resolution_clock::time_point> endtimes;
	printf("====================\nADJACENCY MATRIX REPRESENTATION WITHOUT PRIORITY QUEUE\n====================\n");
	for(unsigned int i = 0; i <20; i++){
		auto start = high_resolution_clock::now();
		matrixg.at(i).primMatrixWithoutPriorityQ(mat.at(i));
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		if(i<10)cout << "Sparse Graph "<< i+1<< ": Duration in microseconds=" << duration.count() << endl;
		else cout<<"Dense Graph "<< i-9<< ": Duration in microseconds=" << duration.count() << endl;
	}
	vector<microseconds> durations;
	vector<int> adjacentSolution;
	auto start1 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(0).prims(adjacent1, numVertices[0]);
	auto stop1 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop1 - start1)); 

	auto start2 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(1).prims(adjacent2, numVertices[1]);
	auto stop2 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop2 - start2)); 
	
	auto start3 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(2).prims(adjacent3, numVertices[2]);
	auto stop3 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop3 - start3)); 
	 
	auto start4 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(3).prims(adjacent4, numVertices[3]);
	auto stop4 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop4 - start4)); 
	
	auto start5 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(4).prims(adjacent5, numVertices[4]);
	auto stop5 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop5 - start5)); 

	auto start6 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(5).prims(adjacent6, numVertices[5]);
	auto stop6 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop6 - start6)); 

	auto start7 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(6).prims(adjacent7, numVertices[6]);
	auto stop7 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop7 - start7)); 
	
	auto start8 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(7).prims(adjacent8, numVertices[7]);
	auto stop8 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop8 - start8)); 

	auto start9 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(8).prims(adjacent9, numVertices[8]);
	auto stop9 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop9 - start9)); 
	
	auto start10 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(9).prims(adjacent10, numVertices[9]);
	auto stop10 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop10 - start10)); 
	
	auto start11 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(10).prims(adjacent11, numVertices[0]);
	auto stop11 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop11 - start11)); 
	
	auto start12 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(11).prims(adjacent12, numVertices[1]);
	auto stop12 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop12 - start12)); 
	
	auto start13 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(12).prims(adjacent13, numVertices[2]);
	auto stop13 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop13 - start13)); 
	
	auto start14 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(13).prims(adjacent14, numVertices[3]);
	auto stop14 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop14 - start14)); 
	
	auto start15 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(14).prims(adjacent15, numVertices[4]);
	auto stop15 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop15 - start15)); 
	
	auto start16 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(15).prims(adjacent16, numVertices[5]);
	auto stop16 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop16 - start16)); 
	
	auto start17 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(16).prims(adjacent17, numVertices[6]);
	auto stop17 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop17 - start17)); 
	
	auto start18 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(17).prims(adjacent18, numVertices[7]);
	auto stop18 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop18 - start18)); 
	
	auto start19 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(18).prims(adjacent19, numVertices[8]);
	auto stop19 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop19 - start19)); 
	
	auto start20 = high_resolution_clock::now(); 
	adjacentSolution = Lists.at(19).prims(adjacent20, numVertices[9]);
	auto stop20 = high_resolution_clock::now(); 
	durations.push_back(duration_cast<microseconds>(stop20 - start20)); 
	
	cout<<"====================\nADJACENCY LIST REPRESENTATION WITH PRIORITY QUEUE\n====================\n";
	for(unsigned int i = 0; i < 20; i ++){
		if (i < 10)cout<< "Sparse Graph" << i+1 << ": Duration in microseconds=" << durations.at(i).count() << endl;
		else cout<< "Dense Graph" << i-9 << ": Duration in microseconds=" << durations.at(i).count()<< endl;
	}
	
	return 0;
}
