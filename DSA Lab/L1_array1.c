#include <stdio.h>

void traverse(int [], int);

int main()
{
    int arr[10], i, n;
    printf("\nEnter the length of the array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    traverse(arr, n);
    insert(arr, n);
    delete(arr, n);
}

void traverse(int arr1[], int m)
{
    int i;

    for (i=0; i<m; i++)
    {
        printf("%d\n", arr1[i]);
    }
}

void insert(int *arr2, int m)
{
    int i, p, data;
    printf("\nEnter the position: ");
    scanf("%d", &p);
    printf("\nEnter the value: ");
    scanf("%d", &data);

    for (i=m-1; i>=p-1; i--)
    {

        arr2[i+1] = arr2[i];
    }
    arr2[p-1] = data;
    m = m + 1;
    traverse(arr2, m);
}

void delete(int *arr3, int m)
{
    int i, p, data;
    printf("\nEnter the position: ");
    scanf("%d", &p);

    data = arr3[p-1];

    for (i = p-1; i < (m - 1); i++)
    {
        arr3[i] = arr3[i+1];
    }
    m = m + 1;

    traverse(arr3, m);
}
