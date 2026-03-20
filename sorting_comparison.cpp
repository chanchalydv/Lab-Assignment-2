#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main(){
    int arr[1000];
    for(int i=0;i<1000;i++) arr[i]=rand();

    auto start=high_resolution_clock::now();

    for(int i=0;i<1000;i++)
        for(int j=0;j<999;j++)
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);

    auto stop=high_resolution_clock::now();

    cout<<"Time: "<<duration_cast<milliseconds>(stop-start).count();
}
