#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#ifndef GRAFE_GRAPH_H
#define GRAFE_GRAPH_H

class Graph {
private:
    int nr_vertices;
    int nr_edges;
    std::vector<Edge> edges;

public:
    explicit Graph(int _NrVertices = 0);
    virtual ~Graph();

    int GetNrVertices();
    int GetNrEdges();
    void SetNrVertices(int value);
    Edge* AddEdge(const Edge& _edge);
    void RemoveEdge(const Edge &_edge);
    void Print() const;
    void RemoveAll();
    void ReadFromFile(const std::string &file_name);
    void ChangeCost(Edge _edge, int new_cost);
};

#endif //GRAFE_GRAPH_H