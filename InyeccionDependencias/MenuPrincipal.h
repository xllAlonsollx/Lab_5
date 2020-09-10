#pragma once
#include<iostream>
#include"MenuAlimentos.h"
#include"MenuPacientes.h"
using namespace std;

class MenuPrincipal
{
private:
	MenuAlimentos* menuAlimentos;
	MenuPacientes* menuPacientes;
	
public:

	MenuPrincipal(MenuAlimentos* menuAlimentos, MenuPacientes* menuPacientes)
	{
		this->menuAlimentos = menuAlimentos;
		this->menuPacientes = menuPacientes;
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
				this->menuAlimentos->invocarMenu();
				break;
			case '2':
				this->menuPacientes->invocarMenu();
				break;
			case opcionSalida:
				break;
			default:
				cerr << "Opcion invalida, digite otra vez" << endl;
			}
		} while (opcion != opcionSalida);
	}

	~MenuPrincipal()
	{
		delete menuAlimentos;
		delete menuPacientes;
	}

private:
	char mostrarOpciones()
	{
		char opcion;
		system("cls");
		cout << "Menu Principal - Seleccionar una opcion:" << endl;
		cout << "1) Menu Alimentos" << endl;
		cout << "2) Menu Pacientes" << endl;
		cout << "3) Salir" << endl;
		cin >> opcion;
		system("cls");
		return opcion;
	}

};