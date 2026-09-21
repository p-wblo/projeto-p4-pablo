# Contrato Semantico e Testes

Este documento define os casos de teste que servirao de contrato para as quatro implementacoes do projeto (imperativa, orientada a objetos, funcional e logica). Cada caso especifica a entrada, a saida esperada e o que esta sendo testado.

## Casos Normais

**T01** - Tabuleiro vazio, vez de X. Saida esperada: melhor jogada no centro do tabuleiro. Testa a primeira jogada da partida.

**T02** - Tabuleiro com X no centro, vez de O. Saida esperada: melhor jogada em um dos cantos. Testa a resposta a uma abertura pelo centro.

**T03** - X ja tem duas marcas na mesma linha, falta uma casa vazia, vez de X. Saida esperada: a melhor jogada completa essa linha e vence. Testa o aproveitamento de uma jogada vencedora.

**T04** - X tem duas marcas na mesma linha, falta uma casa pra vencer, vez de O. Saida esperada: a melhor jogada de O bloqueia essa casa. Testa o bloqueio de uma ameaca de vitoria.

**T05** - X ja completou uma linha horizontal inteira. Saida esperada: jogo terminado, vencedor X. Testa a deteccao de vitoria em linha.

**T06** - X ja completou uma coluna inteira. Saida esperada: jogo terminado, vencedor X. Testa a deteccao de vitoria em coluna.

**T07** - X ja completou uma diagonal inteira. Saida esperada: jogo terminado, vencedor X. Testa a deteccao de vitoria em diagonal.

**T08** - Tabuleiro totalmente preenchido, sem tres marcas iguais alinhadas. Saida esperada: jogo terminado, empate. Testa a deteccao de empate.

**T09** - Tabuleiro parcialmente preenchido, jogada valida de X em uma casa vazia. Saida esperada: tabuleiro atualizado com a nova marca de X. Testa a aplicacao de uma jogada valida.

**T10** - Simulacao completa: humano (X) joga primeiro no centro, depois em dois cantos, e o sistema responde sempre com a melhor jogada para O. Saida esperada: tabuleiro final preenchido, resultado empate. Testa uma partida inteira contra o adversario. 

## Casos-Limite

**T11** - Jogada solicitada em uma casa ja ocupada. Saida esperada: jogada invalida, tabuleiro nao e alterado. Testa jogada em casa ocupada.

**T12** - Pedido de jogada depois que o jogo ja terminou. Saida esperada: sistema indica que nao ha mais jogadas possiveis. Testa pedido de jogada apos o fim do jogo.

**T13** - Tabuleiro com duas linhas vencedoras completas ao mesmo tempo, para jogadores diferentes. Saida esperada: sistema identifica o estado como invalido. Testa um estado de tabuleiro impossivel de ocorrer numa partida real.

## Casos de Entrada Invalida

**T14** - Jogada solicitada em uma posicao que nao existe no tabuleiro. Saida esperada: entrada invalida. Testa posicao fora do intervalo valido do tabuleiro.

**T15** - Jogada solicitada com um valor negativo de posicao. Saida esperada: entrada invalida. Testa posicao negativa, fora do intervalo valido.


[P4-ETAPA-02]
