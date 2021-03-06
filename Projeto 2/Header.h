#pragma once


//Bibliotecas
//*********************************************************
//#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>


#include "templateFunctions.cpp"
//*********************************************************


//Tipos de dados
//*********************************************************
typedef unsigned int uint;


#include "Bus.h"
#include "Company.h"
#include "Driver.h"
#include "Line.h"
#include "Shift.h"
#include "Time.h"
#include "BusTable.h"

//*********************************************************

//Prototipos funcoes
//*********************************************************************************************************
struct connectionInfo
{
	uint line;
	uint time;
	std::string stop;
};







//Funcoes opcao - Menu principal
<<<<<<< Updated upstream
void menu(std::vector<Line> &lines, std::vector<Driver> &drivers, std::vector<Bus> &bus, const std::string &linesFile, const std::string &driversFile, const std::string &busFile);
=======
<<<<<<< Updated upstream
void menu(std::vector<Line> &lines, std::vector<Driver> &drivers, std::multiset<Shift> shifts, const std::string &linesFile, const std::string &driversFile, const std::string &busFile);
=======
<<<<<<< Updated upstream
void menu(std::vector<Line> &lines, std::vector<Driver> &drivers, std::vector<Bus> &bus, const std::string &linesFile, const std::string &driversFile, const std::string &busFile);
=======
<<<<<<< Updated upstream
void menu(std::vector<Line> &lines, std::vector<Driver> &drivers, std::multiset<Shift> shifts, const std::string &linesFile, const std::string &driversFile, const std::string &busFile);
=======
void menu(std::vector<Line> &lines, std::vector<Driver> &drivers, std::vector<Bus> &bus, std::multiset<Shift> &shifts, const std::string &linesFile, const std::string &driversFile, const std::string &busFile);
>>>>>>> Stashed changes
>>>>>>> Stashed changes
>>>>>>> Stashed changes
>>>>>>> Stashed changes
void linesManager(std::string fileName, std::vector<Line> &lines);
void driversManager(std::string fileName, std::vector<Driver> &drivers);
void visualizeInfo(const std::vector<Line> &lines, const std::vector<Driver> &drivers, const std::multiset<Shift> &shifts);
//***************************************************************************************

std::multiset<Shift> createBlankShifts(std::vector<Line> &lines);

//Funcoes - Notepad
void openNotepad(std::vector<Line> &lines, std::string fileName);
void openNotepad(std::vector<Driver> &drivers, std::string fileName);
void openNotepad(std::string fileName);
//*******************************************************************



//Funcoes - Linhas
int openFile(std::string linesFileName, std::string DriversFileName);
void readLines(std::vector<Line> &lines, std::string fileName);
void writeLines(const std::vector<Line> &lines, std::string fileName);
//********************************************************************



//Funcoes - Condutores
void readDrivers(std::vector<Driver> &drivers, std::string fileName);
void writeDrivers(const std::vector<Driver> &drivers, std::string fileName);
unsigned int addDriver(const std::string &fileName, std::vector<Driver> &drivers);
//********************************************************************



//Funcoes - Shift
void readShift(std::vector<Driver> &drivers, std::multiset<Shift> &shifts, std::string fileName);
<<<<<<< Updated upstream
void createShift(const std::string &driversFile, const std::string &busFile, std::vector<Driver> &drivers, std::vector<Bus> &bus);
=======
<<<<<<< Updated upstream
void createShift(const std::string &driversFile, const std::string &busFile, std::vector<Driver> &drivers, std::multiset<Shift> &shifts);
=======
<<<<<<< Updated upstream
void createShift(const std::string &driversFile, const std::string &busFile, std::vector<Driver> &drivers, std::vector<Bus> &bus);
=======
<<<<<<< Updated upstream
void createShift(const std::string &driversFile, const std::string &busFile, std::vector<Driver> &drivers, std::multiset<Shift> &shifts);
=======
void createShift(const std::string &driversFile, const std::string &busFile, std::vector<Driver> &drivers, std::vector<Bus> &bus);
void freeBuses(std::multiset<Shift> shifts, int line, int numberOfBus);
>>>>>>> Stashed changes
>>>>>>> Stashed changes
>>>>>>> Stashed changes
>>>>>>> Stashed changes
//*********************************************************************************************

/*Funcoes - Autocarros

void readBus(std::vector<Driver> &drivers, std::vector<Bus> &bus, std::string fileName);
void writeBus(const std::vector<Bus> &bus, std::string fileName);
//************************************************************************************************/



//Tratamento input utilizador
//**************************************************
void readNum(const char coutText[], uint &num, bool displaySymbol = true);
int readOption();
void ask_YN(char text[], char &answer);
//*********************************************************************************

void colorCout(char symbol);