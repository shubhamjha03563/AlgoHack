#include <iostream>

int binary_search_itr(int a[], int size, int key)
{
    int low = 0, high = size-1, mid;
    while(low <= high)
    {
        mid = (low+high)/ 2;
        if(a[mid] == key) return mid+1;
        else if(key > a[mid]) low = mid+1;
        else high = mid-1;
    }
    return 0;
}

int mid;
int binary_search_rec(int a[], int key, int low, int high)
{
    if(low > high)  return 0;
    mid = (low+high)/ 2;
    if(a[mid] == key) return mid+1;
    else if(a[mid] < key) return binary_search_rec(a, key, mid+1, high);
    else return binary_search_rec(a, key, low, mid-1);
}

int main()
{
    int a[] = {12, 14, 22, 23, 34, 55, 65, 99}; //given array must be sorted for binary search

    std::cout << binary_search_itr(a, 10, 23) << std::endl;
    std::cout << binary_search_itr(a, 10, 200) << std::endl;

    std::cout << binary_search_rec(a, 99, 0, 10) << std::endl;
    std::cout << binary_search_rec(a, 200, 0, 10) << std::endl;

    return 0;
}