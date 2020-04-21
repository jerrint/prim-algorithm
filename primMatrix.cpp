#include <bits>
#include <stdc++.h>
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

void printMST(vector<int> key[], vector<int> parent[]) {
  for (int i=1; i<key.size(); i++) {
    cout << "Parent: " << parent[i] << " Vertex: " << i << ", Distance: " << key[i] << endl;
  }
}

void primMatrixWithoutPriorityQ(vector<vector<int>> Graph) {
  vector<int> key;
  vector<int> parent;
  vector<bool> mst;
  for (int i=0; i<Graph.at(0).size(); i++) {
    key.at(i) = INT_MAX;
    mst.at(i) = false;
  }
  key.at(0) = 0;
  for (int i=0; i<Graph.at(0).size()-1; i++) {
    int u = smallestVertex(key, mst);
    mst.at(u) = true;
    for (int v=0; v<Graph.size(); v++) {
      if (Graph.at(u).at(v) != 0 && mst.at(v) == false && Graph.at(u).at(v) < key.at(v)) {
        key.at(u) = Graph.at(u).at(v);
        parent.at(v) = u;
      }
    }
  }
  printMST(key, parent);
}

int main() {
}
