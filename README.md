<a>
    <img src="https://fisiologiadeinsetosufv.files.wordpress.com/2017/08/novo-brasao-ufv.png" alt="UFV logo" title="UFV" align="right" height="50" />
</a>


<h1 align = "center"> Projeto Final - INF112 </h1>


<h2 align = "center"> Uma aplicação para ajudar alunos de Cálculo I </h2>


## Índice

- [Funções](#Funções)
- [Instalação](#Instalação)
- [Exemplos](#Exemplos)
- [Lista de Exceções](#Lista-de-Exceções)
- [FAQ](#FAQ)
- [Responsáveis](#Responsáveis)
- [CRC](#CRC)
- [Links Úteis](#Links-Úteis)


## Funções
- Determinar domínio e imagem da função 
- Determinar as raízes da função
- Determinar <code> f(x0)</code> dado <code> x0 </code>
- Determinar derivada e integral da função
- Esboçar gráficos

## Instalação

## Exemplos

## Lista de Exceções

## FAQ
### ✔️ Como devo escrever minha função?
No momento, esperamos funções _polinômiais_. Então:
- <img src = "https://en.wikipedia.org/api/rest_v1/media/math/render/svg/869e366caf596564de4de06cb0ba124056d4064b" ><code>Ax</code> indica um monômio
- Utilize <code>x </code> para a variável incógnita.
- Para elevar expoentes utilize <code> ^</code>.                       Ex: _3x^2_
- Coeficientes podem ser do tipo <code> A</code> ou <code> A/B</code>. Ex: _5x_ ou _5/9x_
- Expoentes podem ser do tipo <code> C</code> ou <code> (C/D)</code>.  Ex: _x^5_ ou _x^(5/9)_
- Exemplo de entrada: _2/3x^3 - 12x^(6/3) + 2x - 81/2_.

### ✔️ Posso colocar qualquer tipo de função?
Por enquato a entrada está limitada a somente com _polinômios_, mas estamos trabalhando para adicionar outros tipos de funções!

### ✔️ Como calcula a derivada numérica?
Utilizamos o método das diferenças finitas:  

<img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/b23307e0a166752a67f83d9089a84fc476df8cb8" class="mwe-math-fallback-image-inline" aria-hidden="true" style="vertical-align: -2.005ex; width:29.76ex; height:5.843ex;" alt="f'(x)\simeq {f(x+h)-f(x-h) \over 2h}.">

Em código, temos:

```c++
      double dfx0;

      double h = 0.0001;
      double fmais = retorna_valor(ponto + h); 
      double fmenos = retorna_valor(ponto - h);

      dfx0 = (fmais - fmenos)/(2.*h);

      return dfx0;
```




## Responsáveis
- [Caio](https://github.com/caio-rondow) 
- [Gabriel Bezerra](https://github.com/GdSBezerra)
- [Olavo Barros](https://github.com/Olavo-B)
- [Vitor Moura](https://github.com/vitormoura11)

## CRC

| Classe: Funcao |  |
|-|-|
| Responsabilidade | Colaboração |
|   1.Atributos: Saber os coeficientes; Saber os expoentes; Saber o tipo; Saber domínio e imagem; Saber as raízes;           2.Métodos: Determinar o domínio e imagem; Determinar um f(x0); Determinar as raízes; Determinar o gráfico de f e pontos; |   Gráfico; |

| Classe: Calculo_Numerico |  |
|-|-|
| Responsabilidade | Colaboração |
|   1.Atributos: Saber a derivada; Saber integral definida; e Saber o máximo e mínimo.      2.Métodos:  Determinar a aproximação a derivada em ponto ; Determinar a integral definida; Determinar máximo e mínimo em um determinado trecho do domínio; e Determinar o gráfico da reta tangente e área hachurada. |   Grafico; Funcao. |

| Classe: Calculo_Analitico |  |
|-|-|
| Responsabilidade | Colaboração |
|   1.Atributos: Saber os coeficientes da derivada e integral; Saber os expoentes da derivada e integral; Saber a derivada; Saber integral definida; e Saber o máximo e mínimo. 2.Métodos: Determinar a derivada analítica de f; Determinar um f’(x0); [polimorfismo] Determinar integral analítica de f; Determinar a integral de f em um ponto x0; [polimorfismo] Determinar máximo e mínimo global; Determinar o gráfico da reta tangente e área hachurada; |   Grafico; Funcao. |

| Classe: Grafico |  |
|-|-|
| Responsabilidade | Colaboração |
|   1.Atributos: Saber os coeficientes da derivada e integral; Saber os expoentes da derivada e integral; Saber a derivada; Saber integral definida; e Saber o máximo e mínimo.    2.Métodos:  Plotar um gráfico de funções ; Plotar um gráfico de duas funções; Plotar um gráfico com área hachurada  |   Funcao; Calculo_numerico; Calculo_Analitico. |

## Links Úteis
- [gnuplot](http://www.gnuplot.info/) : ferramenta para plotagem dos gráficos;
- [Diferenciação numérica](https://pt.wikipedia.org/wiki/Diferencia%C3%A7%C3%A3o_num%C3%A9rica#:~:text=Na%20an%C3%A1lise%20num%C3%A9rica%2C%20diferencia%C3%A7%C3%A3o%20num%C3%A9rica,outros%20conhecimentos%20sobre%20a%20fun%C3%A7%C3%A3o.) : como calculamos a derivada númerica

