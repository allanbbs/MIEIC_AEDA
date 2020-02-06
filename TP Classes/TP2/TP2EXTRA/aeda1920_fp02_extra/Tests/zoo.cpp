#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

/*
 * Classe Zoo
 */

int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1) {
	animais.push_back(a1);
}

bool Zoo::animalJovem(string nomeA) {
	for(int i = 0; i < animais.size(); i++){
		if( animais[i]->getNome() == nomeA) return animais[i]->eJovem();
	}
	return false;
}

string Zoo::getInformacao() {

	for(int i = 0; i < animais.size(); i++){
		animais[i]->info();
	}
}

void Zoo::alocaVeterinarios(istream &isV) {
	string nome;
	long cod;
	while(!isV.eof()){
		getline()






	}
















}