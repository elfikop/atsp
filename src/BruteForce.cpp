
#include "BruteForce.h"
#include<climits>
#include <iostream>
using namespace std;
BruteForce::BruteForce():bestCost(2147483647),bestPath(nullptr),currentSize(0),counter(0)
{
}
int BruteForce::calculatePathCost(int* path,int size,MapData& data){
    int total=0;
    for(int i=0;i<size-1;i++){
        total+=data.returnDistance(path[i],path[i+1]);
    }
    total+=data.returnDistance(path[size-1],path[0]);
    return total;
}

void BruteForce::printBestPath(int size){
    if(bestPath==nullptr)return;
    for(int i=0;i<size;i++){
        std::cout<<bestPath[i]<<" -> ";
    }
    std::cout<<bestPath[0]<<std::endl;
}

int BruteForce::getBestCost()const{
    return bestCost;
}

void BruteForce::copyPath(int* source,int* destination,int size){
    for (int i=0;i<size;i++){
        destination[i]=source[i];
    }
}
void BruteForce::backtrack(int* currentPath, bool* visited, int step, int n, MapData& data) {
    if (step == n) {
        int cost = calculatePathCost(currentPath, n, data);
        BruteForce::counter++;
        if(BruteForce::counter%10000000==0)
            cout<<BruteForce::counter<<endl;

        if (cost < bestCost) {
            bestCost = cost;
            copyPath(currentPath, bestPath, n);
        }
        return;
    }

    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            currentPath[step] = i;
            backtrack(currentPath, visited, step + 1, n, data);
            visited[i] = false;
        }
    }
}
void BruteForce::solve(MapData& data) {
    int n=data.getMatrixSize();
    this->bestCost=INT_MAX;

    int* currentPath=new int[n];
    bool* visited=new bool[n];

    for(int i=0;i<n;i++)visited[i]=false;

    currentPath[0]=0;
    visited[0]=true;

    if (this->bestPath!=nullptr)delete[]this->bestPath;
    this->bestPath=new int[n];

    backtrack(currentPath,visited,1,n,data);

    delete[]currentPath;
    delete[]visited;
}

BruteForce::~BruteForce()
{
    if (bestPath!=nullptr)delete[] bestPath;
}
