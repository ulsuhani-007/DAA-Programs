#include<stdio.h>
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[],int low,int high){
    int mid;
    if (low<high){
        mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void merge(int arr[],int low, int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[100];
    
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
            else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
        while(i<=mid){
            temp[k]=arr[i];
            k++;
            i++;
        }
        while(j<=high){
            temp[k]=arr[j];
            k++;
            j++;
        }
for(int i=low,k=0;i<=high;i++,k++){
    arr[i]=temp[k];
    }

}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    
    }
}
