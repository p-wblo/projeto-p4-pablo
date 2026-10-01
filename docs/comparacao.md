# Comparacao entre as Implementacoes Imperativa e Orientada a Objetos

Esta analise compara as duas versoes do jogo da velha do projeto: a imperativa (imperativo/jogodavelha.cpp) e a orientada a objetos (poo/jogodavelhaPOO.cpp). As duas foram feitas em C++, entao as diferencas vem do paradigma e nao da linguagem. As duas passam nos mesmos 15 casos de teste e jogam exatamente igual.

## Aspectos

**Representacao do estado** - No imperativo o estado e um vetor de 9 casas e uma variavel que guarda de quem e a vez, todos dentro do main. No orientado a objetos cada objeto guarda o seu: o Tabuleiro guarda as casas, cada Jogador guarda o seu simbolo e a Partida guarda o tabuleiro e os jogadores.

**Mutabilidade** - No imperativo qualquer funcao pode alterar o vetor do tabuleiro. No orientado a objetos as casas so mudam pelo metodo marcar, e o resto do programa so consegue ler o tabuleiro.

**Fluxo de controle** - No imperativo todo o jogo acontece em um while dentro do main, com um if que decide se e a vez do humano ou do computador. No orientado a objetos o loop fica no metodo jogar da Partida, e nao existe esse if: cada jogador responde do seu jeito quando a partida pede uma jogada.

**Decomposicao do problema** - O imperativo foi dividido por acoes (verificar vitoria, ler jogada, calcular a melhor jogada). O orientado a objetos foi dividido por quem participa do jogo (tabuleiro, jogadores e partida).

**Reutilizacao** - No imperativo as funcoes sao reaproveitadas, como a funcao venceu, usada em varios lugares. No orientado a objetos a mesma Partida funciona para qualquer par de jogadores, e o mesmo Tabuleiro e usado na partida e no minimax.

**Manutencao** - No imperativo o vetor e usado em varias funcoes, entao mudar o jeito de guardar o tabuleiro exigiria mexer em todas elas. No orientado a objetos so a classe Tabuleiro conhece as casas, entao a mudanca ficaria em um lugar so.

**Facilidade de extensao** - Para criar um novo tipo de jogador, o imperativo precisaria de uma nova funcao e de mudar o if do main. No orientado a objetos basta criar uma nova classe filha de Jogador, sem mudar o resto.

**Tratamento de erros** - Nas duas versoes a jogada do usuario e pedida de novo ate ser valida (ser um numero, de 1 a 9, em uma casa vazia). O orientado a objetos tem uma protecao a mais: o metodo marcar recusa jogadas invalidas.

**Efeitos colaterais** - No imperativo o minimax altera o vetor do tabuleiro e depois desfaz a alteracao. No orientado a objetos o minimax trabalha em copias e o tabuleiro real nunca e alterado. Nas duas versoes ler do teclado e escrever na tela continuam sendo efeitos colaterais.

**Facilidade para testar** - O imperativo e mais facil de testar por partes, porque da para montar qualquer tabuleiro e chamar uma funcao direto. No orientado a objetos o tabuleiro so pode ser montado jogada por jogada, e os jogadores dependem do teclado e da tela.

**Organizacao do codigo** - O imperativo tem 11 funcoes soltas, em cerca de 185 linhas. O orientado a objetos tem 5 classes, em cerca de 260 linhas. O codigo ficou maior, mas cada parte tem um lugar claro.

**Complexidade** - O minimax e o mesmo nas duas versoes, com as mesmas notas e a mesma ordem de desempate. O orientado a objetos ficou um pouco mais lento por copiar o tabuleiro (cerca de 55 ms contra 45 ms na primeira jogada), e e mais complexo de entender, porque usa classes, heranca e ponteiros.

## Perguntas

**1. Qual problema ficou mais facil de expressar de forma imperativa?** - O minimax e a verificacao de vitoria. E so percorrer o vetor, marcar a casa, testar e desmarcar.

**2. Qual problema ficou mais facil de expressar utilizando orientacao a objetos?** - Os dois tipos de jogador. Humano e computador viraram duas classes filhas de Jogador, e a partida trata os dois do mesmo jeito.

**3. Onde a orientacao a objetos realmente trouxe vantagem?** - Em proteger o tabuleiro, que so muda pelo metodo marcar, e em tratar humano e computador do mesmo jeito, o que facilita criar novos tipos de jogador.

**4. Em quais situacoes a utilizacao de objetos acrescentou complexidade desnecessaria?** - A classe Partida existe so para um loop que no imperativo era simples. O codigo ficou cerca de 40% maior, e copiar o tabuleiro no minimax deixou a busca um pouco mais lenta.

**5. Que partes do problema praticamente nao mudaram entre as duas implementacoes?** - As regras do jogo, a verificacao de vitoria e de empate, as notas do minimax, a ordem de desempate, a leitura da jogada do usuario e o desenho do tabuleiro.

**6. Que partes precisaram ser completamente remodeladas?** - Quem guarda e quem altera o tabuleiro, o minimax, que passou a usar copias em vez de fazer e desfazer, e o loop do jogo, que saiu do main e foi para a classe Partida.


[P4-ETAPA-05]
