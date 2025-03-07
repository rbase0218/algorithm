#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

Graph createGraph(int vertex_count, int edge_count) {
	Graph graph(vertex_count + 1);

	for (int i = 0; i < edge_count; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	return graph;
}

void visitDFS(const Graph& graph, int currentVertex, vector<bool>& visited) {
	visited[currentVertex] = true;

	for (int vertex_num : graph[currentVertex]) {
		if (!visited[vertex_num])
		{
			visitDFS(graph, vertex_num, visited);
		}
	}
}

int countConnectedVertex(const Graph& graph, int vertex_count) {
	vector<bool> isVisited(vertex_count + 1, false);
	int connectedVertexCount = 0;

	for (int vertex = 1; vertex <= vertex_count; ++vertex) {
		if (!isVisited[vertex]) {
			++connectedVertexCount;
			visitDFS(graph, vertex, isVisited);
		}
	}

	return connectedVertexCount;
}

int main() {
	int vertex_count, edge_count;
	cin >> vertex_count >> edge_count;

	Graph graph = createGraph(vertex_count, edge_count);
	int result = countConnectedVertex(graph, vertex_count);

	cout << result << endl;

	return 0;
}