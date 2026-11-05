//SJF CPU Scheduling non preemptive mode(process with low bt schedule first)
//let all processes arrived at same time
#include <stdio.h>
int main()
{
	int arr[100][4];
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	// User Input Burst Time and Alloting Process Id.
	for (i = 0; i < n; i++) {
    		printf("P%d: ", i + 1);
    		scanf("%d", &arr[i][1]);
    		arr[i][0] = i + 1;
	}
 	// Sorting processes according to their Burst Time.
	for (i = 0; i < n; i++) {
    		index = i;
    		for (j = i + 1; j < n; j++)
        		if (arr[j][1] < arr[index][1])
            			index = j;
            	//sorting bt column
    		temp = arr[i][1];
    		arr[i][1] = arr[index][1];
    		arr[index][1] = temp;
    		
 		//sorting process column
    		temp = arr[i][0];
    		arr[i][0] = arr[index][0];
    		arr[index][0] = temp;
	}
	
	arr[0][2] = 0;// after sorting waiting time of first process is 0
	// Calculate  Waiting Time of other processes
	for (i = 1; i < n; i++) {
    		arr[i][2] = 0;
    		for (j = 0; j < i; j++)   
        		arr[i][2] += arr[j][1];
    	total += arr[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("Process\tBT\tWT\tTAT\n");
    
	// Calculate Turnaround Time of all processes
	for (i = 0; i < n; i++) {
    		arr[i][3] = arr[i][1] + arr[i][2];
    		total += arr[i][3];
    		printf("P%d\t%d\t%d\t%d\n", arr[i][0],arr[i][1], arr[i][2], arr[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %.2f", avg_wt);
	printf("\nAverage Turnaround Time= %.2f", avg_tat);
}


