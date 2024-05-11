/* gedit */
/* g++ -o RRSA.out RSSA.cpp */
/* ./RRSA.out */


#include<iostream>
#include<stdio.h>
using namespace std;

struct Process{
    int processID;
    int arrivalTime;
    int brustTime;
    int exitTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(Process processes[], int noOfProcesses, int timeQuantum)
{
    int remainigTime[noOfProcesses];
    for (int i = 0; i < noOfProcesses; i++)
    {
        remainigTime[i]= processes[i].brustTime;
    }
    int currentTime = 0;
    bool done = false;
    while (!done)
    {   
        done = true;
        for (int i = 0; i < noOfProcesses; i++)
        {
            if (remainigTime[i]>0){
                done =false;
                if (remainigTime[i]> timeQuantum)
                {
                    currentTime += timeQuantum;
                    remainigTime[i] -= timeQuantum;
                }
                else
                {
                    currentTime += remainigTime[i];
                    processes[i].exitTime = currentTime;
                    remainigTime[i] = 0;
                }
            }
        }  
    }  
}

void calcualteTurnaroundTime(Process processes[], int noOfProcesses)
{
    for (int i = 0; i < noOfProcesses; i++)
        processes[i].turnaroundTime = processes[i].exitTime - processes[i].arrivalTime;
}

void calcualteWaitingTime(Process processes[], int noOfProcesses)
{
    for (int i = 0; i < noOfProcesses; i++)
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].brustTime;
}

void printTable(Process processes[], int noOfProcesses)
{
    printf("====================================================================================\n");
    printf("| Process | Arrival Time | Brust Time | Exit Time | Turnaround Time | Waiting Time |\n");
    printf("====================================================================================\n");
    for (int i = 0; i < noOfProcesses; i++)
    {
        printf("| %7d | %12d | %10d | %9d | %15d | %12d |\n", processes[i].processID, processes[i].arrivalTime, processes[i].brustTime, processes[i].exitTime, processes[i].turnaroundTime, processes[i].waitingTime);
        printf("------------------------------------------------------------------------------------\n");
    }
    
    printf("====================================================================================\n");

}


int main()
{
    int noOfProcesses, timeQuantum;

    printf(" \n");
    printf(" Enter The Number of Processes : ");
    scanf("%d", &noOfProcesses);
    printf(" \n");
    
    printf(" \n");
    printf(" Enter The Time Quantum : ");
    scanf("%d", &timeQuantum);
    printf(" \n");

    printf(" \n \n \n");

    Process *processes = new Process[noOfProcesses];

    for (int i = 0; i < noOfProcesses; i++)
    {

        int processNo = i + 1;
        printf(" Enter Process %d Details : \n", processNo);
        
        processes[i].processID = i + 1;

        printf(" \n");
        
        printf("    Arraival Time : ");
        scanf("%d",  &processes[i].arrivalTime);
        
        printf("    Brust Time : ");
        scanf("%d",  &processes[i].brustTime);
        
        printf(" \n"); 
    }

    calculateTimes(processes, noOfProcesses, timeQuantum);
    calcualteTurnaroundTime(processes, noOfProcesses);
    calcualteWaitingTime(processes, noOfProcesses);

    printf(" \n \n \n");

    printf(" Round Robin Scheduling Results : \n");

    printTable(processes, noOfProcesses);

    delete[] processes;

    return 0;
}
