# Pesquisa sobre C++

- Quais as vantagens de uma linguagem compilada em relação a uma interpretada?
    Apresentam um desempenho mais rápido, detectação de erros durante o tempo de compilação, uma melhor otimização de código, mais segurança e consistencia e uma distribuição facilitada.

- Quais os tipos de comentários em C++?
    Existe alguns tipos de comentarios, sendo eles: "//" que funciona para comentar aquilo que esta em uma linha após o sinal, "/* */" que funciona para comentar multiplas linhas.

- O include é um comando para o compilador ou para o pré-processador?
    O include é um comando para o pré-processador, que tem como objetivo inserir conteúdo de arquivos de cabeçalho diretamente no código antes da etapa de compilação.

- O que é o pre-processador? Todos os comandos iniciados por # são para o pré-processador?
    O pré-processador é uma fase inicial de preparação do código-fonte antes da compilação, utilizada em linguagens como C e C++. Ele processa diretivas que começam com o símbolo #, executando uma série de substituições e inclusões de código. O resultado é um código "pré-processado" que será enviado para a etapa de compilação.

- O que é um namespace? Cite outras linguagens que possuem algo similar.
    Um namespace é uma maneira de organizar e agrupar identificadores (como funções, classes e variáveis) para evitar conflitos de nomes, especialmente em projetos grandes. Python, Java, C# e Ruby, todas elas possuem algo similar ao namespace.

- Qual o conceito de escopo em uma linguagem de programação?
    O escopo em uma linguagem de programação define a visibilidade e o tempo de vida das variáveis e outros identificadores (como funções e classes) dentro do código. Em outras palavras, o escopo estabelece onde uma variável pode ser acessada e por quanto tempo ela existe durante a execução do programa.

- Qual a diferença entre uma variável local e uma global?
    Uma váriavel local só pode ser acessada dentro daquele escopo, ou seja, sua visibilidade e tempo de vida esta restrita a aquele lugar que ela se encontra. Já uma variavel global pode ser vista e utilizada dentro de qualquer lugar no arquivo, não tendo o seu tempo de vida definido.

- Quando uma variável é alocada na Stack e quando é alocada na Heap?
    A Stack é usada para armazenar variáveis de tempo de execução conhecido, geralmente aquelas com tempo de vida curto e tamanho conhecido em tempo de compilação.
    A Heap é usada para alocar memória para variáveis e objetos que precisam de vida útil mais longa e tamanho variável ou desconhecido até o tempo de execução.

- Quais as formas de se inicializar uma variável em C++? Qual a mais recomendada?
    Inicialização por atribuição (int x = 5;)
    Inicialização direta (int x(5);)
    Inicialização uniforme(int x{5};)
    Inicialização por lista(std::vector<int> vec{1, 2, 3, 4};)
    Iniciação sem valor (int x{};)
    Inicialização padrão(int x;)

    A inicialização uniforme é a abordagem recomendada por ser mais segura e confiável.

- O que é o buffer de entrada e saída padrão? Como manipular esses buffers?
    O buffer de entrada e saída padrão em C++ é uma área de memória temporária usada para armazenar dados enquanto eles estão sendo lidos (entrada) ou escritos (saída) no programa. Esse buffer ajuda a tornar as operações de I/O (Input/Output) mais eficientes, pois permite que dados sejam manipulados em blocos, reduzindo o número de interações diretas com dispositivos de hardware (como o teclado e o console) ou arquivos.
    Os buffers são manipuladas utilizando std::flush, std::cin.ignore, std::cin.clear(), std::unitbuf e etc..

- O buffer de entrada sempre são sempre teclado e tela ou podem ser redirecionados?
    Os buffers de entrada e saída em C++ não são limitados apenas ao teclado e à tela (console). Eles podem ser redirecionados para diferentes fontes e destinos, incluindo arquivos e outros dispositivos. Isso é uma parte fundamental do sistema de entrada e saída em C++, permitindo uma grande flexibilidade.

- Quais os tipos primivos de dados em C++?
    int, short, long, long long, float, double, long double, char e bool

- Quais os principais modificadores de tipo em C++?
    signed, unsigned, short, long, long long

- Como funciona a palavra reservada auto?
    A palavra reservada auto em C++ é usada para permitir que o compilador deduza automaticamente o tipo de uma variável com base na expressão que está sendo atribuída a ela. Quando você declara uma variável usando auto, o compilador analisa a expressão à direita da atribuição e determina o tipo correspondente.

- Como fazer a conversão entre tipos primivos em C e com é a sintaxe do static_cast? Qual a diferença entre static_cast e reinterpret_cast?
    Em C++, você pode converter entre tipos primitivos usando conversões implícitas, explícitas (como static_cast) ou mais arriscadas (como reinterpret_cast). O static_cast é recomendado para conversões seguras, enquanto o reinterpret_cast deve ser usado com cautela, apenas em situações onde você sabe exatamente o que está fazendo.

- Qual a diferença entre o ++ antes e depois de uma variável?
    Em C++, o operador de incremento (++) pode ser usado de duas formas: como pré-incremento (++variável) e como pós-incremento (variável++). A principal diferença entre as duas formas é o momento em que a variável é incrementada em relação à expressão em que está sendo utilizada.

- Reescreva o seguinte código sem sem usar os operadores unários ++ e -- [LINK](#corrija)
```cpp
int a = 5;
int b = a+1;
int c = a+1 + b-1;
std::cout << a << " " << b << " " << c << '\n';
```

- Na sintaxe de if, else, existe algum padrão que defina quando usar chaves ou não? Não apenas sobre a sintaxe, mas sobre a legibilidade e boas práticas de programação?
    Em C++ (e na maioria das linguagens com estrutura similar), as chaves {} em uma declaração if ou else delimitam um bloco de código associado à condição. Quando um bloco contém uma única instrução, as chaves são opcionais, mas seu uso ou omissão está relacionado a preferências de estilo e boas práticas de legibilidade e segurança no código.

- C++ aceita inicialização de variáveis dentro de um if? No modelo `if (int x = 5; x < value) { ... }`?
    Sim, a partir do C++17, é permitido declarar e inicializar variáveis dentro da expressão de um if (ou switch), usando a sintaxe de inicialização de declaração. Essa sintaxe permite declarar e inicializar variáveis diretamente na cláusula condicional do if

- Como funciona um operador ternário? Quando vale a pena substituir um if else por um operador ternário?

- Em c++ função são elementos de primeira classe? O que isso significa?

- Qual seria a sintaxe para uma função lambda que recebe dois inteiros e retorna a soma deles?

- Para que serve um return em função função que não retorna nada?

- Em uma função, melhor criar vários ifs, elses ou múltiplos pontos de return?

- A passagem de parâmetros em C++ pode ser cópia, ponteiro ou referência. Qual a diferença entre cada uma delas?

- O que é um parâmetro default em uma função?

- O que é uma função inline? Quando vale a pena usar uma função inline?

- O que seria uma sobrecarga de função? Como o compilador diferencia duas funções com o mesmo nome?

- Qual a diferença entre passar um parâmetro por cópia ou por referência constante? Quando usar cada um?

- Qual a diferença entre declaração e definição de uma função?

- O que é a tabela de símbolos de um programa? Como ela é usada pelo compilador?

- Qual o tipo padrão de um texto "Hello World" em C++?

- Quais as formas de se criar um laço de repetição em C++?

- O que faz o continue e o break em um laço de repetição?

- Pesquise onde o C++ é mais utilizado e quais as vantagens de se usar essa linguagem em relação a outras.

- Quais são as principais linguagens com concorrem com C++ e quais as vantagens de cada uma delas?

## Corrija

```cpp
int a = 5;
int b = a++;
int c = ++a + --b;
std::cout << a << " " << b << " " << c << '\n';
```
