#include<stdio.h>
#include<math.h>
int summation(int a,int r,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        printf("%d ",a);
        sum+=a;
        a*=r;
    }
return sum;
}
int main(){
int a,r,n;
printf("Enter the first Element: ");
scanf("%d",&a);
printf("Enter common ratio r: ");
scanf("%d",&r);
printf("Enter the number of Elements: ");
scanf("%d",&n);
int sum=summation(a,r,n);
printf("\nThe Sum of the Elements: %d",sum);
}