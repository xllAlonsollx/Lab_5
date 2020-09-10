#include "InventarioAlimentos.h"

InventarioAlimentos::InventarioAlimentos(IList* contenedor)
{
	this->alimentos = contenedor;
}

void InventarioAlimentos::agregarAlimento(Alimento* alimento)
{
	this->alimentos->insertarAlFinal(alimento);
}

Alimento* InventarioAlimentos::consultaAlimento(string nombre)
{
	IIterador* ite = this->alimentos->obtenerIterador();
	Alimento* resultado = nullptr;
	while (ite->haySiguiente())
	{
		Alimento* actual = dynamic_cast<Alimento*>(ite->actual());
		if (actual->getNombre() == nombre)
		{
			resultado = actual;
			break;
		}
	}
	delete ite;
	return resultado;
}

IIterable* InventarioAlimentos::alimentosBajosEnCalorias(int calorias)
{
	IIterador* ite = this->alimentos->obtenerIterador();
	IList* alimentosBajosEnCalorias = new ArrayList(4);
	while (ite->haySiguiente())
	{
		Alimento* actual = dynamic_cast<Alimento*>(ite->actual());
		if (actual->getCaloriasDiarias() <= calorias)
		{
			alimentosBajosEnCalorias->insertarAlFinal(actual);
		}
	}
	delete ite;
	return alimentosBajosEnCalorias;
}

string InventarioAlimentos::toString()
{
	return this->alimentos->toString();
}

InventarioAlimentos::~InventarioAlimentos()
{
	this->alimentos->liberarDatosInternos();
	delete this->alimentos;
}
