# Reflexao - Do Imperativo para o Orientado a Objetos

Na versao imperativa o jogo era um vetor de 9 caracteres e um conjunto de funcoes soltas que recebiam esse vetor e o alteravam. Na versao orientada a objetos o problema foi remodelado em torno de quem participa do jogo: um `Tabuleiro`, dois jogadores (`JogadorHumano` e `JogadorComputador`, que herdam de `Jogador`) e uma `Partida`, que junta tudo e controla os turnos. O codigo esta em `poo/jogodavelhaPOO.cpp`.

**Representacao do estado** - Antes o estado ficava espalhado: o vetor do tabuleiro e a variavel `vez` ficavam no `main` e qualquer funcao podia alterar o vetor. Agora cada objeto guarda o seu proprio estado: o `Tabuleiro` guarda as casas, cada `Jogador` guarda o seu simbolo e a `Partida` guarda o tabuleiro e os jogadores.

**Responsabilidades** - Cada classe tem uma funcao clara. O `Tabuleiro` so cuida das casas (marcar, verificar vitoria, empate e mostrar). O `Jogador` so escolhe uma jogada. A `Partida` so controla a ordem dos turnos e mostra o resultado. No imperativo essas responsabilidades estavam misturadas entre o `main` e as funcoes.

**Relacionamento entre componentes** - A `Partida` tem um `Tabuleiro` (composicao: o tabuleiro nasce e morre junto com a partida) e usa dois jogadores que foram criados fora dela (agregacao). Os jogadores recebem o tabuleiro so para consulta, entao nao conseguem altera-lo: quem marca a jogada e a `Partida`.

**Reutilizacao** - A mesma classe `Tabuleiro` e usada pela partida e pelo computador no minimax, e a mesma `Partida` funciona para qualquer combinacao de jogadores. Nao foi preciso um loop para o humano como X e outro para o humano como O, basta passar os jogadores na ordem certa.

**Encapsulamento** - As casas do tabuleiro sao privadas e so mudam pelo metodo `marcar`, que recusa casas ocupadas ou fora do tabuleiro, entao o tabuleiro nunca chega a um estado invalido. Na versao imperativa qualquer funcao podia escrever direto no vetor. O minimax tambem mudou: antes ele alterava o proprio tabuleiro e desfazia a jogada depois, agora ele testa as jogadas em copias do objeto e o tabuleiro original nunca e modificado.

**Extensao do sistema** - Para criar um novo tipo de jogador, como um computador facil que joga aleatorio, basta criar uma nova classe filha de `Jogador` com o seu proprio `escolherJogada`. A `Partida` e o `Tabuleiro` nao precisam mudar. Tambem daria para fazer computador contra computador so passando dois `JogadorComputador` para a partida.

**Uso de heranca** - A heranca foi usada porque humano e computador realmente sao tipos de jogador: os dois tem um simbolo e escolhem jogadas, so que de formas diferentes. Isso permite o polimorfismo na `Partida`, que chama `escolherJogada` sem saber qual tipo de jogador esta jogando. Nas outras relacoes foi usada composicao e agregacao, porque uma partida nao e um tabuleiro nem um jogador, ela tem um tabuleiro e usa jogadores.

**Validacao** - Os casos de `testes/casos.md` foram repetidos com as mesmas jogadas usadas na versao imperativa, e todos deram o mesmo resultado.



[P4-ETAPA-04]