#include<stdio.h>
// calculate waiting time for all processes
void findWT(int process[], int n, int bt[], int wt[])
{
wt[0] = 0;
for (int i = 1; i < n ; i++ )
wt[i] = bt[i-1] + wt[i-1] ;
}
//calculate Turnaround time for all processes
void findTAT(int process[], int n, int bt[], int wt[], int tat[])
{
for (int i = 0; i < n ; i++)
tat[i] = bt[i] + wt[i];
}
void findavgTime( int process[], int n, int bt[])
{
int wt[n], tat[n], total_wt = 0, total_tat = 0;
findWT(process, n, bt, wt);
findTAT(process, n, bt, wt, tat);
printf("Process\tBT\tWT\tTAT\n");
for (int i=0; i<n; i++)
{
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
printf(" %d ",(i+1));
printf("\t%d", bt[i] );
printf("\t%d ",wt[i] );
printf("\t%d\n",tat[i] );
}
float avg_wt=(float)total_wt / (float)n; // average waiting time
float avg_tat=(float)total_tat / (float)n; // average turnaround time
printf("Average Waiting Time = %.2f\n",avg_wt);
printf("Average Turnaround Time = %.2f ",avg_tat);
}
int main()
{
int process[] = { 1, 2, 3, 4};
int n = sizeof process / sizeof process[0];
int burst_time[] = {12, 3, 5, 2};
findavgTime(process, n, burst_time);
return 0;
}