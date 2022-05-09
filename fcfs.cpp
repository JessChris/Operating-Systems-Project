//this is the first come first serve process sheduler
#include <iostream>
using namespace std;

//calculating the witing time for the processes
void waitingTime(int processes[], int burstT[], int waitT[])
{
	//waiting time for the intial process will be set to 1
	waitT[0] = 0;

	//calculating the waiting time, start from the second process
	for (int i = 1; i < 4; i++)
	{
		waitT[i] = burstT[i - 1] + waitT[i - 1];
	}
}

// function to calculate turn around time
void findTurnAroundTime(int processes[], int burstT[], int waitT[], int turnAroundT[])
{
    // calculate the turn around time by adding the burst time to the wait time
    for (int i = 0; i < 4; i++)
    {
        turnAroundT[i] = burstT[i] + waitT[i];
    }
}

// calculating the average time
void findAverageTime(int processes[], int burstT[])
{
    int waitT[4];
    int turnAroundT[4];
    int totalWaitT = 0;
    int totalTurnAround = 0;

    // finding wait time for all the processes
    waitingTime(processes, burstT, waitT);

    // finding the turn around time for every process
    findTurnAroundTime(processes, burstT, waitT, turnAroundT);

    // displaying the details
    cout << "Processes  " << " Burst time  " << " Waiting time  " << " Turn around time"<<endl;

    // calculating the total wait time and turn around time
    for (int i = 0; i < 4; i++)
    {
        totalWaitT += waitT[i];
        totalTurnAround += turnAroundT[i];
        cout << "   " << i + 1 << "\t\t" << burstT[i] << "\t    " << waitT[i] << "\t\t  " << turnAroundT[i] << endl;
    }

    cout << "Average waiting time = " << (float)totalWaitT / (float)4;
    cout <<endl<< "Average turn around time = " << (float)totalTurnAround / (float)4;
}

// main function
int main()
{
    // the processes and its ids
    int processes[] = { 1, 2, 3, 4 };

    // the burst times
    int  burst_time[] = { 13, 3, 7, 29 };

    findAverageTime(processes, burst_time);

    return 0;
}