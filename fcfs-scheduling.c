#include<stdio.h>

int main()
{
    int a[25], n, i;
    int wt = 0, swt = 0;
    int tt = 0, stt = 0;

    printf("\nFIRST COME FIRST SERVE SCHEDULING PROCESS\n");

    printf("Enter the no. of jobs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nService Time or Burst Time for process %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time");

    for(i = 0; i < n; i++)
    {
        swt = swt + wt;

        tt = tt + a[i];

        stt = stt + tt;

        printf("\nP%d\t%d\t\t%d\t\t%d", i, a[i], wt, tt);

        wt = wt + a[i];
    }

    printf("\n\nAverage Waiting Time = %d", swt / n);

    printf("\nAverage Turn Around Time = %d", stt / n);

    return 0;
}