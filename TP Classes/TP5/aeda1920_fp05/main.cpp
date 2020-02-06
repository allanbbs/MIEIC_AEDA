#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include "Tests/crianca.h"

using namespace std;


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "AEDA 2019/2020 - Aula Pratica 5" << std::endl;
    Crianca b("Rui",6);
    cout<<b.getIdade()<<endl;

    return RUN_ALL_TESTS();
}