#include "Random.h"

Random::Random():bestCost(2147483647), bestPath(nullptr), path(nullptr)
{

}

void Random::solve(MapData& data){
    static srand(time(NULL));
    int n=data.getMatrixSize();

    if (bestPath == nullptr){
            bestPath= new int[n];
            for(int i = 0; i < n; i++)
                bestPath[i]=0;
    }

     if(path == nullptr) path= new int[n];
    clock_t startTime = clock();
    clock_t endTime = startTime + 3600 * CLOCKS_PER_SEC;

    while (clock() < endTime) {
        for(int i=0;i<n;i++)path[i]=i;
        for(int i=n-1;i>0;i--){
            int j=rand()%(i+1);
            int temp=path[i];
            path[i]=path[j];
            path[j]=temp;
        }

        if(calculatePathCost(path, n, data) < bestCost){
            bestCost=calculatePathCost(path, n, data);
            copyPath(path, bestPath, n);
        }
    }
}


void Random::printBestPath(int size){
    if(bestPath==nullptr)return;
    for(int i=0;i<size;i++){
        std::cout<<bestPath[i]<<" -> ";
    }
    std::cout<<bestPath[0]<<std::endl;
}

void Random::copyPath(int* source,int* destination,int size){
    for (int i=0;i<size;i++){
        destination[i]=source[i];
    }
}

int Random::calculatePathCost(int* path,int size,MapData& data){
    int total=0;
    for(int i=0;i<size-1;i++){
        total+=data.returnDistance(path[i],path[i+1]);
    }
    total+=data.returnDistance(path[size-1],path[0]);
    return total;
}


Random::getBestCost()const{
    return bestCost;
}

Random::~Random()
{
    delete[] path;
    delete[] bestPath;

}
