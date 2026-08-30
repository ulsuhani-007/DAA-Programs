#include<stdio.h>

int main()
{
    int n, target, i;
    int found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    int hash[n];
    int used[n];
    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        hash[i] = 0;
        used[i] = 0;
    }
    printf("Enter the target element: ");
    scanf("%d", &target);
    for(i = 0; i < n; i++)
    {
        int required = target - arr[i];
        int index = ((required % n) + n) % n;
        while(used[index] == 1)
        {
            if(hash[index] == required)
            {
                printf("%d + %d = %d\n",
                       required, arr[i], target);
                found = 1;
                break;
            }
            index = (index + 1) % n;
        }
        if(found)
            break;
        index = ((arr[i] % n) + n) % n;
        while(used[index] == 1)
        {
            index = (index + 1) % n;
        }
        hash[index] = arr[i];
        used[index] = 1;
    }
    if(found == 0)
    {
        printf("Not present\n");
    }
    return 0;
}