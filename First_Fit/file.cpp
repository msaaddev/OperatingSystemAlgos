/* ==============================================
        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
		Algorithm: First Fit
=================================================*/

/* importing iostream library and setting the namespace */
#include <iostream>
using namespace std;

/**
 *
 * prototype of function
 * allocating memory to blocks
 * @param blockSize - dynamic array that has block sizes
 * @param numOfBlock - total number of blocks
 * @param processSize - dynamic array that has process sizes
 * @param numOfProcess - total number of processes
 */
void firstFit(int *blockSize, int numOfBlock, int *processSize, int numOfProcess);

// Driver code
int main()
{
	int numOfProcess, numOfBlock;
	cout << "\nEnter total number of processes: ";
	cin >> numOfProcess;
	int *processSize = new int[numOfProcess];
	for (int i = 0; i < numOfProcess; i++)
	{
		cout << "Enter process size of process " << i + 1 << ": ";
		cin >> processSize[i];
		cout << endl;
	}

	cout << "Enter total number of memory blocks: ";
	cin >> numOfBlock;
	int *blockSize = new int[numOfBlock];

	for (int i = 0; i < numOfBlock; i++)
	{
		cout << "Enter block size of block " << i + 1 << ": ";
		cin >> blockSize[i];
		cout << endl;
	}

	firstFit(blockSize, numOfBlock, processSize, numOfProcess);

	delete[] processSize;
	delete[] blockSize;
}

/**
 * function definiton
 * allocating memory to blocks
 * @param blockSize - dynamic array that has block sizes
 * @param numOfBlock - total number of blocks
 * @param processSize - dynamic array that has process sizes
 * @param numOfProcess - total number of processes
 */
void firstFit(int *blockSize, int numOfBlock, int *processSize, int numOfProcess)
{

	int *memoryAllocation = new int[numOfProcess];
	for (int i = 0; i < numOfProcess; i++)
		memoryAllocation[i] = -1;

	for (int i = 0; i < numOfProcess; i++)
	{
		for (int j = 0; j < numOfBlock; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				memoryAllocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < numOfProcess; i++)
	{
		if (memoryAllocation[i] != -1)
			cout << "Process " << i + 1 << " of process size " << processSize[i] << " allocated in block number " << memoryAllocation[i] + 1;
		else
			cout << "Process " << i + 1 << " of process size " << processSize[i] << " is not allocated.";
		cout << endl;
	}
}
