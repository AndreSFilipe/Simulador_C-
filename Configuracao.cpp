#include "Configuracao.h"
#include "Colonia.h"
#include "Mapa.h"
#include "Identificador_Mapa.h"
#include "Perfil.h"


using namespace std;

Configuracao::Configuracao() {
	caracteristicas.push_back("Bandeira");
	caracteristicas.push_back("Superior");
	caracteristicas.push_back("Pele dura");
	caracteristicas.push_back("Armadura");
	caracteristicas.push_back("Faca");
	caracteristicas.push_back("Espada");
	caracteristicas.push_back("Agressão");
	caracteristicas.push_back("Ecológico");
	caracteristicas.push_back("HeatSeeker");
	caracteristicas.push_back("BuildSeeker");
	caracteristicas.push_back("Walker");
	caracteristicas.push_back("Remedio");
	caracteristicas.push_back("SecondChance");
	caracteristicas.push_back("Aluno");

	dimLin = 0;
	dimCol = 0;
	moedas = 150;
	opon = 1;
	this->dimT = false;
	this->inicioT = false;
	this->moedasT = false;
	this->oponT = false;
	this->comInv = false; // comando invalido
}

void Configuracao::processaComando(string primeira, string segunda, string terceira, string quarta) {
	this->comInv = false;
	if (primeira == "dim" && dimT == false) {
		dimT = true;
		Configuracao::setDim(stoi(segunda), stoi(terceira));
	} else
	if (primeira == "moedas") {
		moedasT = true;
		Configuracao::setMoedas(stoi(segunda));
	} else
	if (primeira == "oponentes" && dimT == true) {
		oponT = true;
		Configuracao::setOponentes(stoi(segunda));
	} else
	if (primeira == "castelo" && oponT == true)
		Configuracao::setPosCastelo(segunda, stoi(terceira), stoi(quarta));
	else
	if (primeira == "inicio")
		Configuracao::setInicio();
	else 
	if (primeira == "mkperfil")
		Configuracao::mkperfil(segunda);
	else 
	if (primeira == "addperfil")
		Configuracao::addperfil(segunda, terceira);
	else
	if (primeira == "subperfil")
		Configuracao::subperfil(segunda, terceira);
	else
	if (primeira == "rmperfil")
		Configuracao::rmperfil(segunda);
	else { this->comInv = true;	}
}

void Configuracao::loadFile(string fich) {
	ifstream infile(fich); if (!infile) { this->comInv = true; return; }

	string line;
	while (getline(infile, line)) {
		istringstream iss(line);
		string primeira, segunda, terceira, quarta;
		iss >> primeira >> segunda >> terceira >> quarta;
		Configuracao::processaComando(primeira, segunda, terceira, quarta);
	}

}
void Configuracao::setInicio() {
	this->inicioT = true;
}
void Configuracao::mkperfil(string segunda){
	const char *letra = segunda.c_str();

	for (int i = 0; i < perfis.size();i++) // valida se há um igual
		if (perfis[i]->getID() == *letra) {
			this->comInv = true;
			return;
		}

	Perfil *p1 = new Perfil(*letra);
	perfis.push_back(p1);
}
void Configuracao::addperfil(string segunda, string terceira)
{
	const char *letra = segunda.c_str();

	int i=0;
	/*
	if (perfis.size() == 0) {
		this->comInv = true;
		return;
	}*/

	while (perfis[i]->getID() != *letra){
		i++;
		if (i > perfis.size()) {
			this->comInv = true;
			return;
		}
	}

	int _case = 0;
	for (int j = 0; j < caracteristicas.size(); j++) {
		if (caracteristicas[j] == terceira)
			break;
		_case++;
		if (j > caracteristicas.size()) { // testa se já percorreu o vector
			this->comInv = true;
			return;
		}
	}
	if (perfis[i]->getForca() <= 0)
		this->comInv = true;
	else {
		switch (_case) {
		case (0):
			perfis[i]->addCarateristica(new Bandeira(1, 1));
		default:
			break;
		}
	}
	

	//perfis[i]->addCarateristica(new Superior(3,2,1));
}
void Configuracao::subperfil(string segunda, string terceira)
{

	const char *letra = segunda.c_str();

	int i = 0;
	while (perfis[i]->getID() != *letra) {
		i++;
		if (i > perfis.size()) {
			this->comInv = true; 
			return;
		}
	}

	int j;
	vector<string> car = perfis[i]->getCar();
	for (j = 0; car[j] != terceira; j++) {
		if (car[j] == terceira)
			break;
	}

	perfis[i]->subCarateristica(j);

}
void Configuracao::rmperfil(string segunda)
{
	const char *letra = segunda.c_str();
	int i = 0;
	while (perfis[i]->getID() != *letra) {
		i++;
		if (i > perfis.size()) {
			this->comInv = true;
			return;
		}
	}
	perfis.erase(perfis.begin() + i);
	//perfis[i].erase(perfis.size() + i);

}

vector<string> Configuracao::getCar(int i)
{
	return vector<string>(perfis[i]->getCar());
}
int Configuracao::getTamanho(int _x , int _y){

	return _x*_y;
}
void Configuracao::setDim(int lin, int col) {
	this->dimLin = lin;
	this->dimCol = col;
	this->tamanho = lin*col;
}
int Configuracao::getDimLin(){
	return this->dimLin;
}
int Configuracao::getDimCol(){
	return this->dimCol;
}
void Configuracao::setMoedas(int n) {
	this->moedas = n;
}
int Configuracao::getMoedas(){
	return this->moedas;
}
Perfil * Configuracao::getPerfil(int i){

	return (this->perfis[i]);
}
int Configuracao::getTamanhoVectorPerfil(){
	return this->perfis.size();
}

void Configuracao::setOponentes(int op) {

	this->opon = op + 1;

	for (int i = 0; i < opon; i++) {
		Cast_X.push_back(rand() % this->dimCol);
		Cast_Y.push_back(rand() % this->dimLin);
	}

	for (int i = 0; i < opon; i++)
		for (int j = 0; j < opon; j++)
			if (Cast_X[i] == Cast_X[j] && Cast_Y[i] == Cast_Y[j]) {
				Cast_X[j] = rand() % this->dimCol;
				Cast_Y[j] = rand() % this->dimLin;
			}
}
int Configuracao::getOponentes()
{
	return this->opon;
}
void Configuracao::setPosCastelo(string colonia, int x, int y) {

	int i = (int)colonia.at(0), teste = i;
	if ((teste - 90) < 0) // 90 poder ser um nr qq entre os char maiusculos e minusculos
		i = i - 65;
	else
		i = i - 97;

	if (this->opon < i) {
		this->comInv = true;
		return;
	}

	if (x < 0 || x > this->dimCol || y < 0 || y > this->dimLin) {
		this->comInv = true;
		return;
	}

	for (int i = 0; i < this->opon; i++) // valida de algum castelo no campo escolhido
		if (Cast_X[i] == x && Cast_Y[i] == y) {
			this->comInv = true;
			return;
		}
	
	Cast_X[i] = x;
	Cast_Y[i] = y;
}

bool Configuracao::getInicio() { 
	return inicioT; 
}

bool Configuracao::getcomInv() {
	return comInv;
}

bool Configuracao::getdimT(){
	return dimT;
}

bool Configuracao::getmoedasT(){
	return moedasT;
}

bool Configuracao::getoponT(){
	return oponT;
}

int Configuracao::gettamvetor() {
	return perfis.size();
}

char Configuracao::getcharperf(int i)
{
	return perfis[i]->getID();
}
int Configuracao::getForcaPerf(int i) {
	return perfis[i]->getForca();
}
int Configuracao::getCustoPerf(int i)
{
	return perfis[i]->getCusto();
}

void Configuracao::Castelos_menu(int _i){
	cout <<"X "<< Cast_X[_i]<<" , "<<"Y " << Cast_Y[_i];
}

int Configuracao::getCast_X(int i)
{
	return Cast_X[i];
}

int Configuracao::getCast_Y(int i)
{
	return Cast_Y[i];
}

