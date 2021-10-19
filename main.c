#include <stdio.h>
#include <stdlib.h>

void menu();

void addmovimentação();
void deposito();
void extratoMOR();
void extratoEST();
void extratoTRANS();
void extratoALIM();
void extratoTRAB();
void extratoanual();

void addMORADIA();
void addESTUDOS();
void addTRANSPORTE();
void addALIMENTAÇÃO();
void addTRABALHO();

void investimento();
void fecharprog();

int main(){
    menu();
}

void menu() {
    int num;
    printf("--------------------------------------\n");
    printf("Seja Bem Vindo a sua carteira digital!\n");
    printf("--------------------------------------\n");
    printf("Por favor selecione uma opção:\n");
    printf("1. Depositar\n");
    printf("2. Registrar nova movimentação\n");
    printf("3. Extrato Anual\n");
    printf("4. Extrato do mês no seguimento MORADIA\n");
    printf("5. Extrato do mês no seguimento ESTUDOS\n");
    printf("6. Extrato do mês no seguimento TRANSPORTE\n");
    printf("7. Extrato do mês no seguimento ALIMENTAÇÃO\n");
    printf("8. Extrato do mês no seguimento TRABALHO\n");
    printf("9. Investimentos\n");
    printf("10.\n");
    printf("11. Resetar carteira\n");
    printf("12. Sair\n");
    printf("--------------------------------------\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &num);
    if (num == 1) {
        deposito();
    }
    else if (num == 2) {
        printf(" \n Movimentações: ");
        printf(" \n 13. MORADIA");
        printf(" \n 14. ESTUDOS");
        printf(" \n 15. TRANSPORTE");
        printf(" \n 16. ALIMENTAÇÃO");
        printf(" \n 17. TRABALHO ");
        printf(" \n 18. Voltar ao menu principal \n ");
        printf(" \n Selecione a opção de movimentação: ");
        scanf("%d", &num);
        switch (num) {
        case 13:
            addMORADIA();
            break;
        case 14:
            addESTUDOS();
            break;
        case 15:
            addTRANSPORTE();
            break;
        case 16:
            addALIMENTAÇÃO();
            break;
        case 17:
            addTRABALHO();
            break;
        case 18:
            menu();
            break;
        }
    }
    else if (num == 3) {
        extratoanual();
    }
    else if (num == 4) {
        extratoMOR();
    }
    else if (num == 5) {
        extratoEST();
    }
    else if (num == 6) {
        extratoTRANS();
    }
    else if (num == 7) {
        extratoALIM();
    }
    else if (num == 8) {
        extratoTRAB();
    }
    else if (num == 9) {
        investimento();
    }
    else if (num == 10) {
        printf("Opção em desenvolvimento");
    }
    else if (num == 11) {
        printf("Opção em desenvolvimento");
    }
    else if (num == 12) {
        fecharprog();
    }
    else if (num > 18) {
        printf("Opção Invalida, Por favor selecione outra opção");
        menu();
    }
}

void addmovimentação(){

}

void deposito(){

}

void extratoMOR(){

}

void extratoEST(){

}

void extratoTRANS(){

}

void extratoALIM(){

}

void extratoTRAB(){

}

void extratoanual(){

}

void addMORADIA(){

}

void addESTUDOS(){

}

void addTRANSPORTE(){

}

void addALIMENTAÇÃO(){
  
}

void addTRABALHO(){

}

void investimento(){

}

void fecharprog() {
    exit(0);
}