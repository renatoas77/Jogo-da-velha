#include <iostream>

class Velha
{
private:
    int Malha[3][3];
    int Posicoes{ 1 };
    int Resposta;
    int JogadorAtual{ 10 }, ProximoJogador{ 0 }, Auxiliar{ 11 };
    char SimboloAtual{ 'X' }, ProximoSimbolo{ 'O' }, SimboloAuxiliar{ 'K' };
    int PontosX{ 0 }, PontosO{ 0 };
    bool Validade, Venceu{ false };

public:
    void ConstruirMalha()
    {
        Posicoes = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Malha[i][j] = Posicoes;
                Posicoes++;
            }
        }

    }

    void ExibirMalha()
    {
        Validade = false;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Malha[i][j] == 10)
                    std::cout << "x ";
                else if (Malha[i][j] == 0)
                    std::cout << "0 ";
                else
                    std::cout << Malha[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void TrocarVez()
    {
        Auxiliar = JogadorAtual;
        JogadorAtual = ProximoJogador;
        ProximoJogador = Auxiliar;
        SimboloAuxiliar = SimboloAtual;
        SimboloAtual = ProximoSimbolo;
        ProximoSimbolo = SimboloAuxiliar;
    }

    void Jogar()
    {
        do
        {
            std::cout << "\nJogador " << SimboloAtual << "\n";
            std::cout << "Digita onde deseja jogar: ";
            std::cin >> Resposta;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (Resposta > 0 && Resposta < 10)
                    {
                        if (Resposta == Malha[i][j])
                        {
                            Malha[i][j] = JogadorAtual;
                            Validade = true;
                        }
                    }
                }
            }
            if (Validade == false)
            {

                std::cout << "Jogada invalida! \n";
                Velha::ExibirMalha();
            }
        } while (Validade == false);
        system("CLS");
    }

    bool Vencedor()
    {
        Venceu = false;
        for (int i = 0; i < 3; i++)
        {
            if (Malha[i][0] == Malha[i][1] && Malha[i][1] == Malha[i][2])
            {
                Venceu = true;
            }
            else if (Malha[0][i] == Malha[1][i] && Malha[1][i] == Malha[2][i])
            {
                Venceu = true;
            }
        }

        if (Malha[0][2] == Malha[1][1] && Malha[1][1] == Malha[2][0])
        {
            Venceu = true;
        }
        else if (Malha[0][0] == Malha[1][1] && Malha[1][1] == Malha[2][2])
        {
            Venceu = true;
        }
        return Venceu;
    }

    void Resultado()
    {
        if (Venceu == false)
        {
            std::cout << "Deu velha \n";
            std::cout << "Placar Atual\n";
            std::cout << "X: " << PontosX << "\n";
            std::cout << "O: " << PontosO << "\n";
            std::cout << "Deseja jogar novamente?\n";
        }
        else
        {
            std::cout << ProximoSimbolo << " venceu!!\n";
            if (ProximoSimbolo == 'X')
            {
                PontosX++;
            }
            else
            {
                PontosO++;
            }
            std::cout << "Placar Atual\n";
            std::cout << "X: " << PontosX << "\n";
            std::cout << "O: " << PontosO << "\n";
            std::cout << "Deseja jogar novamente?\n";
        }
    }
};



int main()
{
    int contador{ 0 };
    bool Vitoria{ false };
    Velha JogoDaVelha;
    char Jogar{ 'S' };


    do
    {
        JogoDaVelha.ConstruirMalha();
        contador = 0;
        do
        {
            JogoDaVelha.ExibirMalha();
            JogoDaVelha.Jogar();
            JogoDaVelha.TrocarVez();
            Vitoria = JogoDaVelha.Vencedor();
            contador++;
        }         while (Vitoria == false && contador < 9);
        JogoDaVelha.Resultado();
        std::cin >> Jogar;
        system("CLS");
    }     while (Jogar == 'S' || Jogar == 's');

    system("PAUSE");
    return 0;
}
