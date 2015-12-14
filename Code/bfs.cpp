#include "bfs.h"

const int vertices = 547;

void directed_BFS(Vertex array[], Edge d_edge[][vertices], Path d_path[][vertices])
{
    Vertex parent;
    queue<Vertex> path;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0; x < vertices; x++){
        //Creating the queue, place starting element into the queue
        path.push(array[x]); //queue
        parent = path.front();
        array[x].DU_Found = true;
        d_path[x][x].DU_Parent = x;
        d_path[x][x].DU_Weight = 0;
        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty() && parent.index !=-1){
            parent = path.front();
            for(int s = 0; s < vertices; s++){
                if(parent.index != -1
                &&d_edge[parent.index][s].Dweight != -1
                && d_edge[parent.index][s].DU_Removed != true
                && array[s].DU_Found != true){
                    path.push(array[s]);
                    array[s].DU_Found = true;
                    d_path[x][s].DU_Parent = parent.index;
                    d_path[x][s].DU_Weight = d_path[x][parent.index].DU_Weight + 1;
                    DU_GoHome(d_edge, x, s, d_path, parent);
                }
            }
            path.pop();
        }

        for(int r = 0; r < vertices; r++){
            array[r].DU_Found = false;
        }
    }
}

void undirected_BFS(Vertex array[], Edge d_edge[][vertices], Path d_path[][vertices])
{
    Vertex parent;
    queue<Vertex> path;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0; x < vertices; x++){
        int from = x;
        //Creating the queue, place starting element into the queue
        path.push(array[x]); //queue
        parent = path.front();
        array[x].UU_Found = true;
        d_path[x][x].UU_Parent = x;
        d_path[x][x].UU_Weight = 0;
        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty() && parent.index !=-1){
            parent = path.front();
            for(int s = 0; s < vertices; s++){
                if(parent.index != -1
                &&d_edge[parent.index][s].Uweight != -1
                && d_edge[parent.index][s].UU_Removed != true
                && array[s].UU_Found != true){
                    path.push(array[s]);
                    array[s].UU_Found = true;
                    d_path[x][s].UU_Parent = parent.index;
                    d_path[x][s].UU_Weight = d_path[x][parent.index].UU_Weight + 1;
                    UU_GoHome(d_edge, from, s, d_path, parent);
                }
            }
            path.pop();
        }

        for(int r = 0; r < vertices; r++){
            array[r].UU_Found = false;
        }
    }
}
