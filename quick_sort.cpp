//Quick sort in c
#include <stdio.h>

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);

        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    } while (i < j);
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n);
    printf("The sorted elements after performing quick sort is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
