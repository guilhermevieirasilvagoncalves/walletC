#include <stdio.h>
#include <stdlib.h>


void menu();

void addMovimentation();
void deposite();
void statementMOR();
void statementEST();
void statementTRANS();
void statementALIM();
void statementTRAB();
void invest();
void annualstatement();
void closeprog();
void addMORADIA();
void addESTUDOS();
void addTRANSPORTE();
void addALIMENTACAO();
void addTRABALHO();


struct wallet{
    int day;
    int month;
    int year;
}
    wallet;
    user;
void menu() {
    int num;
    printf("--------------------------------------");
    printf("Seja Bem Vindo a sua carteira digital!");
    printf("--------------------------------------");
    printf("Por favor selecione uma opção:");
    printf("1. Depositar");
    printf("2. Registrar nova movimentação");
    printf("3. Extrato Anual");
    printf("4. Extrato do mês no seguimento MORADIA");
    printf("5. Extrato do mês no seguimento ESTUDOS");
    printf("6. Extrato do mês no seguimento TRANSPORTE");
    printf("7. Extrato do mês no seguimento ALIMENTAÇÃO");
    printf("8. Extrato do mês no seguimento TRABALHO");
    printf("9. Investimentos");
    printf("10.");
    printf("11. Resetar carteira ");
    printf("12. Sair");
    printf("--------------------------------------");
    printf(" \n Digite a opção desejada: ");
    scanf("%d", &num);
    if(num == 1){
        deposite();
    }
    else if(num == 2){
                printf(" \n Movimentações: ");
                printf(" \n 13. MORADIA" );
                printf(" \n 14. ESTUDOS" );
                printf(" \n 15. TRANSPORTE" );
                printf(" \n 16. ALIMENTAÇÃO" );
                printf(" \n 17. TRABALHO ");
                printf(" \n 18. Voltar ao menu principal \n ");
                printf(" \n Selecione a opção de movimentação: ");
                scanf("%d", &num);
                switch(num){
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
                        addALIMENTACAO();
                        break;
                    case 17:
                        addTRABALHO();
                        break;
                    case 18:
                        menu();
                        break;
                }
    }
    else if(num == 3){
        annualstatement();
    }
    else if(num == 4){
        statementMOR();
    }
    else if(num == 5){
        statementEST();
    }
    else if(num == 6){
        statementTRANS();
    }
    else if(num == 7){
        statementALIM();
    }
    else if(num == 8){
        statementTRAB();
    }
    else if(num == 9){
        invest();
    }
    else if(num == 10){
        printf("Opção em desenvolvimento");
    }
    else if(num == 11){
        printf("Opção em desenvolvimento");
    }
    else if(num == 12){
        closeprog();
    }
    else if(num > 18){
        printf("Opção Invalida, Por favor selecione outra opção");
    }
}