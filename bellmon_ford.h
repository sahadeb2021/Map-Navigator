#pragma once
#ifndef BELLMON_FORD_H
#define BELLMON_FORD_H
#include<vector>
#include<limits.h>
using namespace std;




class bellmon_ford : public dijkstra
{
    private:
        vector<vector<pair<int,int>>> edge;
    public:
        bellmon_ford(){};
        bellmon_ford(vector<vector<pair<int,int>>> e)
        {
            edge = e;
        }
        
        void solution(int src,int dest)
        {
            int V = edge.size();
            vector<int> pre_vertex(V);
            vector<int> dist(V,INT_MAX);
            dist[src] = 0;
            for(int i=0;i<V-1;i++)
            {
                for(int j = 0;j<V;j++) // gives u
                    for(auto k : edge[j]) //gives v and w
                    {
                        int v = k.first,w = k.second;
                        if(dist[j] != INT_MAX and dist[v] > dist[j] + w){
                            dist[v] = dist[j] + w;
                            pre_vertex[v] = j;
                        }
                    }
                        
            }
            
            
            for(int j = 0;j<V;j++)
                for(auto k : edge[j])
                {
                    int v = k.first,w = k.second;
                    if(dist[j] != INT_MAX and dist[v] > dist[j] + w)
                    {
                        cout<<"graph contains negative cycle"<<endl;
                    }
                }
                
            //return dist;
            
            Print_path(pre_vertex,src,dest,0);
            cout<<"The total cost is "<<dist[dest]<<endl;
            // the function will return true if the graph does not contain any negative cycle.
        }
};




#endif