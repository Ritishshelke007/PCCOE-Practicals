import java.util.*;
public class ClubAssignment {
    private int N;
    private int[][] costMatrix;
    private int[] assignedStudents;
    private int[] assignedClubs;
    private int minCost;

    public ClubAssignment(int[][] costMatrix){
        this.N = costMatrix.length;
        this.costMatrix = costMatrix;
        this.assignedStudents = new int[N];
        this.assignedClubs = new int[N];
        Arrays.fill(assignedStudents, -1);
        Arrays.fill(assignedClubs, -1);
        this.minCost = Integer.MAX_VALUE;
    }

    public int solve(){
        backtrack(0);
        return minCost;
    }

    private boolean isFeasible(int student, int club){
        return assignedStudents[student] == -1 && assignedClubs[club] == -1;
    }

    private int bound(int[] assignedStudents,int[] assignedClubs){
        int totalCost = 0;
        for (int student = 0; student < N; student++) {
            if (assignedStudents[student] != -1) {
                totalCost +=
                        costMatrix[student][assignedStudents[student]];
            }
        }
        return totalCost;
    }

    private void backtrack(int student) {
        if (student == N) {
            int currentCost = bound(assignedStudents, assignedClubs);
            if (currentCost < minCost) {
                minCost = currentCost;
            }
            return;
        }
        for (int club = 0; club < N; club++) {
            if (isFeasible(student, club)) {
                assignedStudents[student] = club;
                assignedClubs[club] = student;
                backtrack(student + 1);
                assignedStudents[student] = -1;
                assignedClubs[club] = -1;
            }
        }
    }



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    int n = 4;
        int[][] costMatrix = new int[n][n];
        System.out.println("Enter matrix : ");
        for (int i=0; i<n; i++){
            for (int j = 0; j < n; j++) {
                costMatrix[i][j] = sc.nextInt();
            }
        }
        ClubAssignment problem = new ClubAssignment(costMatrix);
        int minCost = problem.solve();
        System.out.println("Minimum Cost: " + minCost);
    }
}
