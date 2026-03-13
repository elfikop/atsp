
#ifndef MAPDATA_H
#define MAPDATA_H
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class MapData
{
    public:
        MapData(int matrixSize, string filename);

        void deleteMem(int** &tab,int length);

        int returnDistance(int sourceCity, int destinationCity);

        int getMatrixSize();

        virtual ~MapData();

    protected:

    private:
    fstream file;

    int** inputs;

    int matrixSize;
};

#endif // MAPDATA_H
