#include "MapData.h"
using namespace std;
MapData::MapData(int matrixSize, string filename):inputs(nullptr)
{
    file.open(filename,ios::in);
	if(!file){
        cout<<"Blad pliku!"<<endl;
        return;
	}
	string line;
	for(int i=0; i<7; i++){
        getline(file,line);
        cout<<line<<endl;
	}
	this->matrixSize=matrixSize;

	inputs=new int*[matrixSize];

	for(int i=0; i<matrixSize; i++){
        inputs[i]=new int[matrixSize];
	}
	for(int j=0; j<matrixSize; j++){
        for(int i=0; i<matrixSize; i++){
            file>>inputs[i][j];
        }
	}
	for(int j=0; j<matrixSize; j++){
        for(int i=0; i<matrixSize; i++){
            cout<<inputs[i][j]<<"    ";
        }
        cout<<endl;
	}
}
int MapData::getMatrixSize(){
    return matrixSize;
}
int MapData::returnDistance(int sourceCity, int destinationCity){
    if((sourceCity<matrixSize)&&(destinationCity<matrixSize))
        return inputs[destinationCity][sourceCity];
    else
        cout<<"error! city indexes out of range!";
}

void MapData::deleteMem(int** &tab,int length){
    for(int i=0;i<length;i++){
        delete[] tab[i];
    }
    delete[] tab;
}

MapData::~MapData()
{
    deleteMem(inputs,matrixSize);
}
