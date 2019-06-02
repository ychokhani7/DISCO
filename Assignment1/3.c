#include <stdio.h>
#include <stdlib.h>
typedef struct {
    unsigned int first;
    unsigned int second;
} edge;
void connected_components_recursive(const edge *edges, unsigned int n, int *components, unsigned int order, unsigned int vertex,
        unsigned int component)
{
    unsigned int i;
    /* Put this vertex in the current component */
    components[vertex] = component; 
    for (i = 0; i < n; i++) {
        if (edges[i].first == vertex || edges[i].second == vertex) {
            /* Adjacent */
            const unsigned int neighbour = edges[i].first == vertex ?
                    edges[i].second : edges[i].first;
            if (components[neighbour] == -1) {
                /* Not yet visited */
                connected_components_recursive(edges, n, components, order, neighbour, component);
            }
        }
    }
}
 
unsigned int connected_components(const edge *edges, unsigned int n, unsigned int order, int **components)
{
    unsigned int i;
    unsigned int component = 0;
    *components = malloc(order * sizeof(int));
    if (components == NULL) {
        return 0;
    }
    for (i = 0; i < order; i++) {
        (*components)[i] = -1;
    }
     
    for (i = 0; i < order; i++) {
        if ((*components)[i] == -1) {
            connected_components_recursive(edges, n, *components, order, i, component);
            component++;
        }
    }
    return component;
}
int main(void)
{
    int order;
    int n;
    scanf("%d %d",&order,&n);
    edge *edges;
    int *components;
    unsigned int c;
    
    edges = malloc(n * sizeof(edge));
    if (edges == NULL) {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&edges[i].first,&edges[i].second);
    }
    c = connected_components(edges, n, order, &components);
    if (components == NULL) {
        free(edges);
        return 1;
    }
    printf("%d",c);
    free(edges);
    free(components);
 
    return 0;
}