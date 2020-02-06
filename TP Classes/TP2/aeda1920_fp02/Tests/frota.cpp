#include "frota.h"
#include <string>
#include <vector>
using namespace std;


ostream & operator << (ostream &o, const Frota &f) {
    for(Veiculo* x : f.veiculos){
        x->info();
    }
    return o;
}
void Frota::adicionaVeiculo(Veiculo *v1) {
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    return veiculos.size();
}

int Frota::menorAno() const {
    if(veiculos.empty()) return 0;
    int earlier,actual;
    earlier = 100000;
    vector<Veiculo*>::const_iterator it = veiculos.begin();
    while(it!=veiculos.end()){
        actual = (*it)->getAno();
        if( (actual < earlier)) earlier = actual;
        it++;
    }
    return earlier;
}

vector<Veiculo *> Frota::operator()(int anoM) const {
    vector<Veiculo*>::const_iterator it = veiculos.begin();
    vector<Veiculo*> result;
    while(it != veiculos.end()){
        if( (*it)->getAno() == anoM ) result.push_back(*it);
        it++;
    }
    return result;
}

float Frota::totalImposto() const {
    float result = 0;
    for(Veiculo*x : veiculos) result+=x->calcImposto();
    return result;
}
