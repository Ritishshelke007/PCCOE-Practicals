#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int process[10], arrival_time[10], burst_time[10], turn_time[10], waiting_time[10], comp_time[10],priority_time[10],temp_burst_time[10];
int n, temp, y_n, quant_time, sum, count,wait_time, tat_time;

void part1(){
  printf("Enter no of processes : ");
    scanf("%d", &n);

    printf("Enter process id : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
    }

    printf("Enter arrival time : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    printf("Enter burst time : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
    }
}

void printResult(){
    int wait_time = 0, t_time=0;
    float avg_wait_time = 0, avg_t_time=0;
    printf("\nID\tA.T\tB.T\tT.A\tW.T\tC.T\n");

    // average waiting time
    for (int i = 0; i < n; i++)
    {
        wait_time = wait_time + waiting_time[i];
        t_time = t_time + turn_time[i];
    }

    avg_wait_time = (float)wait_time / (float)n;
    avg_t_time = (float)t_time / (float)n;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival_time[i], burst_time[i], turn_time[i], waiting_time[i], comp_time[i]);
    }

    printf("Average waiting time : %f", avg_wait_time);
    printf("\nAverage Turnaround time : %f", avg_t_time);
}

void fcfs(){

    part1();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arrival_time[i] > arrival_time[j])
            {
                // sort id
                temp = process[j];
                process[j] = process[i];
                process[i] = temp;

                // sort arrival time
                temp = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp;

                // sort burst time
                temp = burst_time[j];
                burst_time[j] = burst_time[i];
                burst_time[i] = temp;
            }           
        }      
    }

    // calculation
    int sum = 0;
    sum = sum + arrival_time[0];

    for (int i = 0; i < n; i++)
    {
        sum = sum + burst_time[i];
        // completion time
        comp_time[i] = sum;
        // turnaround time
        turn_time[i] = comp_time[i] - arrival_time[i];
        // waiting time
        waiting_time[i] = turn_time[i] - burst_time[i];
        // if idle at some time then count it also
        if (sum < arrival_time[i+1])
        {
            int t = arrival_time[i + 1] - sum;
            sum = sum + t;
        }    
    }
    printResult();
}

void sjfwithoutarrival(){
     int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("Enter process id : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
/*
void sjf(){
    part1();
    // sort according to arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrival_time[i] > arrival_time[j])
            {
                temp = process[j];
                process[j] = process[i];
                process[i] = temp;

                temp = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[i];
                burst_time[i] = temp;
            }          
        }  
    }
    
    // sort according to burst time for same arrival times

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arrival_time[i] == arrival_time[j])
            {
                if (burst_time[i] > burst_time[j])
                {
                temp = process[j];
                process[j] = process[i];
                process[i] = temp;

                temp = arrival_time[j];
                arrival_time[j] = arrival_time[i];
                arrival_time[i] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[i];
                burst_time[i] = temp;
                }
                
            }
            
        }
        
    }
    
    // sjf calculation
    int value;

    comp_time[0] = arrival_time[0] + burst_time[0];
    turn_time[0] = comp_time[0] - arrival_time[0];
    waiting_time[0] = turn_time[0] - burst_time[0];

    for (int i = 1; i < n; i++)
    {
        temp = comp_time[i - 1];
        int low = burst_time[i];
        for (int j = i; j < n; j++)
        {
            if (temp >= arrival_time[j] && low >= burst_time[j])
            {
                low = burst_time[j];
                value = j;
            }
            
        }

        comp_time[value] = temp + burst_time[value];
        turn_time[value] = comp_time[value] - arrival_time[value];
        waiting_time[value] = turn_time[value] - burst_time[value];
    }

    printResult();
}
*/

void sjfPreemptive(){
    part1();

     int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = burst_time[i];

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (( arrival_time[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;

            waiting_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];
            if (waiting_time[shortest] < 0)
                waiting_time[shortest] = 0;
        }
        t++;
    }


     for (int i = 0; i < n; i++)
        turn_time[i] = burst_time[i] + waiting_time[i];

    printf("Process ID  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turn_time[i]);
    }

     int total_wait_time = 0, total_turnaround_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;


    for (int i = 0; i < n; i++)
    {
        total_wait_time += waiting_time[i];
        total_turnaround_time += turn_time[i];
    }
    
    avg_waiting_time = (float)total_wait_time / (float)n;
    avg_turnaround_time = (float)total_turnaround_time / (float)n;
    printf("\nAverage Waiting time : %f", avg_waiting_time);
    printf("\nAverage Turnaround time : %f", avg_turnaround_time);

}


void priority_scheduling() {
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int total_wait_time = 0, total_turnaround_time = 0;
    printf("\nEnter no of Process : ");
    scanf("%d", &n);

    printf("\nEnter %d process id : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    printf("Enter %d Burst Time : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }
    printf("Enter %d Priority as per process : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &priority_time[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (priority_time[j] < priority_time[j + 1]) {
                temp = process[j + 1];
                process[j + 1] = process[j];
                process[j] = temp;

                temp = burst_time[j + 1];
                burst_time[j + 1] = burst_time[j];
                burst_time[j] = temp;

                temp = priority_time[j + 1];
                priority_time[j + 1] = priority_time[j];
                priority_time[j] = temp;
            }
        }
    }

    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (int j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
        total_wait_time += waiting_time[i];
    }

    avg_waiting_time = (float)total_wait_time / n;
    total_turnaround_time = 0;
    printf("\np\tP.T\t B.T\t TAT\t WT");
    for (int i = 0; i < n; i++) {
        turn_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turn_time[i];
        printf("\nP%d\t%d\t %d \t %d \t %d", process[i], priority_time[i], burst_time[i], turn_time[i], waiting_time[i]);
    }
    avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time : %f", avg_waiting_time);
    printf("\nAverage Turnaround Time : %f", avg_turnaround_time);
}

void round_robin(){
      int i, processes, sum=0,cnt=0, y, q, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_waitt, avg_turnat;  
    printf("Enter no of processes : ");  
    scanf("%d", &processes);  
    y = processes; // Assign the number of process to variable y  
  
// Use for loop to enter the details of the process like Arrival time and the Burst Time
    printf("Enter arrival time : ");
    for (i = 0; i < processes; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("\nEnter Burst time : ");
    for (i = 0; i < processes; i++)
    {
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }



// for(i=0; i<processes; i++)  
// {  
// printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
// printf(" Arrival time is: \t");   
// scanf("%d", &at[i]);  
// printf(" \nBurst time is: \t");   
// scanf("%d", &bt[i]);  
// temp[i] = bt[i]; 
// }  
 
printf("Enter the Time Quantum : ");  
scanf("%d", &q);  
// Display the process No, burst time, Turn Around Time, and the waiting time  
printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
for(sum=0,i = 0; y!=0; )  
{  
if(temp[i] <= q && temp[i] > 0) //    
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    cnt=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - q;  
        sum = sum + q;    
    }  
    if(temp[i]==0 && cnt==1)  
    {  
        y--; //decrement the process no.  
        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        cnt =0;     
    }  
    if(i==processes-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  

avg_waitt = wt * 1.0/processes;  
avg_turnat = tat * 1.0/processes;  
printf("\n Average Turn Around Time: \t%f", avg_waitt);  
printf("\n Average Waiting Time: \t%f", avg_turnat);  
}

int main(){
    int choice,conti;
    do
    {
        printf("\n1. FCFS\n2. SJF\n3. Priority\n4. SJF Preemptive\n5. Round Robin : ");
        scanf("%d", &choice);

            switch (choice)
    {
    case 1:
        fcfs();
        break;
    
    case 2:
        sjfwithoutarrival();
        break;

    case 3:
        priority_scheduling();
        break;

    case 4:
        sjfPreemptive();
        break;

    case 5:
        round_robin();
        break;

    default:
        break;
    }

        printf("\nEnter 1 to continue: ");
        scanf("%d", &conti);
    } while (conti == 1);
    

    



    return 0;
}
