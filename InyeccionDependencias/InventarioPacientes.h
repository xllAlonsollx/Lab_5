#pragma once
#include "Paciente.h"
#include "Colecciones/IList.h"
#include "Colecciones/IIterable.h"
#include "Colecciones/ArrayList.h"

class InventarioPacientes {
	
private:
	IList* pacientes;

public: 
	InventarioPacientes(IList* contenedor);
	InventarioPacientes(const InventarioPacientes& source) = delete;
	InventarioPacientes& operator=(const InventarioPacientes& source) = delete;
	void agregarPaciente(Paciente* paciente);
	Paciente* consultarPaciente(string nombre);
	string toString();
	~InventarioPacientes();



};