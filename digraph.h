#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "edge.h"
#include "graph.h"

#ifndef GRAFE_DIGRAPH_H
#define GRAFE_DIGRAPH_H

class DiGraph : public Graph
{
public:
    explicit DiGraph(int _nr_vertices = 0);
    ~DiGraph() override;

    Edge* FindEdge(const Edge& _edge) const;
    void AddIntoList(Edge* _edge);
    void AddEdge(Edge _edge);
    void PrintLists();
    void ReadFGraph(const std::string &file);
    void ResizeInOut(int n);
    //void ChangeCost(Edge _edge, int new_cost);
    int GetOutDegree(int vrt);
    int GetInDegree(int vrt);
    void ShortestAB(int a, int b);
    void Disjkstra(int x, int y);
    void PrintWalk(std::vector<int>, int);

private:
    std::vector<std::pair<int, int> > degrees;
    std::vector<std::vector<std::pair<int, Edge*> > > in_list;
    std::vector<std::vector<std::pair<int, Edge*> > > out_list;
};

#endif //GRAFE_DIGRAPH_H