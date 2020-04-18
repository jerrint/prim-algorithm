int smallestVertex(int key[], int mst[]) {
  int smallest = INT_MAX;
  int index;
  for (int i=0; i<key.size; i++) {
    if (mst[i] == false && key[i] < smallest) {
      smallest = key[i];
      index = i;
    }
  }
  return i;
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
}

int main() {
  primMatrixWithoutPriorityQ();
}
