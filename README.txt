AUTHOR: Ren Young
DATE: December 2, 2020
CLASS: CS 315 - 001
PROJECT: Final Project
COMPILATION: g++ -o sr speedrunner.cpp
RUNNING: ./sr < filename
SYNOPSIS: Video game speed runner shortest path finder using Dijkstra's algorithm
TEST FILES: 
minecraft.txt - represents simplified version of graph based on minecraft speedrunning actions
	Expected output: 
		Shortest Path:
		0 -> 1 -> 6 -> 13 -> 21 -> 24 -> 28 -> 30 -> 35 -> 36 -> 37 -> 38
candycrush.txt - represents piece of candy crush game
	Expected output:  
		Shortest Path: 
		0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
EXPECTED FORMAT: (for text files fed in - all ints)
#nodes #edges startnode endnode
//#edges lines follow, format: 
	node1 node2 weight
