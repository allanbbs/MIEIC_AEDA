
#include "veterinario.h"
#include <sstream>
using namespace std;




Veterinario::Veterinario(string no, long code) {
	nome = no;
	codOrdem = code;

}
string Veterinario::getNome() const {
	return nome;
}



