#pragma once
#include <vector>
#include "ElementosGraficos/Botao.h"
#include "Estados/Estado.h"
#include <iostream>

namespace menus{
class Menu : public Estado{
protected:
    std::vector<ElementosGraficos::Botao*> vetorBotoes;
    std::vector<ElementosGraficos::Botao*>::iterator it;
    int botaoSelecionado;
    int minimo;
    int maximo;
    bool ativo;
    sf::Texture* pTexturaFundo;
    sf::Sprite* pSpriteFundo;

public:
    Menu(int min, int max, tipoEstado tipo);
    Menu(ger::Gerenciador_Estados* pGE, int min, int max, tipoEstado tipo);
    ~Menu();
    void alterarBotaoSelecionado(int unidade);
    void setTexturaFundo(std::string nomeImg);
    void setSpriteFundo();
    void limparVetorBotoes();
    void adicionarBotao(std::string nomeImg, sf::Vector2f escala, std::string text, sf::Vector2f pos);    
    void desenharBotoes();

    virtual void desenhar();

    virtual void executarEstado() = 0;
    virtual void executar();
};
}