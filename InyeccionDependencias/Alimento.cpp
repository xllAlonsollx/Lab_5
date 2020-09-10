#include "Alimento.h"

Alimento::Alimento(string nombre, int caloriasDiarias)
{
	this->nombre = nombre;
	this->caloriasDiarias = caloriasDiarias;
}

string Alimento::getNombre() const
{
    return nombre;
}

void Alimento::setNombre(string nombre)
{
    this->nombre = nombre;
}

int Alimento::getCaloriasDiarias() const
{
    return caloriasDiarias;
}

void Alimento::setCaloriasDiarias(int caloriasDiarias)
{
    this->caloriasDiarias = caloriasDiarias;
}

string Alimento::toString()
{
	stringstream s;
	s << "Nombre: " << this->nombre << endl;
	s << "Calorias Diarias: " << this->caloriasDiarias << endl;
	return s.str();
}

