#pragma once

#include "ListaEntidades.h"
#include "Personagens.h"

class GerenciadorColisoes
{

private:
	ListaEntidades* lista_obstaculos;
	ListaEntidades* lista_personagens;

	int qJogadores;

public:
	GerenciadorColisoes(ListaEntidades* l_personagem, ListaEntidades* l_obstaculos, int qJogadores);
	~GerenciadorColisoes();

	sf::Vector2f calculaColisoes(Entidade* ent1, Entidade* ent2);
	void verificaColisoes();

	void colisaoPersonagens();
	void colisaoPersonagemObstaculos();
	void colisaoObstaculos();

	void setListas(ListaEntidades* l_personagem, ListaEntidades* l_obstaculos);

	void Executar();


};

//Referencias
/*
C�digo com base no video do monitor Giovane: youtube.com/watch?v=B5zPLK9nuGw&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=7
*/

//GERENCIADOR DE COLOSIOES (Explica��o)
/*

	FUNCIONAMENTO
	O gerenciador de colis�es tem como objetivo Verificar a colis�o entre duas entidades no Jogo.
	Seu funcionamento consiste na seguinte formula:

	colisao x = |distancia entre os centros| - (soma das metades do tamanho)
	colisao y = |(distancia entre os centros)| - (soma das metades do tamanho)

	Se a soma das metades dos tamanhos � menor que a dist�ncia entre os centros, os elementos estao em colisao no eixo analisado!
	Ou seja, se essa diferen�a for negativa, h� colis�o

	O objeto s� esta em colis�o de fato quando os dois eixos se encontram
	Ou seja, colisao x < 0 e colisao y < 0 -> COLISAO!!!!!

*/
