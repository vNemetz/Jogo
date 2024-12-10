#pragma once
#include "Jogo.h"

#define HEIGHT 600
#define WIDTH 810

#include "Gerenciador_Grafico.h"


enum ID{
    vazio = 0,
    jogador,
    plataforma,
    inimigo,
    projetil,
    menu,
    fase
};

class Ente{
protected:
    //Identificação única do Ente
    ID id;
    sf::Vector2f tamanho;
    sf::Vector2f posicao;

    //Gráficos
    static ger::Gerenciador_Grafico* pGG;
    sf::Texture* pTextura;
    sf::Sprite* pSprite;

    //Desenhar
    sf::RenderTarget* pTarget; //Alvo da renderização (janela)
    //...

public:
    //Construtora e Destrutora
    Ente();
    Ente(sf::Vector2f posicao, sf::Vector2f tamanho, ID id = vazio);
    virtual ~Ente();

    virtual void executar() = 0;

    ID getID();
    void setID(ID idPar);

    //virtual void executar() = 0;

    //Gerenciador gráfico
    void setpGG(ger::Gerenciador_Grafico* pGrafico);
    
    //Gráficos
    void setTextura();
    void desenhar();
    void setSprite();
    void setTarget();
    sf::Sprite getSprite() const;

sf::Vector2f getPosition() const;

    void setPosition(sf::Vector2f pos);
};
