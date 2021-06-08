#include <iostream>

void merge(int arr[], int left_index, int mid_index, int right_index)
{
    int i = left_index, j = mid_index+1, k = 0;
    int res_size = right_index-left_index+1, res[res_size];
    
    while(i <= mid_index && j <= right_index)
    {
        if(arr[i] <= arr[j]) res[k++] = arr[i++];
        else res[k++] = arr[j++];
    }

    while(i <= mid_index) res[k++] = arr[i++];
    while(j <= right_index) res[k++] = arr[j++];
    for(i = 0; i < res_size; i++) arr[left_index++] = res[i];
}

void merge_sort(int arr[], int left_index, int right_index)
{
    if(left_index < right_index)
    {
        int mid = (left_index + right_index)/ 2;
        merge_sort(arr, left_index, mid);
        merge_sort(arr, mid+1, right_index);
        merge(arr, left_index, mid, right_index);
    }
}

void print_array(int arr[], int arr_size)
{
    for(int i = 0; i < arr_size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}, arr_size = sizeof(arr)/ sizeof(arr[0]);

    merge_sort(arr, 0, arr_size-1);
    print_array(arr, arr_size); //5 6 7 11 12 13

    return 0;
}
