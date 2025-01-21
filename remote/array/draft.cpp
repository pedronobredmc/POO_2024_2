#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
    // 1. Criar um array vazio
    std::vector<int> array_vazio;

    // 2. Criar um array preenchido
    std::vector<int> array_preenchido = {1, 2, 3, 4, 5};

    // 3. Adicionar e remover elementos ao final
    array_preenchido.push_back(6); // Adiciona ao final
    array_preenchido.pop_back();   // Remove o último elemento

    // 4. Fazer impressão formatada
    std::cout << "Array preenchido: ";
    for (const auto &num : array_preenchido)
        std::cout << num << " ";
    std::cout << std::endl;

    // 5. Criar um array com elementos em sequência de zero a n
    int n = 10;
    std::vector<int> array_sequencia;
    for (int i = 0; i < n; i++)
        array_sequencia.push_back(i);

    // 6. Criar um array com valores aleatórios
    std::srand(std::time(0));
    std::vector<int> array_aleatorio;
    for (int i = 0; i < 10; i++)
        array_aleatorio.push_back(std::rand() % 100);

    // 7. Acessar elementos por índice
    std::cout << "Primeiro elemento: " << array_sequencia[0] << std::endl;
    std::cout << "Último elemento: " << array_sequencia[array_sequencia.size() - 1] << std::endl;

    // 8. Percorrer os elementos utilizando for-range
    std::cout << "Percorrendo com for-range: ";
    for (const auto &elem : array_sequencia)
        std::cout << elem << " ";
    std::cout << std::endl;

    // 9. Percorrer os elementos utilizando for indexado
    std::cout << "Percorrendo com for indexado: ";
    for (size_t i = 0; i < array_sequencia.size(); i++)
        std::cout << "Índice " << i << ", valor " << array_sequencia[i] << std::endl;

    // 10. Procurar um elemento X usando laço
    int x = 5;
    bool encontrado = false;
    for (const auto &elem : array_sequencia) {
        if (elem == x) {
            encontrado = true;
            break;
        }
    }
    std::cout << "Elemento " << x << (encontrado ? " encontrado" : " não encontrado") << " no array." << std::endl;

    // 11. Criar um novo array com elementos filtrados, por exemplo, pares
    std::vector<int> array_pares;
    for (const auto &num : array_sequencia) {
        if (num % 2 == 0)
            array_pares.push_back(num);
    }
    std::cout << "Elementos pares: ";
    for (const auto &num : array_pares)
        std::cout << num << " ";
    std::cout << std::endl;

    // 12. Criar um novo array com elementos transformados, por exemplo, ao quadrado
    std::vector<int> array_quadrado;
    for (const auto &num : array_sequencia)
        array_quadrado.push_back(num * num);
    std::cout << "Elementos ao quadrado: ";
    for (const auto &num : array_quadrado)
        std::cout << num << " ";
    std::cout << std::endl;

    // 13. Buscar e remover um elemento X
    auto it = std::find(array_sequencia.begin(), array_sequencia.end(), x);
    if (it != array_sequencia.end()) {
        array_sequencia.erase(it);
        std::cout << "Elemento " << x << " removido do array." << std::endl;
    } else {
        std::cout << "Elemento " << x << " não encontrado para remoção." << std::endl;
    }

    // 14. Remover todos os elementos X
    std::vector<int> array_repetido = {1, 2, 2, 3, 4, 2, 5};
    array_repetido.erase(
        std::remove(array_repetido.begin(), array_repetido.end(), 2),
        array_repetido.end());
    std::cout << "Array após remover todos os 2: ";
    for (const auto &num : array_repetido)
        std::cout << num << " ";
    std::cout << std::endl;

    // 15. Funções nativas: busca, remoção, ordenação, embaralhamento
    // Busca
    it = std::find(array_preenchido.begin(), array_preenchido.end(), 3);
    if (it != array_preenchido.end())
        std::cout << "Índice do número 3: " << std::distance(array_preenchido.begin(), it) << std::endl;

    // Remoção
    array_preenchido.erase(std::remove(array_preenchido.begin(), array_preenchido.end(), 3), array_preenchido.end());

    // Ordenação
    std::sort(array_aleatorio.begin(), array_aleatorio.end());
    std::cout << "Array ordenado: ";
    for (const auto &num : array_aleatorio)
        std::cout << num << " ";
    std::cout << std::endl;

    // Embaralhamento
    std::random_shuffle(array_aleatorio.begin(), array_aleatorio.end());
    std::cout << "Array embaralhado: ";
    for (const auto &num : array_aleatorio)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
