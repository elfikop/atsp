#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include "MapData.h"
#include "BruteForce.h"
#include "Random.h"
#include <filesystem>

using namespace std;

Menu::Menu()
{
    input_matrix=nullptr;
    menuNumber=0;
    algorithmNumber=0;
}

void Menu::loop(){
    while(true){
        displayOptionsMenu();
        if(!(cin>>menuNumber))break;
        switch(menuNumber){
            case 1:
                displayFileInsertMenu();
                break;
            case 2:
                if(input_matrix!=nullptr){
                    displayAlgoSelectionMenu();
                }else{
                    cout<<"Error! Read the file data first!"<<endl;
                }
                break;
            case 3:
                displayStatistics();
                break;
            default:
                cout<<"Zamykanie programu..."<<endl;
                return;
        }
    }
}

void Menu::displayAlgoSelectionMenu(){
    cout<<"Select an ATSP Algorithm"<<endl;
    cout<<"1. Brute Force"<<endl;
    cout<<"2. Random"<<endl;
    cout<<"3. Greedy"<<endl;
    cin>>algorithmNumber;
    switch(algorithmNumber){
        case 1:{
            BruteForce bf;
            if(input_matrix!=nullptr){
                bf.solve(*input_matrix);
                cout<<"Best path cost: "<<bf.getBestCost()<<endl;
                bf.printBestPath(input_matrix->getMatrixSize());
            }
            break;
        }
        case 2:{
            cout<<"Random Selected - Not implemented yet"<<endl;
            Random R;
            if(input_matrix!=nullptr){
                R.solve(*input_matrix);
                cout<<"Best path cost: "<<R.getBestCost()<<endl;
                R.printBestPath(input_matrix->getMatrixSize());
            }
            break;
        }
        case 3:
            cout<<"Greedy Selected - Not implemented yet"<<endl;
            break;
        default:
            cout<<"Niepoprawny numer algorytmu"<<endl;
            break;
    }
}

void Menu::displayFileInsertMenu(){
    cout<<"Insert input file name (without folder and .atsp extension):"<<endl;
    string a;
    cin>>a;
    std::filesystem::path cwd=std::filesystem::current_path();
    cout<<"current path is: "<<std::filesystem::current_path()<<endl;
    if (cwd.filename() == "ATSPDESKTOP")
        filename="../atsp/atsp/"+a+".atsp";//While working on win 10 cloned repo i needed an alternate location
    else
        filename="atsp/"+a+".atsp"; //Linux location of input data

    cout<<"Insert matrix size:"<<endl;
    cin>>matrixsize;
    if(input_matrix!=nullptr){
        delete input_matrix;
    }
    input_matrix=new MapData(matrixsize,filename);
    cout<<"File "<<filename<<" is loaded"<<endl;
}

void Menu::displayOptionsMenu(){
    cout<<"\n--- ATSP SOLVER MENU ---"<<endl;
    cout<<"1. Wczytaj dane z pliku"<<endl;
    cout<<"2. Wybierz i uruchom algorytm"<<endl;
    cout<<"3. Wyswietl statystyki"<<endl;
    cout<<"0. Wyjscie"<<endl;
    cout<<"Wybor: ";
}

void Menu::displayStatistics(){
    cout<<"Statystyki nie sa jeszcze dostepne."<<endl;
}

Menu::~Menu()
{
    if(input_matrix!=nullptr){
        delete input_matrix;
    }
}
