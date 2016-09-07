#include <vector>
using std::vector;
using std::pair;

// ��������������� ����.
class COrGraph {
public:
	COrGraph( int verticesCount, const vector<pair<int, int>>& edges );

	// ���������� � �������.
	int GetVertexOrder( int index ) const;
	const vector<int>& GetOutEdgesFromVertex( int index ) const;

	// ���������� �����.
	void AddEdge( int fromIndex, int toIndex );
	// �������������� ����������.
	bool TopSort();

private:
	// �������.
	struct CVertex {
		vector<int> OutEdges; // ��������� �����.
		int Order; // ������� �������������� ����������.

		CVertex() : Order( -1 ) {}
	};

	vector<CVertex> vertices;
	int exitTime;

	bool dfsTopSort( int index );
};

bool AddRedEdges( COrGraph& graph, const vector<pair<int, int>>& redEdges );
