#include <bits/stdc++.h>
using namespace std;
#define V 5

int smallestVertex(int key[], bool mst[]) {
  int smallest = INT_MAX;
  int index;
  for (int i=0; i<V; i++) {
    if (mst[i] == false && key[i] < smallest) {
      smallest = key[i];
      index = i;
    }
  }
  return index;
}

void printMST(int key[], int parent[]) {
  for (int i=1; i<V; i++) {
    cout << "Parent: " << parent[i] << " Vertex: " << i << ", Distance: " << key[i] << endl;
  }
}

void primMatrixWithoutPriorityQ(int Graph[V][V]) {
  int key[V], parent[V];
  bool mst[V];
  for (int i=0; i<V; i++) {
    key[i] = INT_MAX;
    mst[i] = false;
  }
  key[0] = 0;
  for (int i=0; i<V-1; i++) {
    int u = smallestVertex(key, mst);
    mst[u] = true;
    for (int v=0; v<V; v++) {
      if (Graph[u][v] != 0 && mst[v] == false && Graph[u][v] < key[v]) {
        key[v] = Graph[u][v];
        parent[v] = u;
      }
    }
  }
  printMST(key, parent);
}

int main() {
  int Graph[5][5] = {
    {0, 3, 4, 1, 5},
    {3, 0, 2, 3, 2},
    {4, 2, 0, 7, 8},
    {1, 3, 7, 0, 0},
    {5, 2, 8, 0, 0}
  };
  primMatrixWithoutPriorityQ(Graph);
}
