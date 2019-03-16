// UVa 201
/*
 * grid definition:
 * 0    1   2   3
 * 4    5   6   7
 * ...
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int check_for_square(vector<int> *graph, int grid_size, int start_vertex, int square_size)
{
    for(int i = start_vertex; i < start_vertex + square_size; i++)
    {
        if(find(graph[i].begin(), graph[i].end(), (i+1)) == graph[i].end())
        {
            return 0;
        }
    }

    for(int i = start_vertex + square_size; i < (start_vertex + square_size) + (square_size * grid_size); i += grid_size)
    {
        if(find(graph[i].begin(), graph[i].end(), (i+grid_size)) == graph[i].end())
        {
            return 0;
        }
    }

    for(int i = (start_vertex + square_size) + (square_size * grid_size); i > start_vertex + (square_size * grid_size); i--)
    {
        if(find(graph[i].begin(), graph[i].end(), (i-1)) == graph[i].end())
        {
            return 0;
        }
    }

    for(int i = start_vertex + (square_size * grid_size); i > start_vertex; i -= grid_size)
    {
        if(find(graph[i].begin(), graph[i].end(), (i-grid_size)) == graph[i].end())
        {
            return 0;
        }
    }

    return 1;
}

int number_of_squares(vector<int> *graph, int grid_size, int square_size)
{
    int total = 0;
    for(int i = 0; i < grid_size - square_size; i++)
    {
        for(int j = 0; j < grid_size - square_size; j++)
        {
            total += check_for_square(graph, grid_size, j + i * grid_size, square_size);
        }
    }
    return total;
}

int main()
{
    int grid_size;
    int count = 1;
    bool first_time = true;
    while(scanf("%d", &grid_size) != EOF)
    {
        vector<int> graph[grid_size * grid_size];
        int edges;
        cin>>edges;
        for(int i = 0; i < edges; i++)
        {
            char type; int n1, n2;
            scanf("\n%c %d %d", &type, &n1, &n2);
            n1--;
            n2--;
            if(type == 'H')
            {
                graph[n1 * grid_size + n2].push_back(n1 * grid_size + (n2+1));
                graph[n1 * grid_size + (n2+1)].push_back(n1 * grid_size + n2);
            }
            else
            {
                graph[n2 * grid_size + n1].push_back(n2 * grid_size + n1 + grid_size);
                graph[n2 * grid_size + n1 + grid_size].push_back(n2 * grid_size + n1);
            }
        }
        vector<int> squares;

        // actually check for squares
        for(int i = 1; i <= grid_size; i++)
        {
            squares.push_back(number_of_squares(graph, grid_size, i));
        }

        if(!first_time)
        {
            cout<<endl<<"**********************************"<<endl<<endl;
        }
        first_time = false;        
        cout<<"Problem #"<<count<<endl<<endl;
        bool has_squares = false;
        for(int i = 0; i < squares.size(); i++)
        {
            if(squares[i])
            {
                cout<<squares[i]<<" square (s) of size "<<i+1<<endl;
                has_squares = true;
            }
        }
        if(!has_squares)
        {
            cout<<"No completed squares can be found."<<endl;
        }
        count++;
    }
    return 0;
}