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
        int infinity = Integer.MAX_VALUE;

        // System.out.print("Enter no of vertices : ");
        // int n = sc.nextInt();

        // System.out.print("No of edges : ");
        // int edges = sc.nextInt();
        // int[][] matrix = {
        //     {0,3,infinity,7},
        //     {8,0,2,infinity},
        //     {5,infinity,0,1},
        //     {2,infinity,infinity,0}
        // };

        int[][] matrix = {
            {0,8,infinity,1},
            {infinity,0,1,infinity},
            {4,infinity,0,infinity},
            {infinity,2,9,0}
        };

        for(int i=0;i<4;i++){
            for(int j=0; j<4;j++){
                if(matrix[i][j]==infinity){
                    System.out.print("∞" + " ");
                }
                else{
                    System.out.print(matrix[i][j] + " ");
                }
            }
            System.out.println();
        }

        // shortest distance from intermediate nodes
        findDist(matrix,4,infinity);

    }
    static void findDist(int[][] matrix,int v,int infinity){
        int[][] result = new int[v][v];

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                result[i][j] = matrix[i][j];
            }
        }

        for(int i=0; i<v;i++){
            for(int j=0;j<v;j++){
                for(int k=0;k<v;k++){
                    if (result[j][i]<infinity && result[i][k]<infinity) {
                        if(result[j][k] >= result[j][i]+result[i][k]){
                            result[j][k] = result[j][i]+result[i][k];
                        }
                    }
                }
            }
            System.out.println("Matrix after intermediate node : "+i);
            for(int a=0;a<v;a++){
                for(int b=0;b<v;b++){
                    if(result[a][b]==infinity){
                        System.out.print("∞" + " ");
                    }
                    else{
                        System.out.print(result[a][b] + " ");
                    }
                }
                System.out.println("");
            }
        }

    }
}
