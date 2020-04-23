#include "primsAdjacencyList.h"
using namespace std;


	//add edges in form addEdge(adjacentVect to store edges, souce vert, destination vert, weight);
	//best to add edges in order starting with node 0

	/*addEdge(adjacent, 0,1,4);
	addEdge(adjacent, 0,7,8);
	addEdge(adjacent, 1,2,8);
	addEdge(adjacent, 1,7,11);
	addEdge(adjacent, 2,3,7);
	addEdge(adjacent, 2,8,2);
	addEdge(adjacent, 2,5,4);
	addEdge(adjacent, 3,4,9);
	addEdge(adjacent, 3,5,14);
	addEdge(adjacent, 4,5,10);
	addEdge(adjacent, 5,6,2);
	addEdge(adjacent, 6,7,1);
	addEdge(adjacent, 6,8,6);
	addEdge(adjacent, 7,8,7);*/
/*
int main(){
	

	int numVertices = 10;
	
	vector<pair<int,int>> adjacent[numVertices];

	
	addEdge(adjacent, 0,1,3);
	addEdge(adjacent, 0,3,4);
	addEdge(adjacent, 0,4,4);
	addEdge(adjacent, 1,2,10);
	addEdge(adjacent, 1,4,2);
	addEdge(adjacent, 1,5,3);
	addEdge(adjacent, 2,5,6);
	addEdge(adjacent, 2,6,1);
	addEdge(adjacent, 3,4,5);
	addEdge(adjacent, 3,7,6);
	addEdge(adjacent, 4,7,2);
	addEdge(adjacent, 4,5,11);
	addEdge(adjacent, 4,8,1);	
	addEdge(adjacent, 5,6,2);
	addEdge(adjacent, 5,8,3);
	addEdge(adjacent, 5,9,11);
	addEdge(adjacent, 6,9,8);
	addEdge(adjacent, 7,8,4);
	addEdge(adjacent, 8,9,7);
	
	vector<int> parent;
	parent = prims(adjacent,numVertices);
	
	for(int i = 0; i<numVertices-1; i++){
		printf("%d - %d\n", parent[i+1], i+1);
	}
	
	return 0;
}
*/
vector<int> primsAdjacencyList::prims(vector<pair<int,int>>adjacent[], int numV){
	//numV is the number of nodes in our graph
	//adj[]s first value is the current node key, adj[]s second val is the current nodes edge weight
	
	
	//by default a PQ is a max heap, so we must change it to implement a min heap.
	//priority queue used to implement a min heap, syntax is 
	//priority_queue< Type, vector<Type>, comparison(we use "greater" for min heap)
	
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> priorityQ;
	
	vector<int> parent(numV, -1); //will contain the "current" MST, index is node number, value is node with lowest edge weight it connects to.
	vector<bool> inMinimumSpanningTree(numV, false); //initialize all nodes as not in MST
	vector<int> weights(numV, INT_MAX); //set initial weight to INF (in this case largest int value)
	
	pair<int, int> sourcePair = make_pair(0, 0);//second value is 0 because our source node is 0
	priorityQ.push(sourcePair);
	
	weights[0] = 0; //weights[sourceNode]
	
	while(priorityQ.empty() == false){//while there are still unvisited nodes
	
		int currentMin = priorityQ.top().second;
		priorityQ.pop();
		
		inMinimumSpanningTree[currentMin] = true; //node is now in MST
		
		for(auto x = adjacent[currentMin].begin(); x!= adjacent[currentMin].end(); x++){
			//x->first is the current node key, x->second is the current nodes minimum edge weight
			int weight = x->second;
			
			if(inMinimumSpanningTree[x->first]==false){//if current node is not yet in MST
				if(weight< weights[x->first]){//if the new weight is less than the current weight
					weights[x->first]= weight;//update new weight
					pair<int, int> newPair = make_pair(weights[x->first],x->first);//update priority queue
					priorityQ.push(newPair);
					parent[x->first] = currentMin; //save node with current smallest edge
				}
			}
		}
	}
	return parent;
}

void primsAdjacencyList::addEdge(vector<pair<int,int>> adjacent[], int src, int dest, int weight){
	//adds an edge to our adjacency list
	//pairs include the node key we are going to, followed by the weight of the edge between the two nodes
	pair<int, int> sourcePair = make_pair(dest, weight);
	pair<int, int> destPair = make_pair(src, weight);
	adjacent[src].push_back(sourcePair);
	adjacent[dest].push_back(destPair);
	
}







