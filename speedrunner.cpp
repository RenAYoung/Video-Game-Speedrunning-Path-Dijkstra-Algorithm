/*
AUTHOR: Ren Young
DATE: December 2, 2020
CLASS: CS 315 - 001
PROJECT: Final Project
COMPILATION: g++ -o sr speedrunner.cpp
SYNOPSIS: Video game speed running path finder
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

	//Dijkstra starts

	//set up some necessary variables
	//create visited vertex list - 0 respresents unvisited, 1 represents visited
	int visit[nodes];
	//prev array to hold previous node in shortest path
	int prev[nodes];
	//create set of distances
	int dist[nodes];
	//count for controlling number of iterations looking at nodes
	int count = 1;
	//curr_min_dist for holding the current min distance for comparison
	int curr_min_dist;
	//next_node to indicate what node to look at next
	int next_node;
	
	//loop and replace all zeros in the graph with INF
	for (int i = 0; i < nodes; i++) {
		for (int j = 0 ; j < nodes; j++) {
			if(graph[i][j] == 0)
				graph[i][j] = INF;
		}
	}

	//set up default distance and visited info
	for (int i = 0; i < nodes; i++) {
		//set all distances to the current distance value from the start
		dist[i] = graph[start][i];
		//set info for current node to visited list
		visit[i] = 0;
		//set info for previous node default
		prev[i] = start;
	}
	//set up info for start vertex
	dist[start] = 0;
	visit[start] = 1;  

	//loop while there are unvisited nodes
	while (count < nodes-1) {
		//reset the current minimum distance
		curr_min_dist = INF;
		//find node with current smallest distance which hasn't been visited
		for (int i = 0; i < nodes; i++) {
			if ((dist[i] < curr_min_dist) && (visit[i] != 1)) { 
				next_node = i;
				curr_min_dist = dist[i];
			}
		}
		//note that the next node is being visited
		visit[next_node] = 1;		
		//loop through unvisited nodes for comparing distances
		for (int i = 0; i < nodes; i++) {
			int new_dist = curr_min_dist + graph[next_node][i];
			//if the new distance is smaller than the previous distance to the current neighbor
			if (new_dist < dist[i]) {
				//set the distance to the new distance if it's smaller
				dist[i] = new_dist;
				//set the previous node info to the current min dist node being evaluated
				prev[i] = next_node;
			}
		}
		count++;
	}

	//start displaying info
	cout << "Shortest Path: " << endl;
	int prev_node = prev[end];
	int node_list[nodes];
	int count2 = 1;
	node_list[0] = end;
	while (prev_node != start) {
		//add node to list for printing, starting at the end node
		node_list[count2] = prev_node;
		//set the current node to the previous node
		prev_node = prev[prev_node];
		count2++;
	}	
	//add start value to list
	if (start != end) {
		node_list[count2] = start;
		count2++;
	}
	//print node values in order
	for (int i = count2-1; i > 0; i--) {
		cout << node_list[i] << " -> ";
	}	
	cout << end << endl;
}







