#include <stdio.h>
#include <stdlib.h>
typedef int flag;
struct Edge
{
    long long int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    long long int V, E;
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
struct subset
{
    long long int parent;
    long long int rank;
    //flag modified;
};
// Creates a graph with V vertices and E edges
struct Graph* createGraph(long long int V, long long int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}

long long int fact(long long int x)
{
	if(x<=1)
		return 1;
	return (x*fact(x-1))%1000000007;
}

long long int find(struct subset subsets[], long long int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        {subsets[i].parent = find(subsets, subsets[i].parent);
        }
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], long long int x, long long int y)
{
    long long int xroot = x;
    long long int yroot = y;

    if (xroot < yroot)
        {subsets[xroot].parent = yroot;
            //subsets[xroot].modified=1;
        	subsets[yroot].rank += subsets[xroot].rank;
        }
    else //if (subsets[xroot].rank > subsets[yroot].rank)
        {subsets[yroot].parent = xroot;
            //subsets[yroot].modified=1;
        	subsets[xroot].rank += subsets[yroot].rank;
        } 
}
 
// The main function to check no of cycle in graph
long long int connection( struct Graph* graph )
{
	long long int v,e;
    long long int V = graph->V;
    long long int E = graph->E;
 
    // Allocate memory for creating V sets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    for (v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 1;
        //subsets[v].modified=0;
    }
 
    // Iterate through all edges of graph, find sets of both
    // vertices of every edge, if sets are same, then there is
    // cycle in graph.
    for(e = 0; e < E; ++e)
    {
        long long int x = find(subsets, graph->edge[e].src);
        long long int y = find(subsets, graph->edge[e].dest);
 
        if(x!=y)
            Union(subsets, x, y);
    }
long long int connectedcomponents=0;
    for(v = 0; v < V; ++v)
    {
    	//printf("%lld :rank=%lld parent=%lld\n",v,subsets[v].rank,subsets[v].parent);
    	if(subsets[v].parent==v)
    	{connectedcomponents++;
    	}
    }
    printf("No of connected components in graph = %ld\n",connectedcomponents );
    return connectedcomponents;
    
}
 
int main()
{
 
    long long int n, c,i;
    scanf("%lld%lld",&n,&c);
	if(n==0) {printf("0");return 0;}
    struct Graph* graph = createGraph(n, c);
 
    // add edge
    for(i=0;i<c;i++)
    {
    	scanf("%lld%lld",&graph->edge[i].src,& graph->edge[i].dest);
    }
    connection(graph);
    return 0;

}
