#pragma once
#include "Personagem.h"


namespace pers{
class Jogador : public pers::Personagem{
private:
    int pontos;
    bool vivo;
protected:
//...
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    ~Jogador();
    void executar();

    void alteraVivo(); //altera o valor de "vivo"
    bool getVivo();
    void mover(sf::Keyboard::Key key);
};
}