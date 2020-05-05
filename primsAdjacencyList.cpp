#include "primsAdjacencyList.h"
using namespace std;

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







