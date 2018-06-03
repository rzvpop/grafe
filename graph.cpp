#include "edge.h"
#include "graph.h"

Graph::Graph(int _nr_vertices)
{
    nr_vertices = _nr_vertices;
    nr_edges = 0;
    edges = std::vector <Edge>(0);
}

Graph::~Graph() = default;

int Graph::GetNrVertices()
{
    return nr_vertices;
}

void Graph::SetNrVertices(int value)
{
    nr_vertices = value;
}

Edge* Graph::AddEdge(const Edge& _edge)
{
    int nr_of_vertices = Graph::GetNrVertices();

    if(_edge.GetStart() >= nr_of_vertices || _edge.GetStop() >= nr_of_vertices)
        throw "Invalid vertices!";
    else
    {
        edges.push_back(_edge);
        nr_edges ++;
    }

    auto it = edges.end() - 1;

    return &(*it);
}

void Graph::RemoveEdge(const Edge& _edge)
{
    if(std::find(edges.begin(), edges.end(), _edge) != edges.end()){
        edges.erase(std::find(edges.begin(), edges.end(), _edge));
        nr_edges --;
    }

}

void Graph::Print() const
{
    std::cout << nr_vertices << '\n';

    for(const Edge &e: edges)
    {
        e.Print();
        std::cout << '\n';
    }
}
void Graph::RemoveAll()
{
    nr_vertices = 0;
    edges.clear();
}
void Graph::ReadFromFile(const std::string &file_name)
{
    std::ifstream fin(file_name);

    int start, stop, cost;

    fin >> nr_vertices;

    while(fin >> start >> stop >> cost)
    {
        Graph::AddEdge(Edge(start, stop, cost));
    }
    fin.close();
}

void Graph::ChangeCost(Edge _edge, int new_cost)
{
    auto it = std::find(edges.begin(), edges.end(), _edge);

    if (it != edges.end())
    {
        it->SetCost(new_cost);

        edges[0].Print();
    }
    else
        throw "Invalid edge!";
}

int Graph::GetNrEdges() {
    return nr_edges;
}
