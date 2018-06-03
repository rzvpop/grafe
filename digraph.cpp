#include "digraph.h"
#define INF 0x3f3f3f3f

DiGraph::DiGraph(int _nr_vertices) : Graph(_nr_vertices)
{
    in_list = std::vector<std::vector<std::pair<int, Edge*> > >((unsigned int)_nr_vertices, std::vector<std::pair<int, Edge*> >(0));
    out_list = std::vector<std::vector<std::pair<int, Edge*> > >((unsigned int)_nr_vertices, std::vector<std::pair<int, Edge*> >(0));
    degrees = std::vector<std::pair<int, int> >((unsigned int)_nr_vertices, std::make_pair(0, 0));
}

void DiGraph::ResizeInOut(int n)
{
    out_list.resize((unsigned long long int)n);
    in_list.resize((unsigned long long int)n);
    degrees.resize((unsigned long long int)n);
}

DiGraph::~DiGraph() = default;

Edge* DiGraph::FindEdge(const Edge& _edge) const
{
    int start = _edge.GetStart();

    for(int i = 0; i < out_list[start].size(); ++i)
        if(out_list[start][i].first == _edge.GetStop())
        {
            return out_list[start][i].second;
        }

    Edge* e = nullptr;
    return e;
}

void DiGraph::AddIntoList(Edge* _edge)
{
    int start = _edge->GetStart(), stop = _edge->GetStop();

    degrees[start].first++;
    degrees[stop].second++;

    out_list[start].emplace_back(std::make_pair(stop, _edge));
    in_list[stop].emplace_back(std::make_pair(start, _edge));
}

void DiGraph::AddEdge(const Edge _edge)
{
    Edge* cp = Graph::AddEdge(_edge);
    AddIntoList(cp);
}

void DiGraph::PrintLists()
{
    int vrtx = 0;

    std::cout << "Out---\n";

    for(const auto &i : out_list)
    {
        if(!i.empty())
        {
            std::cout << vrtx << ": ";

            for(const auto j : i)
                std::cout << j.first << " ";

            std::cout << '\n';
        }
        vrtx++;
    }

    vrtx = 0;

    std::cout << "In---\n";

    for(const auto &i : in_list)
    {
        if(!i.empty())
        {
            std::cout << vrtx << ": ";

            for(const auto j : i)
                std::cout << j.first << " ";

            std::cout << '\n';
        }
        vrtx++;
    }
}

void DiGraph::ReadFGraph(const std::string &file)
{
    std::ifstream fin(file);

    int n = 0, m;
    fin >> n >> m;

    if(n >= 0)
    {
        SetNrVertices(n);
        ResizeInOut(n);
        int start = 0, stop = 0, cost;

        while(fin >> start >> stop >> cost)
        {
            AddEdge(Edge(start, stop, cost));
        }
    }

    fin.close();
}

/*void DiGraph::ChangeCost(Edge _edge, int new_cost)
{

}*/

int DiGraph::GetOutDegree(int vrt)
{
    return degrees[vrt].first;
}

int DiGraph::GetInDegree(int vrt)
{
    return degrees[vrt].second;
}

void DiGraph::ShortestAB(int a, int b)
{
    std::vector<int> q(static_cast<unsigned long>(GetNrVertices()), -1), v(static_cast<unsigned long>(GetNrVertices()), -1);
    int lf = 0, rh = 0, gasit = 0;
    q[lf] = a;

    while(lf <= rh)
    {
        for(int i = 0; i < out_list[q[lf]].size(); i++)
        {
            if(v[out_list[q[lf]][i].first] == -1 && q[lf] != out_list[q[lf]][i].first)
            {
                q[++rh] = out_list[q[lf]][i].first;
                v[out_list[q[lf]][i].first] = q[lf];

                if(out_list[q[lf]][i].first == b)
                {
                    break;
                }
            }
        }
        if(q[rh] == b)
            break;

        ++lf;
    }

    q.clear();
    q.push_back(b);

    /*while(v[b] != -1)
    {
        q.push_back(v[b]);
        b = v[b];
    }*/

    for(int i = static_cast<int>(q.size() - 1); i > 0; --i)
        std::cout << q[i] << ' ' << q[i - 1] << '\n';
    std::cout << '\n';
}

void DiGraph::Disjkstra(int x, int y)
{
    std::priority_queue<std::pair<int,int> > q;
    std::vector<int> v(GetNrVertices(), 0), T(GetNrVertices(), -1), d(GetNrVertices(), INF);

    d[x] = 0;
    q.push({0,x});

    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if(!v[a])
        {
            v[a] = 1;

            //std::cout << 1 << '\n';
            for(auto it : out_list[a])
            {
              //  std::cout << 2 << '\n';
                if(d[a] + it.second->GetCost() < d[it.first])
                {
                   // std::cout << it.first << ' ' << d[it.first] << '\n';
                    d[it.first] = d[a] + it.second->GetCost();
                    //std::cout << it.first << ' ' << d[it.first] << '\n';

                    q.push({-d[it.first], it.first});

                    //std::cout << it.first << ' ' << T[it.first] << '\n';
                    T[it.first] = a;
                }
            }
        }
    }

    PrintWalk(T, y);
    std::cout << '\n';
}

void DiGraph::PrintWalk(std::vector<int> T, int x)
{
    if(T[x] == -1)
        std::cout << x << ' ';
    else
    {
        PrintWalk(T, T[x]);
        std::cout << x << ' ';
    }
}
