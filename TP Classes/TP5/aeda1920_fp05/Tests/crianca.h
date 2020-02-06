/*
 * crianca.h
 */

#ifndef CRIANCA_H_
#define CRIANCA_H_

#include <string>
#include <sstream>
using namespace std;

class Crianca {
	string nome;

public:
    unsigned int idade;
	Crianca();
	Crianca(string nome, unsigned idade);
	Crianca(const Crianca& c1);
	string getNome() const;
	unsigned int getIdade() const;
	bool operator==(const Crianca& c2) const;
	string escreve() const;
	friend ostream & operator<<(ostream & o, const Crianca & d);
    Crianca& operator=(const Crianca& c1) ;
};

#endif /* CRIANCA_H_ */
