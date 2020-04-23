#include<iostream>
#include "primMatrix.h"
#include "primsAdjacencyList.h"
using namespace std;

int main(){
	primMatrix aGraph;
  int graph[5][5] = { { 0, 2, 0, 6, 0 },
                    { 2, 0, 3, 8, 5 },
                    { 0, 3, 0, 0, 7 },
                    { 6, 8, 0, 0, 9 },
                    { 0, 5, 7, 9, 0 } };
  vector<vector<int>> g;
  for (int i=0; i<5; i++) {
    vector<int> v;
    for (int j=0; j<5; j++) {
      v.push_back(graph[i][j]);
    }
    g.push_back(v);
  }
  aGraph.primMatrixWithoutPriorityQ(g);
  return 0;
}
