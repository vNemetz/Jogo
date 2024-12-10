#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Personagem.h"
#include "Jogador.h"
#include <sstream>
//...

Jogo::Jogo() 
: gerGrafico(ger::Gerenciador_Grafico::getInstancia()){
    srand(time(NULL));
    jogador = new pers::Jogador (sf::Vector2f(HEIGHT/2.0, WIDTH/2.0),sf::Vector2f(20.f, 20.f), vazio);
    gerEventos = new ger::Gerenciador_Eventos(gerGrafico, jogador);
   // e = new Ente(gerGrafico);

    executar();
}

Jogo::~Jogo(){
   // delete e;
    delete jogador;
    delete gerGrafico;
    delete gerEventos;
    //e = NULL;
    gerGrafico = NULL;
    gerEventos = NULL;
    jogador = NULL;
}

void Jogo::moveEntes(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            jogador->mover(sf::Keyboard::A);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            jogador->mover(sf::Keyboard::D);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            jogador->mover(sf::Keyboard::W);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            jogador->mover(sf::Keyboard::S);
        }
}

void Jogo::executar(){
    if(gerGrafico){
        jogador->setpGG(gerGrafico);
        jogador->setTarget();

        /*
        DEBUG:
        sf::Font font;
        std::string str = PROJECT_ROOT;
        str += "/assets/fonts/Arial.ttf";
        font.loadFromFile(str);
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(0.f, 0.f);
        */

        // Loop principal do jogo
        while (gerGrafico->getJanelaAberta()) {
            // Gerencia os eventos
            //gerGrafico->setVista(jogador->getPosition().x);
            gerEventos->gerenciar();

            // Limpar a janela
            gerGrafico->limpaJanela();
            moveEntes();
            
            // Centraliza o campo de visão no jogador
            //gerGrafico->centralizarVista(static_cast<Ente*>(jogador));
            
            // Desenhar o jogador (ente)
            gerGrafico->desenharEnte(static_cast<Ente*>(jogador));

            /*
            DEBUG:
            std::ostringstream oss;
            oss << "J: (" << (int) jogador->getPosition().x << ", " << (int) jogador->getPosition().y << ")";
            text.setString(oss.str());
            gerGrafico->getJanela()->draw(text);
            */

            // Exibir a janela
            gerGrafico->getJanela()->display();
        }
    }
}