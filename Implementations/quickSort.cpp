#include <iostream>

int partition(int arr[], int low, int high)
{
    
    int pivot = arr[low], i = low, j = high;
    while(i < j)
    {
        do
        {
            i++;
        } while(arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if(i < j) std::swap(arr[i], arr[j]);
    }
    std::swap(arr[j], arr[low]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index);
        quick_sort(arr, partition_index+1, high);   
    }
}

void print_array(int arr[], int arr_size)
{
    for(int i = 0; i < arr_size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {4, 40, 47, 45, 52, 59, 6, 60, 9, 31, 32, 34}, arr_size = sizeof(arr)/ sizeof(arr[0]);
    
    quick_sort(arr, 0, arr_size);
    print_array(arr, arr_size); //5 6 7 11 12 13

    return 0;
}