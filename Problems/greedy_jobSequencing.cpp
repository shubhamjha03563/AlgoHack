#include<iostream> 
#include<algorithm> 
 
struct Job 
{ 
   char id; // Job Id 
   int dline; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
}; 
  
bool compare(Job a, Job b) 
{ 
    return (a.profit > b.profit); 
}

void max_job_sequence(Job arr[], int arr_size)
{
    std::sort(arr, arr+arr_size, compare);
    char result[arr_size];
    bool slot[arr_size];
    int filled = 0;

    for(int i=0; i<arr_size; i++) slot[i] = false;

    for(int i=0; i<arr_size; i++)
    {
        if(slot[arr[i].dline-1])
        {
            for(int j=arr[i].dline-2; j>=0; j--)
            {
                if(!slot[j])
                {
                    result[j] = arr[i].id;
                    slot[j] = true;
                    filled += 1;
                    break;
                }
            }
            continue;
        }
        result[arr[i].dline-1] = arr[i].id;
        slot[arr[i].dline-1] = true;
        filled += 1;
    }
    
    for(int i=0; i<filled; i++) std::cout << result[i] << " ";
}

int main()
{

    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} }; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    std::cout << "Max profit job sequence: ";
    max_job_sequence(arr, arr_size); //c a e
    return 0; 
}
