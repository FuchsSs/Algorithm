#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            Swap(array + i, array + j);
        }
    }
    i++;
    Swap(array + i, array + end);
    return i;
}

void Quicksort(int array[], int start, int end)
{
    if (end <= start)
        return;
    int pivot = Partition(array, start, end);
    Quicksort(array, start, pivot - 1);
    Quicksort(array, pivot + 1, end);
}
int main()
{
    int array[] = {8, 2, 5, 3, 9, 4, 7, 6, 1};
    int length = sizeof(array) / sizeof(int);
    Quicksort(array, 0, length - 1);
    for (int a : array)
        cout << a << ' ';
    return 0;
}