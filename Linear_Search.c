#include<stdio.h>
int linear_search(int arr[],int n,int key)
{
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int key,n;
    printf("Enter the number of Elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Key Element: ");
    scanf("%d",&key);
    int index=linear_search(arr,n,key);
    if(index==-1){
        printf("Element Not found");
    }
    else{
        printf("Element found at %d",index+1);
    }
}