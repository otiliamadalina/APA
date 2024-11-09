#include <iostream>
#include <time.h>

#define MAX 15

using namespace std;

const int INF = 999;
int edges[4];
int nr_of_nodes[5] = {10, 20, 30, 40, 50};

int parent[MAX] = {0}, visited[MAX] = {0};
int Prim_Graph[MAX][MAX], Kruskal_Graph[MAX][MAX];
int it1 = 0, it2 = 0;


void initialization() {
    it1 = it2 = 0;

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
        parent[i] = 0;
        for (int j = 0; j < MAX; j++) {
            Prim_Graph[i][j] = 0;
            Kruskal_Graph[i][j] = 0;
        }
    }
}

void create_graph(int nr_of_nodes, int dens) {
    int k = 0;
    cout << "\nNodes: " << edges[dens] << endl;

    for (int i = 0; i < nr_of_nodes; i++)
        for (int j = i + 1; j < nr_of_nodes; j++) {
            if (k < edges[dens]) {
                int r = rand() % 80 + 1;
                Prim_Graph[i][j] = r;
                Prim_Graph[j][i] = Prim_Graph[i][j];
                Kruskal_Graph[i][j] = r;
                Kruskal_Graph[j][i] = Kruskal_Graph[i][j];
                k++;
            }
        }

    for (int i = 0; i < nr_of_nodes; i++)
        for (int j = 0; j < nr_of_nodes; j++)
            if (!Prim_Graph[i][j] && i != j) {
                Prim_Graph[i][j] = INF;
                Kruskal_Graph[i][j] = INF;
            }
}

void display_graph(int nr_of_nodes) {
    cout << "Weighted adjacency matrix:" << endl;
    for (int i = 0; i < nr_of_nodes; i++) {
        for (int j = 0; j < nr_of_nodes; j++)
            if (Prim_Graph[i][j] != 999)
                cout << Prim_Graph[i][j] << " ";
            else cout << "0 ";
        cout << endl;
    }
}

//============================PRIM==========================

void Prim(int n) {
    int i, p, min, k, x = 0;
    visited[x] = 1;
    for (i = 1; i <= n; i++) {
        parent[i] = x;
        it1++;
    }
    parent[x] = 0;
    for (k = 1; k <= n - 1; k++) {
        min = INF;
        p = 0;
        it1++;
        for (i = 1; i <= n; i++) {
            it1++;
            if (!visited[i] && min > Prim_Graph[i][parent[i]]) {
                min = Prim_Graph[i][parent[i]];
                p = i;
                it1++;
            }
            visited[p] = 1;
        }
        for (i = 1; i <= n; i++) {
            it1++;
            if (!visited[i] && Prim_Graph[i][parent[i]] > Prim_Graph[i][p]) {
                parent[i] = p;
                it1++;
            }
        }
    }
    cout << "Nr. of iterations <P> : " << it1 << endl;
}

//===============================KRUSKAL==========================

int find(int i) {
    while (parent[i]) {
        i = parent[i];
        it2++;
    }
    return i;
}

void UNION(int x, int y) {
    it2++;
    if (x != y)
        parent[y] = x;
}

void Kruskal(int nr_of_edges) {
    int u, v, x, y, n = 0, minimum;

    while (n < nr_of_edges - 1) {
        it2++;
        minimum = INF;
        for (int i = 0; i < nr_of_edges; i++) {
            it2++;
            for (int j = 0; j < nr_of_edges; j++) {
                it2++;
                if (Kruskal_Graph[i][j] < minimum && i != j) {
                    it2++;
                    minimum = Kruskal_Graph[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        u = find(x);
        v = find(y);
        UNION(u, v);
        Kruskal_Graph[x][y] = Kruskal_Graph[y][x] = INF;
        n++;
    }
    cout << "Nr. of iterations <K> : " << it2 << endl;
}


int main() {

    srand(time(nullptr));
    for (int i = 0; i < 5; i++) {
        edges[0] = nr_of_nodes[i] - 1;
        edges[1] = nr_of_nodes[i] * (nr_of_nodes[i] - 1) / 2;
        edges[2] = nr_of_nodes[i] * (nr_of_nodes[i] - 1) * 0.2;
        edges[3] = nr_of_nodes[i] * (nr_of_nodes[i] - 1) * 0.5;
        for (int j = 0; j < 4; j++) {
            switch (j) {
                case 0:
                    cout << "\tFavorable case " << nr_of_nodes[i] << " nodes.";
                    break;
                case 1:
                    cout << "\tUnfavorable case " << nr_of_nodes[i] << " nodes.";
                    break;
                case 2:
                    cout << "\tAverage case (20%) " << nr_of_nodes[i] << " nodes.";
                    break;
                case 3:
                    cout << "\tAverage case (50%) " << nr_of_nodes[i] << " nodes.";
                    break;
            }

            initialization();
            create_graph(nr_of_nodes[i], j);

            Prim(nr_of_nodes[i]);
            for (int i = 0; i < nr_of_nodes[i]; i++) {
                parent[i] = 0;
                visited[i] = 0;
            }
            Kruskal(nr_of_nodes[i]);
            cout << endl;
        }
        display_graph(nr_of_nodes[i]);
    }

    return 0;
}






