#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

//a alterar
Cliente::Cliente() {
    uint8_t number = rand()%5 + 1;
    numPresentes = number;
}

//a alterar
int Cliente::getNumPresentes() const {
    return numPresentes;
}

//a alterar
Balcao::Balcao(int te): tempo_embrulho(te) {
    prox_chegada = rand()%20 + 1;
    prox_saida = 0;
    tempo_atual = 0;
    clientes_atendidos=0;
}

//a alterar


//a alterar
void Balcao::chegada()
{
    Cliente *novo = new Cliente();
    if(clientes.size() == 0 ){
        prox_saida = tempo_atual + novo->getNumPresentes()*tempo_embrulho;
    }
    clientes.push(*novo);
    prox_chegada =rand()%20 + 1;
    cout<<"tempo: "<<tempo_atual<<"\n"<<"Chegou um cliente com "<<novo->getNumPresentes()<<" presentes"<<endl;
}

//a alterar
void Balcao::saida()
{
    Cliente novo = getProxCliente();
    if(clientes.size() == 0) throw FilaVazia();
    clientes.pop();
    prox_saida = tempo_atual + novo.getNumPresentes()*tempo_embrulho;
    clientes_atendidos++;
}

void Balcao:: proximoEvento() {
    int nextStep = tempo_atual+1;

    if (nextStep == prox_saida) saida();
    if (nextStep == prox_chegada) chegada();
    tempo_atual++;
}


int Balcao::getTempoAtual() const { return tempo_atual; }

int Balcao::getProxChegada() const { return prox_chegada; }

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
    out<<"Numero de clientes atendidos: "<<b1.getClientesAtendidos()<<" Clientes a esperar: "<<b1.clientes.size() - b1.getClientesAtendidos()<<endl;



     return out;
}

//a alterar
int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}

//a alterar
int Balcao::getProxSaida() const {
	return prox_saida;
}

//a alterar
int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}

//a alterar
Cliente & Balcao::getProxCliente() {
    if(clientes.size() == 0) throw FilaVazia();
    Cliente *c = new Cliente();
    *c = clientes.front();
    return *c;
}

      
