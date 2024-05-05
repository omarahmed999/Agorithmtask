#include <stdio.h>
void selectionSort(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}
int findDominator(int A[], int N)
{
    selectionSort(A, N);
    int count = 1;
    int dominator = A[0];
    int maxCount = 1;
    for (int i = 1; i < N; i++)
    {
        if (A[i] == A[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > maxCount)
        {
            maxCount = count;
            dominator = A[i];
        }
    }
    if (maxCount > N / 2)
    {
        return dominator;
    }
    else
    {
        return -1;
    }
}