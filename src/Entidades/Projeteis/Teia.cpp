#include "Entidades/Projeteis/Teia.h"

namespace ent {
namespace prj {

Teia::Teia()
    : Teia(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false)
{
}

Teia::Teia(sf::Vector2f pos, sf::Vector2f esc, bool aDireita)
    : Projetil(pos, esc, aDireita)
{
    setTextura("Web");
    dano = 1;

    velocidade = sf::Vector2f(700.f, -450.f);

    if (!paraDireita) {
        velocidade.x *= -1;
    }
}

Teia::~Teia()
{
}

void Teia::executar() {
    mover();
}

void Teia::mover() {
    sf::Vector2f ds(0.f, 0.f);
    dt = pGG->getDeltaTime();

    velocidade.y += GRAVIDADE * dt;

    ds += velocidade * dt;

    setPosition(ds + posicao);
}

}
}
