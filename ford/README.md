# Algoritmo de Ford-Fulkerson

O algoritmo de Ford-Fulkerson (assim designado em honra de Lester Randolph Ford, Jr e Delbert Ray Fulkerson) é um algoritmo utilizado para resolver problemas de fluxo em rede (network flow). O algoritmo é empregado quando se deseja encontrar um fluxo de valor máximo que faça o melhor uso possível das capacidades disponíveis na rede em questão.

## Compilação

Para compilar, utilizar o comando abaixo na pasta do algoritmo:

``make build``

## Entrada

A entrada deve ser dada por dois inteiros **v** e **e**, indicando respectivamente o número de vértices e de arestas. Na sequência, devem ser informadas **e** linhas contendo três inteiros: **a**, **b** e **c**, onde **a** e **b** são os vértices nas extremidades da aresta e **c** é o peso (ou custo) da aresta (opcional). Importante salientar que 1 <= a, b <= v. Caso o peso da aresta não seja informado, será considerado 1.

Abaixo é possível visualizar um exemplo de entrada de um grafo com 6 vértices e 8 arestas:

```
6 8
1 2 5
1 3 4
1 4 2
1 6 6
2 4 1
2 5 7
3 5 6
4 6 1
```

Obs: Para maior conveniência, utilizar um arquivo de entrada (como o ``arquivo-entrada.dat`` já presente no projeto) e informar no momento da execução através do parâmetro ``-f arquivo-entrada.dat``.

## Execução

O comando base de execução do algoritmo é (após compilado):

``./ford``

Como citado acima, é conveniente utilizar um arquivo de entrada e informar através do parâmetro ``-f``. Também é possível informar um arquivo para a saída com o parâmetro ``-o``.

Para indicar os vértices de início e fim, utilizar ``-i`` e ``-l``, respectivamente, seguidos de um inteiro entre 1 e v. O parâmetro ``-l`` é opcional e se não informado serão calculados os fluxos máximos entre o vértice informado após ``-i`` e todos os outros. Também é possível exibir o caminho com o parâmetro ``-s``, que, de forma análoga, mostra apenas o caminho para o vértice final se ``-l`` for informado e para todos os outros se não for. Para ajuda durante a execução, utilizar ``-h``.

Logo, uma execução do algoritmo informando o vértice inicial (obrigatório) e um arquivo de entrada (da entrada de exemplo), além de pedir a solução (caminho encontrado) seria do tipo:

``./ford -f arquivo-entrada.dat -i 1 -s``

Com o retorno:

```
For the vertex: 2
(1,2) 0
(1,3) 4
(1,4) 2
(1,6) 6
(2,1) 5
(2,4) 1
(2,5) 7
(3,1) 0
(3,5) 6
(4,1) 0
(4,2) 0
(4,6) 1
(5,2) 0
(5,3) 0
(6,1) 0
(6,4) 0

For the vertex: 3
(1,2) 5
(1,3) 0
(1,4) 2
(1,6) 6
(2,1) 0
(2,4) 1
(2,5) 7
(3,1) 4
(3,5) 6
(4,1) 0
(4,2) 0
(4,6) 1
(5,2) 0
(5,3) 0
(6,1) 0
(6,4) 0

For the vertex: 4
(1,2) 4
(1,3) 4
(1,4) 0
(1,6) 6
(2,1) 1
(2,4) 0
(2,5) 7
(3,1) 0
(3,5) 6
(4,1) 2
(4,2) 1
(4,6) 1
(5,2) 0
(5,3) 0
(6,1) 0
(6,4) 0

For the vertex: 5
(1,2) 0
(1,3) 0
(1,4) 2
(1,6) 6
(2,1) 5
(2,4) 1
(2,5) 2
(3,1) 4
(3,5) 2
(4,1) 0
(4,2) 0
(4,6) 1
(5,2) 5
(5,3) 4
(6,1) 0
(6,4) 0

For the vertex: 6
(1,2) 4
(1,3) 4
(1,4) 2
(1,6) 0
(2,1) 1
(2,4) 0
(2,5) 7
(3,1) 0
(3,5) 6
(4,1) 0
(4,2) 1
(4,6) 0
(5,2) 0
(5,3) 0
(6,1) 6
(6,4) 1
```

## Saída

A saída pode variar de acordo com os parâmetros informados:
 1. Se ``-l`` for informado e ``-s`` for utilizado, serão informadas várias linhas no formato ``(a, b) c``, onde a e b são vértices e c é o peso da arestas entre a e b.
 2. Se ``-l`` for informado e ``-s`` não for utilizado, será um inteiro indicando o fluxo máximo encontrado.
 3. Se ``-l`` não for informado e ``-s`` for utilizado, serão informadas várias linhas para cada vértice do grafo, no formato ``(a, b) c``, onde a e b são vértices e c é o peso da arestas entre a e b.
 4. Se ``-l`` não for informado e ``-s`` não for utilizado, serão pares do tipo ``a:b``, onde a é um vértice e b o fluxo máximo entre o vértice inicial e a.
