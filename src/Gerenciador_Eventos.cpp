#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"

ger::Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico* gG, pers::Jogador* jog)
    : gerGrafico(gG), jogador(jog)
{
}

ger::Gerenciador_Eventos::~Gerenciador_Eventos() {
    gerGrafico = nullptr;
    jogador = nullptr;
}

void ger::Gerenciador_Eventos::gerenciar() {
    sf::Event evento;
    while (gerGrafico->pesquisaEventoJanela(evento)) {
        // Fechar a Janela
        if (evento.type == sf::Event::Closed) {
            gerGrafico->fechaJanela();
        }

        // Redimensionar a Janela
        if (evento.type == sf::Event::Resized) {
            if (gerGrafico) {
                float aspect_ratio = static_cast<float>(evento.size.width) / evento.size.height;
                gerGrafico->redimensionar(aspect_ratio);
            }
        }
    }
}
