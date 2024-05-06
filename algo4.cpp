#include <iostream>

using namespace std;

int find_candidate(int A[], int size)
{
    int candidate = A[0];
    int count = 1;

    for (int i = 1; i < size; i++)
    {
        if (A[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                candidate = A[i];
                count = 1;
            }
        }
    }

    return candidate;
}

int count_occurrences(int A[], int size, int candidate)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] == candidate)
        {
            count++;
        }
    }
    return count;
}

int find_dominator_index(int A[], int start, int end)
{
    if (start == end)
    {
        return start;
    }

    int mid = start + (end - start) / 2;

    int left_dominator = find_dominator_index(A, start, mid);
    int right_dominator = find_dominator_index(A, mid + 1, end);

    if (left_dominator == right_dominator)
    {
        return left_dominator;
    }

    int left_candidate = A[left_dominator];
    int right_candidate = A[right_dominator];

    int left_count = count_occurrences(A, end - start + 1, left_candidate);
    int right_count = count_occurrences(A, end - start + 1, right_candidate);

    if (left_count > (mid - start + 1) / 2)
    {
        return left_dominator;
    }
    else if (right_count > (end - mid) / 2)
    {
        return right_dominator;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int A[] = {3, 4, 3, 2, 3, -1, 3, 3};
    int size = sizeof(A) / sizeof(A[0]);
    int result = find_dominator_index(A, 0, size - 1);
    if (result != -1)
    {
        cout << "Dominator index: " << result << endl;
    }
    else
    {
        cout << "No dominator found." << endl;
    }
    return 0;
}
