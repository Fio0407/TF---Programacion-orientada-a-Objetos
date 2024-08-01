#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class Archivo {
private:
	ofstream fileWrite; //Write
	ifstream fileRead; //Read
	string text;

	int tiempoN1;
	int tiempoN2;
public:
	Archivo() { ReadData(); }
	~Archivo() {}

	int getTiempoN1() { return this->tiempoN1; }
	int getTiempoN2() { return this->tiempoN2; }

	void ReadData()
	{
		fileRead.open("Configuracion.txt", ios::in);

		getline(fileRead, text);
		tiempoN1 = stoi(text);

		getline(fileRead, text);
		tiempoN2 = stoi(text);

		/*while (!fileRead.eof()) {
		
		}*/

		fileRead.close();
	}
};