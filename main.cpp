#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <tuple>
using namespace std;
// I can't get the file working with C++
// data structure to store graph edges
struct Edge {
	int src, dest, weight;
	char c;
};

typedef pair<int, int> Pair;

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors of Pairs to represent an adjacency list
	bool digraph;
	vector<vector<Pair>> adjList;
	bool isDirect(Graph &graph);

	void neighbors(unsigned int);

	void addVertex(Graph &graph, unsigned int);

	void addEdge(Graph &graph,unsigned int, unsigned int, unsigned int);

	void RemoveEdge(Graph& graph, unsigned int, unsigned int);

	int getweight(Graph& graph, int, int);

	bool isEmpty(Graph& graph);
	//The function below is the same as size()
	int Vertices(Graph& graph);
	
	int _edges(Graph& graph);

	int degree(Graph& graph, unsigned int v);

	void Clear(Graph& graph);

	bool VertexExists(Graph& graph, unsigned int v);

	void RemoveVertex(Graph& graph, unsigned int v);
	// Graph Constructor with no vertices
	Graph() 
	{
		std::cout << "No vertices " << std::endl;
	}
	Graph(vector <Edge> const& edges, int N) {
		adjList.resize(N);
		for (auto& edge : edges)
		{
			int src = edge.src;
			int dest = edge.dest;
			int weight = edge.weight;
			adjList[src].push_back(make_pair(dest, weight));
		}
	}
	// Graph Constructor
	Graph(vector<Edge> const& edges, int N, bool _digraph)
	{
		// resize the vector to N elements of type vector<Pair>
		adjList.resize(N);

		// add edges to the directed graph
		
		for (auto& edge : edges)
		{
			digraph = _digraph;
			int src = edge.src;
			int dest = edge.dest;
			int weight = edge.weight;
			char c = edge.c;
			// insert at the end
			adjList[src].push_back(make_pair(dest, weight));

		}
	}
	bool adjacent(int u, int v);
};
///Printing Graph
void printGraph(Graph const& graph, int N)
{
	for (int i = 0; i < graph.adjList.size(); i++)
	{
		// print all neighboring vertices of given vertex
		for (Pair v : graph.adjList[i])
			cout << "(" << i << ", " << v.first <<
			", " << v.second << ") ";
		cout << endl;
	}
}
///Beggining of class declaration

void Graph::RemoveVertex(Graph& graph, unsigned int v) {
	std::vector<vector<Pair>>::iterator row;
	std::vector<Pair>::iterator col;
	row = std::next(graph.adjList.begin(), v);


	for (col = row->begin(); col != row->end(); col++) {
		if (col->first == v)
		{
			graph.adjList[v].erase(col);
			
		}
	}
	graph.adjList.erase(row);
}


bool Graph::isDirect(Graph& graph) {
	std::vector <vector<Pair>>::iterator row;
	std::vector <Pair>::iterator col;
	try {
		for (row = graph.adjList.begin(); row != graph.adjList.end(); row++) {
			for (col = row->begin(); col != row->end(); col++) {
				if (col->second = 0) {
					throw 20;
					return true;
				}
			}
		}
	}
	catch (int e) { cout << "No graph to be found ERROR NO " << e << endl; return false; }
}


bool Graph::VertexExists(Graph& graph, unsigned int v) 
{

	std::vector<vector<Pair>>::iterator row = graph.adjList.begin();
	if (v >= row->size()) {
		std::cout << "Doesn't Exist" << std::endl;
		return false;
	}
	else {
		std::cout << "It does exist" << std::endl;
		return true;
	}
}

void Graph::Clear(Graph& graph) {
	graph.adjList.clear();
}
int Graph::degree(Graph& graph, unsigned int v) {
	std::vector <vector<Pair>>::iterator row;
	std::vector <Pair>::iterator col;
	unsigned int count = 0;
	row = std::next(graph.adjList.begin(), v);
	for (col = row->begin(); col != row->end(); col++) {
		
			count++;
		
	}
	return count;
}
int Graph::_edges(Graph& graph) {
	std::vector<vector<Pair>>::iterator row;
	std::vector<Pair>::iterator col;
	unsigned int count = 0;
	for (row = graph.adjList.begin(); row != graph.adjList.end(); row++) {
		for (col = row->begin(); col != row->end(); col++)
		{
			count++;
		}
		count++;
	}
	return count;
}
int Graph::Vertices(Graph& graph) {
	std::vector<vector<Pair>>::iterator row;
	unsigned int count = 0;
	for (row = graph.adjList.begin(); row != graph.adjList.end(); row++)
	{
		count++;
	}
	return count;
}
bool Graph::isEmpty(Graph &graph) {
	if (graph.adjList.empty()) {
		std::cout << "The vector is empty" << std::endl;
		return true;
	}
	else
	{
		std::cout << "The vector isn't empty" << std::endl;
		return false;
	}
}
int Graph::getweight(Graph& graph, int v, int w) {
	std::vector <vector<Pair>>::iterator row;
	std::vector <Pair>::iterator col;
	row = std::next(graph.adjList.begin(), v);
	for (col = row->begin(); col != row->end(); col++) {
		if (col->first == w) {
			return col->second;
		}
	}
}
void Graph::RemoveEdge(Graph& graph, unsigned int v, unsigned int w) {
	std::vector<vector<Pair>>::iterator row;
	std::vector<Pair>::iterator col;
	row = std::next(graph.adjList.begin(), v);
	
	
	for (col = row->begin(); col != row->end(); col++) {
		if (col->first == w)
		{
			graph.adjList[v].erase(col);
			break;
		}
	}
	

}
void Graph::addEdge(Graph &graph,unsigned int u, unsigned int v, unsigned int w) 
{
	

	if (u >= adjList.size()) {
		graph.adjList.resize(u + 1);
		graph.adjList[u].push_back(make_pair(v, w));
	 }
	else 
	{
		graph.adjList[u].push_back(make_pair(v, w));
	}
}
void Graph::addVertex(Graph &graph, unsigned int v) {
	int u = adjList.size();
	if (v >= adjList.size()) {
		graph.adjList.resize(v + 1);
		graph.adjList[v].push_back(make_pair(0, 0));
	}
	else {
		cout << " ERROR NOT ENOUGH ROOM " << endl;
	}
}


void Graph::neighbors(unsigned int i) {
	int count = 0;
	vector <vector<Pair>>::iterator row;
	vector<Pair>::iterator col;
	row = adjList.begin();
	for (row = adjList.begin(); row != adjList.end(); row++)
	{
		if (count == i) 
		{
			for (col = row->begin(); col != row->end(); col++)
			{
				std::cout << " { "<< col->first << " } " << std::endl;
			}
		}
		count++;
	}
}


bool Graph::adjacent(int u, int v) {
	auto p = make_pair(u, v);
	vector<vector<Pair>>::iterator row;
	int count = 0;
	
	vector<Pair>::iterator col;
	row = adjList.begin();
	col = row->begin();
	for (row = adjList.begin(); row != adjList.end(); row++)
	{
		for (col = row->begin(); col != row->end(); col++)
		{ 
			if (count == u && col->first == v)
			{ 
				cout << "True" << endl;
				return true;
			}
			
		}
		///Counting the number of loops through the row of the 3D vector
		count++;
	}
	return false;
	
}
	


// Graph Implementation using STL
int main()
{
	
	vector<Edge> edges =
	{
		// (x, y, w) -> edge from x to y having weight w
		{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
		{ 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }, {0, 2, 12}, {1, 4, 9}
	};

	// Number of nodes in the graph
	int N = 8;

	// construct graph
	Graph graph(edges, N, isdigraph);

	//Its the first two numbers you see on screen
	graph.adjacent(1, 2);

	//Second line
	graph.neighbors(0);


	// print adjacency list representation of graph
	printGraph(graph, N);


	graph.addVertex(graph, 9);


	graph.addEdge(graph, 2, 4, 20);


	graph.addEdge(graph, 5, 2, 30);


	graph.RemoveEdge(graph, 0, 2);


	graph.addVertex(graph, 10);


	///Removes edge {1, 2, 7}
	graph.RemoveEdge(graph, 1, 2);

	//Printing weight
	std::cout << endl;
	std::cout << graph.getweight(graph, 2, 0);

	// Printing if it's empty
	std::cout << endl;
	std::cout << graph.isEmpty(graph);
	std::cout << endl;

	//Printing Vertices
	std::cout << endl;

	std::cout << " The number of vertices are " << graph.Vertices(graph);

	std::cout << endl;

	//Printing edges

	std::cout << endl;

	std::cout << "The number of edges are " << graph._edges(graph) << std::endl;

	std::cout << std::endl;

	//Print DEGREE

	std::cout << endl;

	std::cout << "The degree of 0 vector is " << graph.degree(graph, 0);
	std::cout << std::endl;
	
	std::cout << " The degree of 2 vector is " << graph.degree(graph, 2);

	std::cout << std::endl;
	printGraph(graph, N);

	std::cout << std::endl;

	std::cout << std::endl;


	///TESTING IF VERTEX EXISTS!
	std::cout <<  graph.VertexExists(graph, 12) << std::endl;;

	std::cout << std::endl;
	///Clearing the GRAPH!!!!
	graph.Clear(graph);

	///PRINTING AGAIN IT SHOULD ONLY PRINT TWICE!!!!!!!!!!!!!!!!!!!!!!!!

	printGraph(graph, N);
	return 0;
}
