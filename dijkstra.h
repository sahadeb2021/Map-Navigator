#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;



class compare{
    public:
        bool operator()(pair<int,int> &b,pair<int,int> &a)
        {
            return a.second < b.second;
        }
};


class dijkstra{
    private:                                // pair<vertex,weight>
        vector<vector<pair<int,int>>> edges;  // size gives the number of vertices.
    public:
        dijkstra(){};
        dijkstra(vector<vector<pair<int,int>>> e){
            edges = e;
        }
        
        
        void solve(int src,int dest)         // src :: source
        {
            // pair<vertex,distance>
            
            int V = edges.size();
            vector<int> pre_vertex(V);
            priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;   // will satisfy min heap property
            vector<int> dist(V,INT_MAX);
            dist[src] = 0;
            pre_vertex[src] = -1;
            pq.push(make_pair(src,0));
            while(!pq.empty())
            {
                pair<int,int> temp = pq.top();pq.pop(); // temp.first = vertex, temp.second = weight
                int u = temp.first;
                for(auto i : edges[u])
                {
                    int v = i.first,weight = i.second;
                    if(dist[u] != INT_MAX and dist[v] > dist[u]+weight){
                        dist[v] = dist[u] + weight;
                        pq.push(make_pair(v,dist[v]));
                        pre_vertex[v] = u;
                    }
                }
            }
            
                    
            Print_path(pre_vertex,src,dest,0);
            cout<<"The total cost is "<<dist[dest]<<endl;
            //return dist;// containing the vertex and the distance pair<vertex,distance>
        }
        
        
        void Print_path(vector<int> vertex,int src,int dest,int index)
        {
            vector<int> v;
            v.push_back(dest);
            for(int i=dest;i>src;){
                v.push_back(vertex[i]);
                i = vertex[i];
            }
            
            reverse(v.begin(),v.end());
            cout<<"The optimal path to reach the destination is ";
            cout<<v[0];
            for(int i=1;i<v.size();i++)
                cout<<"---->"<<v[i];
            cout<<endl;
        }
};



#endif