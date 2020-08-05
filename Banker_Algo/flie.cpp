/* ==============================================
        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
		Algorithm: Banker Algo
=================================================*/

#include <iostream>
using namespace std;

/**
 *
 * finding need of each process
 * @param numOfProcesses - total number of processes
 * @param numOfResources - total number of resources
 * @param need - 2d dynamic need matrix to store result
 * @param maxResources - 2d dynamic matrix that has maximum resources stored
 * @param allocateResources - 2d dynamic matrix that has allocated resources
*/
void calculateNeed(int numOfProcesses, int numOfResources, int **need, int **maxResources,
				   int **allocateResources);
/**
 *
 * finding the system is in safe state or not
 * @param numOfProcesses - total number of processes
 * @param numOfResources - total number of resources
 * @param processes - 1d dynamic array that has process values
 * @param availableResources - 1d dynamic array that has values of available resources
 * @param maxResources - 2d dynamic matrix that has maximum resources stored
 * @param allocateResources - 2d dynamic matrix that has allocated resources
*/
bool isSafe(int numOfProcesses, int numOfResources, int *processes, int *availableResources, int **maxResources, int **allocateResources);

int main()
{

	int numOfProcesses, numOfResources;
	cout << "Enter number of processes: ";
	cin >> numOfProcesses;

	cout << "Enter number of resources: ";
	cin >> numOfResources;

	cout << endl;

	int *processes = new int[numOfProcesses];
	int *availableResources = new int[numOfResources];

	for (int i = 0; i < numOfProcesses; i++)
		processes[i] = i;

	for (int j = 0; j < numOfResources; j++)
	{
		cout << "Enter available resource instance: ";
		cin >> availableResources[j];
	}

	cout << endl;

	// declaring 2d dynamic arrays to store max resources and allocate resources data
	int **maxResources = new int *[numOfProcesses];
	int **allocateResources = new int *[numOfProcesses];
	for (int i = 0; i < numOfProcesses; i++)
	{
		maxResources[i] = new int[numOfResources];
		allocateResources[i] = new int[numOfResources];
	}

	// getting max resource data from user
	for (int i = 0; i < numOfProcesses; i++)
	{
		for (int j = 0; j < numOfResources; j++)
		{
			cout << "Enter maximum resources that can be allocated to process " << i + 1 << " : ";
			cin >> maxResources[i][j];
		}
		cout << endl;
	}

	cout << endl;

	// getting resource data from user
	for (int i = 0; i < numOfProcesses; i++)
	{
		for (int j = 0; j < numOfResources; j++)
		{
			cout << "Enter resources that can be allocated to process " << i + 1 << " : ";
			cin >> allocateResources[i][j];
		}
		cout << endl;
	}

	isSafe(numOfProcesses, numOfResources, processes, availableResources, maxResources, allocateResources);

	return 0;
}

// functiond definition
void calculateNeed(int numOfProcesses, int numOfResources, int **need, int **maxResources,
				   int **allocateResources)
{
	// Calculating Need of each process
	for (int i = 0; i < numOfProcesses; i++)
		for (int j = 0; j < numOfResources; j++)
			need[i][j] = maxResources[i][j] - allocateResources[i][j];
}

// function definiton
bool isSafe(int numOfProcesses, int numOfResources, int *processes, int *availableResources, int **maxResources, int **allocateResources)
{
	int **need = new int *[numOfProcesses];
	for (int i = 0; i < numOfProcesses; i++)
	{
		need[i] = new int[numOfResources];
	}

	// finding need matrix
	calculateNeed(numOfProcesses, numOfResources, need, maxResources, allocateResources);

	// for storing boolean finish, safe sequence and copying available resources
	bool *finish = new bool[numOfProcesses];
	int *safeSeq = new int[numOfProcesses];
	int *work = new int[numOfResources];

	// copying
	for (int i = 0; i < numOfResources; i++)
		work[i] = availableResources[i];

	int count = 0;
	while (count < numOfProcesses)
	{
		bool found = false;
		for (int p = 0; p < numOfProcesses; p++)
		{
			if (finish[p] == 0)
			{
				int j;
				for (j = 0; j < numOfResources; j++)
					if (need[p][j] > work[j])
						break;

				if (j == numOfResources)
				{
					for (int k = 0; k < numOfResources; k++)
						work[k] += allocateResources[p][k];

					safeSeq[count++] = p;
					finish[p] = 1;
					found = true;
				}
			}
		}

		if (found == false)
		{
			cout << "System is not in safe state";
			return false;
		}
	}

	cout << "System is in safe state.\nSafe"
			" sequence is: ";
	for (int i = 0; i < numOfProcesses; i++)
		cout << safeSeq[i] << " ";

	return true;
}
