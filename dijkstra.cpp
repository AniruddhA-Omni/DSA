#include <iostream>
#include <limits.h>
using namespace std;

int miniDist(int distance[], bool Tset[]){
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<9;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}
void path(int parent[],int j){
    char k = 65;
    cout<<"Path: ";
    for(int i = 0; i<j;i++){
        if (i==j-1)
            cout<<char(k+parent[i])<<endl;
        else
            cout<<char(k+parent[i])<<"->";
    }
}

void DijkstraAlgo(int graph[9][9],int src){
    int distance[9]; // // array to calculate the minimum distance for each node                             
    bool Tset[9];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<9; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<9; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<9; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Source\t\tDestination\tDistance"<<endl;
    cout<<"A\t\tH\t\t"<<distance[7]<<endl;
    int parent[9] = {0,1,3,4,5,6,8,7};
    path(parent,8);
}

int main(){
    int graph[9][9]={
    //  A B C D E F G H I
        {0,5,7,0,0,0,0,0,0},
        {5,0,10,4,0,0,17,0,0},
        {7,10,0,3,15,0,0,0,0},
        {0,4,3,0,1,0,0,0,0},
        {0,0,15,1,0,3,0,0,0},
        {0,0,0,0,3,0,2,0,0},
        {0,17,0,0,0,0,0,15,4},
        {0,0,0,0,0,0,15,0,2},
        {0,0,0,0,0,0,4,2,0}
    };
    DijkstraAlgo(graph,0);
    return 0;                           
}