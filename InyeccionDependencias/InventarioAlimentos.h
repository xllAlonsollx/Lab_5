#pragma once
#include"Alimento.h"
#include"Colecciones/IList.h"
#include"Colecciones/IIterable.h"
#include"Colecciones/ArrayList.h"

class InventarioAlimentos
{
private:
	IList* alimentos;

public:
	InventarioAlimentos(IList* contenedor);
	InventarioAlimentos(const InventarioAlimentos& source) = delete;
	InventarioAlimentos& operator=(const InventarioAlimentos& source) = delete;
	void agregarAlimento(Alimento* alimento);
	Alimento* consultaAlimento(string nombre);
	IIterable* alimentosBajosEnCalorias(int maxCalorias);
	string toString();

	~InventarioAlimentos();
};