#include "maquinaEmpacotar.h"
#include <sstream>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


// a alterar
unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
    unsigned result = 0;
	for(auto it= objs.begin();it!=objs.end();it++){
        if(it->getPeso() <= capacidadeCaixas){
            objetos.push(*it);
            objs.erase(it);
            it--;
            result++;
        }
	}
	return result;
}

// a alterar
Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	Caixa cx;
    stack<Caixa> aux;
    bool exists = false;
    while(!caixas.empty()){
        if(caixas.top().getCargaLivre()>=obj.getPeso()){
            cx = caixas.top();
            caixas.pop();
            exists = true;
            break;
        }else{
            aux.push(caixas.top());
            caixas.pop();
        }
    }
    while(!aux.empty()){
        caixas.push(aux.top());
        aux.pop();
    }
    //cx.addObjeto(obj);
    return cx;
}

// a alterar
unsigned MaquinaEmpacotar::empacotaObjetos() {
	while(!objetos.empty()){
	    Objeto actual(objetos.top().getID(),objetos.top().getPeso());
	    Caixa aux = procuraCaixa(actual);
	    aux.addObjeto(actual);
	    caixas.push(aux);
	    objetos.pop();
	}
	return caixas.size();
}

// a alterar
string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
    stringstream result;
    if(objetos.empty()) return "Nao ha objetos!\n";
    HEAP_OBJS aux = objetos;
    while(!aux.empty()){
        result<<aux.top()<<endl;
        aux.pop();
    }
	return result.str();
}

// a alterar
Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
    if(caixas.empty()) throw MaquinaSemCaixas();
	HEAP_CAIXAS temp = caixas;
	Caixa actual = temp.top();
	temp.pop();
	while(!temp.empty()){
	    if(temp.top().getSize() > actual.getSize()){
	        actual = temp.top();
	    }
	    temp.pop();
	}
	return actual;
}



