#include <stdio.h>
#include <string.h>

// Função que exibe uma barra de progresso simples
void ExibirBarra(char* nome, int valor) {
    int i;
    int totalBarras = 20; // total de blocos na barra
    int preenchido = (valor * totalBarras) / 100;

    printf("%s: [", nome);
    for (i = 0; i < totalBarras; i++) {
        if (i < preenchido) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", valor);
}

// Função do Menu de Status da Torre
void MenuTorre(int* TorreAlt, int* TorreEst, int* TorreOrn) {
    printf("\n================ ESTADO DA TORRE ================\n");
    ExibirBarra("Altura", TorreAlt);
    ExibirBarra("Estrutura", TorreEst);
    ExibirBarra("Ornamentos", TorreOrn);
    printf("=================================================\n\n");
}

// Função do Menu Coleta de Recursos
void MenuRecursos(int* RecMad, int* RecPed, int* RecCri, int* TempoDias) {
    char EscolhaRecursos[10];
    printf("\n================ RECURSOS ATUAIS ================\n");
    printf("Madeira:  %i\n", *RecMad);
    printf("Pedras:   %i\n", *RecPed);
    printf("Cristais: %i\n", *RecCri);
    printf("\n================ COLETAR RECURSOS ===============\n");
    printf("[F]loresta - ⇑⇑ Madeira  | ⇑ Pedra\n");
    printf("[P]edreira - ⇑⇑ Pedras   | ⇑ Cristais\n");
    printf("[C]averna  - ⇑⇑ Cristais | ⇑ Pedra\n");
    printf("Ou aperte outra tecla para voltar ao menu anterior!\n");
    printf("=================================================\n\n");
    
    fgets(EscolhaRecursos, 10, stdin);

    // Remover o \n se presente
    size_t len = strlen(EscolhaRecursos);
    if (len > 0 && EscolhaRecursos[len - 1] == '\n') {
        EscolhaRecursos[len - 1] = '\0';
    }

    if (strcmp(EscolhaRecursos, "F") == 0) {
        printf("=================================================\n\n");
        printf("Os aldeões passam 5 dias na Floresta!\n");
        printf("Encontraram 15 Madeiras e 5 Pedras!\n");
        printf("=================================================\n\n");
        *RecMad += 15;
        *RecPed += 5;
        *TempoDias -= 5;

    } else if (strcmp(EscolhaRecursos, "P") == 0) {
        printf("=================================================\n\n");
        printf("Os aldeões passam 5 dias na Pedreira!\n");
        printf("Encontraram 10 Pedras e 2 Cristais!\n");
        printf("=================================================\n\n");
        *RecPed += 10;
        *RecCri += 2;
        *TempoDias -= 5;

    } else if (strcmp(EscolhaRecursos, "C") == 0) {
        printf("=================================================\n\n");
        printf("Os aldeões passam 5 dias nas cavernas!\n");
        printf("Encontraram 5 Cristais e 5 Pedras!\n");
        printf("=================================================\n\n");
        *RecCri += 5;
        *RecPed += 5;
        *TempoDias -= 5;
    } else {
        printf("Você escolheu voltar!\n\n");
    }
}

// Função do Menu de Construção
void MenuConstrucao(int* TorreAlt, int* TorreEst, int* TorreOrn, int* RecMad, int* RecPed, int* RecCri, int* TempoDias) {
    char EscolhaRecursos[10];
    printf("\n================ RECURSOS ATUAIS ================\n");
    printf("Madeira:  %i\n", *RecMad);
    printf("Pedras:   %i\n", *RecPed);
    printf("Cristais: %i\n", *RecCri);
    printf("\n================ Seções Disponíveis ===============\n");
    printf("[S]imples - 5 Madeira & 1 Pedra & 5 Dias  | +5 Altura & + 1 Estabilidade \n");
    printf("[E]strutural - 5 Pedras & 10 Madeiras & 10 Dias  | +2 Altura & + 5 Estabilidade \n");
    printf("[D]ecorada - 10 Madeira & 5 Cristais & 10 Dias  | +5 Altura & + 5 Ornamentos & - 4 Estabilidade \n");
    printf("Es[C]ulpida - 20 Madeiras& 12 Pedras e 10 Cristais & 15 Dias  | +5 Altura & + 4 Estabilidade & + 3 Ornamentos  \n");
    printf("Ou aperte outra tecla para voltar ao menu anterior!\n");
    printf("=================================================\n\n");
    
    fgets(EscolhaRecursos, 10, stdin);

    // Remover o \n se presente
    size_t len = strlen(EscolhaRecursos);
    if (len > 0 && EscolhaRecursos[len - 1] == '\n') {
        EscolhaRecursos[len - 1] = '\0';
    }

    if (strcmp(EscolhaRecursos, "S") == 0) {
        printf("=================================================\n\n");
        printf("Os aldeões passam 5 dias Construindo a seção Simples!\n");
        printf("A torre ganhou +5 Altura & + 1 Estabilidade!\n");
        printf("=================================================\n\n");
        *RecMad -= 5;
        *RecPed -= 1;
        *TempoDias -= 5;
        *TorreAlt += 5;
        *TorreEst += 1;

    } else if (strcmp(EscolhaRecursos, "E") == 0) {
         printf("=================================================\n\n");
        printf("Os aldeões passam 10 dias Construindo a seção Estrutural!\n");
        printf("A torre ganhou +2 Altura & + 5 Estabilidade!\n");
        printf("=================================================\n\n");
        *RecMad -= 10;
        *RecPed -= 5;
        *TempoDias -= 10;
        *TorreAlt += 2;
        *TorreEst += 5;

    } else if (strcmp(EscolhaRecursos, "D") == 0) {
        printf("=================================================\n\n");
        printf("Os aldeões passam 10 dias Construindo a seção Decorada!\n");
        printf("A torre ganhou +5 Altura & + 5 Ornamentos e perde - 4 Estabilidade!\n");
        printf("=================================================\n\n");
        *RecMad -= 10;
        *RecCri -= 5;
        *TempoDias -= 10;
        *TorreAlt += 5;
        *TorreEst -= 4;
        *TorreOrn += 5;

        
    } else if (strcmp(EscolhaRecursos, "C") == 0) {
        printf("=================================================\n\n");
        printf("Os aldeões passam 15 dias Construindo a seção Esculpida!\n");
        printf("A torre ganhou +5 Altura & + 4 Estabilidade & + 3 Ornamentos!\n");
        printf("=================================================\n\n");
        *RecMad -= 20;
        *RecPed -= 12;
        *RecCri -= 10;
        *TempoDias -= 15;
        *TorreAlt += 5;
        *TorreEst += 4;
        *TorreOrn += 3;

    } else {
        printf("Você escolheu voltar!\n\n");
    }
}

// Função de Escolha de outros menus
void MenuPrincipal(int TorreAlt, int TorreEst, int TorreOrn,
                   int RecMad, int RecPed, int RecCri, int TempoDias) {
    char Escolha[10];

    while (TempoDias>0) {
        printf("================================================\n\n");
        printf("Dias Remanescentes: %i \n\n", TempoDias);
        printf("Escolha uma das Ações abaixo:\n\n");
        printf("Observar a [T]orre.\n");
        printf("Coletar [R]ecursos.\n");
        printf("Iniciar a [C]onstrução de uma seção.\n");
        printf("================================================\n\n");

        fgets(Escolha, 10, stdin);

        // Remover o \n se presente
        size_t len = strlen(Escolha);
        if (len > 0 && Escolha[len - 1] == '\n') {
            Escolha[len - 1] = '\0';
        }

        if (strcmp(Escolha, "T") == 0) {
            printf("Menu Torre\n");
            MenuTorre(TorreAlt, TorreEst, TorreOrn);
        } else if (strcmp(Escolha, "R") == 0) {
            printf("Menu Recursos\n");
            MenuRecursos(&RecMad, &RecPed, &RecCri, &TempoDias);
        } else if (strcmp(Escolha, "C") == 0) {
            printf("Menu Construção\n");
            MenuConstrucao(&TorreAlt, &TorreEst, &TorreOrn,&RecMad, &RecPed, &RecCri, &TempoDias);

        } else {
            printf("Por favor escolha entre as opções T, R ou C!\n\n");
        }
    }
}

int main() {
    int* TorreAlt = 0;
    int* TorreEst = 25;
    int* TorreOrn = 0;
    int* RecMad = 0;
    int* RecPed = 0;
    int* RecCri = 0;
    int* TempoDias = 365;

    printf("Inicializando STONE...\n\n");
    printf("Variáveis resetadas para valores iniciais\n\n");

    MenuPrincipal(TorreAlt, TorreEst, TorreOrn, RecMad, RecPed, RecCri, TempoDias);

    return 0;
}
