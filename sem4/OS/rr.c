//Round Robin CPU Scheduling with time quantam
//Let all processes arrived at same time
#include<stdio.h>  
   
    // find the waiting time for all processes
    void findWT(int process[], int n,int bt[], int wt[], int tq)
    {
        // Make a copy of burst times bt[] to store remaining burst times.
        int rem_bt[n];
        for (int i = 0 ; i < n ; i++)
            rem_bt[i] =  bt[i];
      
        int t = 0; // current time
     
        while(1)
        {
            int flag = 0;
      
            // Traverse all processes one by one repeatedly
            for (int i = 0 ; i < n; i++)
            {
                if (rem_bt[i] > 0)
                {
                    printf("P%d ",process[i]);
                    flag = 1; // There is a pending process
      
                    if (rem_bt[i] > tq)
                    {
                        t += tq; // how much time a process has been process
                        rem_bt[i] -= tq; // Decrease the burst_time of current process by tq
                    }
                    // If bt is smaller than or equal to tq
                    else
                    {
                        t += rem_bt[i];
                        wt[i] = t - bt[i];
                        rem_bt[i] = 0; // process complets its total bt
                    }
                }
                
            }
      		
            // If all processes are done
            if (flag == 0)
              break;
        }
    }
    void findTAT(int process[], int n, int bt[], int wt[], int tat[])
    {
        for (int i = 0; i < n ; i++)
            tat[i] = bt[i] + wt[i];
    }
    void findavgTime(int process[], int n, int bt[],int tq)
    {
        int wt[n], tat[n], total_wt = 0, total_tat = 0;
      
        findWT(process, n, bt, wt, tq);
        findTAT(process, n, bt, wt, tat);
      
        printf("\nProcess\tBT\tWT\tTAT\n");
        for (int i=0; i<n; i++)
        {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            printf("P%d\t%d\t%d\t%d\n",(i+1), bt[i],wt[i],tat[i]);
        }
      
        float avg_wt=(float)total_wt / (float)n;  // average waiting time
	float avg_tat=(float)total_tat / (float)n; // average turnaround time
	printf("Average Waiting Time = %.2f\n",avg_wt);
    	printf("Average Turnaround Time = %.2f ",avg_tat);
    }
     
    // Driver Method
    int main() 
    {
	    int process[] = { 1, 2, 3}; 
	    int n = sizeof process / sizeof process[0]; 
	    int burst_time[] = {5, 7, 13};
	    int tq = 2; 
	    findavgTime(process, n, burst_time, tq); 
	    return 0; 
    } 


