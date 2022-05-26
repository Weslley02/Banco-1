#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct NO {
  char letra1;
  char letra2;
  char letra3;
  char letra4;
  int num;
  struct NO *prox;
} NO;
typedef struct Fila {
  NO *primeiro;
  NO *ultimo;
} Fila;
void inicializaFila(Fila *f) {
  f->primeiro = NULL;
  f->ultimo = NULL;
}
void enfileira(char letra1, char letra2, char letra3, char letra4, int num,
               Fila *f) {
  NO *ptr =
      (NO *)malloc(sizeof(NO));
  if (ptr == NULL) {
    printf("Erro de alocação");
    return;
  } else {
    ptr->letra1 = letra1;
    ptr->letra2 = letra2;
    ptr->letra3 = letra3;
    ptr->letra4 = letra4;
    ptr->num = num;
    ptr->prox = NULL;
    if (f->primeiro == NULL) {
      f->primeiro = ptr;
    } else {
      f->ultimo->prox = ptr;
    }
    f->ultimo = ptr;
    return;
  }
}
void desenfileira(Fila *f) {
  NO *ptr = f->primeiro;        
  char letra1;              
  char letra2;
  char letra3;
  char letra4;
  int num;
  if (ptr != NULL) {
    f->primeiro = ptr->prox;
    ptr->prox = NULL;
    letra1 = ptr->letra1;
    letra2 = ptr->letra2;
    letra3 = ptr->letra3;
    letra4 = ptr->letra4;
    num = ptr->num;
    free(ptr);
    if (f->primeiro == NULL) {
      f->ultimo = NULL;
    }
    printf("%c%c %d ", letra1, letra2, letra3, letra4, num);
  } else {
    printf("\nFila vazia");
  }
}
void imprimeFila(Fila *f) {
  NO *ptr = f->primeiro;  
  if (ptr != NULL) {
    while (ptr != NULL) {
      printf("-> %c%c %d \n", ptr->letra1, ptr->letra2, ptr->letra3, ptr->letra4, ptr->num);
      ptr = ptr->prox;
    }
  } else {
    printf("\nFila vazia.");
    return;
  }
}
void detroiFila(Fila *f) {
 NO *ptr = f->primeiro;          
                   
  if (ptr != NULL) {
    f->primeiro = ptr->prox;
    free(ptr);
    if (f->primeiro == NULL) {
      f->ultimo = NULL;
    }
    printf("Fila iniciada");
  } else {
    printf("Fila destruida");
  }
}
void chamarClienteParaAtendimento(Fila *f) {
  NO *ptr = f->primeiro;  
  if (ptr != NULL) {
    printf("%c%c %d ", ptr->letra1, ptr->letra2, ptr->letra3, ptr->letra4, ptr->num);
  } else {
    printf("\nNão há cliente prioritario");
    return;
  }
}
void tamanhofila(Fila *f) {
  NO *ptr = f->primeiro;
  int cont = 0;
  if (ptr != NULL) {
    while (ptr != NULL) {
      cont++;
      ptr = ptr->prox;
    }
    printf("Número de cliente id. é %i", cont);
  } else {
    printf("\nNão é possivel atender.");
    return;
  }
}
int main(void) {
  Fila *atendimento = (Fila *)malloc(sizeof(Fila));
  Fila *clientePrioritario = (Fila *)malloc(sizeof(Fila));
  if (atendimento == NULL || clientePrioritario == NULL) {
    printf("Erro de alocação");
    exit(-1);
  } else {
    inicializaFila(atendimento);
    inicializaFila(clientePrioritario);
    int op, dp, n;
    char l1, l2, l3,l4;
    do {
      printf("       Atendimento com prioridade       \n");
      printf("1- Atendimento cliente com prioridade     \n");
      printf("2- Atendimento cliente normal             \n");
      printf("Informe o seu numero: ");
      scanf("%i", &op);
      switch (op) {
      case 1:
        printf("Deseja adicionar um numero de atendimento na fila de: \n");
        printf("1- AtendimentoClientePrioridade\n2-AtendimentoClienteNormal\n->");
        scanf("%i", &dp);
        if (dp == 1) {
          printf("Cliente normal...\n");
          printf("Informe o numero do cliente: \n");
          printf("Informe a primeira letra: ");
          scanf("%c", &l1);
          l1 = getchar();
          printf("Informe a segunda letra: ");
          scanf("%c", &l2);
          l2 = getchar();
          printf("Informe o numero de identificação:");
          scanf("%i", &n);
          getchar();
          getchar();
          enfileira(l1, l2, l3, l4, n, atendimento);
        } else if (dp == 2) {
          printf("Cliente com prioridade...\n");
          printf("Informe o numero do cliente prioritario: \n");
          printf("Informe a primeira letra: ");
          scanf("%c", &l1);
          l1 = getchar();
          printf("Informe a segunda letra: ");
          scanf("%c", &l2);
          l2 = getchar();
          printf("Informe o numero de identificação:");
          scanf("%i", &n);
          getchar();
          enfileira(l1, l2, l3, l4, n, clientePrioritario);
        } else {
          printf("Opção inválida!\nTente novamente!");
        }
        break;
      case 2:
        printf("Deseja Listar os clientes da fila de: \n");
        printf("1- AtendimentoClienteNormal\n2-AtendimentoClienteComPrioridade\n->");
        scanf("%i", &dp);
        if (dp == 1) {
          printf("Atendimento de Cliente normal...\n");
          imprimeFila(atendimento);
        } else if (dp == 2) {
          printf("Atendimento de Cliente com prioridade...\nInforme o numero de identificação:");
          imprimeFila(clientePrioritario);
        } else {
          printf("Opção inválida!\nTente novamente!");
        }
        break;
      case 3:
        printf("Número de clientes da fila de: \n");
        printf("1- AtendimentoClienteComPrioridade\n2-AtendimentoClienteNormal\n->");
        scanf("%i", &dp);
        if (dp == 1) {
          printf("AtendimentoClienteComPrioridade...\n");
          tamanhofila(atendimento);
        } else if (dp == 2) {
          printf("AtendimentoClienteNormal...\n");
          tamanhofila(clientePrioritario);
        } else {
          printf("Opção inválida!\nTente novamente!");
        }
        break;
      case 0:
      printf("Finalizando Programa...\n\n");
      printf("Destruindo fila de AtendimentoClienteNormal...\n");
      detroiFila(clientePrioritario);
      printf("\nImprimindo fila de clientePrioritario: ");
      imprimeFila(clientePrioritario);
      printf("\n\nDestruindo fila de AtendimentoClienteComPrioridade...\n");
      detroiFila(atendimento);
      printf("\nImprimindo fila de atendimento: ");
      imprimeFila(atendimento);
        break;
      default:
        printf("Opção inválida!\nTente novamente!");
      }
    } while (op != 0);
  }
  return 0;
}