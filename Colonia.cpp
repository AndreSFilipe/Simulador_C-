#include "Colonia.h"

Colonia::Colonia(Castelo *c) : castelo(c){
	id = aux;
	aux++;
	
}
char Colonia::aux = 'A';

bool Colonia::AddPerfil(Perfil * p){
	if (p == nullptr)
		return false;

	Perfil* aux = p;
	perfis.push_back(aux);
	return true;

}

/*bool Colonia::AddSer(Ser * s){
	if (s == nullptr)
		return false;

	Ser* aux = s;
	aux->setPosicao(this->edificos[0]->getPosEdificio());
	seres.push_back(aux);
	return true;
}*/

bool Colonia::AddEdificio(Edificio * e){
	if (e == nullptr)
		return false;

	Edificio* aux = e;

	aux->SetIdentificaCol(this->getIDCol());
	edificos.push_back(aux);
	return true;
}

bool Colonia::BuildSer(char perfil, char id_col){

	int op = posPerfil(perfil);
	if (op == -1)
		return false;
	Ser *nSer = new Ser(perfis[op]);
	nSer->setIDCol(id_col);
	this->castelo->addSer(nSer);  // adiciona o ser dentro do castelo, após este se mover vai para o vector de seres
	return true;

}

char Colonia::getIDCol(){
	return this->id;
}

int Colonia::getMoedas(){
	return this->moedas;
}

void Colonia::setMoedas(int moedas){
	this->moedas = moedas;
}

void Colonia::infoColonia(){
	ostringstream os;
	os.str("");
	cout << "Colonia " << id << endl;
	cout << "Dinheiro: " << moedas << endl;
	cout << "------------------" << endl;
	if (!perfis.empty()) {
		for (int i = 0; i < perfis.size(); i++) {
			perfis[i]->infoPerfil();
		}
	}/*
	if (!seres.empty()) {
		for (int i = 0; i < seres.size(); i++) {
			seres[i]->mostraSerInfo(os);
			cout << os.str() << endl;
		}
	}*/
	if (!edificos.empty()) {
		for (int i = 0; i < edificos.size(); i++) {
			edificos[i]->InfoEdificio(os);
			cout << os.str() << endl;
		}
	}

}

int Colonia::posPerfil(char perfil)
{
	for (int i = 0; i < perfis.size(); i++)
		if (perfil == perfis[i]->getID())
			return i;
	return -1;

}


Edificio * Colonia::getCast()
{
	return edificos[0];
}

bool Colonia::getOrdem()
{
	return this->castelo->getOrdem();
}

void Colonia::setOrdem(bool ordem)
{
	this->castelo->setOrdem(ordem);
}

vector<Ser*> Colonia::getSeresCastelo()
{
	return this->castelo->retornaSeres();
}
