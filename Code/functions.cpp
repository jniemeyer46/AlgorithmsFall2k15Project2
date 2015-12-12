#include "functions.h"

void undirect(Edge matrix[][]){
    for(int i = 0; i < 547; i++)
    {
        for(int j = i; j < 547; j++)
        {
            if (matrix[i][j].Dweight == -1)
                matrix[i][j].Uweight = matrix[j][i].Dweight;
            else if(matrix[j][i] != -1)
                matrix[i][j].Uweight = matrix[i][j].Dweight+matrix[j][i].Dweight;
        }
    }
    return;
}

void edgeArrayInit(Edge RBM[], int num_edges){
    for(int i = 0; i < num_edges; i++)
    {
        getline(cin, RBM[i].from, ',');//that is a comma
        getline(cin, RBM[i].to, ',');//also a comma
        getline(cin, RBM[i].weight, '\n'); //not a comma
    }
    edgeSort(RBM, 0, num_edges);
    return;
}

void edgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      string pivot = arr[(left + right) / 2].StartVertex;

      /* partition */
      while (i <= j) {
            while (arr[i].StartVertex < pivot)
                  i++;
            while (arr[j].StartVertex > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            edgeSort(arr, left, j);
      if (i < right)
            edgeSort(arr, i, right);
    return;
}

void vertArrayInit(Vertex vert[], int num_edges, Edge RBM[]) {
    vertNo = 0;
    vert[0].index = 0;
    vert[0].name = RBM[0].StartVertex;
    for(int i = 1; i < num_edges; i++)
    {
        if (RBM[i].from !=vert[vertNo].name)
        {
            vertNo++;
            vert[vertNo].index = vertNo;
            vert[vertNo].name = RBM[i].from;
        }
    }
    return;
}

void DW_GoHome(Edge matrix[][], int from, int to, Path parents[][]){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse();
        path.DW_GoHome(matrix, from, parents[from][to], parents);
    }
    return;
}

void UW_GoHome(Edge matrix[][], int from, int to, Path parents[][]){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse();
        path.UW_GoHome(matrix, from, parents[from][to], parents);
    }
    return;
}

void DU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse(start);
        path.DU_GoHome(matrix, from, parents[from][to], parents, start);
    }
    return;
}

void UU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse(start);
        path.UU_GoHome(matrix, from, parents[from][to], parents, start);
    }
    return;
}

void redPill(Edge matrix[][], Edge RBM[], Vertex vertical[], int num_edge){ //NOT DONE YET!!!
    int from, to;
    for(int i = 0; i < num_edge; i++)
    {
        from = VertexSearch(vertical, 0, num_edge, RBM[i].StartVertex);
        to = VertexSearch(vertical, 0, num_edge, RBM[i].EndVertex);
        matrix[from][to] = RBM[i];
        matrix[from][to].index_Start = from;
        matrix[from][to].index_End = to;
    }
    return;
}

int VertexSearch (Vertex vertical[], int left, int right, string name){
    int middle = (left+right)/2;
    if (vertical[middle].name == name)
        return middle;
    else if (vertical[middle].name > name)
        return VertexSearch(vertical, middle, right, name);
    else
        return VertexSearch(vertical, left, middle, name);
}

void bluePill(Edge RBM[], Edge Edgy[][], int num_edge){
    int from to;
    for (int i = 0; i < num_edge; i++)
    {
        from = RBM[i].index_Start;
        to = RBM[i].index_End;
        RBM[i] = Edgy[from][to];
    }
    return;
}

void UU_ComunismEdgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      int pivot = arr[(left + right) / 2].UU_BetweennessCentrality;

      /* partition */
      while (i <= j) {
            while (arr[i].StartVertex > pivot)
                  i++;
            while (arr[j].StartVertex < pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            UU_ComunismEdgeSort(arr, left, j);
      if (i < right)
            UU_ComunismEdgeSort(arr, i, right);
    return;
}

void DU_ComunismEdgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      int pivot = arr[(left + right) / 2].DU_BetweennessCentrality;

      /* partition */
      while (i <= j) {
            while (arr[i].StartVertex > pivot)
                  i++;
            while (arr[j].StartVertex < pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            DU_ComunismEdgeSort(arr, left, j);
      if (i < right)
            DU_ComunismEdgeSort(arr, i, right);
    return;
}

int UU_Comunism(Edge RBM[], int num_edge) {
    int removed = 0, Max = 0;
    UU_ComunismEdgeSort(RBM, 0, num_edge);
    for(int i = 0; i < 5; i++)
    {
        Max = RBM[removed].UU_BetweennessCentrality;
        while(RBM[removed].UU_BetweennessCentrality == Max)
        {
            RBM[removed].UU_Removed = true;
            removed++;
        };
    }
    return removed;
}

int DU_Comunism(Edge RBM[], int num_edge) {
    int removed = 0, Max = 0;
    DU_ComunismEdgeSort(RBM, 0, num_edge);
    for(int i = 0; i < 5; i++)
    {
        Max = RBM[removed].DU_BetweennessCentrality;
        while(RBM[removed].DU_BetweennessCentrality == Max)
        {
            RBM[removed].DU_Removed = true;
            removed++;
        };
    }
    return removed;
}

void PurplePill(Edge RBM[], Edge Edgy[][], int num_edges) {
    int from, to;
    for(int i = 0; i < num_edges; i++)
    {
        from = RBM[i].index_Start;
        to = RBM[i].index_End;
        Edgy[from][to] = RBM[i];
    }
    return;
}

void degreeFinder(Vertex nodesBro[], Edge matrix[][], int num_verts){
    for(int i = 0; i < num_verts; i++)
    {
        for(int x = 0; x < num_verts; x++)
        {
            if(matrix[i][x].Dweight != -1)
            {
                nodesBro[i].DW_OutDegree += matrix[i][x].Dweight;
                nodesBro[i].DU_OutDegree++;
                nodesBro[x].DW_InDegree += matrix[i][x].Dweight;
                nodesBro[x].DU_InDegree++;
            }
        }
    }
    return;
}

void LSP(Path wayHome[][], int num_verts, Vertex Nodes[]){
    int DW_Max = -1, DU_Max = -1, UW_Max = -1, UU_Max = -1;
    for (int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {
            if(wayHome[from][to].DU_Weight > DU_Max)
            {
                DU_Max = wayHome[from][to].DU_Weight;
                Nodes[from].DU_LSP_EndNode = Nodes[to].name;
            }
            if(wayHome[from][to].UU_Weight > UU_Max)
            {
                UU_Max = wayHome[from][to].UU_Weight;
                Nodes[from].UU_LSP_EndNode = Nodes[to].name;
            }
            if(wayHome[from][to].DW_Weight > DW_Max)
            {
                DW_Max = wayHome[from][to].DW_Weight;
                Nodes[from].DW_LSP_EndNode = Nodes[to].name;
            }
            if(wayHome[from][to].UW_Weight > UW_Max)
            {
                UW_Max = wayHome[from][to].UW_Weight;
                Nodes[from].UW_LSP_EndNode = Nodes[to].name;
            }
        }
        DW_Max = -1;
        DU_Max = -1;
        UW_Max = -1;
        UU_Max = -1;
    }
    return;
}

void DegPrint(Vertex Nodes[], const int weight_in, const int weight_out,
const int weightless_in, const int weightless_out, const int num_verts){
    int WI[weight_in] = {0};
    int WO[weight_out] = {0};
    int UI[weightless_in] = {0};
    int UO[weightless_out] = {0};
    int WI_count = 0, WO_count = 0, UI_Count = 0, UO_Count = 0;
    for(int i = 0; i < num_verts; i++)
    {
        WI[Nodes[i].DW_InDegree]++;
        WO[Nodes[i].DW_OutDegree]++;
        UI[Nodes[i].DU_InDegree]++;
        UO[Nodes[i].DU_OutDegree]++;
        if (Nodes[i].DW_InDegree == weight_in-1)
            cout << Nodes[i].name << " is tied for max Weighted InDegree." << endl;
        if (Nodes[i].DW_OutDegree == weight_out-1)
            cout << Nodes[i].name << " is tied for max Weighted OutDegree." << endl;
        if (Nodes[i].DU_InDegree == weightless_in-1)
            cout << Nodes[i].name << " is tied for max Unweighted InDegree." << endl;
        if (Nodes[i].DU_OutDegree == weightless_in -1)
            cout << Nodes[i].name << " is tied for max Unweighted Outdegree." << endl;
    }
    //printing out
    //Weight_out
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weight_out/10); x++)
        {
            WO_count += WO[(weight_out/10)*i+x];
        }
        cout << "Number of nodes with weighted out degree between " << i*(weight_out/10) <<
            " and " << (i+1)*(weight_out/10) << ": " << WI_count << endl;
        WO_count = 0;
    }

    //Weight_in
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weight_in/10); x++)
        {
            WI_count += WI[(weight_in/10)*i+x];
        }
        cout << "Number of nodes with weighted in degree between " << i*(weight_in/10) <<
            " and " << (i+1)*(weight_in/10) << ": " << WI_count << endl;
        WI_count = 0;
    }

    //Unweighted in
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weightless_in/10); x++)
        {
            UI_count += UI[(weightless_in/10)*i+x];
        }
        cout << "Number of nodes with weightless in degree between " << i*(weightless_in/10) <<
            " and " << (i+1)*(weightless_in/10) << ": " << WI_count << endl;
        UI_count = 0;
    }

    //Unweighted out
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weightless_out/10); x++)
        {
            UO_count += UO[(weightless_out/10)*i+x];
        }
        cout << "Number of nodes with weightless out degree between " << i*(weightless_out/10) <<
            " and " << (i+1)*(weightless_out/10) << ": " << UO_count << endl;
        UO_count = 0;
    }



    return;
}

void ShortestPathDistroPrint(Path wayHome[][], const int num_verts, Vertex Nodes[]){
    int DMax = 0, UMax = 0;
    for(int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {   //find diameters
            if(wayHome[from][to].UU_Weight > UMax)
                UMax = WayHome[from][to].UU_Weight;
            if(wayHome[from][to].DU_Weight > DMax)
                DMax = wayHome[from][to].DU_Weight;
        }
    }
    UndirectedPathDistributionOutput(wayHome, num_verts, Nodes, UMax);
    DirectedPathDistributionOutput(wayHome, num_verts, Nodes, DMax);
    return;
}


void UndirectedPathDistributionOutput(Path wayHome[][], const int num_verts,
Vertex Nodes[], const int UMax){
    int Distro[UMax+1] = {0};
    for (int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {
            if(wayHome[from][to].UU_Weight == -1)
                Distro[0]++;
            else
                distro[wayHome[from][to].UU_Weight]++;
            if(wayHome[from][to].UU_Weight == UMax)
            {
                cout << "Path from " << Nodes[from] << " to " << Nodes[to] <<
                " is tied for longest shortest undirected path." << endl;
            }
        }
    }
    for(int i = 1; i < UMax; i++)
        cout << "Undirected Unweighted paths with length " << i << " : " << Distro[i] << endl;
    cout << Distro[0] << " unwalkable paths in Undirected Unweighted graph" << endl;
    return;
}


void DirectedPathDistributionOutput(Path wayHome[][], const int num_verts,
Vertex Nodes[], const int DMax){
    int Distro[DMax+1] = {0};
    for (int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {
            if(wayHome[from][to].DU_Weight == -1)
                Distro[0]++;
            else
                distro[wayHome[from][to].DU_Weight]++;
            if(wayHome[from][to].DU_Weight == UMax)
            {
                cout << "Path from " << Nodes[from] << " to " << Nodes[to] <<
                " is tied for longest shortest Directed path." << endl;
            }
        }
    }
    for(int i = 1; i < DMax; i++)
        cout << " Directed Unweighted paths with length " << i << " : " << Distro[i] << endl;
    cout << Distro[0] << " unwalkable paths in Directed Unweighted graph" << endl;
    return;
}






