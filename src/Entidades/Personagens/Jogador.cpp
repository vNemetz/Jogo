#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cmath>
#include <stdexcept>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), true)
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, bool jog)
    : Personagem(pos, tam, jogador)
    , pulando(false)
    , jogador1(jog)
{
    pontos = 0;
    setNumVidas(15);
    setTextura("Rogue-Stand");
    setVelocidadeMaxima(sf::Vector2f(600.f, 600.f));
    carregarControles();
}

Jogador::~Jogador()
{
}

void Jogador::executar() {
    atualizarPosicao();

    atualizarEstado();
    
    atualizarAnimacao();
}

void Jogador::desenhar() {
    try {
        if (pSprite)
            pGG->desenharEntidade(this);

        else
            throw std::runtime_error("Sprite do Jogador vazio!");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "ERRO: " << e.what() << std::endl;
        exit(1);
    }
}

/* Movimentação */

void Jogador::atualizarMovimentacao(bool estado, std::string key) {
    if (key == botaoEsquerda) {
        movendoEsquerda = estado;
    }

    else if (key == botaoDireita) {
        movendoDireita = estado;
    }

    else if (key == botaoPular) {
        pulando = estado;
    }

    else if (key == botaoCorrer) {
        correndo = estado;
    }

    else if (key == botaoAtacar) {
        if (estado)
            atacando = estado;
    }
}

void Jogador::atualizarPosicao() {
    if (pulando && noChao && !levandoDano)
        pular();
    
    if (vivo)
        mover();
}

void Jogador::pular() {
    velocidade.y = -600.f;
    noChao = false;
}

void Jogador::carregarControles() {
    if (jogador1) {
        botaoEsquerda = "A";
        botaoDireita = "D";
        botaoPular = "W";
        botaoCorrer = "LShift";
        botaoAtacar = "Space";
    }

    else {
        botaoEsquerda = "Left";
        botaoDireita = "Right";
        botaoPular = "Up";
        botaoCorrer = "K";
        botaoAtacar = "L";
    }
}

void Jogador::incrementarPontos(int pontos) {
    this->pontos += pontos;
}

/* Animação */

void Jogador::atualizarElementosAnimacao() {
    std::string sufixo = (jogador1) ? "" : "2";

    switch (est) {
        case estado::pulando:
            setTextura("Rogue-Jump" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(7,1), 0.2f, ElementosGraficos::pulando);
            break;
        
        case andando:
            setTextura("Rogue-Walk" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6,1), 0.16f, ElementosGraficos::andando);
            break;
        
        case parado:
            setTextura("Rogue-Stand" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(1, 1), 0.001f, ElementosGraficos::parado);
            break;

        case ausente:
            setTextura("Rogue-Idle" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(17,1), 0.16f, ElementosGraficos::estatico);
            break;

        case sofrendo:
            setTextura("Rogue-Hurt" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(4, 1), 0.15f, ElementosGraficos::sofrendo);
            break;

        case estado::correndo:
            setTextura("Rogue-Run" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(8, 1), 0.1f, ElementosGraficos::correndo);
            break;

        case estado::atacando:
            setTextura("Rogue-Attack" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(7, 1), duracaoAtaque / 7.f, ElementosGraficos::atacando);
            break;

        case estado::morrendo:
            setTextura("Rogue-Death" + sufixo);
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(10, 1), duracaoMorrendo / 10.f, ElementosGraficos::morrendo);
            break;
        
        default:
            break;
    }

    setCorpo();
}

void Jogador::setCorpo() {
    if (pSprite) {
        /* Do corpo inteiro, frame pega apenas a parte em que há textura de fato */
        sf::IntRect frame = animacao.getCorpo();

        if (est == estado::morrendo) {
            frame.top = 90;
            frame.height = 66;

            if (frame.width > 0) {
                frame.left += 60;
                frame.width = 113;
            }

            else {
                frame.left -= 83;
                frame.width = -113;
            }
        }

        else {
            frame.top += 52;
            frame.height -= 52;
            
            if (frame.width > 0) {
                frame.left += 15;
                frame.width = 56;
            }

            else {
                frame.left -= 56;
                frame.width = -56;
            }

            if (est == estado::atacando) {
                if (frame.width > 0) {
                    frame.width += 10;
                }
                else {
                    frame.left += 10;
                }
            }
        }

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);
        
        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}


/*Getters e Setters para SAVE*/

int pers::Jogador::getPontos() const
{
    return pontos;
}


void Jogador::setPontos(int pts)
{
    pontos = pts;
}

bool Jogador::getEhJogador1() const
{
    return jogador1;
}

void Jogador::setEhJogador1(bool j1)
{
    jogador1 = j1;
}

bool Jogador::getPulando() const
{
    return pulando;
}

void Jogador::setPulando(bool pulo)
{
    pulando = pulo;
}


}
}