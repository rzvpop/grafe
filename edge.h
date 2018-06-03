#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#ifndef GRAFE_EDGE_H
#define GRAFE_EDGE_H

class Edge {
private:
    int start, stop, cost;
public:
    explicit Edge(int _start = 0, int _stop = 0, int _cost = 0);

    ~Edge();

    void SetStart(int _start);
    int GetStart() const;
    void SetStop(int _stop);
    int GetStop() const;
    void SetCost(int _cost);
    int GetCost() const;
    bool operator==(const Edge &_edge) const;
    bool operator!=(const Edge &_edge) const;
    bool operator<(const Edge &_edge) const;
    void Print() const;
};

#endif //GRAFE_EDGE_H