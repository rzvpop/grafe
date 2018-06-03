#include "edge.h"

Edge::Edge(int _start, int _stop, int _cost) : start(_start), stop(_stop), cost(_cost)
{
}

Edge::~Edge() = default;

void Edge::SetStart(int _start)
{
    start = _start;
}
int Edge::GetStart() const
{
    return start;
}
void Edge::SetStop(int _stop)
{
    stop = _stop;
}
int Edge::GetStop() const
{
    return stop;
}
void Edge::SetCost(int _cost)
{
    cost = _cost;
}
int Edge::GetCost() const
{
    return cost;
}

bool Edge::operator == (const Edge& _edge) const
{
    return (start == _edge.GetStart() && _edge.GetStop() == stop);
}

bool Edge::operator != (const Edge& _edge) const
{
    return (start != _edge.GetStart() || _edge.GetStop() != stop);
}

bool Edge::operator < (const Edge& _edge) const
{
    if (cost == _edge.GetCost())
        return cost < _edge.GetCost();
    if (start == _edge.GetStart())
        return start < _edge.GetStart();
    return cost < _edge.GetCost();
}

void Edge::Print() const
{
    std :: cout << start << ' ' << stop << ' ' << cost;
}