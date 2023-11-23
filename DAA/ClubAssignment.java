import java.util.*;

public class ClubAssignment {

  private int N;
  private int[][] costMatrix;
  private int[] assignedStudents; 
  private int[] assignedClubs;
  
  private int minCost = Integer.MAX_VALUE;
  private int[] optimalAssign;

  public ClubAssignment(int[][] costMatrix) {
    this.N = costMatrix.length;
    this.costMatrix = costMatrix;
    
    this.assignedStudents = new int[N];
    this.assignedClubs = new int[N];
    
    Arrays.fill(assignedStudents, -1);
    Arrays.fill(assignedClubs, -1);
    
    this.optimalAssign = new int[N];
  }

  public void solve() {
    backtrack(0);
    
    System.out.println("Minimum Cost: " + minCost);
    
    for(int i = 0; i < N; i++) {
      System.out.print("Student " + i + " assigned to Club ");
      System.out.println(optimalAssign[i]);
    }
  }

  private boolean isFeasible(int student, int club) {
    return (assignedStudents[student] == -1 && assignedClubs[club] == -1); 
  }

  private void backtrack(int student) {   
    if(student == N) {
      int[] temp = Arrays.copyOf(assignedClubs, N);
      int currCost = calculateCost(assignedClubs);
      
      if(currCost < minCost) {
        minCost = currCost;
        optimalAssign = temp;
      }
      return;
    }
    
    for(int club = 0; club < N; club++){
      if(isFeasible(student, club)){ 
        assignedStudents[student] = club;
        assignedClubs[club] = student;
       
        backtrack(student+1);
        
        assignedStudents[student] = -1; 
        assignedClubs[club] = -1;
      }
    }
  }

  int calculateCost(int[] assignedClubs) {
    int cost = 0;
    for(int i = 0; i < N; i++) {
      int club = assignedClubs[i];
      cost += costMatrix[i][club];
    }
    return cost;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int n = 3;
    int[][] costMatrix = new int[n][n];
    
    System.out.println("Enter cost matrix");
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        costMatrix[i][j] = sc.nextInt();
      }
    }
        
    ClubAssignment ca = new ClubAssignment(costMatrix);
    ca.solve();
  } 
}
