#include <iostream>

void max_heap(int a[], int size, int i) //O(nlogn)
{
    if(i >= size) return;
    //if child is greater than parent
    if(a[i] > a[(i-1)/2])
    {
        int j = i;
        //until child is greater than it's parent
        while(j >= 0 && a[j] > a[(j-1)/2])
        {
            std::swap(a[j], a[(j-1)/2]);
            j = (j-1) /2;
        }
    }
    max_heap(a, size, i+1);
}

void max_heap_rec_Util(int a[], int size, int pos)
{
    if(pos <= 0 || a[pos] < a[(pos-1)/2]) return;
    std::swap(a[pos], a[(pos-1)/2]);
    max_heap_rec_Util(a, size, (pos-1)/2);
}

void max_heap_rec(int a[], int size)
{
    for(int i=1; i<size; i++) 
    {
        if(a[i] > a[(i-1)/2]) max_heap_rec_Util(a, size, i);
    }
}

void heap_sort(int a[], int size)
{
    max_heap(a, size, 1);
    for(int i=size-1; i>0; i--)
    {
        std::swap(a[0], a[i]);
        max_heap(a, i, 1);
    }
}

void heapify(int a[], int size, int root) //O(n)
{
    int largest = root, left = 2*root +1, right = 2*root +2; 
    if(left < size && a[left] > a[largest]) largest = left;
    if(right < size && a[right] > a[largest]) largest = right;
    if(largest != root)
    {
        std::swap(a[root], a[largest]);
        heapify(a, size, largest);
    }
}

void heap_sort_heapify(int a[], int size)
{
    /*We need to pass the non-leaf nodes only...
    Complete and Almost Complete Binary tree property -> if 'n' nodes
    are present, then n/2 +1 to n are leafs and rest are non-leaf nodes*/
    for(int i=size/2 -1; i>=0; i--) heapify(a, size, i);

    for(int i=size-1; i>0; i--)
    {
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void print_heap(int a[], int size)
{
    for(int i=0; i<size; i++) std::cout << a[i] << " ";
}

int main()
{      
    int a[] = {10, 20, 15, 17, 9, 21}, size = sizeof(a)/ sizeof(a[0]);
    std::cout << "\nHeap -> ";
    print_heap(a, size); //10 20 15 17 9 21

    max_heap(a, size, 1);
    std::cout << "\nMax heap -> ";
    print_heap(a, size); //21 17 20 10 9 15

    heap_sort(a, size);
    std::cout << "\nHeap sort-> ";
    print_heap(a, size); //9 10 15 17 20 21

    int b[] = {10, 20, 15, 17, 9, 21};
    for(int i=size/2-1; i>=0; i--) heapify(b, size, i);
    std::cout << "\nHeapify -> ";
    print_heap(b, size); //21 20 15 17 9 10

    int c[] = {10, 20, 15, 17, 9, 21};
    heap_sort_heapify(c, size);
    std::cout << "\nHeap sort with heapify -> ";
    print_heap(c, size); //9 10 15 17 20 21

    int d[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    max_heap_rec(d, 9);
    std::cout << "\nRecursion Max heap -> ";
    print_heap(d, 9);

    return 0;
}