import java.util.Scanner;
/*
INPUT:
4

0 8 -1 1
-1 0 1 -1
4 -1 0 -1
-1 2 9 0

output:
0 3 4 1
5 0 1 6
4 7 0 5
7 2 3 0

input:
4

0 3 -1 7
8 0 2 -1
3 -1 0 1
2 -1 -1 0

output:
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0
*/


public class FloydWarshall {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Total vertices : ");
        int v = sc.nextInt();

        int[][] matrix = new int[v][v];

        System.out.println("Enter matrix (input -1 if dist is inf)");
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                matrix[i][j] = sc.nextInt();
                if (matrix[i][j] == -1) {
                    matrix[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        // input matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == Integer.MAX_VALUE)
                    System.out.print("inf" + "\t");
                else
                    System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }

        int[][] result = new int[v][v];
        int[][] path = new int[v][v];

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                result[i][j] = matrix[i][j];
                path[i][j] = -1;
            }
        }

        // logic
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                for (int k = 0; k < v; k++) {
                    if (result[j][i] < Integer.MAX_VALUE && result[i][k] < Integer.MAX_VALUE) {
                        if (result[j][k] > result[j][i] + result[i][k]) {
                            result[j][k] = result[j][i] + result[i][k];
                            path[j][k] = i;
                        }
                    }
                }
            }
            System.out.println("Resultant matrix after intermediate node : " + (i + 1));
            for (int a = 0; a < v; a++) {
                try {
                    for (int b = 0; b < v; b++) {

                        System.out.print(result[a][b] + "\t");
                    }
                    System.out.println();
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
        }

        System.out.println("Final matrix");
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (result[i][j] == Integer.MAX_VALUE)
                    System.out.print("inf" + "\t");
                else
                    System.out.print(result[i][j] + "\t");
            }
            System.out.println();
        }

        int u1 = 0;
        int v1 = 1;

        int minDist = result[u1][v1];
        System.out.println("Min Dist between " + u1 + " and " + v1 + " is " + minDist);

        System.out.print("Path: ");
        printPath(path, u1, v1);

    }
    static void printPath(int[][] path, int u1, int v1){
        if (path[u1][v1] == -1) {
            System.out.print(u1 + " -> " + v1);
            return;
        }
    printPath(path, u1, path[u1][v1]);
    System.out.print(" -> " + v1); 
  } 
}
