#include <stdio.h>
#include <limits.h>

int is_bst(int arr[], int idx, int n, int mini, int maxi)
{
    if (idx >= n || arr[idx] == 0)
        return 1;
    if (arr[idx] <= mini || arr[idx] >= maxi)
        return 0;

    return is_bst(arr, 2 * idx + 1, n, mini, arr[idx]) && is_bst(arr, 2 * idx + 2, n, arr[idx], maxi);
}

int sum_in_range(int arr[], int idx, int n, int low, int high)
{
    if (idx >= n || arr[idx] == 0)
        return 0;

    int total = 0;

    if (low <= arr[idx] && arr[idx] <= high)
        total += arr[idx];

    total += sum_in_range(arr, 2 * idx + 1, n, low, high);
    total += sum_in_range(arr, 2 * idx + 2, n, low, high);

    return total;
}

int main()
{
    int n, low, high;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &low, &high);

    if (is_bst(arr, 0, n, INT_MIN, INT_MAX))
    {

        int total_sum = sum_in_range(arr, 0, n, low, high);
        printf("1 %d\n", total_sum);
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
