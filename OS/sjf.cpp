#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct process {
	int pid;
	int burst_time;
	int arrival_time;
};


void findWaitingTime(process pro[], int n, int waiting_time[]){
	int rt[n];
	
	for (int i=0; i<n; i++){
	
		rt[i] = pro[i].burst_time;
		
		int complete = 0, t = 0, minm = INT_MAX;
		int shortest = 0, finish_time;
		bool check = false;
		
		
		while (complete != n) {
		      for (int j = 0; j < n; j++) {
			 if ((pro[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) {
			    minm = rt[j];
			    shortest = j;
			    check = true;
			 }
		      }
		      if (check == false) {
			 t++;
			 continue;
		      }
		      
		      rt[shortest]--;  // decrementing the remaining time
		      
		      minm = rt[shortest];
		      if (minm == 0)
			 minm = INT_MAX;
			 
			 if (rt[shortest] == 0) {
			    complete++;
			    check = false;
			    finish_time = t + 1;
			    // Calculate waiting time
			    waiting_time[shortest] = finish_time - pro[shortest].burst_time - pro[shortest].arrival_time;
			    if (waiting_time[shortest] < 0)
			       waiting_time[shortest] = 0;
			 }        
			 t++;
   }
}

}


void findTurnaroundTime(process pro[], int n, int waiting_time[], int turnaround_time[]){

	for (int i=0; i<n; i++){
	
		turnaround_time[i] = pro[i].burst_time + waiting_time[i];
	
	}


}
	


void findAverageTime(process pro[], int n){
	int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
	
	findWaitingTime(pro, n, waiting_time);  // find waiting time for processes;
	
	findTurnaroundTime(pro, n, waiting_time, turnaround_time); // find turnaround time
	
	cout << "Process ID " << " Burst Time" << " Waiting Time" << " Turnaround Time\n";
	
	for (int i=0; i<n; i++){
	
		total_waiting_time +=  waiting_time[i];
		total_turnaround_time += turnaround_time[i];
		cout << pro[i].pid << "\t\t" << pro[i].burst_time << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl; 
	
	}  
	
	cout << "\nAverage Waiting Time " << (float)total_waiting_time/(float)n;
	cout << "\nAverage Turnaround Time : " << (float)total_turnaround_time/(float)n;
	
}

int main (){

	cout << "Hello";
	process pro[] =  {{ 1, 5, 1 }, { 2, 3, 1 }, { 3, 6, 2 }, { 4, 5, 3 } };
	int n = sizeof(pro) / sizeof(pro[0]);
	cout << n;
	findAverageTime(pro,n);

	return 0;
}
