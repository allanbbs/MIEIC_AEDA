#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

// a alterar
bool Aposta::contem(unsigned num) const
{
    return numeros.find(num) != numeros.end();
}

//a alterar
void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
    unsigned tries = 0;
    for(auto it=valores.begin();it!=valores.end(),tries<n;it++){
        if(numeros.find(*it)==numeros.end()) {
            numeros.insert(*it);
            tries++;
        }
    }
}

//a alterar
unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
    unsigned total = 0;

    for(auto it = sorteio.begin();it!=sorteio.end();it++){
        if(numeros.find(*it) != numeros.end()) total++;
    }
    return total;
}

int Aposta::somaNumeros() const{
    int result = 0;
    for(auto it = numeros.begin();it!=numeros.end();it++){
        result+=*it;
    }
    return result;
}





