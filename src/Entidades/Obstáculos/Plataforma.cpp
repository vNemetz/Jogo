#include "Entidades/Obstáculos/Plataforma.h"
#include <cmath>


namespace ent {
namespace obs {

Plataforma::Plataforma()
    : Obstaculo()
    , altura(0)
{
}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt)
    : Obstaculo(pos, tam, dan, plataforma)
    , altura(alt)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() {
}

tipoPlataforma Plataforma::getTipoPlataforma() const
{
    return (tipo);
}

void Plataforma::setTipoPlataforma(tipoPlataforma tip) 
{
    tipo = tip;
}
}
}

