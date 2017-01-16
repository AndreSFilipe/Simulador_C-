#include "Ser.h"

Ser::Ser(Perfil * p) : perf(p){
	this->id = aux;
	aux++;
	this->forca = p->getForca(); // capacidade de ter inumeras caracteristicas
	this->custo = p->getCusto(); // deixar apenas o custo no perfil ?
	//carregar novas caracteristas apartir do perfil
	this->saude += 10;
	this->ataque = 0;
	this->defesa = 0;
	this->velocidade = 0;
}

char Ser::aux = 'a';
int Ser::getSaude()
{
	return this->saude;
}
void Ser::setSaude(int saude){
	this->saude += saude;
}
int Ser::getCusto()
{
	return this->custo;
}
void Ser::setCusto(int custo){
	this->custo += custo;
}
int Ser::getForca()
{
	return this->forca;
}
void Ser::setForca(int forca){
	this->forca -= forca;
}
void Ser::setPosicao(int lin, int col){
	this->posicao[0] = col;
	this->posicao[1] = lin;
}
int * Ser::getPos()
{
	return this->posicao;
}
void Ser::mostraSerInfo(ostringstream & os) const{
	os.str("");
	os << "ID(" <<id <<") -";
	os << " Stats:(Forca : " << forca << " | Saude : " << saude << " )" <<endl;
	cout << os.str();
	perf->infoPerfil();
}
int Ser::getVelocidade()
{
	return this->velocidade;
}
char Ser::getID()
{
	return this->id;
}
void Ser::setIDCol(int n)
{
	this->id_col = n;
}
int* Ser::moveSer(int velocidade, int posicao[], int limites[], vector<int> posOcupadas) {  
													// col = posicao[0] = x
													// lin = posicao[1] = y
	bool repete; //para validar o movimento
	bool passou = false;

	for (int i = 0; i < velocidade; i++) {
		do {
			do {
				int new_pos = rand() % 8;
				repete = false;
				switch (new_pos) {
				case 0: // CIMA
					if (posicao[1] == 0) //y == 0
						repete = true;
					else
						posicao[1]++;

				case 1: // CIMA DIREITA
					if (posicao[0] == limites[0] && posicao[1] == 0) // x == maxX && y == 0
						repete = true;
					else {
						posicao[0]++; // x++
						posicao[1]++;
					}
				case 2: // DIREITA
					if (posicao[0] == limites[0]) // x == maxX
						repete = true;
					else
						posicao[0]++;

				case 3: // BAIXO DIREITA
					if (posicao[0] == limites[0] && posicao[1] == limites[1]) // x = maxX && y = maxY
						repete = true;
					else {
						posicao[0]++;
						posicao[1]--; // y--
					}
				case 4: // BAIXO
					if (posicao[1] == limites[1]) // y == maxY
						repete = true;
					else
						posicao[1]--;

				case 5: // BAIXO ESQUERDA
					if (posicao[0] == 0 && posicao[1] == limites[1]) // x == 0 && y == maxY
						repete = true;
					else {
						posicao[0]--;
						posicao[1]--;
					}

				case 6: // ESQUERDA
					if (posicao[0] == 0) // x == 0
						repete = true;
					else
						posicao[0]--;

				case 7: // CIMA ESQUERDA
					if (posicao[0] == 0 && posicao[1] == 0) // x == 0 && y == 0
						repete = true;
					else {
						posicao[0]--; //x--
						posicao[1]++;
					}

				default:
					break;
				}
			} while (repete == true);

			passou = true; // nada indica que esteja ocupado
			for (int j = 0; j < sizeof(posOcupadas); j = j + 2)
				if (posOcupadas[j] == posicao[0] && posOcupadas[j + 1] == posicao[1])
					passou = false; // a posicao está ocupada e vai procurar uma nova

		} while (passou == false);
	}

	return posicao;
}

