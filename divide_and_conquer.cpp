#include <iostream>
using namespace std;

// Binary Search
int binarySearch(int arr[], int l, int r, int x){
    if(l>r) return -1;
    int mid=(l+r)/2;

    if(arr[mid]==x) return mid;
    if(arr[mid]>x) return binarySearch(arr,l,mid-1,x);
    return binarySearch(arr,mid+1,r,x);
}

// Merge Sort
void merge(int arr[], int l, int m, int r){
    int temp[100], i=l, j=m+1, k=0;

    while(i<=m && j<=r){
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(int i=0;i<k;i++) arr[l+i]=temp[i];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high){
    int pivot=arr[high], i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

// Min & Max
void minmax(int arr[], int n){
    int min=arr[0], max=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }
    cout<<"Min="<<min<<" Max="<<max<<endl;
}

// Strassen (simple)
void matrixMultiply(){
    int A[2][2]={{1,2},{3,4}};
    int B[2][2]={{5,6},{7,8}};
    int C[2][2];

    C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];

    cout<<"Matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++) cout<<C[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int arr[]={5,2,9,1,7};

    mergeSort(arr,0,4);
    cout<<"Sorted: ";
    for(int i=0;i<5;i++) cout<<arr[i]<<" ";

    cout<<"\nSearch 3 index: "<<binarySearch(arr,0,4,3)<<endl;

    minmax(arr,5);

    matrixMultiply();
}
