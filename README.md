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
- o adversario artificial deve sempre fazer a melhor jogada, como definido na secao 5.1

## 5.1 Definicao de melhor jogada

A melhor jogada e escolhida supondo que o adversario tambem sempre joga da melhor forma possivel. Entre as jogadas validas, vale esta ordem de prioridade:

1. vencer na hora: se existe uma jogada que completa uma linha, ela e escolhida
2. garantir a vitoria: se existe uma jogada que leva a vitoria mesmo com o adversario jogando perfeito, ela e escolhida, preferindo a que vence em menos jogadas
3. garantir pelo menos o empate: se nao da pra garantir a vitoria, escolhe uma jogada que nao deixa o adversario vencer. O bloqueio entra aqui: quando o adversario tem dois simbolos em uma linha e a terceira casa esta vazia, ocupar essa casa e a unica forma de nao perder
4. adiar a derrota: se todas as jogadas levam a derrota, escolhe a que faz a derrota demorar mais
5. desempate: se duas ou mais jogadas tem o mesmo resultado, vale a ordem fixa centro (5), cantos (1, 3, 7, 9) e lados (2, 4, 6, 8), ficando com a primeira dessa ordem

Por isso, se for possivel vencer ou bloquear, vencer tem prioridade. E com o tabuleiro vazio todas as jogadas levam ao empate, entao a melhor jogada e o centro pelo desempate.

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

- imperativo: o tabuleiro vira um vetor de 9 casas alterado a cada jogada, as 8 linhas de vitoria sao conferidas com lacos, e a busca da melhor jogada pode marcar uma casa, avaliar e desmarcar no mesmo tabuleiro, usando estado mutavel de forma direta
- orientado a objetos: o jogo tem entidades claras, um tabuleiro que protege as proprias casas e so aceita jogadas validas, jogadores humano e computador que escolhem jogadas de jeitos diferentes mas com a mesma interface, e uma partida que controla os turnos
- funcional: cada jogada pode ser uma funcao que recebe um tabuleiro e devolve um tabuleiro novo sem alterar o anterior, a vitoria pode ser verificada aplicando uma funcao sobre as 8 linhas, e a busca da melhor jogada e recursiva por natureza
- logico: as regras do jogo podem ser escritas como fatos e regras, por exemplo quais casas formam uma linha, o que e uma jogada valida e o que e vencer, e a melhor jogada pode ser uma consulta, deixando o backtracking do Prolog testar as jogadas possiveis

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
