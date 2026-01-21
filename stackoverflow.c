#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Funcao que causará um stack overflow
void stack_overflow(int count) {

    char buffer[1024]; // Variável local (stack)
        printf("Recursion depth: %d\n", count);
    
    //Chamada recursiva, cada recursão cria um novo stackframe
    stack_overflow(count + 1);

}

//main function
int main() {
    printf("PID do processo: %d\n", getpid());

    int *heap_array = malloc(100* sizeof(int)); //memória alocada no heap

    if (heap_array == NULL) {
        fprintf(stderr, "Falha na alocação de memória no heap\n");
        return 1;
    }

    //preenche o heap
    for (int i = 0; i < 100; i++) {
        heap_array[i] = i;
    }

    printf("Heap alocado em: %p\n", heap_array);

    printf("Iniciando a função que causará stack overflow...\n");

    int count = 1;

    stack_overflow(1);

    //libera a memória alocada no heap
    free(heap_array);
    return 0;

}