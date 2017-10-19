/*
	Name: All paths between two vertices
	Copyright: Free Software
	Author: Leonardo Ospino
	Date: 19/10/17 10:00
	Description: Strudture of data II
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define SIZEGRAPH 30
#include "libraries/vertex.h"
#include "libraries/graph.h"

int main(){
	system("title All paths between two vertices (LEONARDO F. OSPINO)");
	Graph *g = new Graph(SIZEGRAPH);
	
	//Creating vertices
	g->newVertex("a");
	g->newVertex("b");
	g->newVertex("c");
	g->newVertex("d");
	g->newVertex("e");
	g->newVertex("f");
	
	//Creating arcs
	g->newArc("a","b",7);
	g->newArc("b","a",7);
	g->newArc("a","c",9);
	g->newArc("c","a",9);
	g->newArc("a","f",14);
	g->newArc("f","a",14);
	g->newArc("b","c",10);
	g->newArc("c","b",10);
	g->newArc("b","d",15);
	g->newArc("d","b",15);
	g->newArc("c","f",2);
	g->newArc("f","c",2);
	g->newArc("f","e",9);
	g->newArc("e","f",9);
	g->newArc("c","d",11);
	g->newArc("d","c",11);
	g->newArc("d","e",6);
	g->newArc("e","d",6);
	
	g->printVertices();
	g->printMatAdj();
	g->allPaths("a","e");
}
