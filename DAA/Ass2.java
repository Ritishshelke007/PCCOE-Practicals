import java.util.*;
import java.util.Scanner;

class Jobs{
    String id;
    int deadline;
    int profit;
    Jobs(String id,int deadline, int profit){
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
    @Override
    public String toString() {
        return "Job ID: " + id + ", Deadline: " + deadline + ", Profit: " + profit;
    }
}

public class Ass2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList <Jobs> arr = new ArrayList<>();

        System.out.print("Enter total Jobs : ");
        int n = sc.nextInt();
        System.out.println("Job Id : Job Deadline : Job Profit : ");
        for (int i=0; i<n;i++){
            String id = sc.next();
            int deadline = sc.nextInt();
            int profit = sc.nextInt();

            arr.add(new Jobs(id,deadline,profit));
        }

        // Sort the arr in descending order using comparator
        arr.sort(Comparator.comparingInt((Jobs jobs) -> jobs.profit).reversed());


        // find max deadline
        int maxDeadline = 0;
        for (Jobs job: arr) {
            if (job.deadline > maxDeadline){
                maxDeadline = job.deadline;
            }
        }
        System.out.println("Max deadline is : "+maxDeadline);

        // print
        System.out.println("Sorting jobs : ");
        for (Jobs jobs : arr) {
            System.out.println(jobs);
        }

        // initialise an array
        int[] deadlineBool = new int[maxDeadline+1];
        Arrays.fill(deadlineBool,-1);

        // logic
        int count =0;
        int profit =0;
        ArrayList <Jobs> resultArr = new ArrayList<>();

        for (Jobs job: arr){
            if (count < maxDeadline){
                if (deadlineBool[job.deadline]==-1){
                    deadlineBool[job.deadline] = 1;
                    profit+= job.profit;
                    count+=1;
                    resultArr.add(job);
                }
                else {
                    for (int i = job.deadline;i>=1; i--){
                        if (deadlineBool[i]==-1){
                            deadlineBool[i] = 1;
                            profit+= job.profit;
                            count+=1;
                            resultArr.add(job);
                            break;
                        }
                    }
                }
            }
        }

        System.out.println("\nSequence of Jobs according to maximum profit : ");
        for (Jobs job: resultArr){
            System.out.println(job);
        }
        System.out.println("Total profit is : "+profit);
    }
}
