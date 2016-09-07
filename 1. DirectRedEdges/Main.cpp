#include <iostream>
#include <vector>
#include <OrGraph.h>

using std::cin;
using std::cout;
using std::vector;

int main()
{
	int verticesCount = 0;
	cin >> verticesCount;

	int greenEdgesCount = 0;
	cin >> greenEdgesCount;
	vector<std::pair<int, int>> greenEdges( greenEdgesCount );
	for( size_t i = 0; i < greenEdgesCount; ++i ) {
		cin >> greenEdges[i].first >> greenEdges[i].second;
	}

	int redEdgesCount = 0;
	cin >> redEdgesCount;
	vector<std::pair<int, int>> redEdges( redEdgesCount );
	for( size_t i = 0; i < redEdgesCount; ++i ) {
		cin >> redEdges[i].first >> redEdges[i].second;
	}

	// Строим ориентированный граф на n вершинах с зелеными ребрами.
	COrGraph graph( verticesCount, greenEdges );

	bool success = AddRedEdges( graph, redEdges );
	if( !success ) {
		cout << "IMPOSSIBLE";
	} else {
		// Вывести направление красных ребер.
	}

	return 0;
}