#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

template<typename T>
void QuickSort(vector<T>& arr, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    T tempValue = arr[left];
    while (i < j)
    {
        while (i<j && arr[j] >= tempValue) j--;
        while (i<j && arr[i] <= tempValue) i++;
        if (i<j)
        {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = tempValue;

    QuickSort(arr, left, i-1);
    QuickSort(arr, i+1, right);
}

void BubbleSort(vector<int>& arr)
{
    for (int i=0; i<arr.size()-1; i++)
        for (int j=i+1; j<arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
}

void SelectSort(vector<int>& arr)
{
    for (int i=0; i<arr.size(); i++)
    {
        int minValue = arr[i];
        int minIndex = i;
        for (int j=i+1; j<arr.size(); j++)
        {
            if (arr[j] < minValue)
            {
                minValue = arr[j];
                minIndex = j;
            }
        }
        int tmp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = tmp;
    }
}

void InsertSort(vector<int>& arr)
{
    for(int sortIndex = 1; sortIndex<arr.size(); sortIndex++)
    {
        int minValue = arr[sortIndex];
        int minIndex = sortIndex;
        for(int i=0; i<sortIndex; i++)
        {
            int tmp = 0;
            if (arr[sortIndex] < arr[i])
            {
                tmp = arr[sortIndex];
                for (int k=sortIndex; k>i; k--)
                {
                    arr[k] = arr[k-1];
                }
                arr[i] = tmp;
                break;
            }
        }
    }
}

void ShellSort(vector<int>& arr)
{
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
    {
        for (int i=gap; i<arr.size(); i++)
        {
            int j = i;
            while (j - gap >= 0 && arr[j] < arr[j-gap])
            {
                int tmp = arr[j];
                arr[j] = arr[j-gap];
                arr[j-gap] = tmp;
                j -= gap;
            }
        }
    }
}

void MakeMaxHeap(vector<int>& arr, int size)
{
    for (int i=size; i>0; i--)
    {
        if (arr[i] > arr[(i-1) / 2])
        {
            int tmp = arr[i];
            arr[i] = arr[(i-1) / 2];
            arr[(i-1) / 2] = tmp;
        }
    }
}
void HeapSort(vector<int>& arr)
{
    for (int i = arr.size()-1; i>0; i--)
    {
        MakeMaxHeap(arr, i);
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
    }
}

void Merge(vector<int>& arr, int left, int mid, int right)
{
    int len = right - left + 1;
    vector<int> tmp(len);
    int i = left, j = mid+1;
    int index = 0;
    while (i<=mid && j<=right)
    {
        tmp[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i<=mid)
        tmp[index++] = arr[i++];
    
    while (j<=right)
        tmp[index++] = arr[j++];
    
    for (int i=0; i<len; i++)
    {
        arr[left+i] = tmp[i];
    }
}

void MergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {4,3,5,6,8,2,1,7,9};
    // QuickSort(arr, 0, arr.size()-1);
    // BubbleSort(arr);
    // SelectSort(arr);
    // InsertSort(arr);
    // ShellSort(arr);
    // HeapSort(arr);
    MergeSort(arr, 0, arr.size()-1);
    for (auto iter : arr) {
        cout << iter << " ";
    }
    return 0;
}
