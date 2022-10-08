#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> g2[N];
bool vis[N];
/*
8 6
1 2
1 5
2 3
2 4
3 5
6 7 
*/
bool dfs(int vertex, int par)
{ // When we reach the child of the vertex
   vis[vertex] = true;
   bool isloopexist = false;

   for (int child : g2[vertex])
   {
      if(vis[child] && child == par)
         continue;
      if (vis[child])
         return true;
      isloopexist = dfs(child,vertex); // Keeps going to find childs of connected vertice until all visited/unavailable
      // After traversing through the childs of the connected vertice
   }
   return isloopexist;
}
int main()
{
   int vc, e;// no. of vertices, no. of edges
   cin >> vc >> e;
   vector<int> v;
   for (int i = 0; i < e; i++)
   {
      int v1, v2;
      cin >> v1 >> v2;
      v.push_back(v1);
      g2[v1].push_back(v2);
      g2[v2].push_back(v1);
   }

   bool isloopexist = false;
   for (int i = 1; i <= vc; i++)
   {
      if (vis[i])
         continue;
      if(dfs(i,0))
      {
         isloopexist = true;
         break;
      }
   }
   cout<<isloopexist<<endl;
}
