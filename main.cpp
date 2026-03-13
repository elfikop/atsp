
#include <iostream>
#include "MapData.h"
#include "BruteForce.h"

using namespace std;

int main()
{
    string inputFile="atsp/";
    cout << "Podaj nazwe pliku wejsciowego" << endl;
    string a;
    cin>>a;
    inputFile+=a+".atsp";
    cout<<inputFile<<endl;
    cout << "Podaj rozmiar macierzy" << endl;
    int matSize;
    cin>>matSize;
    MapData input_matrix(matSize, inputFile);

    cout<<input_matrix.returnDistance(2,3)<<endl; // source city is the city in -1 column destination city is located in -1 row of the table
    cout<<input_matrix.returnDistance(3,2)<<endl;
    cout<<"koniec konfiguracji"<<endl;

    BruteForce bf;
    bf.solve(input_matrix);
    cout<<"Best path: "<<bf.getBestCost()<<endl;
    bf.printBestPath(matSize);

    return 0;
}
