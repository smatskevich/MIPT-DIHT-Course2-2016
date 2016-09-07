#include <vector>
using std::vector;
using std::pair;

// Ориентированный граф.
class COrGraph {
public:
	COrGraph( int verticesCount, const vector<pair<int, int>>& edges );

	// Информация о вершине.
	int GetVertexOrder( int index ) const;
	const vector<int>& GetOutEdgesFromVertex( int index ) const;

	// Добавление ребра.
	void AddEdge( int fromIndex, int toIndex );
	// Топологическая сортировка.
	bool TopSort();

private:
	// Вершина.
	struct CVertex {
		vector<int> OutEdges; // Исходящие ребра.
		int Order; // Порядок топологической сортировки.

		CVertex() : Order( -1 ) {}
	};

	vector<CVertex> vertices;
	int exitTime;

	bool dfsTopSort( int index );
};

bool AddRedEdges( COrGraph& graph, const vector<pair<int, int>>& redEdges );
