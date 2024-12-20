#include "Jogo.h"
#include "Ente.h"
#include "Entidades/Entidade.h"
#include "Entidades/Goblin.h"
#include "Entidades/Plataforma.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>
//...

Jogo::Jogo()
: gerGrafico(ger::Gerenciador_Grafico::getInstancia())
, gerEventos(ger::Gerenciador_Eventos::getInstancia())
, gerColisoes(ger::Gerenciador_Colisoes::getInstancia())
, listaEntidades()
{
    srand(time(NULL));

    inicializaEntidades();

    executar();
}

Jogo::~Jogo() {
    listaEntidades.limpar();
    
    jogador = nullptr;
    gerGrafico = nullptr;
    gerEventos = nullptr;
    gerColisoes = nullptr;
}

void Jogo::inicializaEntidades() {
    jogador = new ent::pers::Jogador (sf::Vector2f(WIDTH/2.0, HEIGHT/2.0),sf::Vector2f(1.7f, 1.7f));
    jogador->setpGG(gerGrafico);
    jogador->setTextura("/assets/images/Rogue/rogue.png");
    jogador->setVelocidade(sf::Vector2f(0.125f, 0.125f));

    /* Inclui jogador nos gerenciadores */
    gerEventos->setJogador(jogador);
    gerColisoes->setJogador(jogador);
    ger::Gerenciador_Input::getInstancia()->setJogador(jogador);

    /* Criação do Goblin */
    ent::pers::Goblin* goblin = new ent::pers::Goblin(sf::Vector2f(WIDTH/2.0+600.f, HEIGHT/2.0),sf::Vector2f(1.7f, 1.7f), jogador);
    goblin->setTextura("/assets/images/Goblin/0goblin.png");
    goblin->setVelocidade(sf::Vector2f (0.05f, 0.05f));

    /* Criação da Plataforma */
    ent::obs::Plataforma* obstaculo = new ent::obs::Plataforma(sf::Vector2f(WIDTH/2.0, HEIGHT/2.0+250.f), sf::Vector2f(1.7f, 1.7f), false, 50);
    obstaculo->setTextura("/assets/images/Tiles/Ground_grass_0001_tile.png");

    /* Inclui as entidades no Ger. Colisões e na Lista de Entidades*/
    gerColisoes->incluirInimigo(static_cast<ent::pers::Inimigo*>(goblin));
    gerColisoes->incluirObstaculo(static_cast<ent::obs::Obstaculo*>(obstaculo));

    listaEntidades.incluir(static_cast<ent::Entidade*>(obstaculo));
    listaEntidades.incluir(static_cast<ent::Entidade*>(jogador));
    listaEntidades.incluir(static_cast<ent::Entidade*>(goblin));
}

void Jogo::atualizaEntidades() {
    listaEntidades.percorrer();
}

void Jogo::executar() {
    while (gerGrafico->getJanelaAberta()) {
        gerEventos->gerenciar(); // Gerencia os eventos

        gerColisoes->executar(); // Detecta as colisões

        gerGrafico->limpaJanela(); // Limpa a janela
        
        atualizaEntidades(); // Atualiza e Desenha as Entidades

        gerGrafico->centralizarVista(jogador); // Centraliza o campo de visão no jogador

        gerGrafico->display(); // Exibe a janela
    }
}
