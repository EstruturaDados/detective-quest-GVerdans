// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🌱 Struct Sala
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Função para criar uma nova sala
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória para a sala!\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função para conectar salas
void conectarSalas(Sala* pai, Sala* esquerda, Sala* direita) {
    if (pai != NULL) {
        pai->esquerda = esquerda;
        pai->direita = direita;
    }
}

// Função para explorar as salas
void explorarSalas() {
    // 🏰 Criando todas as salas da mansão
    Sala* hallEntrada = criarSala("🎪 Hall de Entrada");
    Sala* biblioteca = criarSala("📚 Biblioteca Antiga");
    Sala* cozinha = criarSala("🍳 Cozinha Real");
    Sala* sotao = criarSala("🕸️ Sótão Misterioso");
    Sala* salaJantar = criarSala("🍽️ Sala de Jantar");
    Sala* jardim = criarSala("🌹 Jardim de Inverno");
    Sala* quarto = criarSala("🛏️ Quarto Principal");
    Sala* porao = criarSala("💀 Porão Assombrado");
    
    // 🔗 Conectando as salas para formar a árvore binária
    // Hall de Entrada conecta à Biblioteca (esq) e Cozinha (dir)
    conectarSalas(hallEntrada, biblioteca, cozinha);
    
    // Biblioteca conecta ao Sótão (esq) e Sala de Jantar (dir)
    conectarSalas(biblioteca, sotao, salaJantar);
    
    // Cozinha conecta ao Jardim (esq) e Quarto Principal (dir)
    conectarSalas(cozinha, jardim, quarto);
    
    // Sala de Jantar conecta ao Porão (esq) e NULL (dir)
    conectarSalas(salaJantar, porao, NULL);
    
    // 🎮 Sistema de exploração
    Sala* salaAtual = hallEntrada;
    char comando;
    
    printf("🏰 BEM-VINDO À MANSÃO MISTERIOSA! 🏰\n");
    printf("=====================================\n");
    printf("Use os comandos:\n");
    printf("  'e' - ir para ESQUERDA\n");
    printf("  'd' - ir para DIREITA\n");
    printf("  's' - SAIR da mansão\n\n");
    
    do {
        printf("\n📍 Você está na: %s\n", salaAtual->nome);
        printf("Onde deseja ir? (e/d/s): ");
        scanf(" %c", &comando);
        
        switch (comando) {
            case 'e':
            case 'E':
                if (salaAtual->esquerda != NULL) {
                    salaAtual = salaAtual->esquerda;
                    printf("➡️ Indo para a sala à esquerda...\n");
                } else {
                    printf("❌ Não há sala à esquerda! É um beco sem saída.\n");
                }
                break;
                
            case 'd':
            case 'D':
                if (salaAtual->direita != NULL) {
                    salaAtual = salaAtual->direita;
                    printf("➡️ Indo para a sala à direita...\n");
                } else {
                    printf("❌ Não há sala à direita! É um beco sem saída.\n");
                }
                break;
                
            case 's':
            case 'S':
                printf("🚪 Saindo da mansão... Até a próxima!\n");
                break;
                
            default:
                printf("❌ Comando inválido! Use 'e', 'd' ou 's'.\n");
                break;
        }
        
    } while (comando != 's' && comando != 'S');
    
    // 🧹 Liberar memória (opcional, já que o programa está terminando)
    free(hallEntrada);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(salaJantar);
    free(jardim);
    free(quarto);
    free(porao);
}

// Função auxiliar para mostrar o mapa da mansão
void mostrarMapa() {
    printf("\n🗺️  MAPA DA MANSÃO:\n");
    printf("    🎪 Hall de Entrada\n");
    printf("    /               \\\n");
    printf("📚 Biblioteca     🍳 Cozinha\n");
    printf("   /    \\          /    \\\n");
    printf("🕸️ Sótão  🍽️ SalaJantar 🌹 Jardim  🛏️ Quarto\n");
    printf("              /    \n");
    printf("          💀 Porão\n\n");
}

// Função principal
int main() {
    printf("🌳 EXPLORAÇÃO DA MANSÃO COM ÁRVORE BINÁRIA 🌳\n");
    
    // Mostrar o mapa antes de começar
    mostrarMapa();
    
    // Iniciar a exploração
    explorarSalas();
    
    return 0;
}

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

