#pragma once
#include "Jogo.h"
class Ente;


/* Gerenciadores - Namespace */
namespace ger{
class Gerenciador_Grafico{
private:

    sf::VideoMode videoMode;    // Guarda altura e largura da tela
    sf::RenderWindow* pJanela;  // Ponteiro para a janela onde tudo será renderizado
    sf::View vista;  // Para modularizar o tamanho da janela
    std::map<const char*, sf::Texture*> mapaTexturas;   // Mapa de texturas
    sf::Clock clock;
    static float deltaTime;

    /* Singleton - Padrão de Projeto */
    static Gerenciador_Grafico* instancia;
    Gerenciador_Grafico();

public:
    ~Gerenciador_Grafico();
    static Gerenciador_Grafico* getInstancia();

    /* Video Mode (Resolução) */
    void setVideoMode();
    
    /* Janela */
    void setJanela();
    sf::RenderWindow* getJanela() const;
    sf::Vector2u getTamanhoJanela() const;
    bool getJanelaAberta() const;
    void limpaJanela();
    void fechaJanela();
    bool pesquisaEventoJanela(sf::Event&);
    
    /* Vista */
    void setVista(float x);
    sf::View getVista() const;
    void setTamanhoVista(sf::Vector2f tam);
    void setCentroVista(sf::Vector2f pos);
    void centralizarVista(Ente* e);
    void redimensionar(float aspect_ratio); // Redimensiona pJanela
    
    /* Clock */
    void updateDeltaTime();
    
    /* Texturas */
    sf::Texture* carregarTextura(const char* caminho);
    
    /* Renderização */
    void desenharEnte(Ente* pE) const;
    void desenhar(sf::RectangleShape* corpo) const;
};
}