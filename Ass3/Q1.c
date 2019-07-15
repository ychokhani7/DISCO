#include <stdio.h>
#define MAX 1000

int graph[MAX][MAX];
// int visited[MAX];
int degree[MAX];
int n;
int edges = 0;
int edgesPrinted = 0;

void dfs(int node, int *visitedLocal)
{

  if (visitedLocal[node] == 1)
    return;

  visitedLocal[node] = 1;
  int i;

  for (i = 0; i < n; i++)
  {
    if (graph[node][i] == 1)
    {
      dfs(i, visitedLocal);
    }
  }
}

int numNodes(int node)
{

  int visitedLocal[MAX] = {0};
  dfs(node, visitedLocal);

  int count = 0, i;

  for (i = 0; i < n; i++)
  {
    if (visitedLocal[i] == 1)
      count++;
  }

  return count;
}

void printEuler(int node)
{

  if (edgesPrinted == edges)
    return;

  printf("%d ", node);
  edgesPrinted++;
  int i, oldNum = numNodes(node);

  for (i = 0; i < n; i++)
  {
    if (graph[node][i] == 1)
    {
      graph[node][i] = 0;
      graph[i][node] = 0;
      degree[node]--;
      degree[i]--;
      if (degree[node] == 0)
      {
        printEuler(i);
      }
      else
      {
        int newNum = numNodes(node);
        if (newNum == oldNum)
        {
          printEuler(i);
        }
        else
        {
          graph[node][i] = 1;
          graph[i][node] = 1;
          degree[node]++;
          degree[i]++;
        }
      }
    }
  }
}

int main()
{
  int i, x, y, j;
  scanf("%d", &n);
  scanf("%d", &i);

  edges = i;

  while (i--)
  {
    scanf("%d %d", &x, &y);
    graph[x][y] = 1;
    graph[y][x] = 1;
    degree[x]++;
    degree[y]++;
  }

  for (i = 0; i < n; i++)
  {
    if (degree[i] % 2 == 1)
    {
      printf("-1\n");
      return 0;
    }
  }

  printEuler(0);

  printf("0\n");
  return 0;
}