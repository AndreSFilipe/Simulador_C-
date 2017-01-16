#include "Castelo.h"

Castelo::Castelo() {
	this->custo = 0;
	this->saude = 50;
	this->defesa = 10;
}
char Castelo::getIdColonia()
{
	return this->id_col;
}
/*void Castelo::InfoEdificio(ostringstream  & os) {

	os.str("");
	os << " ___EDIFICIO___" << endl;
	os << "|ID Colonia: " << id_col << " |" << endl;
	os << "|Saude: " << saude << "     |" << endl;
	os << "|Defesa: " << defesa << "    |" << endl;
	os << "|______________|" << endl;
	if (!edSeres.empty()) {
		for (int i = 0; i < edSeres.size(); i++) {
			edSeres[i]->mostraSerInfo(os);
			cout << os.str() << endl;
		}
	}
}*/
void Castelo::SetIdentificaCol(char id)
{
	this->id_col = id;
}
void Castelo::setPosEdificio(int col, int lin)
{
	this->posicao[0] = col;
	this->posicao[1] = lin;
}
int* Castelo::getPosEdificio()
{
	return this->posicao;
}
bool Castelo::addSer(Ser * s)
{
	if (s == nullptr)
		return false;

	Ser* aux = s;
	int* posCast = this->getPosEdificio();
	aux->setPosicao(posCast[1], posCast[0]);
	edSeres.push_back(aux);
	return true;
}
//->
bool Castelo::removeSer(int i)
{
	if (edSeres.size() < i) {
		edSeres.erase(edSeres.begin() + i);
		return true;
	}	
	else	
		return false;
}
vector<Ser*> Castelo::retornaSeres()
{
	return this->edSeres;
}
//->
Ser * Castelo::getSerEspecifico(int i)
{
	return this->edSeres[i];
}

void Castelo::setOrdem(bool ordem)
{
	this->ordem = ordem;
}
bool Castelo::getOrdem()
{
	return this->ordem;
}

int Castelo::NumSeres()
{
	return this->edSeres.size();
}
