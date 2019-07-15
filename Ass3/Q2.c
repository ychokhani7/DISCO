#include <stdio.h>
#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];
int inDegree[MAX];
int n;

int main()
{
  int i, x, y, start = -1, j;
  scanf("%d", &n);
  scanf("%d", &i);

  while (i--)
  {
    scanf("%d %d", &x, &y);
    graph[x][y] = 1;
    inDegree[y]++;
  }

  for (i = 0; i < n; i++)
  {
    if (inDegree[i] == 0)
      start = i;
  }

  if (start == -1)
  {
    printf("-1\n");
    return 0;
  }

  int queue[MAX] = {start, -1};
  int front = 0;
  int nextIndex = 2;

  visited[start] = 1;

  i = 0;

  while (i < n)
  {

    while (queue[front] != -1)
    {
      printf("%d ", queue[front]);

      for (j = 0; j < n; j++)
      {
        if (graph[queue[front]][j] == 1 && visited[j] == 0)
        {
          visited[j] = 1;
          queue[nextIndex++] = j;
        }
      }
      front++;
      i++;
    }

    queue[nextIndex++] = -1;
    printf("\n");
    front++;
  }

  return 0;
}