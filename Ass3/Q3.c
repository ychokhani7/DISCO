#include <stdio.h>
#define MAX 1000

char graph[MAX][MAX];
int visited[MAX];
int inDegree[MAX];
int scores[MAX];
int n;

void dfs(int node, int score)
{

  if (visited[node] == 1)
    return;

  visited[node] = 1;
  scores[node] = score;

  int i;

  for (i = 0; i < n; i++)
  {

    if (graph[node][i] == 'l' && visited[i] == 0)
    {
      dfs(i, score - 1);
    }
    else if (graph[node][i] == 'r' && visited[i] == 0)
    {
      dfs(i, score + 1);
    }
  }
}

int main()
{
  int i, x, y, start = -1, j;
  char c;
  scanf("%d", &n);
  scanf("%d", &i);

  while (i--)
  {
    scanf("%d %d %c", &x, &y, &c);
    graph[x][y] = c;
    inDegree[y]++;
  }

  for (i = 0; i < n; i++)
  {
    if (inDegree[i] == 0)
      start = i;
  }

  dfs(start, 0);

  int group = 65;
  int count = 0;

  for (i = -n; i <= n; i++)
  {
    int found = 0;

    for (j = 0; j < n; j++)
    {
      if (scores[j] == i)
      {
        found = 1;
      }
    }

    if (found == 1)
      count++;
  }

  printf("%d\n", count);

  for (i = -n; i <= n; i++)
  {
    int found = 0;

    for (j = 0; j < n; j++)
    {
      if (scores[j] == i)
      {
        if (found == 0)
        {
          found = 1;
          printf("%c: ", group);
          group++;
        }
        printf("%d ", j);
      }
    }

    if (found == 1)
      printf("\n");
  }
  return 0;
}