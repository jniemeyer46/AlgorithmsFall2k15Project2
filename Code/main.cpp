#include "functions.h"
#include "Dijkstra.h"
#include "bfs.h"
/*
FIRST THINGS FIRST, an explanation of what the plan is for when I'm working on this
later. As with all great plans, this is subject to change (especially the names).

notes to know before reading our steps:
-we will be using three data structures called Path, Edge, and Vertex.
-Our Dijkstra will be modified to ignore all edges with weight -1 and modify some stuff.
-

1) Modify our input slightly so that all the nodes with no edges starting from them have an edge back to themselves with wight -1
    Normally I would say this is lowbrow, but it saves time and only has to work for one dataset. This project could be done without
    this step, but it would take longer.
2) Input our edges into our Edge DS from the input.txt file, storing them into an array (lets call it ReplaceableByMatrix, cuz it is).
    Quicksort this alphabetically by the StartVertex.
3) Make an array to hold the verteces (lets call it Vertical, because, reasons).
    Populate it by going through ReplaceableByMatrix (RBM).
    For the first edge of RBM, make a new Vertex with name =  RBM[0]StartVertex.
    For each other edge i in RBM, if RBM[i].StartVertex doesnt equal RBM[i-1].StartVertex, make a new Vertex with name RBM[i].StartVertex.
    These verteces should be in alphabetic order.
    When making these verteces, update RBM.StartIndex
4) Run through RBM getting the EndIndex (or whatever we end up calling it) using a binary search of Vertical
5) Create a matrix for the edges (lets call it Edgy to describe how the class makes some students feel)
    Populate it by going through RBM and coppieng each entry into the proper location (based on the StartIndex and EndIndex)
    This is, in practice, just an adjacency matrix.
    As it populates, it will also update the verices InDegree and OutDegree.
6) Create a matrix of Path elements called Paths (because it's getting late and I'm out of good names).
7) Okay,here is where you run the modified Dijkstra (or BFS). For each path found, our Dijkstra (or BFS) will:
    a: Put the parent of the vertex added to the solution into the proper entry on Paths
        (so if a path goes A -> B -> C, Paths[A][C] would contain B.)
    b: Call a recursive algorithm that incriments all edges used.
        (example above would go to Paths[A][C] and see B, incriment the edge from B to C, and then call
            itself on Paths[A][B] and continue until it sees that it would be calling itself on Paths[A][A])
    c: Update verious stats on the vertices based on if this is the Weighted/Unweighted Directed/Undirected run.
8) Mark the most used edge as not open (there is a bool for this).
    If there is a tie hightest centrality, mark all of them.
9) Repeat 4x (so, five total itterations)

Upon closer inspection, it looks like the majority of the stats are for the unweighted graphs. However
we get extra credit for fining "Additional interesting information." So maybe doing this for weighted
as well would count.

At verious points through this we will be outputting some information so that we can make graphs out of it later.
*/
int main(){
    cout << "Is this even happening right now? " << endl;
    //declare consts and veriables
    const int NUM_VERTEX = 547;
    const int NUM_EDGE = 1957;
    const int WEIGHTED_IN_MAX = 2046;
    const int WEIGHTED_OUT_MAX = 2865;
    const int UNWEIGHTED_IN_MAX = 54;
    const int UNWEIGHTED_OUT_MAX = 52;
    int KickedByUU, KickedByDu; //Denotes how many edges are kicked by community dectection.
    cout << "Well, there I went" << endl;

    Edge RBM[NUM_EDGE];

    cout << "well, here we go" << endl;
    static Edge Edgy[NUM_VERTEX][NUM_VERTEX];

    Vertex Vertical[NUM_VERTEX];
    static Path theWay[NUM_VERTEX][NUM_VERTEX];

    cout << "Do I get here?" << endl;

    //setting up arrays and matrixes
    edgeArrayInit(RBM, NUM_EDGE);
    cout << "edge array initialized" << endl;
    vertArrayInit(Vertical, NUM_EDGE, RBM);
    cout << "vertex array initialized" << endl;
    redPill(Edgy, RBM, Vertical, NUM_EDGE, NUM_VERTEX);
    undirect(Edgy);
    //find stats required for assignment
    degreeFinder(Vertical, Edgy, NUM_VERTEX);
    DegPrint(Vertical, WEIGHTED_IN_MAX, WEIGHTED_OUT_MAX, UNWEIGHTED_IN_MAX, UNWEIGHTED_OUT_MAX, NUM_VERTEX);
    //dijkstra
//    DW_dijkstra(theWay,Vertical, Edgy, NUM_VERTEX);
  //  UW_dijkstra(theWay, Vertical, Edgy, NUM_VERTEX);
    //bfs
    directed_BFS(Vertical, Edgy, theWay);
    undirected_BFS(Vertical, Edgy, theWay);
    ShortestPathDistroPrint(theWay, NUM_VERTEX, Vertical);
    cout << "\n \n \n \n \n \n \n \n"<< endl;

    bluePill(RBM, Edgy, NUM_EDGE);
    cout << "blue pill taken" << endl;
    UnweightedBetweennessDisplay(RBM, NUM_EDGE);
    KickedByUU = UU_Comunism(RBM, NUM_EDGE);
    KickedByDu = DU_Comunism(RBM, NUM_EDGE);

    //BFS

    return 0;
}

