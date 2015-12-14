#include "functions.h"

void undirect(Edge matrix[][547]){
    for(int i = 0; i < 547; i++)
    {
        for(int j = i; j < 547; j++)
        {
            if (matrix[i][j].Dweight == -1)
                matrix[i][j].Uweight = matrix[j][i].Dweight;
            else if(matrix[j][i].Dweight != -1)
                matrix[i][j].Uweight = matrix[i][j].Dweight+matrix[j][i].Dweight;
        }
    }
    return;
}

void edgeArrayInit(Edge RBM[], int num_edges){
    for(int i = 0; i < num_edges; i++)
    {
        string garbage;
        getline(cin, RBM[i].StartVertex, ',');//that is a comma
        getline(cin, RBM[i].EndVertex, ',');//also a comma
        cin >> RBM[i].Dweight;
        getline(cin, garbage);
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
    int vertNo = 0;
    vert[0].index = 0;
    vert[0].name = RBM[0].StartVertex;
    for(int i = 1; i < num_edges; i++)
    {
        if (RBM[i].StartVertex !=vert[vertNo].name)
        {
            vertNo++;
            vert[vertNo].index = vertNo;
            vert[vertNo].name = RBM[i].StartVertex;
        }
    }
    return;
}

void DW_GoHome(Edge matrix[][547], int from, int to, Path parents[][547]){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to].DW_Parent][to].DW_Traverse();
        cout << parents[from][to].DW_Parent << endl;
        DW_GoHome(matrix, from, parents[from][to].DW_Parent, parents);
    }
    return;
}

void UW_GoHome(Edge matrix[][547], int from, int to, Path parents[][547]){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to].UW_Parent][to].UW_Traverse();
        UW_GoHome(matrix, from, parents[from][to].UW_Parent, parents);
    }
    return;
}

void DU_GoHome(Edge matrix[][547], int from, int to, Path parents[][547], Vertex start){
    if(from == to | matrix[from][to].StartVertex == "NULL")
        return;
    else
    {
        matrix[parents[from][to].DU_Parent][to].DU_Traverse(start);
        DU_GoHome(matrix, from, parents[from][to].DU_Parent, parents, start);
    }
    return;
}

void UU_GoHome(Edge matrix[][547], int from, int to, Path parents[][547], Vertex start){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to].UU_Parent][to].UU_Traverse(start);
        UU_GoHome(matrix, from, parents[from][to].UU_Parent, parents, start);
    }
    return;
}

void redPill(Edge matrix[][547], Edge RBM[], Vertex vertical[], int num_edge, int num_vert){
    int from = -1, to = -1, x = 0;
    for(int i = 0; i < num_edge; i++)
    {
        for(int x = 0; x < num_vert; x++)
        {
            if(vertical[x].name == RBM[i].StartVertex)
                from = vertical[x].index;
            if(vertical[x].name == RBM[i].EndVertex)
                to = vertical[x].index;
        }
        RBM[i].index_Start = from;
        RBM[i].index_End = to;
        matrix[from][to] = RBM[i];
        matrix[from][to].index_Start = from;
        matrix[from][to].index_End = to;
    }
    return;
}


void bluePill(Edge RBM[], Edge Edgy[][547], int num_edge){
    int from = 0, to = 0;
    cout << "take the pill" << endl;
    for (int i = 0; i < num_edge; i++)
    {
        cout << "FOR THE " << i <<"TH TIME, TAKE THE PILL!!!" << endl;
        from = RBM[i].index_Start;
        cout << "Piss";
        to = RBM[i].index_End;
        cout << " off" << endl;
        cout << "from = " <<from << endl;
        cout << "to =  " << to << endl;
        RBM[i] = Edgy[from][to];
        cout << "Midway through taking pill" << endl;
    }
    cout << "pill taken" << endl;
    return;
}

void UU_ComunismEdgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      int pivot = arr[(left + right) / 2].UU_BetweennessCentrality;

      /* partition */
      while (i <= j) {
            while (arr[i].UU_BetweennessCentrality > pivot)
                  i++;
            while (arr[j].UU_BetweennessCentrality < pivot)
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
            while (arr[i].DU_BetweennessCentrality > pivot)
                  i++;
            while (arr[j].DU_BetweennessCentrality < pivot)
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

void PurplePill(Edge RBM[], Edge Edgy[][547], int num_edges) {
    int from, to;
    for(int i = 0; i < num_edges; i++)
    {
        from = RBM[i].index_Start;
        to = RBM[i].index_End;
        Edgy[from][to] = RBM[i];
    }
    return;
}

void degreeFinder(Vertex nodesBro[], Edge matrix[][547], int num_verts){
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

void LSP(Path wayHome[][547], int num_verts, Vertex Nodes[]){
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
    int WI[weight_in];
    int WO[weight_out];
    int UI[weightless_in];
    int UO[weightless_out];
    int WI_Count = 0, WO_Count = 0, UI_Count = 0, UO_Count = 0;

    for(int i = 0; i < weightless_in; i++)
        UI[i] = 0;
    for(int i = 0; i < weightless_out; i++)
        UO[i] = 0;
    for(int i = 0; i < weight_in; i++)
        WI[i] = 0;
    for(int i = 0; i < weight_out; i++)
        WO[i] = 0;

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
            WO_Count += WO[(weight_out/10)*i+x];
        }
        cout << "Number of nodes with weighted out degree between " << i*(weight_out/10) <<
            " and " << (i+1)*(weight_out/10) << ": " << WO_Count << endl;
        WO_Count = 0;
    }

    //Weight_in
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weight_in/10); x++)
        {
            WI_Count += WI[(weight_in/10)*i+x];
        }
        cout << "Number of nodes with weighted in degree between " << i*(weight_in/10) <<
            " and " << (i+1)*(weight_in/10) << ": " << WI_Count << endl;
        WI_Count = 0;
    }

    //Unweighted in
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weightless_in/10); x++)
        {
            UI_Count += UI[(weightless_in/10)*i+x];
        }
        cout << "Number of nodes with weightless in degree between " << i*(weightless_in/10) <<
            " and " << (i+1)*(weightless_in/10) << ": " << UI_Count << endl;
        UI_Count = 0;
    }

    //Unweighted out
    for(int i = 0; i < 10; i++)
    {
        for(int x = 0; x < (weightless_out/10); x++)
        {
            UO_Count += UO[(weightless_out/10)*i+x];
        }
        cout << "Number of nodes with weightless out degree between " << i*(weightless_out/10) <<
            " and " << (i+1)*(weightless_out/10) << ": " << UO_Count << endl;
        UO_Count = 0;
    }



    return;
}

void ShortestPathDistroPrint(Path wayHome[][547], const int num_verts, Vertex Nodes[]){
    int DMax = 0, UMax = 0;
    for(int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {   //find diameters
            if(wayHome[from][to].UU_Weight > UMax)
                UMax = wayHome[from][to].UU_Weight;
            if(wayHome[from][to].DU_Weight > DMax)
                DMax = wayHome[from][to].DU_Weight;
        }
    }
    UndirectedPathDistributionOutput(wayHome, num_verts, Nodes, UMax);
    DirectedPathDistributionOutput(wayHome, num_verts, Nodes, DMax);
    return;
}


void UndirectedPathDistributionOutput(Path wayHome[][547], const int num_verts,
Vertex Nodes[], const int UMax){
    int Distro[UMax+1];
    for(int i = 0; i <= UMax; i++)
        Distro[i] = 0;
    for (int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {
            if(wayHome[from][to].UU_Weight == -1)
                Distro[0]++;
            else
                Distro[wayHome[from][to].UU_Weight]++;
            if(wayHome[from][to].UU_Weight == UMax)
            {
                cout << "Path from " << Nodes[from].name << " to " << Nodes[to].name <<
                " is tied for longest shortest undirected path." << endl;
            }
        }
    }
    for(int i = 1; i < UMax; i++)
        cout << "Undirected Unweighted paths with length " << i << " : " << Distro[i] << endl;
    cout << Distro[0] << " unwalkable paths in Undirected Unweighted graph" << endl;
    return;
}


void DirectedPathDistributionOutput(Path wayHome[][547], const int num_verts,
Vertex Nodes[], const int DMax){
    int Distro[DMax+1];
    for(int i = 0; i < DMax+1; i++)
        Distro[i] = 0;
    for (int from = 0; from < num_verts; from++)
    {
        for(int to = 0; to < num_verts; to++)
        {
            if(wayHome[from][to].DU_Weight == -1)
                Distro[0]++;
            else
                Distro[wayHome[from][to].DU_Weight]++;
            if(wayHome[from][to].DU_Weight == DMax)
            {
                cout << "Path from " << Nodes[from].name << " to " << Nodes[to].name <<
                " is tied for longest shortest Directed path." << endl;
            }
        }
    }
    for(int i = 1; i < DMax; i++)
        cout << " Directed Unweighted paths with length " << i << " : " << Distro[i] << endl;
    cout << Distro[0] << " unwalkable paths in Directed Unweighted graph" << endl;
    return;
}

void UnweightedBetweennessDisplay(Edge RBM[], const int num_edge){
    int DMax = 0, UMax = 0;
    for(int i = 0; i < num_edge; i++)
    {
        if(RBM[i].DU_BetweennessCentrality > DMax)
            DMax = RBM[i].DU_BetweennessCentrality;
        if(RBM[i].UU_BetweennessCentrality > UMax)
            UMax = RBM[i].UU_BetweennessCentrality;
    }
    UU_BetweennessPrint(RBM, num_edge, UMax);
    DU_BetweennessPrint(RBM, num_edge, DMax);

    return;
}


void UU_BetweennessPrint(Edge RBM[], const int num_edge, const int UMax){
    int Distro[UMax+1];
    int blah = 0;
    for(int i = 0; i <= UMax; i++)
        Distro[i]=0;
    for(int i = 0; i < num_edge; i++)
        Distro[RBM[i].UU_BetweennessCentrality]++;
    for(int i = 0; i <=10 ; i++)
    {
        for(int x = i*35+1; x < (i+1)*35; x++)
        {
            blah += Distro[x];
        }
        cout << "Edges with Unweighted Undirected Betweenness Centrality between " << i*35+1 << " and " << (i+1)*35  << ": " << blah << endl;
        blah = 0;
    }
    return;
}


void DU_BetweennessPrint(Edge RBM[], const int num_edge, const int DMax){
    int Distro[DMax+1];
    for(int i = 0; i <= DMax; i++)
        Distro[i] = 0;
    for(int i = 0; i < num_edge; i++)
        Distro[RBM[i].DU_BetweennessCentrality]++;
    for(int i = 1; i <= DMax; i++) //We may change this depending on the size of DMax
        cout << "Edges with Unweighted Directed Betweenness Centrality " << i << ": " << Distro[i] << endl;
    return;
}

