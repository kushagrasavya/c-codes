//negative element at the end of the array

//largest amout of sum
#include<iostream>
using namespace std;
int main(){
    int arr[]={-1, -3, 4, 2, -1, 5};
    int sum=0;
    int sum1=0;
    for(int i=0; i<sizeof(arr); i++){

        for(int j=0; i<sizeof(arr); j++){
            sum+=arr[j];
        }
          sum1=sum;
    }
}