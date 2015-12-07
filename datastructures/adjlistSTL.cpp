/*
Stannis Baratheon's army is marching towards the Battle of Winterfell. There are many soldiers and so to keep track of them Melisandre casts a spell so that they are connected. They can be many different groups due to intensity of the spell. If soldier no. 4 and 5 belong to one group and 5 & 6 belong to one group, then 4, 5, 6 are in the same group. Now, each soldier is made capable of using all the weapons that are present in his group so that weapons can be exchanged during the war. Since, there can be a lot of exchanges, Stannis wonders, how many distinct exchanges exist in this scenario. See the example test case for more clarity.

Input:
First line contains 2 integers, N and C, the number of soldiers and the number of connections. Next, C lines follow, each containing two integers (0 based), the numbers of soldiers that are in the same group.

Output:
A single integer that corresponds to total number of distinct exchanges. Since the output can be large, print it modulo 10^9 + 7.

Constraints:
1 <= N <= 100000
1 <= C <= 100000

Sample Input:
7 3
3 4
1 0
2 5

Sample Output:
8

Explanation:
[0,1], [2,5], [3,4], [6] form groups. Within [0,1], there are 2 distinct ways of exchanging weapons, either 0 and 1 exchange weapons or they keep what they already have. Similarly for [2,5] and [3,4].
Therefore, total number of possible states of exchanges during the war = 2*2*2*1 = 8.

Note: There is no need of end line after the output.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <malloc.h>
#include <map>
#include <iomanip>
#include <queue>
#include <list>

#define FOR(i,j) for(int i=0;i<j;i++)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define sf(n) scanf("%f",&n)
#define p(n) printf("%d\n",n)
#define pl(n) printf("%ld\n",n)
#define pll(n) printf("%lld\n",n)
#define pn printf("")
#define MOD 1000000007
#define VI vector<int>

using namespace std;

list<int> adj[100010];
int visited[100010];
//int totalComponents[100010];
int tc = 0;

void DFS(int s, int selected)
{
	visited[s] = 1;
	tc++;

	if(adj[s].empty())
		return;	
	//totalComponents[selected]++;
	while(!adj[s].empty())
	{
		int z = adj[s].front();
		adj[s].pop_front();
		if(!visited[z])
			DFS(z, selected);		
	}
}


int main()
{
	int t;
	//s(t);
	//while(t--)
	//{
		int n, m, u, v;
		s(n);
		s(m);

		for(int i=0;i<m;i++)
		{
			s(u);
			s(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int components = 0;
		long long int p = 1;
		
		for(int i=0;i<n;i++)
		{
			tc = 0;
			if(!visited[i])
			{
				components++;
				DFS(i, i);
				for(int i=1;i<=tc;i++)
				{
					p = p*i;
					p = p%MOD;
				}
			}
		}

		printf("%lld\n",p);
	
		return 0;
}
