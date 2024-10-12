#include <iostream>
using namespace std;

int main(){
    int arr[3];
    int temp;

    for(int i=0;i<3;i++){
        cin>> arr[i];
    }

    for(int i=0;i<2;i++)
    {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }

    }

    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}