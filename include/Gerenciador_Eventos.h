#pragma once
#include "Jogo.h"
#include "Jogador.h"
namespace ger {
class Gerenciador_Eventos {
private:
    // TODO: Gerenciador_Colisoes* gerColisoes;
    Gerenciador_Grafico* gerGrafico;
    pers::Jogador* jogador; 

public:
    Gerenciador_Eventos(Gerenciador_Grafico* gG, pers::Jogador* jogador);
    ~Gerenciador_Eventos();

    void gerenciar();
};
}