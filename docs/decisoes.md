# Decisoes de Implementacao

## Etapa 03 - Implementacao Imperativa

A implementacao imperativa foi feita em C++ usando apenas o estilo procedural: vetores, variaveis, lacos, condicionais e funcoes, sem classes nem objetos. O codigo esta em `imperativo/jogodavelha.cpp`.

**Estados mantidos** - O estado principal e o tabuleiro, um vetor de 9 caracteres (X, O ou espaco vazio), e a variavel `vez`, que guarda de quem e o turno. Tambem sao guardados o simbolo do jogador humano e o do computador.

**Operacoes que modificam estado** - A funcao `limpar` zera o tabuleiro, cada jogada e feita por atribuicao direta (`tab[pos] = vez`) e a troca de turno e feita com `vez = outro(vez)`.

**Efeitos colaterais** - O vetor do tabuleiro e passado para as funcoes, entao quando uma funcao altera o vetor, a alteracao aparece para quem chamou. O minimax usa isso de proposito: faz a jogada no proprio tabuleiro, avalia o resultado e depois desfaz a jogada. A leitura do teclado e a escrita na tela tambem sao efeitos colaterais.

**Estruturas de controle** - Lacos `for` para percorrer as casas e as 8 formas de ganhar, `while` para o loop da partida e para repetir a leitura ate o usuario digitar uma opcao valida, e `if/else` para as regras do jogo.

**Organizacao dos subprogramas** - As funcoes foram separadas em grupos: as que consultam o tabuleiro (`venceu`, `cheio`, `acabou` e `outro`), a IA (`minimax` e `melhorJogada`) e as da partida (`mostrar`, `escolherSimbolo`, `lerJogada` e o `main`, que controla o loop do jogo).

**Por que e predominantemente imperativa** - A solucao funciona como uma sequencia de comandos que alteram um estado passo a passo: o tabuleiro muda a cada jogada, o turno muda por atribuicao, e ate a busca da melhor jogada e feita modificando e restaurando o mesmo vetor, em vez de criar novos tabuleiros.

**Outras decisoes** - O usuario escolhe se quer ser X ou O, e o X sempre comeca. As casas sao digitadas de 1 a 9 e convertidas para as posicoes 0 a 8 do vetor. A IA testa as casas na ordem centro, cantos e lados, entao quando duas jogadas sao igualmente boas ela prefere o centro e depois os cantos.

## Validacao

A solucao foi validada jogando manualmente os casos de `testes/casos.md`:

- **T01** - escolhendo ser O, o computador (X) comeca jogando no centro (casa 5).
- **T02** - jogando X na casa 5, o computador responde em um canto (casa 1).
- **T03 e T07** - escolhendo O e jogando nas casas 2 e 4, o computador fica com duas marcas na diagonal e completa na casa 9, vencendo na diagonal.
- **T04** - jogando X nas casas 1 e 2, o computador bloqueia na casa 3.
- **T05** - escolhendo O e jogando nas casas 1, 7 e 2, o computador vence na linha do meio.
- **T06** - escolhendo O e jogando nas casas 7, 9 e 3, o computador vence na coluna do meio.
- **T08 e T10** - jogando X nas casas 5, 9, 2, 4 e 7, sempre a melhor jogada, o jogo termina empatado.
- **T09** - a cada jogada o tabuleiro e mostrado de novo com a marca na casa escolhida.
- **T11** - digitando uma casa ocupada aparece "Essa casa ja esta ocupada!" e a jogada e pedida de novo.
- **T12** - quando o jogo termina, o programa mostra o resultado e nao pede mais jogadas.
- **T13** - um tabuleiro impossivel nunca acontece no programa, porque ele so aceita jogadas em casas vazias, alterna os turnos e para na primeira vitoria.
- **T14 e T15** - digitando 10 ou -1 aparece "Essa casa nao existe!".


[P4-ETAPA-03]