#include "Identificador_Mapa.h"
#include "Consola.h"

Identificador_Mapa::Identificador_Mapa(int linhas,int colunas){
	this->ser_pos = nullptr;
	this->edificio_pos = nullptr;
	this->cast_pos = nullptr;
}


bool Identificador_Mapa::addSer(Ser * s) {
	if (s == nullptr || edificio_pos != nullptr || ser_pos != nullptr)
		return false;
	else {
		Ser *aux = s; // o ser contém de que colónia é
		this->ser_pos = aux;
		return true;
	}
	return false;
}
bool Identificador_Mapa::addEdificio(Edificio * e)
{
	if (e == nullptr || ser_pos != nullptr || edificio_pos != nullptr)
		return false;
	else {
		Edificio *aux = e;
		this->edificio = e->getTipoEd();
		this->edificio_pos = aux;
		return true;
	}
}

bool Identificador_Mapa::addCastelo(Castelo * c)
{
	if (c == nullptr || ser_pos != nullptr || edificio_pos != nullptr)
		return false;
	else {
		Castelo *aux = c;
		this->cast_pos = aux;
		return true;
	}
}


Ser * Identificador_Mapa::getSer()
{
	if (this->ser_pos == nullptr) { return false; }
	else { return this->ser_pos; }
}

Edificio * Identificador_Mapa::getEdificio()
{
	if (edificio_pos == nullptr)
		return nullptr;
	else
		return this->edificio_pos;
}

bool Identificador_Mapa::verificaOcupado()
{
	if (ser_pos != nullptr && edificio_pos==nullptr && cast_pos==nullptr)
		return true;
	else
		return false;
}

bool Identificador_Mapa::setSer(Ser *s) // tem que receber a colonia
{
	if (edificio_pos != nullptr || ser_pos != nullptr)
		return false;
	else {
		this->ser_pos = s;
		return true;
	}
}

void Identificador_Mapa::imprime()
{
	/*
	testar se está vazio
		break;
	senão
		-calcular cor
		-imprimir edificio ou ser
	*/

	if (cast_pos == nullptr && ser_pos == nullptr && edificio_pos != nullptr)
		cout << " E";
	else
		if (cast_pos == nullptr && ser_pos != nullptr && edificio_pos == nullptr)
			cout << " S";//cout << ser_pos;
		else
			if (cast_pos != nullptr && ser_pos == nullptr && edificio_pos == nullptr)
				cout << "C";
			else
				if (cast_pos == nullptr && ser_pos == nullptr && edificio_pos == nullptr)
					cout << "";

}

string Identificador_Mapa::getTipoEdificio()
{
	return edificio_pos->getTipoEd();
}
