#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   explicit NoRepetido(N inf) { info=inf; }
};
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	explicit NoInexistente(N inf) {
		info = inf;
	}
};

template<class N>
class ArestaRepetida{
public:
    N info,info2;

    explicit ArestaRepetida(N inf,N inf2){ info = inf;info2 = inf2;}

};

template<class N>
class ArestaInexistente{
public:
    N info,info2;

    explicit ArestaInexistente(N inf,N inf2): info(inf),info2(inf2){}

};



template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

template<class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &ar)
{ out << "Aresta repetida: " << ar.info << " , " << ar.info2; return out; }

template<class N>
std::ostream & operator<<(std::ostream & out, const ArestaInexistente<N> & ai){
    out << "Aresta inexistente: " << ai.info << " , " << ai.info2;
    return out;
}
template<class N,class A>
std::ostream & operator<<(std::ostream&out,const Grafo<N,A> &f){
    f.imprimir(out);
    return out;
}
/*template<class N,class A>
bool operator==(const No<N,A>& a,const No<N,A>&b){
    return a == b;
}*/


//GRAFO---------------------------------------------------------------
template<class N,class A>
Grafo<N,A>::Grafo() {}
template<class N,class A>
Grafo<N,A>::~Grafo() {}
template <class N,class A>
Grafo<N,A> &Grafo<N,A>::inserirNo(const N &dados) {
    for(No<N,A>*no : nos){
        if(no->info == dados){
            throw NoRepetido<N>(dados);
        }
    }
    nos.push_back(new No<N,A>(dados));
    return *this;
}

template<class N,class A>
Grafo<N,A> &Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val) {
    bool existingInitialNode = false;
    bool existingFinalNode = false;
    int i,j,k,posEnd,posBegin;
    for(i = 0;i<nos.size();i++){
        if(nos[i]->info == inicio){
            existingInitialNode = true;
            posBegin = i;
        }
        if(nos[i]->info == fim){
            existingFinalNode = true;
            posEnd = i;
        }
    }
    if(!existingInitialNode) throw NoInexistente<N>(inicio);
    if(!existingFinalNode) throw NoInexistente<N>(fim);

    for(auto a: nos[posBegin]->arestas){
        if(a.destino->info == fim) throw ArestaRepetida<N>(inicio,fim);
    }
    nos[posBegin]->arestas.push_back(Aresta<N,A>(nos[posEnd],val));
    return *this;
}

template<class N,class A>
Grafo<N,A>&Grafo<N,A>::eliminarAresta(const N &inicio, const N &fim) {
    int endPos = -1;
    for(int i = 0;i<nos.size();i++){
        if(nos[i]->info == inicio){
            endPos = i;
            break;
        }
    }
    if(endPos == -1) throw NoInexistente<N>(inicio);
    for(auto it = nos[endPos]->arestas.begin();it!=nos[endPos]->arestas.end();it++){
        if(it->destino->info == fim) {
            nos[endPos]->arestas.erase(it);
            return *this;
        }
    }
    throw ArestaInexistente<N>(inicio,fim);
}

template <class N,class A>
int Grafo<N,A>::numNos() const {
    return nos.size();
}

template<class N,class A>
int Grafo<N,A>::numArestas() const {
    int result = 0;
    for(int i =0;i<nos.size();i++){
        result+=nos[i]->arestas.size();
    }
    return result;
}

template<class N,class A>
A& Grafo<N,A>::valorAresta(const N &inicio, const N &fim) {
    int posBegin = -1;
    for(int i = 0; i < nos.size();i++){
        if(nos[i]->info == inicio){
            posBegin = i;
            break;
        }
    }
    if(posBegin == -1) throw NoInexistente<N>(inicio);
    for(auto it = nos[posBegin]->arestas.begin();it!=nos[posBegin]->arestas.end();it++){
        if(it->destino->info == fim) return it->valor;

    }
    throw ArestaInexistente<N>(inicio,fim);
}
template<class N, class A>
void Grafo<N,A>::imprimir(std::ostream &os) const {
    for (auto it = nos.begin(); it< nos.end(); it++){
        os << "( " << (*it)->info;
        for (auto it2 = (*it)->arestas.begin(); it2 < (*it)->arestas.end(); it2++){
            os << "[ " << it2->destino->info << " " << it2->valor << "] ";
        }
        os << ") ";
    }
}












//---------------------------------------------------------------------























