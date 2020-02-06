#include "veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a) {
    marca = mc;
    ano = a;
    mes = m;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) : Veiculo(mc,m,a){
    combustivel = c;
    cilindrada = cil;
}
Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc,m,a,c,cil) {}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado(mc,m,a,c,cil)  {
    carga_maxima = cm;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo(mc,m,a) {
    tipo = t;
}
string Motorizado::getCombustivel() const {
    return combustivel;
}
string Veiculo::getMarca() const {
    return marca;
}

int Veiculo::getAno() const {
    return ano;
}
int Veiculo::info() const {
    cout << " Marca: " << marca << endl;
    cout << " Mes/Ano: " << mes << " / " << ano << endl;
    return 3;
}

int Motorizado::info() const {
    Veiculo::info();
    cout << "Combustivel: " << combustivel << endl;
    cout << "Cilindradas: " << cilindrada << endl;
    return 5;
}

int Automovel::info() const {
    Motorizado::info();
    return 5;
}

int Camiao::info() const {
    Motorizado::info();
    cout << "Carga maxima: " << carga_maxima << endl;
    return 6;
}

int Bicicleta::info() const {
    Veiculo::info();
    cout << "Tipo: " << tipo << endl;
    return 4;
}

bool Veiculo::operator<(const Veiculo &v) const {
    if( ano < v.ano ) return true;
    if ( v.ano < ano ) return false;
    else return mes < v.mes;
}

float Motorizado::calcImposto() const {
    float result = 0.0;
    if( combustivel == "gasolina"){
        if( cilindrada <= 1000){
            if( ano > 1995) result+=14.56;
            else result+=8.10;
        }
        if (cilindrada > 1000) {
            if (cilindrada <= 1300) {
                if (ano > 1995) result += 29.06;
                else result += 14.56;
            }
        }
        if (cilindrada > 1300) {
            if (cilindrada <= 1750) {
                if (ano > 1995) result += 45.15;
                else result += 22.65;
            }
        }
        if (cilindrada > 1750) {
            if (cilindrada <= 2600) {
                if (ano > 1995) result += 113.98;
                else result += 54.89;
            }
        }
        if (cilindrada > 2600) {
            if (cilindrada <= 3500) {
                if (ano > 1995) result += 181.17;
                else result += 87.13;
            }
        }
        if( cilindrada > 3500){
            if( ano > 1995) result+= 320.89;
            else result+=148.37;
        }
    }
    else{
        if( cilindrada <= 1500){
            if( ano > 1995) result+=14.56;
            else result+=8.10;
        }
        if (cilindrada > 1500) {
            if (cilindrada <= 2000) {
                if (ano > 1995) result += 29.06;
                else result += 14.56;
            }
        }
        if (cilindrada > 2000) {
            if (cilindrada <= 3000) {
                if (ano > 1995) result += 45.15;
                else result += 22.65;
            }
        }
        if( cilindrada >3000){
            if( ano > 1995) result+= 113.98;
            else result+=54.89;
        }
    }
    return result;
}





















































