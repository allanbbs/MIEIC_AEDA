/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

// a implementar
Jogo::Jogo()
{
}

// a implementar
Jogo::Jogo(list<Crianca>& lc2)
{
    criancas = lc2;
}

// a implementar
void Jogo::insereCrianca(const Crianca &c1)
{
    criancas.push_back(c1);
}

// a implementar
list<Crianca> Jogo::getCriancasJogo() const
{
    list<Crianca> res(criancas);
    return res;
}

// a implementar
string Jogo::escreve() const
{
    string res;
    list<Crianca>::const_iterator it = criancas.begin();
    for(auto it = criancas.begin(); it != criancas.end() ;it++) {
        res += (*it).escreve() + "\n";
       // cout << *(it)->escreve() << endl;
    }

    return res;
}
/*
// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
    unsigned int size = numPalavras(frase);
    list<Crianca>::const_iterator it = criancas.begin();
    while(criancas.size() != 1){
        










    }
    Crianca *c1 = new Crianca(*it);
    return *c1;
}
*/
// a implementar
list<Crianca>& Jogo::inverte()
{
    reverse(criancas.begin(),criancas.end());
    return criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned int id)
{
    list<Crianca> res;
    list<Crianca>::const_iterator it = criancas.begin();
    for(;it!=criancas.end();it++){
        if((it)->idade > id){
            res.push_back(Crianca(it->getNome(),it->idade));
            criancas.erase(it);
        }
    }
    return res;
}

// a implementar
void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    list<Crianca>::const_iterator it = l1.begin();
    for(;it!=l1.end();it++)
        criancas.push_back(*(it));
}

// a implementar
bool Jogo::operator==(Jogo& j2)
{
    if(criancas.size() != j2.getCriancasJogo().size()) return false;
    bool verify = true;
    list<Crianca>::const_iterator it1=criancas.begin(),it2=j2.getCriancasJogo().begin();
    for(;it1!=criancas.begin();it1++,it2++)
        if(!(*it1  == *it2)) return false;

	return true;
}

// a implementar
/*
list<Crianca> Jogo::baralha()
{
    int i;
    bool verify;
    list<Crianca> res;
    list<Crianca>::const_iterator it = criancas.begin(),it2 = res.begin();
    for(;it!=criancas.end();it++){
        verify = true;
        i = rand()%criancas.size();
        while(pre)
        for(it2 = res.begin();it2!=res.end();it2++){
            if((*it).getNome() == (*it2).getNome()){
                verify = false;
                break;
            }
        }
        if(verify){
            advance(it,i);
            res.push_back(*it);
            prev(it,i);
        }
    }
    return res;
}*/
