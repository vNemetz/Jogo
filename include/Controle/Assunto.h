#pragma once
#include <list>
#include "Observador.h"

/*Seguindo o Padrão de Projeto "Observer" do livro "Design Patterns"*/
namespace controle{

/*Essa classe faz o papel da classe abstrata "Subject"*/
class Assunto{
protected:
    std::list<controle::Observador*> listaObservadores;
    std::list<controle::Observador*>::iterator it;

public:
    Assunto();
    ~Assunto();

    virtual void incluirObservador(controle::Observador* obs);
    virtual void excluirObservador(controle::Observador* obs);

    void teclaApertada(sf::Keyboard::Key tecla);
    void teclaSoltada(sf::Keyboard::Key tecla);

};
}