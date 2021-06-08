#include <iostream> 
#include <algorithm>
  
struct Item
{ 
    int value, weight; 
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    } 
}; 
  
bool compare(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
}

double fractionalKnapsack(int knapsack_weight, struct Item arr[], int arr_size)
{
    double max_profit = 0;
    std::sort(arr, arr + arr_size, compare);
    for(int i=0; i<arr_size; i++)
    {
        if(knapsack_weight == 0) return max_profit;
        if(arr[i].weight <= knapsack_weight)
        {
            max_profit += arr[i].value;
            knapsack_weight -= arr[i].weight;
        }
        else
        {
            max_profit += ((double)knapsack_weight/ arr[i].weight) * arr[i].value;
            knapsack_weight = 0;
        }
    }
    return max_profit;
}


int main() 
{ 
    Item arr[] = { {100, 10}, {280, 40}, {120, 20}, {120, 24} };
    int knapsack_weight = 60, arr_size = sizeof(arr) / sizeof(arr[0]); 
    std::cout << "Maximum value = " << fractionalKnapsack(knapsack_weight, arr, arr_size) << std::endl; //440 

    return 0; 
}