#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "parque.h"
#include <string>


using testing::Eq;


TEST(test_1, a_AbrirParque){
    ParqueEstacionamento p1(4, 6);
    ASSERT_EQ(4, p1.getNumLugares());
    ASSERT_EQ(6, p1.getNumMaximoClientes());
}

TEST(test_1, b_AdicionarCliente){
    ParqueEstacionamento p1(3, 5);
    ASSERT_EQ(true, p1.adicionaCliente("Joao"));
    p1.adicionaCliente("Antonio");
    p1.adicionaCliente("Rui");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Clara");
    ASSERT_EQ(false, p1.adicionaCliente("Paula"));
    ASSERT_EQ(1, p1.posicaoCliente("Antonio"));
    ASSERT_EQ(-1, p1.posicaoCliente("Joana"));
}

TEST(test_1, c_EntrarParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.adicionaCliente("Rui");
    ASSERT_EQ(true, p1.entrar("Maria"));
    ASSERT_EQ(false, p1.entrar("Paula"));
    ASSERT_EQ(false, p1.entrar("Maria"));
    p1.entrar("Joao");
    p1.entrar("Antonio");
    ASSERT_EQ(false, p1.entrar("Rui"));
}

TEST(test_1, d_RetirarCliente){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.entrar("Maria");
    ASSERT_EQ(false, p1.retiraCliente("Maria"));
    ASSERT_EQ(true, p1.retiraCliente("Antonio"));
    ASSERT_EQ(false, p1.retiraCliente("Ana"));
}

TEST(test_1, e_SairParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Rui");
    p1.entrar("Maria");
    p1.entrar("Joao");
    p1.entrar("Rui");
    ASSERT_EQ(true, p1.sair("Maria"));
    ASSERT_EQ(false, p1.sair("Maria"));
    ASSERT_EQ(false, p1.sair("Antonio"));
}

TEST(test_1, f_LugaresLotacaoParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.entrar("Maria");
    p1.entrar("Antonio");
    ASSERT_EQ(3, p1.getNumLugares());
    ASSERT_EQ(2, p1.getNumLugaresOcupados());
    ASSERT_EQ(3, p1.getNumClientesAtuais());
}