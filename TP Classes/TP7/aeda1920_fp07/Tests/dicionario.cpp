#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

//a alterar
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
     return palavra<ps1.getPalavra();
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich)
{
    string name,meaning;
    while(!fich.eof()){
        getline(fich,name);
        getline(fich,meaning);
        palavras.insert(PalavraSignificado(name,meaning));
    }
     return;
}

//a alterar
string Dicionario::consulta(string palavra) const
{
    string auxnome = palavras.find(PalavraSignificado(palavra,"")).getPalavra();
    string auxmean = palavras.find(PalavraSignificado(palavra,"")).getSignificado();
    if(auxnome!= "" && auxmean != ""){
        return auxmean;
    }
    throw PalavraNaoExiste();
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    if(palavras.find(PalavraSignificado(palavra,"")).getPalavra() != "" && palavras.find(PalavraSignificado(palavra,"")).getSignificado()!=""){
        palavras.remove(PalavraSignificado(palavra,""));
        palavras.insert(PalavraSignificado(palavra,significado));
        return true;
    }
    else{
        palavras.insert(PalavraSignificado(palavra,significado));
        return false;
    }


}

//a alterar
void Dicionario::imprime() const
{

    iteratorBST<PalavraSignificado> it = palavras.begin();
    for(;it!=palavras.end();it++){
        cout<<(*it).getPalavra()<<endl;
        cout<<(*it).getSignificado()<<endl;
    }
    return;
}

