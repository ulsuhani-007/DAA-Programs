#include<stdio.h>
int partition(int arr[],int low,int high);
void quickSort(int arr[],int low, int high){
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while(i<j){
        while(arr[i]<=pivot&&i<=high){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if (i<j){
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp;
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
