#pragma once
#include"InventarioAlimentos.h"

class MenuAlimentos
{
private:
	InventarioAlimentos* inventarioAlimentos;

public:
	MenuAlimentos(InventarioAlimentos* inventarioAlimentos)
	{
		this->inventarioAlimentos = inventarioAlimentos;
	}

	void invocarMenu()
	{
		const char opcionSalida = '3';
		char opcion;
		do {
			opcion = mostrarOpciones();
			switch (opcion)
			{
			case '1':
				this->ingresarAlimento();
				break;
			case '2':
				this->imprimirAlimentos();
				break;
			case opcionSalida:
				break;
			default:
				cerr << "Opcion invalida, digite otra vez" << endl;
			}
		} while (opcion != opcionSalida);
	}

private:
	char mostrarOpciones()
	{
		char opcion;
		system("cls");
		cout << "Menu Alimentos:" << endl;
		cout << "1) Ingresar Alimento" << endl;
		cout << "2) Imprimir Alimentos" << endl;
		cout << "3) Salir" << endl;
		cin >> opcion;
		system("cls");
		return opcion;
	}

	void ingresarAlimento()
	{
		Alimento* alimento = crearAlimento();
		this->inventarioAlimentos->agregarAlimento(alimento);
	}

	Alimento* crearAlimento()
	{
		string nombre;
		int calorias;
		cout << "Nombre:" << endl;
		cin >> nombre;
		cout << "Calorias:" << endl;
		cin >> calorias;
		return new Alimento(nombre, calorias);
	}

	void imprimirAlimentos()
	{
		cout << this->inventarioAlimentos->toString() << endl;
		system("pause");
	}
};