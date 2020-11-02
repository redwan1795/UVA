/*
Write your code to find the shortest path between the nodes. You can assume the
graphs are undirected for task2.
Input: In the first line of the input you will be given the number of vertices(V) and the numbers
of edges(E) of the graph. The remaining lines of the input indicate the connection between the
vertices. Find the shortest path between the smallest and largest vertices in the graph.
Please see the following examples for a better understanding of the problem statement.
Example 1:
3 2 //3 Vertices, 2 Edges
1 2
1 3
Output
1 //shortest path from node 1 to node 3 
Example 2:
3 2
1 2
2 3
Output:
2 //shortest path from node 1 to node 3
*/

#include <stdio.h>

#define SIZE 100 // Highest number of Vertex

int Matrix[SIZE][SIZE]; //Adjancency Matrix
int Vertex[SIZE];

int input [8], output[8], visited[8];

int min = 11111;

int solve(int output[], int source, int destination)
{
    
    int length = 0;
    for (int i=0; output[i];i++)
        length++;
    
    
    int count = 0;
    int updateMin = 0;
        
    for (int i=0; i<length ; i++)
    {
     
        //printf("i: %d output[i]: %d output[i+1]: %d\n", i, output[i], output[i+1]);
        if (output[i+1] != 0 && Matrix[output[i]][output[i+1]] == 1)
        {
            //printf("Inn\n");
            count++;
            
            if (output[i+1] == destination )
                updateMin = 1;
            else
                updateMin = 0;
        }
        else if (output[i+1] != 0)
        {
            //printf("Out\n");
            break;
        }
        
        /*
        if(updateMin)
        {
            if (count> min)
            {
                //printf()
                min = count;
                printf("solve - min: %d count: %d \n",min ,count);
            }
        }
        */
        
                
    }

    if(!updateMin) // this min is not acceptable as it does not reach to the destination node
        return 11111;
    
    return count;
}

void permutation (int level, int V, int source, int destination)
{
    if (level == V)
    {
        for (int i =0 ; i<V; i++)
        {
            //printf("%d ", output[i]);
        }
        //printf("\n");
        //printf("cal-min: %d \n",solve(output,source, destination));
        int result = solve(output,source, destination);
        if(result< min)
            min = result;
        
        return;
    }
    
    for (int i =0 ; i < V; i++)
    {
        if(visited[i] == 0)
        {
            output[level] = input[i];
            
            if (output[0] == source)
            {
                visited[i] = 1;
                permutation(level+1, V, source, destination);
                visited[i] = 0;   
            }
            
        }
    }
}

void initVertexArray(int V, int source, int destination)
{
    for (int i = 1; i <= V; i++)
    {
        Vertex[i] = 1;// initializing true to the all vertex
        input[i-1] = i;
    }
    permutation(0,V, source, destination);
}

void initGraph(int V)//initializing adjacency Matrix
{
    for (int i = 0; i<V; i++ )
    {
        for (int j = 0; j<V; j++ )
        {
            Matrix[i][j] = 0;
        }
    }
}

void testPrintGraph(int V)
{
    for (int i = 0; i<=V; i++ )
    {
        for (int j = 0; j<=V; j++ )
        {
            printf("%d ", Matrix[i][j]);     
        }
        printf("\n");
    }
    
}

int main()
{
   FILE *fp;
   
   fp = fopen("test.txt", "r");
   int V, E;
   
   scanf ("%d %d",&V, &E);
   
   
   initGraph(V);
   
   for(int i =0; i< E; i++)
   {
       int source, destination;
       scanf("%d %d", &source, &destination);
       //printf("Source: %d Destination: %d \n", source, destination);
       
       Matrix[source][destination] = 1;
       Matrix[destination][source] = 1;
   }
   
   //testPrintGraph(V);
   initVertexArray(V, 4,8); // to measure shortest path from 1 to 3
   //printf("%d %d\n", V, E);
   printf("%d\n", min );
}
