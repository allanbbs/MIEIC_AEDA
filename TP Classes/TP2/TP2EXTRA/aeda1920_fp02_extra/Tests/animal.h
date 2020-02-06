
#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinario.h"
#include <string>
using namespace std;


class Animal {
protected:
	string nome;
	int idade;
	Veterinario *vet;
	static int maisJovem;
public:
	Animal(string no, int i);
	int getMaisjovem();
	virtual ~Animal(){};
	string getNome() const;
	virtual bool eJovem() const = 0;
	virtual string info();
	//completar
};


class Cao: public Animal {
	string raca;
public:
	Cao(string nome, int idade, string raca);
	bool eJovem();
	string info();
};


class Voador {
	int velocidade_max;
	int altura_max;
public:
	Voador(int vmax, int amax);
    virtual ~Voador(){};
	virtual string info();
};


class Morcego: public Animal, public Voador {
public:
	Morcego(string nome, int idade, int vmax, int amax);
	bool eJovem();
	string info();
};


#endif /* SRC_ANIMAL_H_ */
