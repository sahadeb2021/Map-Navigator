/****************************************************************************/
#include<bits/stdc++.h>
#include<queue>
#include<utility>
#include "dijkstra.h"
#include "bellmon_ford.h"
using namespace std;








int main()
{
    int V,E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the number of edges : ";
    cin>>E;
    vector<vector<pair<int,int>>> edge(V);
    int x,y,w;
    
    cout<<"Enter the vertice and weights (u,v,w) "<<endl;
    for(int i=0;i<E;i++){
        cin>>x>>y>>w;
        edge[x].push_back(make_pair(y,w));
    }
    
    
    
    int src;
    cout<<"Enter the source vertex: ";
    cin>>src;
    int destination;
    cout<<"Enter the destination vertex: ";
    cin>>destination;
    
    
    
    
    cout<<"...........The result from dijkstra algorithm................"<<endl;
    dijkstra d(edge);
    d.solve(src,destination);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    
    cout<<"..........The result from bellmon ford algorithm..........."<<endl;
    bellmon_ford b(edge);
    b.solution(src,destination);// gives true when the graph doesn't contain negative cycle
                                                    // false the graph contains negative cycle
    
    cout<<endl;
    cout<<endl;
}