#include "Ente.h"
#include "Gerenciadores/Gerenciador_Grafico.h"

Ente::Ente() {
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
}

Ente::Ente(sf::Vector2f pos, sf::Vector2f esc, ID id)
    : id(id)
    , posicao(pos)
    , escala(esc)
    , tamanho()
{
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
}

Ente::~Ente() {
    delete pTextura;  // Libera a memória alocada para pTextura
    delete pSprite;   // Libera a memória alocada para pSprite
    
    pSprite = NULL;
    pTextura = NULL;
    pGG = NULL;
}  

ger::Gerenciador_Grafico* Ente::pGG(NULL); //atributo static

void Ente::setpGG(ger::Gerenciador_Grafico* pGrafico){ //testa e seta o pGG
    if(pGrafico){pGG = pGrafico;}
}

//Gráficos
void Ente::setSprite() {
    pSprite->setTexture(*pTextura, false);
    pSprite->setPosition(posicao);
    
    pSprite->setScale(escala.x, escala.y);

    tamanho.x = pTextura->getSize().x * escala.x;
    tamanho.y = pTextura->getSize().y * escala.y;
}

sf::Sprite Ente::getSprite() const{
    return *pSprite;
}

void Ente::setTextura(const char *caminhoImagem) {
    pTextura = pGG->carregarTextura(caminhoImagem); 

    setSprite();
}


void Ente::desenhar() {
    pGG->desenharEnte(this);
}


void Ente::setPosition(sf::Vector2f pos) {
    if ((pos.y < 0) || (pos.y + tamanho.y > HEIGHT))
        pos.y = getPosition().y;

    pSprite->setPosition(pos);
}

sf::Vector2f Ente::getPosition() const {
    return pSprite->getPosition();
}

sf::Vector2f Ente::getTamanho() const {
    return tamanho;
}

void Ente::setID(ID idPar){
    id = idPar;
}
ID Ente::getID(){
    return id;
}