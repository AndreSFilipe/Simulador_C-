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

bool Identificador_Mapa::verificaSer()
{
	if (ser_pos != nullptr)
		return false;
	else
		return true;
}

bool Identificador_Mapa::verificaCasetelo()
{
	if (cast_pos == nullptr)
		return true;
	else
		return false;
}

bool Identificador_Mapa::verificaEdificio()
{	
	if (edificio_pos == nullptr)
		return true;
	else
		return false;
}

bool Identificador_Mapa::PremissaoParaMover()
{	
	bool ser = verificaSer();
	bool edi = verificaEdificio();
	bool cas = verificaCasetelo();

	if (cas == false || ser == false || ser == false)
		return false;
	else
		return true;
}

bool Identificador_Mapa::RetiraCastelo(int i){
	cast_pos->removeSer(i);
	return true;
}

bool Identificador_Mapa::RetiraSerDoMapa()
{
	//fazer destrutor do ser antes
	this->ser_pos = nullptr;
	return true;
}

int Identificador_Mapa::retornaNumSeres()
{
	return cast_pos->NumSeres();
}

Ser * Identificador_Mapa::getSerDoCastelo(int i)
{
	return cast_pos->getSerEspecifico(i);
}

void Identificador_Mapa::atualizaPosSer(int x, int y)
{
	ser_pos->setPosicao(x, y);
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

