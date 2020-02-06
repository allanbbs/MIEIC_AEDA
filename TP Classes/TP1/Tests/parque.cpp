#include "parque.h"
#include <vector>
#include <algorithm>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot , unsigned int nMaxCli) : lotacao(lot),numMaximoClientes(nMaxCli) {
    this->vagas = this->lotacao;
}


unsigned int ParqueEstacionamento::getNumLugares() const {
    return this->lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
    return this->numMaximoClientes;
}
int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    for(int i = 0;i<this->clientes.size();i++){
        if(this->clientes[i].nome == nome)
            return i;
    }
    return -1;
}
bool ParqueEstacionamento::adicionaCliente(const string &nome) {
    if(this->clientes.size() == this->numMaximoClientes)
        return false;
    InfoCartao cliente;
    cliente.nome = nome;
    cliente.presente = false;
    this->clientes.push_back(cliente);
    return true;
}
bool ParqueEstacionamento::entrar(const string &nome) {
    if(-1 == this->posicaoCliente(nome))
        return false;
    else if(this->clientes[this->posicaoCliente(nome)].presente)
        return false;
    else if(this->vagas ==0)
        return false;
    this->clientes[this->posicaoCliente(nome)].presente = true;
    this->vagas-=1;
    return true;
}
bool ParqueEstacionamento::retiraCliente(const string &nome) {
    if(this->posicaoCliente(nome) == -1)
        return false;
    else return !this->clientes[this->posicaoCliente(nome)].presente;
}
bool ParqueEstacionamento::sair(const string &nome) {
    if(this->posicaoCliente(nome) == -1)
        return false;
    else if(!this->clientes[this->posicaoCliente(nome)].presente)
        return false;
    this->vagas+=1;
    this->clientes[this->posicaoCliente(nome)].presente = false;
    return true;
}
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    unsigned int t=0;
    for(int i = 0;i<this->clientes.size();i++){
        if(this->clientes[i].presente)
            t++;
    }
    return t;
}
unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return this->clientes.size();
}

