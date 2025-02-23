#include "Jogador.h"

int Jogador::pontuacao_j1 = 0;
int Jogador::pontuacao_j2 = 0;

Jogador::Jogador(int jogador):Personagens(), tempo(), tipoJogador(jogador)
{
    id = ID::jogador;
    iniciar();
}

void Jogador::iniciar()
{
    //Forma Jogador
    corpo.setSize(Vector2f(JOGADOR_X, JOGADOR_Y));
    this->setTexturaJogador();
    
    //Atributos Jogador
    setVelocidade(Vector2f(VELOCIDADE_JOGADOR_X, 0.f));
    setQuantidadeVida(20.0);
    setDano(5.0);
}

Jogador::~Jogador(){}

void Jogador::setTexturaJogador()
{
    if (tipoJogador == 1)
    {
        Entidade::setTextura("assets/wizard1.png");
    }
    else if (tipoJogador == 2)
    {
        Entidade::setTextura("assets/wizard2.png");
    }
}

void Jogador::Mover()
{
    movGravidade();

    if (andando)
    {
        if(olhandoDireita)
            movimentaEntidade(Vector2f(speed.x, 0.f), true);

        else if(olhandoEsquerda)
            movimentaEntidade(Vector2f(-speed.x, 0.f), false);
    }
}

void Jogador::Executar()
{
    verificaVida();
    //cout << " Pontos Jogador1: " << pontuacao_j1 << endl;
    //cout << " Pontos Jogador2: " << pontuacao_j2 << endl;
    cout << q_vida << endl;
    Mover();

}

/* OS GERENCIADORES QUE CHAMAM ESSAS FUN��ES */

//GERENCIADOR DE EVENTOS
void Jogador::andar(int i)
{
    andando = true;

    if (i == 2)
    {
        movimentaEntidade(Vector2f(-speed.x, 0.f), false);
    }
    else if (i == 4)
    {
        movimentaEntidade(Vector2f(speed.x, 0.f), true);
    }
}

void Jogador::atacar(Entidade* adversario, float dano)
{
    Personagens* adv = static_cast<Personagens*>(adversario);
    adv->perdeVida(dano);

    if (adv->getQuantidadeVida() <= 0.f) {

        if (tipoJogador == 1)
            ++pontuacao_j1;

        else if (tipoJogador == 2)
            ++pontuacao_j2;
    }
        
}

//PONTOS

void Jogador::setPontos(int pontos_j1, int pontos_j2)
{
    pontuacao_j1 = pontos_j1;
    pontuacao_j2 = pontos_j2;
}

const int Jogador::getPontos(int tipoJogador)
{
    if (tipoJogador == 1)
        return pontuacao_j1;

    else if (tipoJogador == 2)
        return pontuacao_j2;
    else
        cout << "NAO TEM PONTOS" << endl;
}

//GERENCIADOR DE COLIS�ES
void Jogador::reagirColisao(Entidade* entidade, Vector2f inter_colisao)
{
    corrigeColisoes(entidade, inter_colisao);

}



