#include<stdio.h>
int binary_search(int arr[],int n,int key){
    int low=0,high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int key,n;
    printf("Enter the number of Elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Key Element: ");
    scanf("%d",&key);
    int index=binary_search(arr,n,key);
    if (index==-1){
        printf("Element Not Found");
    }
    else{
        printf("Element found at %d",index+1);
    }

}