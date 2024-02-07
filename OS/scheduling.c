#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>


int process[10], arrival_time[10], burst_time[10], waiting_time[10], turnaround_time[10], temp_burst_time[10], priority_time[10];

int n, i, j, temp, quant_time, y_n, sum, count, wait_time, tat_time;

void part1() {
    printf("\nEnter no of Process : ");
    scanf("%d", &n);

    printf("\nEnter %d process id : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    printf("Enter %d Arrival time:", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }
    printf("Enter %d Burst time:", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }
}

void average() {

    int total_wait_time = 0, total_turnaround_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;


    for (int i = 0; i < n; i++)
    {
        total_wait_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    
    avg_waiting_time = (float)total_wait_time / (float)n;
    avg_turnaround_time = (float)total_turnaround_time / (float)n;
    printf("\nAverage Waiting time : %f", avg_waiting_time);
    printf("\nAverage Turnaround time : %f", avg_turnaround_time);
}

void part2() {
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int total_wait_time = 0, total_turnaround_time = 0;
    waiting_time[0] = 0;
    turnaround_time[0] = waiting_time[0] + burst_time[0];
    for (i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_wait_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time = (float)total_wait_time / (float)n;
    avg_turnaround_time = (float)total_turnaround_time /(float)n;
    printf("\np\t A.T\t B.T\t TAT\t WT");

    for (i = 0; i < n; i++) {
        printf("\nP%d\t %d\t %d \t %d \t %d", process[i], arrival_time[i], burst_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("\nAverage Waiting time : %f", avg_waiting_time);
    printf("\nAverage Turnaround time : %f", avg_turnaround_time);

}

void fcfs_scheduling() {
    part1();
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i); j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                temp = process[j + 1];
                process[j + 1] = process[j];
                process[j] = temp;

                temp = arrival_time[j + 1];
                arrival_time[j + 1] = arrival_time[j];
                arrival_time[j] = temp;

                temp = burst_time[j + 1];
                burst_time[j + 1] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }
    part2();
}

void sjf_scheduling() {
    part1();
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                temp = process[j + 1];
                process[j + 1] = process[j];
                process[j] = temp;

                temp = burst_time[j + 1];
                burst_time[j + 1] = burst_time[j];
                burst_time[j] = temp;

                temp = arrival_time[j + 1];
                arrival_time[j + 1] = arrival_time[j];
                arrival_time[j] = temp;
            }
        }
    }

    part2();
}

void round_robin_scheduling() {
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int total_wait_time = 0, total_turnaround_time = 0;
    printf("\nEnter no of Process : ");
    scanf("%d", &n);
    y_n = n;

    printf("\nEnter %d process id : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    printf("Enter %d Arrival Time:", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }
    printf("Enter %d Burst Time:", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    printf("Enter the Time Quantum : \n");
    scanf("%d", &quant_time);

    printf("\n Process id \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y_n != 0;) {
        if (temp_burst_time[i] <= quant_time && temp_burst_time[i] > 0) {
            sum = sum + temp_burst_time[i];
            temp_burst_time[i] = 0;
            count = 1;
        } else if (temp_burst_time[i] > 0) {
            temp_burst_time[i] = temp_burst_time[i] - quant_time;
            sum = sum + quant_time;
        }
        if (temp_burst_time[i] == 0 && count == 1) {
            y_n--;
            printf("\nP[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);
            wait_time = wait_time + sum - arrival_time[i] - burst_time[i];
            tat_time = tat_time + sum - arrival_time[i];
            count = 0;
        }
        if (i == n - 1) {
            i = 0;
        } else if (arrival_time[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    avg_waiting_time = wait_time * 1.0 / n;
    avg_turnaround_time = tat_time * 1.0 / n;
    printf("\n Average Turnaround Time: \t%f", avg_waiting_time);
    printf("\n Average Waiting Time: \t%f", avg_turnaround_time);
}

void priority_scheduling() {
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int total_wait_time = 0, total_turnaround_time = 0;
    printf("\nEnter no of Process : ");
    scanf("%d", &n);

    printf("\nEnter %d process id : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    printf("Enter %d Burst Time : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }
    printf("Enter %d Priority as per process : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &priority_time[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
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

    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
        total_wait_time += waiting_time[i];
    }

    avg_waiting_time = (float)total_wait_time / n;
    total_turnaround_time = 0;
    printf("\np\tP.T\t B.T\t TAT\t WT");
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("\nP%d\t%d\t %d \t %d \t %d", process[i], priority_time[i], burst_time[i], turnaround_time[i], waiting_time[i]);
    }
    avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time : %f", avg_waiting_time);
    printf("\nAverage Turnaround Time : %f", avg_turnaround_time);

}

void sjf_preemptive() {
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
        turnaround_time[i] = burst_time[i] + waiting_time[i];

    printf("Process ID  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    average();
}

int main() {
    int choice, ch;
    do {
        printf("\n1. FCFS\n2. SJF (Non Preemptive)\n3. SJF (Preemptive)\n4. Priority\n5. Round Robin\n6.Exit");
        printf("\nEnter Your choice :");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fcfs_scheduling();
                break;
            case 2:
                sjf_scheduling();
                break;
            case 3:
                sjf_preemptive();
                break;
            case 4:
                priority_scheduling();
                break;
            case 5:
                round_robin_scheduling();
                break;
            case 6:
                exit(0);
                break;
            default:
                break;
        }
        printf("\n-------------------------------------------------");
        printf("\nDo You want to continue press 1 :\n");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}
