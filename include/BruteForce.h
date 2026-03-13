
#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <MapData.h>

class BruteForce
{
    public:
        BruteForce();

        virtual ~BruteForce();

        void solve(MapData& data);

        int getBestCost() const;

        void printBestPath(int size);

        long long counter;

    private:
        int bestCost;

        int* bestPath;

        int currentSize;

        int calculatePathCost(int* path, int size, MapData& data);

        void copyPath(int* source, int* destination, int size);

        void backtrack(int* currentPath, bool* visited, int step, int n, MapData& data);
};

#endif // BRUTEFORCE_H
