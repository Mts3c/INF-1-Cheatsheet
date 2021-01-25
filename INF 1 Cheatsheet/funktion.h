/*
* 
Informatik Praktikum Gruppe A3
Autor: Mathis Rathjen
Mat#: 1085895
Geschrieben am: 12.01.2021
Zuletzt geändert:  .  .2021
*/

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

const int ANZ = 100;

struct myStruct {
	int number = 1;
	string name = { 0 };
};

struct datenIn {
	string first = { 0 };
	string second = { 0 };
	string thrid = { 0 };
	string fourth = { 0 };
	string fifth = { 0 };
};

//Starte Dynamisches Array
myStruct* dynFeldStart(int anz);

//Defensive Benutzereingaben
bool eingabeZahlen(string &puffer, int minAnz = 0, int maxAnz = 0);
char eingabeZahlen();
bool eingabeBuchstaben(string &puffer, int minAnz, int maxAnz);
char eingabeBuchstaben();
//Vertausche Überladungen
void vertausche(vector<myStruct>& myStructName, int a, int b);	
void vertausche(myStruct* myStructArray, int a, int b);			

//Bubblesort Überladungen
void bubbleSort(vector<int>& myIntVec);					//Ggfs. Überladung für c.b.v hinzufügen!
void bubbleSort(myStruct* myStructArray, int anz);		//Ggfs. Überladung für c.b.v hinzufügen!

//Insertionsort Überladungen
void insertionSortRef(vector<int>& myIntVec);				
vector<int>insertionSortVal(vector<int> myIntVec);
void insertionSortRef(vector<float>& myIntVec);				
vector<float> insertionSortVal(vector<float> myIntVec);
void insertionSortRef(vector<double>& myIntVec);			
vector<double>insertionSortVal(vector<double> myIntVec);
void insertionSortRef(vector<char>& myIntVec);				
vector<char>insertionSortVal(vector<char> myIntVec);
void insertionSortRef(vector<string>& myIntVec);			
void insertionSortRef(vector<myStruct>& myStructVector);	
vector<myStruct>insertionSortVal(vector<myStruct> myStructVector);
void insertionSortRef(myStruct* myStructArray, int anz);
void insertionSortRef(string& myString);					
string insertionSortVal(string myString);
//myStruct insertionSortVal(myStruct myStructArray, int anz);
//vector<string>insertionSortVal(vector<string> myIntVec);

char insertionSort(char chrArray[99]);
int insertionSort(int Array[99]);
float insertionSort(float Array[99]);
double insertionSort(double Array[99]);

//Lineare Suche Überladungen
int searchHighest(myStruct* myStructArray, int anz, int& hiWert);
int searchHighest(vector<myStruct>myIntVec, int& hiWert);

//Aus Datei einlesen funktionen
bool einZlesenVecStr(vector<datenIn>& myStream, int leseBr1);