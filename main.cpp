#include <iostream>
#include "edge.h"
#include "graph.h"
#include "digraph.h"

void PrintCommands()
{
    std::cout << "---------\n" <<
              "0.Exit\n" <<
              "1.Help\n" <<
              "2.Add edge\n" <<
              "3. a) Print graph as list of edges\n" <<
              "   b) Print graph as adjacency list\n" <<
              "4.Find edge(and change the cost if the user wants to)\n" <<
              "5.Change cost\n" <<
              "6.In-out dregree of vertex\n" <<
              "7.Number of vertices\n" <<
              "8.Shortest path from a vertex to another\n" <<
              "9.Path of minimum cost\n" <<
              "---------\n";
}

int main()
{
    int comm = 0;

    PrintCommands();

    DiGraph dg;
    dg.ReadFGraph("graph.txt");

    while(true)
    {
        std::cout << ">> ";
        std::cin >> comm;

        if(comm == 0)
            return 0;
        else if(comm == 1)
            PrintCommands();
        else if(comm == 2)
        {
            int start, stop, cost;

            std::cout << "Give start point: ";
            std::cin >> start;
            std::cout << "\nGive end point: ";
            std::cin >> stop;
            std::cout << "\nGive cost: ";
            std::cin >> cost;

            dg.AddEdge(Edge(start, stop, cost));
        }
        else if(comm == 3)
        {
            char sub = 'a';
            std::cout << "(a or b?)>> ";
            std::cin >> sub;

            if(sub == 'a')
                dg.Print();
            else if(sub == 'b')
                dg.PrintLists();
        }
        else if(comm == 4)
        {
            int start = 0, stop = 0;

            std::cout << "Start: ";
            std::cin >> start;

            std::cout << "Stop: ";
            std::cin >> stop;

            Edge* e = dg.FindEdge(Edge(start, stop, 0));
            //std::cout << e << '\n';
            if(e != nullptr)
            {
                e->Print();
            }
            else
                std::cout << "Can't find edge!\n";
        }
        else if(comm == 5)
        {
            int start = 0, stop = 0, new_cost = 0;

            std::cout << "Start: ";
            std::cin >> start;

            std::cout << "Stop: ";
            std::cin >> stop;

            std::cout << "New cost: ";
            std::cin >> new_cost;

            dg.Graph::ChangeCost(Edge(start, stop), new_cost);
        }
        else if(comm == 6)
        {
            int vertex;

            std::cout << "Give vertex: ";
            std::cin >> vertex;

            std::cout << "Out: " << dg.GetOutDegree(vertex) << '\n' <<
                      "In: " << dg.GetInDegree(vertex) << '\n';
        }
        else if(comm == 7)
        {
            std::cout << dg.GetNrVertices() << '\n';
        }
        else if(comm == 8)
        {
            int start = 0, dest = 0;

            std::cout << "Give start node: ";
            std::cin >> start;

            std::cout << "Give destination node: ";
            std::cin >> dest;

            dg.ShortestAB(start, dest);
        }
        else if(comm == 9)
        {
            int a, b;
            std::cout << "Start: ";
            std::cin >> a;
            std::cout << "Stop: ";
            std::cin >> b;

            dg.Disjkstra(a, b);
        }
        else
            std::cout << "Wrong command!\n";
    }
}