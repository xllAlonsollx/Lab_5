#pragma once
#include"Alimento.h"
#include"Colecciones/ObjetoBase.h"
#include"Colecciones/IList.h"
#include"Colecciones/ArrayList.h"
#include"Colecciones/IIterador.h"

class Paciente : public ObjetoBase
{
private:
	string nombre;
	IList* alimentos;

public:
	Paciente(string nombre);
	Paciente(const Paciente& source) = delete;
	Paciente& operator=(const Paciente& source) = delete;
	void agregarAlimentoADieta(Alimento* alimento);
	int totalCaloriasEnDieta();
	string toString();
	~Paciente();
public:
    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }
};