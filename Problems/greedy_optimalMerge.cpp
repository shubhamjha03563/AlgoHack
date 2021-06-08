#include <iostream>
#include <algorithm>

//build minHeap
void heapify(int a[], int size, int root) 
{
    int smallest = root, left = 2*root +1, right = 2*root +2; 
    if(left < size && a[left] < a[smallest]) smallest = left;
    if(right < size && a[right] < a[smallest]) smallest = right;
    if(smallest != root)
    {
        std::swap(a[root], a[smallest]);
        heapify(a, size, smallest);
    }
}

int minComputation(int no_of_files, int files[])
{
    int min = 0;
    while(1)
    {
        if(files[1] == 999999) return min;
        files[0] += files[1];
        min += files[0];
        files[1] = 999999;
        std::swap(files[--no_of_files], files[1]);
        // for(int i=no_of_files/2-1; i>=0; i--) heapify(files, no_of_files, i);
        std::sort(files, files+no_of_files);
    }
}

int main()
{
    // no of files 
    int no_of_files = 6;

    // 6 files with their sizes 
    int files[] = {2, 3, 4, 5, 6, 7}; 

    // total no of computations to be done final answer 
    std::cout << "Minimum computations = " << minComputation(no_of_files, files) << std::endl;
}
