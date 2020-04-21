#include <bits/stdc++.h>
#include <vector>
using namespace std;

int smallestVertex(vector<int> key, vector<bool> mst) {
  int smallest = INT_MAX;
  int index;
  for (int i=0; i<key.size(); i++) {
    if (mst.at(i) == false && key.at(i) < smallest) {
      smallest = key.at(i);
      index = i;
    }
  }
  return index;
}

void printMST(vector<int> key, vector<int> parent) {
  for (int i=1; i<key.size(); i++) {
    cout << "Parent: " << parent.at(i) << " Vertex: " << i << ", Distance: " << key.at(i) << endl;
  }
}

void primMatrixWithoutPriorityQ(vector<vector<int>> Graph) {
  vector<int> key;
  vector<int> parent;
  vector<bool> mst;
  for (int i=0; i<Graph.at(0).size(); i++) {
    key.push_back(INT_MAX);
    mst.push_back(false);
    parent.push_back(-1);
  }
  key.at(0) = 0;
  for (int i=0; i<Graph.at(0).size()-1; i++) {
    int u = smallestVertex(key, mst);
    mst.at(u) = true;
    for (int v=0; v<Graph.at(0).size(); v++) {
      if (Graph.at(u).at(v) != 0 && mst.at(v) == false && Graph.at(u).at(v) < key.at(v)) {
        key.at(v) = Graph.at(u).at(v);
        parent.at(v) = u;
      }
    }
  }
  printMST(key, parent);
}

int main() {
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
  primMatrixWithoutPriorityQ(g);
}
