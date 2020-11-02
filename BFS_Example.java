/*
Write your code to implement Breadth-First Search. You can assume graphs are
directed for task1.
Input: In the first line of input, you are given two integers V and E, Where V and E indicate the
number of vertices and edges of the graph respectively. The remaining lines of the input indicate
the connection between the vertices. Please see the following example for a better understanding.
Example 1:
4 3
0 1 0 3 3 2
The graph has 4 vertices(Nodes) and three edges. Node 0 has an edge to 1, and 3. similarly node
3 has an edge to node 2. The above example can be visualized in the following way.
Output:
0132

*/

import java.util.*;

public class BFS
{
    static int[][] Matrix = new int[100][100];
    //static Hashtable<Integer, Integer> AdjacencyList = new Hashtable<Integer, Integer>(); //Source, Destination
   
    public BFS()
    {
    }
   
   
    private static void initGrpah(int V)
    {
        for (int i=0; i<V; i++)
        {
            for (int j=0; j<V; j++)
            {
                Matrix[i][j] = 0; // initializing the V*V size with 0
            }
        }
    }
   
   
    private static void printMatrix(int V)
    {
        for (int i=0; i<V; i++)
        {
            for (int j=0; j<V; j++)
            {
                System.out.printf("%d ", Matrix[i][j]);
            }
            System.out.println("");
        }
    }
    /*
    private static void printList(int E)
    {
        Enumeration keys;
        Integer str;
        keys = AdjacencyList.keys();
       
        while(keys.hasMoreElements())
        {
            str = (Integer) keys.nextElement();
            System.out.println(str + ": " + AdjacencyList.get(str));
        }
    }
    */
   
    public static void OnBFS(int startNode, int V)
    {
        Queue<Integer> q = new LinkedList<>();
       
        boolean visitedVertex[] = new boolean[V]; // Default elements are false
       
        visitedVertex[startNode] = true;
        q.add(startNode);
       
        int out;       
        while (q.size() != 0)
        {
            out = q.remove();
            System.out.print(out+" ");
           
            for (int j = 0; j<V; j++)
            {
                if (Matrix[out][j] == 1 && visitedVertex[j] == false)
                {
                    //System.out.printf("%d", startNode);
                    q.add(j);
                    visitedVertex[j] = true;
                }
            }
        }
       
       
    }

     public static void main(String []args)
     {
         
        int V, E;
        Scanner myScanner = new Scanner(System.in);
       
        V = myScanner.nextInt();
        //System.out.printf("%d ", V);
       
        initGrpah(V);
       
        E = myScanner.nextInt();
        //System.out.printf("%d ", E);
       
        int count = 0;
       
        while(myScanner.hasNext() && count <E*2)
        {
            int input1 = myScanner.nextInt();
            int input2 = myScanner.nextInt();
           
            //System.out.printf("Source: %d Destination: %d \n", input1, input2);
           
            //AdjacencyList.put(input1, input2); // inserting into AdjacencyList
           
            //Inserting into Adjacency Matrix
            Matrix[input1][input2] = 1;  
            Matrix[input2][input1] = 1;
            count++;
        }
       
        printMatrix(V);
        OnBFS(2,V);// 0 is the start Node and always have to be for this implementation
       
        //printMatrix(V);
        //printList(E);
       
     }
}
