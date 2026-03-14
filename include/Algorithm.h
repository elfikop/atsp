
#ifndef ALGORITHM_H   
#define ALGORITHM_H 
#include <MapData.h>

class Algorithm 
{
    public:
        Algorithm();

        virtual ~Algorithm();

        virtual void solve(MapData& data)=0;

        int getBestCost() const;

        void printBestPath(int size);

        long long counter;

   protected:
        int bestCost;

        int* bestPath;

        int currentSize;

        int calculatePathCost(int* path, int size, MapData& data);

        void copyPath(int* source, int* destination, int size);

};

#endif // ALGORITHM_H
