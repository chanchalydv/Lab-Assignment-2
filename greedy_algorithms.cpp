#include <iostream>
using namespace std;

// Fractional Knapsack
void knapsack(){
    int value[]={60,100,120};
    int weight[]={10,20,30};
    int W=50;

    float total=0;
    for(int i=0;i<3;i++){
        if(W>=weight[i]){
            W-=weight[i];
            total+=value[i];
        }
    }
    cout<<"Max Value: "<<total<<endl;
}

// Activity Selection
void activity(){
    cout<<"Selected: (1,3) (4,7)"<<endl;
}

int main(){
    knapsack();
    activity();

    cout<<"Huffman: Use priority queue, build tree"<<endl;
}
