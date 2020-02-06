#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(const InfoCartao &a,const InfoCartao &b){
    if(a.frequencia < b.frequencia) return false;
    else if(a.frequencia > b.frequencia) return true;
    if(a.nome < b.nome) return true;
    else if(a.nome > b.nome) return false;
}
bool InfoCartao::operator<(InfoCartao &b) {
    if (frequencia < b.frequencia)
        return false;
    else if (frequencia > b.frequencia)
        return true;

    if (nome < b.nome)
        return true;
    else if (nome > b.nome)
        return false;
}


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }


// a imnplementar
int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    for(int i = 0;i<clientes.size();i++){
        if(clientes[i].nome == nome) return i;
    }
    return -1;
}

//a implementar
int ParqueEstacionamento::getFrequencia(const string &nome) const
{
    for(int i =0;i<clientes.size();i++){
        if(clientes[i].nome == nome) return clientes[i].frequencia;
    }
    throw ClienteNaoExistente(nome);
}

// a alterar/atualizar ?
bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
	clientes.push_back(info);
	numClientes++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	vagas--;
	for(int i = 0;i<clientes.size();i++){
	    if(clientes[i].nome == nome) clientes[i].frequencia+=1;
	}
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

		
// a implementar
void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    sort(clientes.begin(),clientes.end(),Compare);


}


// a implementar
void ParqueEstacionamento::ordenaClientesPorNome()
{
    for(int i = 0;i<clientes.size();i++){
        for(int j = i+1;i<clientes.size();i++){
            if(clientes[i].nome > clientes[j].nome){
                swap(clientes[i],clientes[j]);
            }


        }
    }
}


// a implementar
vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{
    insertionSort(clientes);
    vector<string> nomes;
    for(int i = 0;i<clientes.size();i++){
        if(clientes[i].frequencia >=n1 && clientes[i].frequencia<=n2) nomes.push_back(clientes[i].nome);
    }
    return nomes;
}


// a implementar
ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    for(int i=0;i<pe.clientes.size();i++){
        os<<"Cliente: "<<pe.clientes[i].nome<<" Presente: "<< pe.clientes[i].presente<<" Frequencia: "<<pe.clientes[i].frequencia<<endl;
    }
    return os;
}


// a implmentar
InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    if(p>(clientes.size()-1)) throw PosicaoNaoExistente(p);
    return clientes[p];
}
