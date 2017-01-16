#include "Mapa.h"
#include "Colonia.h"
#include "Castelo.h"
#include "Ser.h"
#include "Edificio.h"
#include "Perfil.h"
#include "Configuracao.h"
#include "Consola.h"
#include "Simulacao.h"
#include <ctime>


//F
void desenharCaixa(int x, int y, int dimX, int dimY) {
	for (int i = 0; i < dimY; i++) {
		Consola::gotoxy(x, y + i);			cout << (char)186; // linha da esquerda
		Consola::gotoxy(x + dimX, y + i);	cout << (char)186; // linha da direita
	}
	for (int i = 0; i < dimX; i++) {
		Consola::gotoxy(x + i, y);			cout << (char)205; // linha de cima
		Consola::gotoxy(x + i, y + dimY);	cout << (char)205; // linha de baixo
	}
	Consola::gotoxy(x, y);					cout << (char)201; // canto sup esq
	Consola::gotoxy(x, y + dimY);			cout << (char)200; // canto sup dir
	Consola::gotoxy(x + dimX, y);			cout << (char)187; // canto inf esq
	Consola::gotoxy(x + dimX, y + dimY);	cout << (char)188; // canto inf dir
}

void desenhaMapa() { // foco � o canto sup esq da grelha
	
	//foco

	int i, j;
	for (i = 0; i < 40; i++)
		for (j = 0; j < 20; j++) {
			for (int v = 0; v < 2; v++) {
				Consola::gotoxy(8 + i * 4, 4 + j * 2 + v);			cout << (char)179; // linha da esquerda
				Consola::gotoxy(8 + i * 4 + 4, 4 + j * 2 + v);		cout << (char)179; // linha da esquerda
			}
			for (int h = 0; h < 4; h++) {
				Consola::gotoxy(8 + i * 4 + h, 4 + j * 2);			cout << (char)196; // linha de cima
				Consola::gotoxy(8 + i * 4 + h, 4 + j * 2 + 2);		cout << (char)196; // linha de cima
			}
			Consola::gotoxy(8 + i * 4, 4 + j * 2);					cout << (char)197; // canto sup esq
			Consola::gotoxy(8 + i * 4 + 4, 4 + j * 2);				cout << (char)197; // canto sup dir
			Consola::gotoxy(8 + i * 4, 4 + j * 2 + 2);				cout << (char)197; // canto inf esq
			Consola::gotoxy(8 + i * 4 + 4, 4 + j * 2 + 2);			cout << (char)197; // canto inf dir
		}
	desenharCaixa(8, 4, 40 * 4, 20 * 2);
}


int main() {

	srand(time(NULL));

	cout << endl << endl << "       Por favor maximize o ecra. ";
	getchar();

	Configuracao c;

	string comando;
	do {
		Consola::clrscr();
		//x, y, largura, altura
		desenharCaixa(1, 1, 50, 4); // do texto
		desenharCaixa(1, 6, 50, 2); // caixa de terminal
		desenharCaixa(1, 9, 50, 4); // das var


		Consola::gotoxy(3, 2);
		cout << "Bem vindo ao jogo!";
		Consola::gotoxy(3, 3);
		cout << "Aqui inseres os comandos para configurar o jogo";
		Consola::gotoxy(3, 4);
		cout << "Para usares um wizard, escreve 'configurar'";

		if (c.getdimT() == false) Consola::setTextColor(Consola::VERMELHO_CLARO); else Consola::setTextColor(Consola::VERDE_CLARO);
		Consola::gotoxy(3, 10);
		cout << "Dimensao da planicie: ";
		Consola::setTextColor(Consola::BRANCO);
		cout << c.getDimLin() << " Lin, " << c.getDimCol() << " Col";
		if (c.getoponT() == false) Consola::setTextColor(Consola::VERMELHO_CLARO); else Consola::setTextColor(Consola::VERDE_CLARO);
		Consola::gotoxy(3, 11);
		cout << "Numero de oponentes: ";
		Consola::setTextColor(Consola::BRANCO);
		cout << c.getOponentes() - 1;
		if (c.getmoedasT() == false) Consola::setTextColor(Consola::VERMELHO_CLARO); else Consola::setTextColor(Consola::VERDE_CLARO);
		Consola::gotoxy(3, 12);
		cout << "Numero de moedas: ";
		Consola::setTextColor(Consola::BRANCO);
		cout << c.getMoedas();

		//posicoes de castelos das colonias
		for (int i = 0;i < c.getOponentes(); i++) {
			desenharCaixa(1, (14 + (3 * i)), 50, 2);
			Consola::gotoxy(3, (15 + (3 * i)));
			if (c.getOponentes() == 1)
				cout << "Sem Castelos da colonia definidos.";
			else {
				cout << "Castelo da colonia " << (char)(65 + i) << ": ";
				c.Castelos_menu(i);
			}

			//cout << "X: " << c. << ", Y : " << c.getCoordY(i);
		}

		if (c.gettamvetor() > 0) { // mostrar os perfis
			for (int i = 0; i < c.gettamvetor(); i++) {
				desenharCaixa(53 + (28 * i), 1, 25, 20);
				Consola::gotoxy(54 + (28 * i), 2);
				cout << "       Perfil '" << c.getcharperf(i) << "'"; // o perfil tem uma letra especificada pelo jogador
				Consola::gotoxy(54 + (28 * i), 3);
				cout << "Forca disponivel: " << c.getForcaPerf(i); // max 10
				Consola::gotoxy(54 + (28 * i), 4);
				cout << "Custo do perfil: " << c.getCustoPerf(i);
				Consola::gotoxy(54 + (28 * i), 5);
				cout << "Caracteristicas:";
				vector<string> car = c.getCar(i);
				for (int j = 0; j < car.size(); j++) {
					Consola::gotoxy(56 + (28 * i), 6 + j);
					cout << car[j];
				}
			}
		}

		if (c.getcomInv() == true) {
			Consola::gotoxy(40, 7);
			Consola::setTextColor(Consola::VERMELHO_CLARO);
			cout << "Invalido!";
			Consola::setTextColor(Consola::BRANCO);
		}

		Consola::gotoxy(3, 7);
		cout << "comando: ";
		getline(cin, comando);// comando completo
		istringstream iss(comando);
		string primeira, segunda, terceira, quarta;
		iss >> primeira >> segunda >> terceira >> quarta;


		if (primeira == "load")
			c.loadFile(segunda);
		else
			c.processaComando(primeira, segunda, terceira, quarta);
		

	} while (c.getInicio() == false);

	Consola::clrscr();

	//iniciar o jogo

	Mapa *mapa = new Mapa(c.getDimLin(), c.getDimCol());
	vector<Colonia *> colonias;
	for (int i = 0; i < c.getOponentes(); i++) {
		Castelo * castelo = new Castelo();
		castelo->setPosEdificio(c.getCast_X(i), c.getCast_Y(i));
		Colonia *colonia = new Colonia(castelo);
		colonia->setMoedas(c.getMoedas());
		castelo->SetIdentificaCol(colonia->getIDCol()); // identifica a que colónia pertence o castelo
		castelo->setPosEdificio(c.getCast_X(i), c.getCast_Y(i)); // posiciona o castelo

		//perfis
		if (i == 0) {
			colonia->AddPerfil(c.getPerfil(0));
			colonia->AddPerfil(c.getPerfil(1));
		}
		else {
			colonia->AddPerfil(c.getPerfil(rand() % c.getTamanhoVectorPerfil()));
			colonia->AddPerfil(c.getPerfil(rand() % c.getTamanhoVectorPerfil()));
		}
		mapa->SetMapaCastelo(c.getCast_X(i), c.getCast_Y(i), castelo);
		
		colonias.push_back(colonia);
	}

	Simulacao sim(mapa, colonias);




	Consola::setTextSize(12,12);

	while (1) {

		desenhaMapa(); 
		mapa->preencheMapaEcrajogo(sim.getfocoX(), sim.getfocoY());
		/*
		//caixa para stats à direita.
		desenharCaixa(170, 4, 40, 43);
		for (int i = 0; i < 5; i++) {
			Consola::gotoxy(171, 5 + i * 5);
			cout << "Legenda do mapa ?";
		}
		*/

		//caixa para comandos
		desenharCaixa(8, 45, 40 * 4, 2);
		Consola::gotoxy(9, 46);
		getline(cin, comando);// comando completo
		istringstream iss(comando);
		string primeira, segunda, terceira, quarta;
		iss >> primeira >> segunda >> terceira >> quarta;
		sim.processaComando(primeira, segunda, terceira);

		//ecr� de perfis
		Consola::clrscr();

		sim.movimentodeSeres();
	}


	Consola::gotoxy(0, 0);
	return 0;

}
