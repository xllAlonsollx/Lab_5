#include "InventarioPacientes.h"

InventarioPacientes::InventarioPacientes(IList* contenedor)
{
	this->pacientes = contenedor;
}

void InventarioPacientes::agregarPaciente(Paciente* paciente)
{
	this->pacientes->insertarAlFinal(paciente);
}

Paciente* InventarioPacientes::consultarPaciente(string nombre)
{
	IIterador* ite = this->pacientes->obtenerIterador();
	Paciente* resultado = nullptr;
	while (ite->haySiguiente())
	{
		Paciente* actual = dynamic_cast<Paciente*>(ite->actual());
		if (actual->getNombre() == nombre)
		{
			resultado = actual;
			break;
		}
	}
	delete ite;
	return resultado;
}

string InventarioPacientes::toString()
{
	return this->pacientes->toString();
}

InventarioPacientes::~InventarioPacientes()
{
	this->pacientes->liberarDatosInternos();
	delete this->pacientes;
}



