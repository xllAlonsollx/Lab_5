#include "Paciente.h"

Paciente::Paciente(string nombre)
{
	this->nombre = nombre;
	this->alimentos = new ArrayList(8);
}

void Paciente::agregarAlimentoADieta(Alimento* alimento)
{
	this->alimentos->insertarAlFinal(alimento);
}

int Paciente::totalCaloriasEnDieta()
{
	int total = 0;
	IIterador* ite = this->alimentos->obtenerIterador();
	while (ite->haySiguiente())
	{
		Alimento* actual = dynamic_cast<Alimento*>(ite->actual());
		total += actual->getCaloriasDiarias();
	}
	delete ite;
	return total;
}

string Paciente::toString()
{
	stringstream s;
	s << "Nombre: " << this->nombre << endl;
	if (this->alimentos->getCantidad() > 0)
	{
		s << "Los alimentos del paciente son: " << endl;
		IIterador* ite = this->alimentos->obtenerIterador();
		while (ite->haySiguiente())
		{
			Alimento* actual = dynamic_cast<Alimento*>(ite->actual());
			s << actual->getNombre() << endl;
		}
		delete ite;
	}
	else
	{
		s << "El paciente no tiene alimentos asociados." << endl;
	}
	return s.str();
}

Paciente::~Paciente()
{
	delete this->alimentos;
}
