import java.util.*;

public class KnightTour{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Size of Chessboard : ");
        int n = sc.nextInt();

        int[][] matrix = new int[n+1][n+1];

        // fill with -1
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                matrix[i][j] = -1;
            }
        }

        // print matrix with -1
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=n ; j++){
//                System.out.print(matrix[i][j] + " ");
//            }
//            System.out.println();
//        }

        // moves for knight
        int[] x_moves = {2,1,-1,-2,-2,-1,1,2};
        int[] y_moves = {1,2,2,1,-1,-2,-2,-1};

        // initials

        matrix[1][1] = 0;

        int row = 1;
        int col = 1;
        int steps = 1;

        if (solution(matrix, row, col, steps, x_moves, y_moves, n)){
            for (int i=1; i<=n; i++){
                for (int j=1; j<=n; j++){
                    System.out.print(matrix[i][j] + "   ");
                }
                System.out.println();
            }
        }
        else {
            System.out.println("Solution is not possible !");
        }
    }

    private static boolean solution(int[][] matrix, int row, int col, int steps, int[] xMoves, int[] yMoves, int n) {

        if (steps == n*n){
            return true;
        }

        for (int k=0; k<n; k++){
            int next_row = row+xMoves[k];
            int next_col = col+yMoves[k];

            // if next move is valid then only check
            if (isValidMove(next_row, next_col, matrix, n)){
                matrix[next_row][next_col] = steps;
                if (solution(matrix,next_row, next_col, steps+1, xMoves, yMoves,n)){
                    return true;
                }
                matrix[next_row][next_col] = -1;
            }
        }

        return false;
    }

    private static boolean isValidMove(int nextRow, int nextCol, int[][] matrix,int n) {
// check whether the next move is valid or invalid
        return nextRow >= 1 && nextRow <= n && nextCol >= 1 && nextCol <= n && matrix[nextRow][nextCol] == -1;
    }


}
