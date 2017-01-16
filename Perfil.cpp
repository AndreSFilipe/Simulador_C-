#include "Perfil.h"

Perfil::Perfil(char i) {
	this->id = i;
	this->forca = 10;
	this->custo = 0;
}
Perfil::Perfil(Perfil & p){
	this->id = p.id;
	this->forca = p.forca;
	this->custo = p.custo;
	for (int i = 0; i < caracteristicas.size(); i++){
		caracteristicas.push_back(p.caracteristicas[i]->clone());
	}
}

Caracteristica * Caracteristica::clone()
{
	return new Caracteristica(*this);
}

bool Perfil::addCarateristica(Caracteristica *c){
	if (c == nullptr)
		return false;

	this->setForca(c->getForca());
	this->setCusto(c->getCusto());
	caracteristicas.push_back(c);
	nomesCar.push_back(c->getNome());

	return true;
}
void Perfil::subCarateristica(int i) {
	// verificar se foi bem sucedido
	this->forca += caracteristicas[i]->getForca();
	this->custo -= caracteristicas[i]->getCusto();
	this->caracteristicas.erase(caracteristicas.begin() + i);
	this->nomesCar.erase(nomesCar.begin() + i);
}
void Perfil::perfilMenu(string nome) {
	
}
char Perfil::getID()
{
	return this->id;
}
int Perfil::getForca()
{
	return this->forca;
}
vector<string> Perfil::getCar()
{
	return vector<string>(this->nomesCar);
}
void Perfil::infoPerfil() const{
	ostringstream  os;
	os.str("");
	os << "Perfil: " << this->id << endl;
	cout << os.str();
	if (!caracteristicas.empty()) {
		for (int i = 0; i < caracteristicas.size(); i++) {
			caracteristicas[i]->infoCaracteristica(os);
			cout << os.str() << endl;
		}
	}
}

/*int Perfil::verificEspada(){
	int espada = 0;
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome == "Espada")
			espada = i;

	if (espada == 1)
		return espada;
	else
		return 0;
}

/*bool Perfil::VerificanumAtk(){
	int espada = verificEspada();
	if (espada != 0) {
		caracteristicas[espada]->
	}
}*/



Caracteristica::Caracteristica(string _nome, int _id,int _custo, int _forca) 
	: nome(_nome),id(_id), custo(_custo),forca(_forca) { }
int Caracteristica::getForca()
{
	return this->forca;
}
int Caracteristica::getCusto()
{
	return this->custo;
}

void Perfil::setForca(int _f){
	this->forca -= _f;
}
int Perfil::getCusto()
{
	return this->custo;
}
void Perfil::setCusto(int _c)
{
	this->custo += _c;
}

string Caracteristica::getNome()
{
	return string(nome);
}
void Caracteristica::infoCaracteristica(ostringstream &os){
	os.str("");
	os << "Nome: " << nome << endl;
	os << "Custo: " << custo << endl;
	os << "Forca:" << forca << endl;
	cout << os.str();
}


Bandeira::Bandeira(int cust,int forc) : Caracteristica("Bandeira",1,cust,forc){
}
void Bandeira::infoCaracteristica(ostringstream & os)
{
	os.str("");
	os << "Nome: " << nome << endl;
	os << "Custo: " << custo << endl;
	os << "Forca:" << forca << endl;
}
Superior::Superior(int cust, int forc) : Caracteristica("Superior",2,cust, forc) {
	this->up_saude = 1;
}
void Superior::infoCaracteristica(ostringstream & os){
	os.str("");
	os << "Nome: " << nome << endl;
	os << "Custo: " << custo << endl;
	os << "Forca:" << forca << endl;
}
int Superior::getSau(){
	return this->up_saude;
}

PeleDura::PeleDura(int cust, int forc) : Caracteristica("Pele Dura",3,cust, forc){
	this->upDef = 1;
}
int PeleDura::getDef()
{
	return this->upDef;
}

Armadura::Armadura(int cust, int forc) : Caracteristica("Armadura",4,cust, forc){
	this->upDef = 2;
}
int Armadura::getDef()
{
	return this->upDef;
}

Faca::Faca(int cust, int forc) :Caracteristica("Faca", 5, cust, forc) {
	this->upAtk = 1;
}
int Faca::getAtk()
{
	return this->upAtk;
}

Espada::Espada(int custo, int forc): Caracteristica("Espada",6,custo,forc)
{
	this->upAtk = 3;
	this->numAtk = 2;
	this->reload = false;
}
int Espada::getAtk()
{
	return this->upAtk;
}
void Espada::setAtk(int upAtk)
{
	this->upAtk = upAtk;
}
int Espada::getNumAtk()
{
	return this->numAtk;
}
void Espada::setNumAtk(int _NumAtk)
{
	this->numAtk = _NumAtk;
}
bool Espada::getReload()
{
	return this->reload;
}
void Espada::setRealod(bool _reload)
{
	this->reload = _reload;
}

