import java.util.*;

public class Dijkstra {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Total vertices : ");
        int vertices = sc.nextInt();

        System.out.print("Total edges : ");
        int edges = sc.nextInt();

        int[][] graph = new int[vertices][vertices];

        System.out.println("Enter edges : ");
        System.out.println("Node 1 | Node 2 | Weight");
        for(int i=0; i<edges; i++){
            int node1 =sc.nextInt();
            int node2 = sc.nextInt();
            int weight = sc.nextInt();

            graph[node1][node2] = weight;
        }

        System.out.println("Graph is : ");
        for(int i=0;i<vertices;i++){
            for(int j=0; j<vertices; j++){
                System.out.print(graph[i][j] + " ");
            }
            System.out.println();
        }

        System.out.print("Enter source vertex : ");
        int sourceVertex = sc.nextInt();

        dijkstraAlgorithm(graph,sourceVertex);
    }

    private static void dijkstraAlgorithm(int[][] graph, int sourceVertex) {
        int infinity = Integer.MAX_VALUE;
        int dist[] = new int[graph.length];
        Arrays.fill(dist,infinity);

        ArrayList <Integer> sequenceArray = new ArrayList<>();

        boolean[] visited = new boolean[graph.length];
        dist[sourceVertex] = 0;


        for(int i=0;i<graph.length;i++){
        int nextVertex = findNextMin(graph,dist,visited,sequenceArray);
        System.out.println("Next min vertex : "+nextVertex);
        visited[nextVertex] = true;
        sequenceArray.add(nextVertex);

        for (int j = 0; j < graph.length; j++) {
            if (!visited[j] && graph[nextVertex][j] != 0 && dist[nextVertex] != infinity &&
                    dist[nextVertex] + graph[nextVertex][j] < dist[j]) {
                dist[j] = dist[nextVertex] + graph[nextVertex][j];
            }
        }
    }

        System.out.println("Vertex | Dist from SourceVertex");
        for(int i=0;i<graph.length;i++){
            System.out.println(i+ " " +dist[i]);
        }
        
        System.out.println("Sequence : "+sequenceArray);
        
    }

    private static int findNextMin(int[][] graph, int[] dist, boolean[] visited,ArrayList<Integer> sequenceArray) {
        int nextVertex = -1;

        for(int i=0;i<graph.length;i++){
            if(!visited[i] && (nextVertex==-1 || dist[i] < dist[nextVertex])){
                nextVertex = i;
            }
        }

        return nextVertex;
    }
}
