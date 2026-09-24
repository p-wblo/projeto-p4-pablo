#include <iostream>
#include <cstdlib>
using namespace std;

int linhas[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

void limpar(char tab[]) {
    for (int i = 0; i < 9; i++) {
        tab[i] = ' ';
    }
}

void mostrar(char tab[]) {
    cout << endl;
    for (int i = 0; i < 9; i++) {
        if (tab[i] == ' ')
            cout << " " << i + 1 << " ";
        else
            cout << " " << tab[i] << " ";

        if (i == 2 || i == 5)
            cout << endl << "---+---+---" << endl;
        else if (i != 8)
            cout << "|";
    }
    cout << endl << endl;
}

bool venceu(char tab[], char jogador) {
    for (int i = 0; i < 8; i++) {
        if (tab[linhas[i][0]] == jogador &&
            tab[linhas[i][1]] == jogador &&
            tab[linhas[i][2]] == jogador)
            return true;
    }
    return false;
}

bool cheio(char tab[]) {
    for (int i = 0; i < 9; i++) {
        if (tab[i] == ' ')
            return false;
    }
    return true;
}

bool acabou(char tab[]) {
    return venceu(tab, 'X') || venceu(tab, 'O') || cheio(tab);
}

char outro(char jogador) {
    if (jogador == 'X')
        return 'O';
    return 'X';
}

int minimax(char tab[], char vez, char ia, int prof) {
    if (venceu(tab, ia))
        return 10 - prof;
    if (venceu(tab, outro(ia)))
        return prof - 10;
    if (cheio(tab))
        return 0;

    int melhor;
    if (vez == ia)
        melhor = -100;
    else
        melhor = 100;

    for (int i = 0; i < 9; i++) {
        if (tab[i] == ' ') {
            tab[i] = vez;
            int valor = minimax(tab, outro(vez), ia, prof + 1);
            tab[i] = ' ';

            if (vez == ia && valor > melhor)
                melhor = valor;
            if (vez != ia && valor < melhor)
                melhor = valor;
        }
    }
    return melhor;
}

int melhorJogada(char tab[], char jogador) {
    int ordem[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

    int melhorPos = -1;
    int melhorValor = -100;

    for (int k = 0; k < 9; k++) {
        int i = ordem[k];
        if (tab[i] == ' ') {
            tab[i] = jogador;
            int valor = minimax(tab, outro(jogador), jogador, 1);
            tab[i] = ' ';

            if (valor > melhorValor) {
                melhorValor = valor;
                melhorPos = i;
            }
        }
    }
    return melhorPos;
}

int lerJogada(char tab[], char humano) {
    int num;
    while (true) {
        cout << "Sua vez (" << humano << "), escolha uma casa de 1 a 9: ";
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
        if (tab[num - 1] != ' ') {
            cout << "Essa casa ja esta ocupada!" << endl;
            continue;
        }
        return num - 1;
    }
}

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
    char tab[9];
    char vez = 'X';
    limpar(tab);

    cout << "=== JOGO DA VELHA ===" << endl;
    char humano = escolherSimbolo();
    char ia = outro(humano);

    while (!acabou(tab)) {
        mostrar(tab);
        int pos;
        if (vez == humano) {
            pos = lerJogada(tab, humano);
        } else {
            pos = melhorJogada(tab, ia);
            cout << "Computador jogou na casa " << pos + 1 << endl;
        }
        tab[pos] = vez;
        vez = outro(vez);
    }

    mostrar(tab);
    if (venceu(tab, humano))
        cout << "Voce ganhou!" << endl;
    else if (venceu(tab, ia))
        cout << "O computador ganhou!" << endl;
    else
        cout << "Deu velha! (empate)" << endl;

    return 0;
}
