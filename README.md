# Algoritmo Hill Climbing para solucionar o problema das N rainhas
	O problema das N-rainhas consiste em dispor N rainhas em um tabuleiro de tamanho NxN, de maneira em que nenhuma rainha consiga atacar outra rainha. A fim de resolver computacionalmente o problema proposto foi utilizada a técnica conhecida como Hillclimbing, que será brevemente explicada abaixo.

## Hillclimbing
<ul>
  <li>	O Hillclimbing consiste em uma busca Heurística que é utilizada para otimização de problemas matemáticos, Uma função heurística consiste em um conceito que enumera e qualifica diferentes alternativas para solução de um problema, o que possibilita que o algoritmo decida como tomar uma decisão que encontra um ótimo máximo ou ótimo mínimo. Os ótimos máximos e mínimos de um problema, podem ser entendidos como os pontos de máximos e mínimos da função que quer ser otimizada.</li>
  <li>	O hillcilmbing consiste em um algoritmo que avalia um estado inicial e observa os pontos vizinhos, se o ponto vizinho for “melhor” que o atual, o algoritmo passa a assumir o valor do ponto vizinho. Uma maneira fácil de observar isso é utilizando o problema das N-rainhas. Sendo o ponto inicial, o tabuleiro aleatório, e o ponto vizinho outro tabuleiro com as peças organizadas de maneira diferente. E o fator que dirá qual ponto está mais próximo do desejada é o número heurístico. No caso proposto o número heurístico seria o número de ataques totais possível entre as rainhas no tabuleiro, e uma otimização do problema seria encontrar uma configuração de rainhas com menos ataques totais. No exemplo abaixo podemos observar os diferentes números de ataques possível para cada casa do tabuleiro. 
  Dessa forma o algoritmo Hillclimbing irá mover as rainhas, apenas quando houver uma otimização do número heurístico, ou seja, quando o número de ataques diminuir. Dessa maneira é possível encontrar a solução para qualquer configuração de tabuleiro.</li>
</ul>

## Conclusão:
  <ul>
  <li> Foi possível observar que é possível com o Hillclimbing encontrar soluções que diminuem a quantidade de ataques das rainhas em muito pouco tempo de execução até mesmo com números grandes para N. Comparando com outros algoritmos encontrados como o backtracking, é possível afirmar que obteve-se resultados satisfatórios em relação ao tempo necessário para resolução do problema. 
	Mas quando se trata de problemas de otimização que exigem soluções ideais, é necessário um algoritmo mais robusto do que o Hillclimbing, como por exemplo tabu search ou simulated anneling.  </li>
</ul>

<ul> Compilando: gcc hill_climbing.c Func.c Func.h -o hill </ul>

