#pragma once
#include "Entidades/Entidade.h"
#include "ElementosGraficos/Animacao.h"

namespace ent {
namespace pers{

enum estado {
    parado,
    andando,
    correndo,
    pulando,
    atacando,
    morrendo,
    ausente,
    sofrendo
};

class Inimigo;

class Personagem : public Entidade {
protected:
    bool vivo;
    int numVidas;

    /* Estado */
    estado est;
    float tempoParado;
    const float duracaoAusente = 1.8f;
    float tempoDano;
    const float duracaoInvulneravel = 1.8f;
    float tempoAtaque;
    const float duracaoAtaque = 0.35f; // Duração Total do Ataque

    /* Gravidade - Constantes */
    const float GRAVIDADE_REAL = 9.8f; // metros por segundo ao quadrado (m/s^2)
    const float ESCALA_GRAVIDADE_PIXEL = 100.f; // pixels por metro (px/m)
    const float GRAVIDADE = GRAVIDADE_REAL * ESCALA_GRAVIDADE_PIXEL; // pixels por segundo ao quadrado (px/s^2)

    /* Movimentação - Atributos */
    bool movendoEsquerda;
    bool movendoDireita;
    bool olhandoDireita;
    bool correndo;
    bool levandoDano;
    bool atacando;

    /* Knockback - Constantes */
    const float knockbackHorizontal = 500.f;
    const float knockbackVertical = 300.f;

    /* Animação */
    ElementosGraficos::Animacao animacao;
    
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    ~Personagem();

    virtual void executar() = 0;

    /* Movimentação */
    virtual void mover();
    void sofrerDano(Personagem* atacante);
    bool getOlhandoDireita() const;
    virtual void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds) = 0;
    
    /* Estado */
    void atualizarEstado();
    void setEstado(estado est);
    estado getEstado() const;

    void setVivo(bool vivo);
    bool getVivo() const;
    void setNumVidas(int numVidas);
    int getNumVidas() const;

    /* Animação */
    void atualizarAnimacao();
    virtual void atualizarElementosAnimacao() = 0;
};
}
}
