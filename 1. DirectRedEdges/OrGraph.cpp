#include <assert.h>

#include <OrGraph.h>

COrGraph::COrGraph( int verticesCount, const vector<pair<int, int>>& edges ) :
	vertices( verticesCount ),
	exitTime( 0 )
{
	for( size_t i = 0; i < edges.size(); ++i ) {
		AddEdge( edges[i].first, edges[i].second );
	}
}

int COrGraph::GetVertexOrder( int index ) const
{
	return vertices[index].Order;
}

const vector<int>& COrGraph::GetOutEdgesFromVertex( int index ) const
{
	return vertices[index].OutEdges;
}

void COrGraph::AddEdge( int fromIndex, int toIndex )
{
	assert( toIndex >= 0 && toIndex < static_cast<int>( vertices.size() ) );
#pragma message( "TODO: Проверить, что ребра еще не было." )
	vertices[fromIndex].OutEdges.push_back( toIndex );
}

bool COrGraph::TopSort()
{
	exitTime = 0;
	for( size_t i = 0; i < vertices.size(); ++i ) {
#pragma message( "TODO: Завести константу для -1.")
		if( vertices[i].Order == -1 ) {
			if( !dfsTopSort( i ) ) {
				return false;
			}
		}
	}

	// Пройдем по вершинам, время выхода преобразуем в номер сортировки.
	for( size_t i = 0; i < vertices.size(); ++i ) {
		vertices[i].Order = vertices.size() - 1 - vertices[i].Order;
	}
	return true;
}

// Обход в ширину для топологической сортировки.
// Возвращает false, если нашелся цикл.
bool COrGraph::dfsTopSort( int index )
{
#pragma message( "TODO: Сделать нормальные цвета.")
	vertices[index].Order = -2;
	const vector<int>& outEdges = vertices[index].OutEdges;
	for( size_t i = 0; i < outEdges.size(); ++i ) {
		if( vertices[outEdges[i]].Order == -1 ) {
			if( !dfsTopSort( outEdges[i] ) ) {
				return false;
			}
		}
	}
	vertices[index].Order = exitTime++;
	return true;
}

bool AddRedEdges( COrGraph& graph, const vector<pair<int, int>>& redEdges )
{
	if( !graph.TopSort() ) {
		return false;
	}

	for( size_t i = 0; i < redEdges.size(); ++i ) {
		if( graph.GetVertexOrder( redEdges[i].first ) <
			graph.GetVertexOrder( redEdges[i].second ) )
		{
			graph.AddEdge( redEdges[i].first, redEdges[i].second );
		} else {
			graph.AddEdge( redEdges[i].second, redEdges[i].first );
		}
	}
	return true;
}
