# Implementação de Algoritmos envolvendo Grafos.

Projeto desenvolvido para a disciplina de Teoria dos Grafos - 2021.1, no Instituto de Computação da Universidade de Alagoas (IC/UFAL).

#### Professor
- Rian Gabriel Santos Pinheiro

#### Alunos 
- Bruno Lemos de Lima
- José Ferreira Leite Neto

## Sumário

Clique nos links abaixo para acessar rapidamente a seção desejada:

- [Sobre](#sobre)
- [Algoritmos Implementados](#algoritmos-implementados)
- [Estrutura do Projeto](#estrutura-do-projeto)

## Sobre
Neste projeto, foi proposta a implementação de 4 algoritmos envolvendo o estudo de Teoria dos Grafos. Na seção a seguir, é possível ver os algoritmos escolhidos e uma curta descrição para cada (retirada da Wikipédia e site da UFSC no caso de Dijkstra). Na sequência, temos a estrutura do projeto para melhor navegação.

## Algoritmos Implementados

### Algoritmo de Dijkstra
O Algoritmo de Dijkstra (E.W. Dijkstra) é um dos algoritmos que calcula o caminho de custo mínimo entre vértices de um grafo. Escolhido um vértice como raiz da busca, este algoritmo calcula o custo mínimo deste vértice para todos os demais vértices do grafo. Ele é bastante simples e com um bom nível de performance.

### Algoritmo de Ford-Fulkerson
O algoritmo de Ford-Fulkerson (assim designado em honra de Lester Randolph Ford, Jr e Delbert Ray Fulkerson) é um algoritmo utilizado para resolver problemas de fluxo em rede (network flow). O algoritmo é empregado quando se deseja encontrar um fluxo de valor máximo que faça o melhor uso possível das capacidades disponíveis na rede em questão.

### Algoritmo de Kruskal
O algoritmo de Kruskal é um algoritmo em teoria dos grafos que busca uma árvore geradora mínima para um grafo conexo com pesos. Isto significa que ele encontra um subconjunto das arestas que forma uma árvore que inclui todos os vértices, onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado. Se o grafo não for conexo, então ele encontra uma floresta geradora mínima (uma árvore geradora mínima para cada componente conexo do grafo). O algoritmo de Kruskal é um exemplo de um algoritmo guloso (também conhecido como ganancioso ou greedy).

### Algoritmo de Prim
O Algoritmo de Prim é um algoritmo guloso (greedy algorithm) empregado para encontrar uma árvore geradora mínima (minimal spanning tree) num grafo conectado, valorado e não direcionado. Isso significa que o algoritmo encontra um subgrafo do grafo original no qual a soma total das arestas é minimizada e todos os vértices estão interligados. O algoritmo foi desenvolvido em 1930 pelo matemático Vojtěch Jarník e depois pelo cientista da computação Robert Clay Prim em 1957 e redescoberto por Edsger Dijkstra em 1959.

## Estrutura do Projeto

O projeto está estruturado da seguinte forma:

```
Raiz
│   README.md
└───dijkstra
│   └───README.md
│   └───arquivo-entrada.dat
│   └───dijkstra.cpp
│   └───dijkstra.h
│   └───main.cpp
│   └───makefile
└───ford
│   └───README.md
│   └───arquivo-entrada.dat
│   └───ford.cpp
│   └───ford.h
│   └───main.cpp
│   └───makefile
└───kruskal
│   └───README.md
│   └───arquivo-entrada.dat
│   └───kruskal.cpp
│   └───kruskal.h
│   └───main.cpp
│   └───makefile
└───prim
│   └───README.md
│   └───arquivo-entrada.dat
│   └───main.cpp
│   └───makefile
│   └───prim.cpp
│   └───prim.h
└───utils
│   └───graph.cpp
│   └───graph.h
│   └───utils.cpp
│   └───utils.h
```

Cada pasta contém o código para execução de um algoritmo, incluindo:
 - ``README.md`` com as informações necessárias para executar
 - ``arquivo-entrada.dat`` com um exemplo de entrada
 - ``{nome_do_algoritmo}.cpp`` e ``{nome_do_algoritmo}.h`` com a implementação de fato
 - ``main.cpp`` com o código da main que coleta as entradas, executa o algoritmo e exibe a saída
 - ``makefile`` para ajudar na compilação

Além disso, temos a pasta ``utils`` com arquivos comuns a todos os algoritmos, como a estrutura do grafo e algumas funções.
