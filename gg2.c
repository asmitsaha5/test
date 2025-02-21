#include <stdio.h>

void sortProcesses(int processes[], int n, int bt[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {

                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    sortProcesses(processes, n, bt);
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("\nProcess  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("  %d\t     %d\t       %d\t        %d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    findAvgTime(processes, n, burst_time);
    return 0;
}
