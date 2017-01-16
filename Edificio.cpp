#include "Edificio.h"

Edificio::Edificio(int custo, int saude, int def): custo(custo),saude(saude),defesa(def) {
	this->id = aux;
	aux++;
}
char Edificio::aux = 'a';

void Edificio::InfoEdificio(ostringstream  & os){
	
	os.str("");
	os << "ID Colonia: " << id_col << endl;
	os << "ID: " << id << endl;
	os << "Saude: " << saude << endl;
	os << "Defesa: " << defesa << endl;
}
char Edificio::getIdEdificio()
{
	return this->id;
}
void Edificio::SetIdentificaCol(char id)
{
	this->id_col = id;
}
void Edificio::setPosEdificio(int col, int lin)
{
	this->posicao[0] = col;
	this->posicao[1] = lin;
}
int * Edificio::getPosEdificio()
{
	return this->posicao;
}
string Edificio::getTipoEd()
{
	return "Edificio";
}


Torre::Torre(int custo, int saude, int def, int atk) : Edificio(custo, saude, def), ataque(atk) {
}
void Torre::InfoEdificio(ostringstream  & os){	
	os.str("");
	os << "ID Colonia: " << id_col << endl;
	os << "ID: " << id << endl;
	os << "Saude: " << saude << endl;
	os << "Defesa: " << defesa << endl;
	os << "Ataque: " << ataque << endl;
	
}
char Torre::getIdEdificio()
{
	return this->id;
}
void Torre::SetIdentificaCol(char id)
{
	this->id_col = id;
}
int * Torre::getPosEdificio()
{
	return this->posicao;
}
bool Torre::PermissaoConstrucao(int col, int lin)
{
	int limite_col = this->posicao[0];
	int limite_lin = this->posicao[1];
	if (col < limite_col - 10 || lin < limite_lin - 10)
		return false;
	else
		if (col > limite_col + 10 || lin < limite_col - 10)
			return false;
		else
			return true;
}
void Torre::setPosEdificio(int col, int lin)
{
	this->posicao[0] = col;
	this->posicao[1] = lin;
}


Quinta::Quinta(int custo, int saude, int def, int prod) : Edificio(custo, saude, def),producao(prod){}
/*bool Quinta::PermissaoConstrucao(int col, int lin)
{
	int limite_col = this->posicao[0];
	int limite_lin = this->posicao[1];
	if (col < limite_col - 10 || lin < limite_lin - 10)
		return false;
	else
		if (col > limite_col + 10 || lin < limite_col - 10)
			return false;
		else
			return true;
}

*/


