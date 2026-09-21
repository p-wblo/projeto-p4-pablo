# Projeto de paradigmas

## 1. Descricao do problema
O problema proposto e o jogo da velha em um tabuleiro padrao 3x3
com os jogadores usando X e O para realizar suas jogadas alternando entre a vez
de jogar, ate que um dos dois jogadores consiga alinhar 3 do seu respectivo simbolo
assim marcando o fim do jogo com a vitoria ou ate que acabem os espacos do tabueliro
marcando assim um empate.

A proposta do projeto alem de criar um sistema com um tabuleiro jogavel de jogo da
velha e tambem de implementar um adversario artificial que nao comete erros, jogando
sempre da maneira optima.

## 2. Objetivo
O sistema sera capaz de:

- representar o estado do tabuleiro a qualquer momento da partida
- verificar se a jogada e valida no tabuleiro atual
- aplicar a jogada feita pelo usuario e atualizar o tabuleiro
- determinar se a partida acabou, por empate ou vitoria de um dos lados
- calcular a melhor jogada possivel para o adversario, garantindo que ele nunca perca

## 3. Entradas
O sistema recebe:
- o estado do tabuleiro, ou seja o conteudo de cada uma das casas
- qual jogador deve jogar
- a jogada que o usuario deseja fazer

## 4. Saidas
O sistema deve produzir:
- o estado atual do jogo, sendo ou o tabuleiro ou uma mensagem dizendo como o jogo acabou
- se a jogada proposta e invalida
- o novo estado atual do jogo apos a jogada do usuario

## 5. Regras do problema
- o tabuleiro tem 9 casas em um 3x3
- existem dois jogadores X e O, e o X comeca jogando
- os jogadores alternam entre as jogadas
- a jogada so e valida se for em uma casa vazia
- vence quem completar uma linha de 3 dos seus respectivos simbolos
- e empate quando todas as casas sao preenchindas e ninguem venceu
- o adversario artificial deve sempre fazer a melhor jogada para nunca perder

## 6. Casos de exemplo

- tabuleiro vazio, e a vez de X -> a melhor jogada e marcar o centro
do tabuleiro
- X ja tem duas simbolos na mesma linha, e e a vez de X -> a melhor 
jogada e completar essa linha
- X tem duas simbolos na mesma linhamas e a vez de O -> a melhor
jogada de O e ocupar essa casa restante, para evitar a vitoria de X
- X ja completou uma linha inteira -> o jogo termina, X como vencedor
- o tabuleiro esta totalmente preenchido e nenhum dos dois
conseguiu alinhar tres simbolos -> o jogo terminou em empate

## 7. Casos-limite

- jogada em casa ja ocupada -> sistema indica jogada invalida, sem
alterar o tabuleiro
- posicao fora de casa valida -> jogada invalida
- jogada depois que o jogo ja terminou -> sistema indica
que nao ha mais jogadas possiveis


## 8. Restricoes

- realizar os mesmos calculos de melhores jogadas para um tabuleiro maior
- modo multiplayer
- salvar historico de partidas

## 9. Principais conceitos do dominio

- tabuleiro
- casa
- jogador
- turno
- estado do jogo
- melhor jogada
- resultado da partida

## 10. Adequacao aos quatro paradigmas

- imperativo: da pra resolver seguindo os passos e conferindo o
tabuleiro aos poucos
- orientado a objetos: da pra pensar o tabuleiro e o adversario como
coisas que guardam informacao e fazem acoes
- funcional: da pra calcular a melhor jogada testando as
possibilidades repetidamente ate achar a melhor
- logico: da pra escrever as regras do jogo e deixar o programa
descobrir sozinho a jogada certa

## 11. Linguagens inicialmente consideradas

- imperativo: C++, porque permite programar em estilo procedural, 
com variaveis, lacos e fluxo de controle explicitos
- orientado a objetos: C++, por ser usada tanto no
ensino quanto no mercado para modelagem orientada a objetos
- funcional: JavaScript, porque e uma linguagem que
permite escrever com funcoes puras e recursao
- logico: Prolog, porque foi feita especificamente pra representar
fatos e regras logicas, com um mecanismo de backtracking ja
embutido na linguagem, o que facilita expressar a melhor jogada

[P4-ETAPA-01]
