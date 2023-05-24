import java.util.*;

public class DijkstraAlgorithm {
    private static final int INF = Integer.MAX_VALUE;

    public static void dijkstra(int[][] graph, int source) {
        int numVertices = graph.length;
        int[] dist = new int[numVertices];
        boolean[] visited = new boolean[numVertices];

        // Initialize distances
        Arrays.fill(dist, INF);
        dist[source] = 0;

        for (int i = 0; i < numVertices - 1; i++) {
            int minVertex = findMinVertex(dist, visited);
            visited[minVertex] = true;

            for (int j = 0; j < numVertices; j++) {
                if (!visited[j] && graph[minVertex][j] != 0 && dist[minVertex] != INF &&
                        dist[minVertex] + graph[minVertex][j] < dist[j]) {
                    dist[j] = dist[minVertex] + graph[minVertex][j];
                }
            }
        }

        // Print the shortest distances
                System.out.println("============================");

        System.out.println("Vertex\tDistance from Source\n");
        for (int i = 0; i < numVertices; i++) {
            System.out.println(i + "\t\t" + dist[i]);
        }
    }

    private static int findMinVertex(int[] dist, boolean[] visited) {
        int minVertex = -1;
        for (int i = 0; i < dist.length; i++) {
            if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
                minVertex = i;
            }
        }
        return minVertex;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of nodes: ");
        int numNodes = scanner.nextInt();

        System.out.print("Enter the number of edges: ");
        int numEdges = scanner.nextInt();
 
        

        int[][] graph = new int[numNodes][numNodes];
        for (int i = 0; i < numEdges; i++) {
            System.out.println("\nEnter the details for edge " + (i + 1) + ":");
            System.out.print("\nSource: ");
            int source = scanner.nextInt();
            System.out.print("Destination: ");
            int destination = scanner.nextInt();
            System.out.print("Weight: ");
            int weight = scanner.nextInt();

            graph[source][destination] = weight;
        }

        System.out.println("\nEnter the starting node: ");
        int sourceNode = scanner.nextInt();

        scanner.close();

        dijkstra(graph, sourceNode);
    }
}
