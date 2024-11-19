#include<iostream>
#include<iomanip>

using namespace std;

#define INF 999
#define MAX 15

int start_node, cost[MAX][MAX], dist[MAX], parent[MAX], iteration_dijkstra, iteration_floyd;
bool visited[MAX] = {0};
int nodes[3] = {5, 10, 15}, edges[3];

void initialization(int n) {
    iteration_dijkstra = iteration_floyd = 0;
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = i;
    }
    dist[start_node] = 0;
}

void create_graph(int n, int dens) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j > i) {
                int r = rand() % 10 + 1;
                if (r <= edges[dens]) {
                    r = rand() % 20 + 1;
                    cost[i][j] = r;
                }
            } else if (i > j) {
                cost[i][j] = cost[j][i];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (i != j && cost[i][j] == 0)
                            cost[i][j] = INF;
            }
}

void display_graph(int nr_of_nodes) {
    for (int i = 0; i < nr_of_nodes; i++) {
        for (int j = 0; j < nr_of_nodes; j++)
            cout << setw(4) << cost[i][j] << " ";
        cout << endl;
    }
}

int get_nearest(int n) {
    int min_value = INF;
    int min_node = 0;
    for (int i = 0; i < n; i++) {
        iteration_dijkstra++;
        if (!visited[i] && dist[i] < min_value) {
            min_value = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

void dijkstra(int n) {
    for (int i = 0; i < n; i++) {
        int k = get_nearest(n);
        visited[k] = true;
        iteration_dijkstra++;
        for (int j = 0; j < n; j++) {
            iteration_dijkstra++;
            if (cost[k][j] != INF && dist[j] > dist[k] + cost[k][j]) {
                iteration_dijkstra++;
                dist[j] = dist[k] + cost[k][j];
                parent[j] = k;
            }
        }
    }
    cout << "\nD: " << iteration_dijkstra << endl;
}

void display_dijkstra(int n) {
    cout << "Node:\t\t\tCost :\t\t\tPath \n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t\t" << dist[i] << "\t\t\t" << " ";
        cout << i + 1 << " ";
        int parent_node = parent[i];
        while (parent_node != start_node) {
            cout << " <-- " << parent_node + 1 << " ";
            parent_node = parent[parent_node];
        }
        cout << " <-- " << start_node + 1;
        cout << endl;
    }
}

//void display_floyd(int n, int D[][MAX]);

void floyd(int n) {
    int D[n][n], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            D[i][j] = cost[i][j];
            iteration_floyd++;
        }

    for (k = 0; k < n; k++) {
        iteration_floyd++;
        for (i = 0; i < n; i++) {
            iteration_floyd++;
            for (j = 0; j < n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                iteration_floyd++;
            }
        }
    }

    cout << "F: " << iteration_floyd << endl;
}

void display_floyd(int n, int D[][MAX]) {
    cout << "\n------------------------ Floyd -----------------------------";
    cout << endl << "Minimum distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF)
                cout << setw(4) << "INF";
            else
                cout << setw(4) << D[i][j];
        }
        cout << endl;
    }
}

int main() {

    for (int i = 0; i < 3; i++) {
        edges[0] = nodes[i] - 1;
        edges[1] = nodes[i] * (nodes[i] - 1) / 4;
        edges[2] = nodes[i] * (nodes[i] - 1) / 2;
        for (int j = 0; j < 3; j++) {
            switch (j) {
                case 0:
                    cout  << "\nFavorable case  " << nodes[i]  << " nodes" << endl;
                    break;
                case 1:
                    cout  << "\nAverage case  "  << nodes[i]  << " nodes" << endl;
                    break;
                case 2:
                    cout  << "\nUnfavorable case  "  << nodes[i] << " nodes" << endl;
                    break;
            }
            initialization(nodes[i]);
            create_graph(nodes[i], j);
            dijkstra(nodes[i]);
            floyd(nodes[i]);
        }
    }
    return 0;
}
