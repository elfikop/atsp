
#ifndef MENU_H
#define MENU_H
#include <filesystem>
#include <iostream>
#include "BruteForce.h"
#include "MapData.h"

class Menu
{
	 public:
        Menu();
		void loop();
		void displayOptionsMenu();
		void displayAlgoSelectionMenu();
		void displayFileInsertMenu();
		void displayStatistics();
		virtual ~Menu();


	private:
		MapData* input_matrix;
		int algorithmNumber;
		int menuNumber;

		string filename;
		int matrixsize;
};

#endif // MENU_H
