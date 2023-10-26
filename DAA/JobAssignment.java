import java.util.*;

public class JobAssignment {

    public static void main(String[] args) {
        //int[][] matrix = new int[4][4];
        Scanner sc = new Scanner(System.in);

        // System.out.println("Enter Person - Job Cost : ");
        // for(int i=0; i<4; i++){
        //     for(int j=0; j<4; j++){

        //     }
        // }
        int[][] matrix = {
            {8,5,4,6},
            {1,3,7,5},
            {6,2,5,8},
            {7,3,7,6}
        };
        System.out.println("Given Person Job Matrix : ");
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix.length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

      int lb_count = 0;
       

        for(int i=0; i<matrix.length; i++){
            int lb = Integer.MAX_VALUE;
            for(int j=0; j<matrix.length; j++){
                if (matrix[i][j] < lb){
                    lb = matrix[i][j]; 
                }                      
            }
            lb_count += lb;
        }
        System.out.println("Lower Bound : "+lb_count);

        boolean[] finalJob = new boolean[4];
        boolean[] person = new boolean[4];

        
        int jobLeastCost = 0;

        for (int i = 0; i < matrix.length; i++) {
            
            int minOfRow = Integer.MAX_VALUE;
            boolean[] innerJobs = new boolean[4];

            for (int j = 0; j < matrix.length; j++) {
                if(i==j) {
                    minOfRow = matrix[i][j];
                    innerJobs[j] = true;
                    break;
                } 

                if (innerJobs[j] != true) {
                    if(matrix[i][j] < minOfRow){
                        minOfRow = matrix[i][j];
                    }
                }
                
            }
            jobLeastCost += minOfRow;
        }

        System.out.println(jobLeastCost);

    












    }
}
