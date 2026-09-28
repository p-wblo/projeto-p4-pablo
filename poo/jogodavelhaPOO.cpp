#include <iostream>
#include <cstdlib>
using namespace std;

class Tabuleiro {
private:
    char casas[9];

    static const int linhas[8][3];

public:
    Tabuleiro() {
        for (int i = 0; i < 9; i++)
            casas[i] = ' ';
    }

    bool casaLivre(int pos) const {
        return casas[pos] == ' ';
    }

    bool marcar(int pos, char simbolo) {
        if (pos < 0 || pos > 8 || !casaLivre(pos))
            return false;
        casas[pos] = simbolo;
        return true;
    }

    bool venceu(char simbolo) const {
        for (int i = 0; i < 8; i++) {
            if (casas[linhas[i][0]] == simbolo &&
                casas[linhas[i][1]] == simbolo &&
                casas[linhas[i][2]] == simbolo)
                return true;
        }
        return false;
    }

    bool cheio() const {
        for (int i = 0; i < 9; i++) {
            if (casas[i] == ' ')
                return false;
        }
        return true;
    }

    bool acabou() const {
        return venceu('X') || venceu('O') || cheio();
    }

    void mostrar() const {
        cout << endl;
        for (int i = 0; i < 9; i++) {
            if (casas[i] == ' ')
                cout << " " << i + 1 << " ";
            else
                cout << " " << casas[i] << " ";

            if (i == 2 || i == 5)
                cout << endl << "---+---+---" << endl;
            else if (i != 8)
                cout << "|";
        }
        cout << endl << endl;
    }
};

const int Tabuleiro::linhas[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

class Jogador {
protected:
    char simbolo;

public:
    Jogador(char s) {
        simbolo = s;
    }

    virtual ~Jogador() {}

    char getSimbolo() const {
        return simbolo;
    }

    virtual int escolherJogada(const Tabuleiro& tab) = 0;
};

class JogadorHumano : public Jogador {
public:
    JogadorHumano(char s) : Jogador(s) {}

    int escolherJogada(const Tabuleiro& tab) override {
        int num;
        while (true) {
            cout << "Sua vez (" << simbolo << "), escolha uma casa de 1 a 9: ";
            if (!(cin >> num)) {
                if (cin.eof())
                    exit(0);
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Digite um numero!" << endl;
                continue;
            }
            if (num < 1 || num > 9) {
                cout << "Essa casa nao existe!" << endl;
                continue;
            }
            if (!tab.casaLivre(num - 1)) {
                cout << "Essa casa ja esta ocupada!" << endl;
                continue;
            }
            return num - 1;
        }
    }
};

class JogadorComputador : public Jogador {
private:
    char adversario() const {
        if (simbolo == 'X')
            return 'O';
        return 'X';
    }

    int minimax(Tabuleiro tab, char vez, int prof) const {
        if (tab.venceu(simbolo))
            return 10 - prof;
        if (tab.venceu(adversario()))
            return prof - 10;
        if (tab.cheio())
            return 0;

        char proximo = (vez == 'X') ? 'O' : 'X';
        int melhor;
        if (vez == simbolo)
            melhor = -100;
        else
            melhor = 100;

        for (int i = 0; i < 9; i++) {
            if (tab.casaLivre(i)) {
                Tabuleiro copia = tab;
                copia.marcar(i, vez);
                int valor = minimax(copia, proximo, prof + 1);

                if (vez == simbolo && valor > melhor)
                    melhor = valor;
                if (vez != simbolo && valor < melhor)
                    melhor = valor;
            }
        }
        return melhor;
    }

public:
    JogadorComputador(char s) : Jogador(s) {}

    int escolherJogada(const Tabuleiro& tab) override {
        int ordem[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        int melhorPos = -1;
        int melhorValor = -100;

        for (int k = 0; k < 9; k++) {
            int i = ordem[k];
            if (tab.casaLivre(i)) {
                Tabuleiro copia = tab;
                copia.marcar(i, simbolo);
                int valor = minimax(copia, adversario(), 1);

                if (valor > melhorValor) {
                    melhorValor = valor;
                    melhorPos = i;
                }
            }
        }
        cout << "Computador jogou na casa " << melhorPos + 1 << endl;
        return melhorPos;
    }
};

class Partida {
private:
    Tabuleiro tabuleiro;
    Jogador* jogadorX;
    Jogador* jogadorO;

public:
    Partida(Jogador* x, Jogador* o) {
        jogadorX = x;
        jogadorO = o;
    }

    void jogar() {
        Jogador* daVez = jogadorX;

        while (!tabuleiro.acabou()) {
            tabuleiro.mostrar();
            int pos = daVez->escolherJogada(tabuleiro);
            tabuleiro.marcar(pos, daVez->getSimbolo());

            if (daVez == jogadorX)
                daVez = jogadorO;
            else
                daVez = jogadorX;
        }

        tabuleiro.mostrar();
        mostrarResultado();
    }

    void mostrarResultado() const {
        if (tabuleiro.venceu('X'))
            cout << "O X ganhou!" << endl;
        else if (tabuleiro.venceu('O'))
            cout << "O O ganhou!" << endl;
        else
            cout << "Deu velha! (empate)" << endl;
    }
};

char escolherSimbolo() {
    char c;
    while (true) {
        cout << "Voce quer ser X ou O? (o X sempre comeca): ";
        if (!(cin >> c))
            exit(0);
        if (c == 'X' || c == 'x')
            return 'X';
        if (c == 'O' || c == 'o')
            return 'O';
        cout << "Opcao invalida!" << endl;
    }
}

int main() {
    cout << "=== JOGO DA VELHA ===" << endl;
    char s = escolherSimbolo();

    JogadorHumano humano(s);
    JogadorComputador computador(s == 'X' ? 'O' : 'X');

    if (s == 'X') {
        Partida partida(&humano, &computador);
        partida.jogar();
    } else {
        Partida partida(&computador, &humano);
        partida.jogar();
    }
    
cout << endl << "Aperte Enter para sair...";
    cin.ignore(1000, '\n');
    cin.get();

    return 0;
}