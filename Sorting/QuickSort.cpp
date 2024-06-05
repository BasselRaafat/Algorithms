#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

void quickSort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }
    int cntr1 = 0, cntr2 = 0, pivot = arr[n / 2];
    int lft[n]{}, rit[n]{};
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] < pivot)
        {
            lft[cntr1] = arr[i];
            cntr1++;
        }
        else
        {
            rit[cntr2] = arr[i];
            cntr2++;
        }
    }

    for (int i = (n / 2) + 1; i < n; i++)
    {
        if (arr[i] < pivot)
        {
            lft[cntr1] = arr[i];
            cntr1++;
        }
        else
        {
            rit[cntr2] = arr[i];
            cntr2++;
        }
    }
    quickSort(lft, cntr1);
    quickSort(rit, cntr2);
    for (int i = 0; i < cntr1; i++)
    {
        arr[i] = lft[i];
    }
    arr[cntr1] = pivot;
    for (int i = cntr1 + 1; i < n; i++)
    {
        arr[i] = rit[i - (cntr1 + 1)];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}