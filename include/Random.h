#ifndef RANDOM_H
#define RANDOM_H
#include<iostream>
#include<time.h>
#include"MapData.h"
#include <cstdlib>
#include <ctime>

class Random
{
    public:
        Random();
        virtual ~Random();

        void solve(MapData& data);

        int getBestCost() const;//

        void printBestPath(int size);//

    private:
        int bestCost;

        int* bestPath;
        int* path;

        void copyPath(int* source,int* destination,int size);

        int calculatePathCost(int* path,int size,MapData& data);
};

#endif // RANDOM_H
