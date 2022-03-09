/*
AUTHOR:
DATE:
CLASS:
PROJECT:
COMPILATION:
SYNOPSIS:
BUGS:
*/


#include <bits/stdc++.h>
#define INF 9999
using namespace std;


int main() {
	//set up variables
	int nodes = -1, edges = -1, start = -1, end = -1;
	int curr_start = -1, curr_end = -1, weight = 0;

	//read in intro info
	cin >> nodes >> edges >> start >> end;

	//read in info for graph
	vector<vector<int>> graph(nodes, vector<int> (nodes));
	for (int i = 0; i < edges; i++) {
		cin >> curr_start >> curr_end >> weight;
		graph[curr_start][curr_end] = weight;
	}	

	//display graph for testing purposes
	/*
	for (int i = 0; i < nodes; i++) {
		cout << endl;
		for (int j = 0; j < nodes; j++) {
			cout << graph[i][j] << " ";
		}
	}
	*/

	int cost[nodes][nodes], distance[nodes], prev[nodes];
	int visit[nodes], count, mindistance, nextnode, i, j;
	for (i = 0; i < nodes; i++) {
		for (j = 0; j < nodes; j++) {
			if(graph[i][j] == 0) 
				cost[i][j] = INF;
			else
				cost[i][j] = graph[i][j];
		}
	}
	for (i = 0; i < nodes; i++) {
		distance[i] = cost[start][i];
		prev[i] = start;
		visit[i] = 0;
	}

	//cout << endl;

	distance[start] = 0;
	visit[start] = 1;
	count = 1;
	while(count < nodes-1) {
		mindistance = INF;
		for (i = 0; i < nodes; i++) {
			if((distance[i] < mindistance) && (visit[i] == 0)) {
				mindistance = distance[i];
				nextnode = i;
			}
		}
		visit[nextnode] = 1;
		for (i = 0; i < nodes; i++) {
			if (mindistance + cost[nextnode][i] < distance[i]) {
			distance[i] = mindistance + cost[nextnode][i];
			prev[i] = nextnode;
			}
		}
		count++;
	}

	//cout << endl;

	/*
	for(i = 0; i < nodes; i++) {
		if(i != start) {
			cout << "\nPath=" << i;
			j = i;
			do {
				j = prev[j];
				cout << "<-" << j;
			} while (j != start);
		}
	}

	cout << endl;

	*/
	//Dijkstra starts
	/*
	//create visited vertex list - 0 respresents unvisited, 1 represents visited
	int visit[nodes];

	//create set of distances
	int dist[nodes-1];
	for (int i = 0; i < nodes; i++) {
		//set all distances to the max int value
		dist[i] = INT_MAX;
		//set info for current node to visited list
		visit[i] = 0;
	}
	//set up info for start vertex
	dist[start] = 0;
	visit[start] = 1;

	//put values into distance based on known distance from start
	for (int i = 0; i < nodes; i++){
		if (graph[start][i] != 0)
			dist[i] = graph[start][i];
	}

	cout << endl;
	//print dist and visit for testing purposes
	for (int i = 0; i < nodes; i++) {
		cout << "dist[" << i << "]: " << dist[i] << endl;
		cout << "visit[" << i << "]: " << visit[i] << endl;
	}

	//create set for previous nodes info	
	int prev[nodes];
	prev[start] = start;

	//set up other variables needed for Dijkstra
	int curr_min = -1, count = 0, curr_min_dist, new_dist; 

	//loop while there are unvisited nodes
	while (count < nodes-1) {
		//get the node with the minimum distance that hasn't been visited
		curr_min_dist = INT_MAX;
		cout << endl << "test in loop" << endl;
		for (int i = 0; i < nodes; i++) {
			//cout << "dist[" << i << "]: " << dist[i] << endl;
			if ((dist[i] < curr_min_dist) && (visit[i] != 1)) { 
				curr_min = i;
				curr_min_dist = dist[i];
				//cout << "i: " << i << endl << "curr_min: " << curr_min << endl << "curr_min_dist: " << curr_min_dist << endl;
			}
		}
		cout << endl << "curr_min: " << curr_min;
		//note that the current node is being visited
		visit[curr_min] = 1;		
		//loop through unvisited nodes for comparing distances
		for (int i = 0; i < nodes; i++) {
			if (visit[i] != 1) {
				//get the potential distance through this path of nodes from the source
				new_dist = curr_min_dist + graph[curr_min][i];
				//if the new distance is smaller than the previous distance to the current neighbor
				if (new_dist < dist[i]) {
					//set the distance to the new distance if it's smaller
					dist[i] = new_dist;
					//set the previous node info to the current min dist node being evaluated
					prev[i] = curr_min;
				}
			}
		}
		count++;
	}
	
	cout << endl << "test out of loop" << endl;
*/
	/*
	for (int i = 0; i < nodes; i++) {
		cout << "distance[" << i << "]: " << distance[i] << endl;
		cout << "visit[" << i << "]: " << visit[i] << endl;
		cout << "prev[" << i << "]: " << prev[i] << endl;
	}
	*/
	
		
	//display info 
	cout << "Shortest Path: " << endl;
	int prev_node = prev[end];
	int node_list[nodes];
	int count2 = 1;
	node_list[0] = end;		
	while (prev_node != start) {
		//print node for current step, starting at the end node
		//cout << endl << prev_node;
		node_list[count2] = prev_node;
		//set the current node to the previous node
		prev_node = prev[prev_node];
		count2++;
	}	
	//cout << "start: " << start << endl;
	if(start != end) {
		node_list[count2] = start;
		count2++;
	}
	for (int i = count2-1; i > 0; i--) {
		cout << node_list[i] << " -> ";
	}
	cout << end << endl;
	//cout << "count2: " << count2 << endl;
}







