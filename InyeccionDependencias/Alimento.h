#pragma once
#include<iostream>
#include<sstream>
#include"Colecciones/ObjetoBase.h"
using namespace std;

class Alimento : public ObjetoBase
{
private:
	string nombre;
	int caloriasDiarias;

public:
	Alimento(string nombre, int caloriasDiarias);
    string getNombre() const;
    void setNombre(string nombre);

    int getCaloriasDiarias() const;
    void setCaloriasDiarias(int caloriasDiarias);
	string toString();
};