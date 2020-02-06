
#include "animal.h"
#include <sstream>
using namespace std;

/*
 * Classe Animal
 */






Animal::Animal(string no, int i) {
	nome = no;
	idade = i;

}
string Animal::getNome() const {
	return nome;
}

/*string Animal::info() {
	string result = "";
	result+="Nome: " + nome + "Idade: ";
	result+=to_string(idade);
	return result;
}*/






Cao::Cao(string nome, int idade, string r) : Animal(nome,idade),raca(r){}
bool Cao::eJovem() {
	return idade<5;
}
/*string Cao::info() {

}*/




Voador::Voador(int vmax, int amax) {
	velocidade_max = vmax;
	altura_max = amax;
}











Morcego::Morcego(string nome, int idade, int vmax, int amax): Animal(nome,idade),Voador(vmax,amax) {}

bool Morcego::eJovem() {
	return idade<4;
}
