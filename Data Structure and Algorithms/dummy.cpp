#include <iostream>
#include <vector>

using namespace std;

int lastOccurrence(vector<int> arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            // result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {1, 3, 4, 4, 5, 5, 5, 5, 10, 19, 20, 211};
    int x = 4;

    int lastOccurenceIndex = lastOccurrence(arr, x);

    if (lastOccurenceIndex == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Last occurrence of " << x << " is at index " << lastOccurenceIndex << endl;
    }

    return 0;
}