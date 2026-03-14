
#include "Algorithm.h"
#include<climits>
#include<iostream>

Algorithm::Algorithm():bestCost(2147483647),bestPath(nullptr),currentSize(0),counter(0)
{
}
int Algorithm::calculatePathCost(int* path,int size,MapData& data){
    int total=0;
    for(int i=0;i<size-1;i++){
        total+=data.returnDistance(path[i],path[i+1]);
    }
    total+=data.returnDistance(path[size-1],path[0]);
    return total;
}

void Algorithm::printBestPath(int size){
    if(bestPath==nullptr)return;
    for(int i=0;i<size;i++){
        std::cout<<bestPath[i]<<" -> ";
    }
    std::cout<<bestPath[0]<<std::endl;
}

int Algorithm::getBestCost(){
    return bestCost;
}

void Algorithm::copyPath(int* source,int* destination,int size){
    for (int i=0;i<size;i++){
        destination[i]=source[i];
    }
}

Algorithm::~Algorithm()
{
    if (bestPath!=nullptr)delete[] bestPath;
}
