#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void menu();
void registromovimentacao();
void deposito();
void resetarcarteira();
void extratoanual();
void extratomensal();
void emprestimo();
void cambio();
void fecharprog();


struct data{
    int dia;
    int mes;
    int ano;
}data;

struct dados{
    float depositar;
    float saldo;
    float gasto;
    int categoria;
}dados;

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
    printf("4. Extrato do mês em cada seguimento \n");
    printf("5. Câmbio\n");
    printf("6. Empréstimos\n");
    printf("7. Resetar carteira\n");
    printf("8. Sair\n");
    printf("--------------------------------------\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &num);
    if (num == 1) {
        deposito();
    }
    else if (num == 2) {
        registromovimentacao();
    }
    else if (num == 3) {
        extratoanual();
    }
    else if(num == 4){
        extratomensal();
    }
    else if (num == 5) {
        cambio();
    }
    else if (num == 6) {
        emprestimo();
    }
    else if(num == 7){
        resetarcarteira();
    }
    else if (num == 8) {
        fecharprog();
    }
    else if (num >= 9) {
        printf("Opção Invalida, Por favor selecione outra opção");
        menu();
    }
}

void deposito(){
    FILE *file = fopen("gerenciador_financeiro.txt","a");
    int i;
    printf("--------------------------------------\n");
    printf("              DEPOSITAR               \n");
    printf("--------------------------------------\n");
    printf("Digite o valor a ser depositado: \n");
    printf("R$ ");scanf("%f",&dados.depositar);
    printf("");
    printf("\nDigite a data do depósito\n");
    printf("");
    printf("\nDia:");
    scanf("%d",&data.dia);
    printf("\nMês:");
    scanf("%d",&data.mes);
    printf("\nAno:");
    scanf("%d",&data.ano);

    FILE *saldo = fopen("saldo.txt","a");
    fprintf(saldo," %.2f", dados.depositar);
    fclose(saldo);
    printf("");
    printf("\nDepósito realizado com sucesso!\n");
    printf("");
    FILE *deposito = fopen("gerenciadorReceita.txt","a");
    fprintf(file,"");
    fprintf(file,"|Receita");
    fprintf(file," |Valor: R$ %.2f", dados.depositar);
    fprintf(file," |Data: %d ", data.dia);
    fprintf(file,"/ %d ", data.mes);
    fprintf(file,"/ %d", data.ano);

    fprintf(deposito,"1");
    fprintf(deposito," %.2f", dados.depositar);
    fprintf(deposito," %d", data.dia);
    fprintf(deposito," %d", data.mes);
    fprintf(deposito," %d\n", data.ano);
    fclose(file);
    fclose(deposito);
    int num;
    printf("\nDeseja realizar outra operação?\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n");
    scanf("%d",&num);

    switch(num){
        case 1:
        menu();
        case 2: 
        fecharprog();
    }

    }

void registromovimentacao(){
    FILE *file = fopen("gerenciador_financeiro.txt","a");
    int i;
    printf("--------------------------------------\n");
    printf("       REGISTRAR NOVA MOVIMENTAÇÃO    \n");
    printf("--------------------------------------\n");
    printf("Digite o valor gasto: \n");
    printf("R$ ");scanf("%f",&dados.gasto);
    printf("\nDigite a data da movimentação\n");
    printf("");
    printf("\nDia:");
    scanf("%d",&data.dia);
    printf("\nMês:");
    scanf("%d",&data.mes);
    printf("\nAno:");
    scanf("%d",&data.ano);
    if(data.dia < 0 || data.dia > 31){
        printf("O número colocado no campo Dia é invalido, por favor coloque outro número:\n");
        scanf("%d",&data.dia);
    }
    if(data.mes < 0 || data.mes > 12){
        printf("O número colocado no campo Mês é invalido, por favor coloque outro número:\n");
        scanf("%d",&data.mes);
    }
    if(data.ano < 0){
        printf("O número colocado no campo Ano é invalido, por favor coloque outro número:\n");
        scanf("%d",&data.ano);
    }
    printf(" \n 1. MORADIA");
    printf(" \n 2. ESTUDOS");
    printf(" \n 3. TRANSPORTE");
    printf(" \n 4. ALIMENTAÇÃO");
    printf(" \n 5. TRABALHO ");
    printf("\n");
    printf("\nDigite o número da categoria da movimentação: \n");
    printf("\n");
    scanf("%d",&dados.categoria);
    printf("");
    printf("\nMovimentação realizada com sucesso!\n");
    printf("");
    FILE *gasto = fopen("gerenciadorGasto.txt","a");
    fprintf(file,"==============================================================================\n");
    fprintf(file,"|Gasto");
    fprintf(file," |Valor: R$ -%.2f", dados.gasto);
            if(dados.categoria == 1){
            fprintf(file," |Categoria: Moradia");
            }
            if(dados.categoria == 2){
            fprintf(file," |Categoria: Estudos");
            }
            if(dados.categoria == 3){
            fprintf(file," |Categoria: Transportes");
            }
            if(dados.categoria == 4){
            fprintf(file," |Categoria: Alimentacao");
            }
            if(dados.categoria == 5){
            fprintf(file," |Categoria: Trabalho");
            }
    fprintf(file," |Data: %d ", data.dia);
    fprintf(file,"/ %d ", data.mes);
    fprintf(file,"/ %d", data.ano);

    fprintf(gasto,"2");
    fprintf(gasto," -%.2f", dados.gasto);
    fprintf(gasto," %d", dados.categoria);
    fprintf(gasto," %d", data.dia);
    fprintf(gasto," %d", data.mes);
    fprintf(gasto," %d\n", data.ano);
    fclose(file);
    fclose(gasto);
    int num;
    printf("\nDeseja realizar outra operação?\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n");
    scanf("%d",&num);

    switch(num){
        case 1:
        menu();
        case 2: 
        fecharprog();
    }

}


void extratoanual(){
    int ano;
    FILE *cssanual = fopen("estilo.css","w");
    fprintf(cssanual,".a{font-family: 'Arial Black';color:black;text-align: center;align-content: center;font-size: 30pt;}.t{font-family: 'Arial Black';color:darkred;text-align: center;font-size: 12pt;}.e{font-family: 'Arial Black';color:darkred;font-size: 15pt;text-align: center;}table{text-align:center;border-color: red;border-style: solid;background-color: black;}.body{background-color: darkblue;}");
    FILE *arqhtmlanual = fopen("anual.html","w");
    fprintf(arqhtmlanual,"<!DOCTYPE html>");
    fprintf(arqhtmlanual,"<html>");
    fprintf(arqhtmlanual,"<head><meta charset='UTF-8'><title>Estrato Anual</title><link href='estilo.css'rel='stylesheet'></head><body class='body' align='center'> <a class='a' >Extrato Anual</a><br>");
    fprintf(arqhtmlanual,"<table border='2' align='left' ><tr class='e'><td>Cadastro</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
    FILE *file = fopen("gf.txt","r");


    printf("--------------------------------------\n");
    printf("             EXTRATO ANUAL            \n");
    printf("--------------------------------------\n");
    printf("\n Digite o ano do extrato a ser emitido: \n");
    scanf("%d",&ano);
    int r = 0;
    float x;
    float v[1000];

    int i=0;

    int z = 0;
    float a;
    float v2[1000];
    int n = 0;

    for (i = 0;(fscanf(file, "%f", &x)) != EOF;) {
    v[i] = x;
    for(r=0; v[r]!= 0;){
    if(v[i] == ano && r % 5 == 0){
        i = i-5;

        fprintf(arqhtmlanual,"<tr class='t'>");
        fprintf(arqhtmlanual,"<td> Receita </td>");
        i = i+1;
        fprintf(arqhtmlanual,"<td> R$%.2f </td>",v[i]);
        i = i+1;
        if(v[i]== 1){
          fprintf(arqhtmlanual,"<td> Moradia </td>");
        }
        if(v[i]== 2){
          fprintf(arqhtmlanual,"<td> Estudos </td>");
        }
        if(v[i]== 3){
          fprintf(arqhtmlanual,"<td> Transportes </td>");
        }
        if(v[i]== 4){
          fprintf(arqhtmlanual,"<td> Alimentacao </td>");
        }
        if(v[i]== 5){
          fprintf(arqhtmlanual,"<td> Trabalho </td>");
        }
        i = i+1;
        fprintf(arqhtmlanual,"<td> %.0f ",v[i]);
        i = i+1;
        fprintf(arqhtmlanual," / %.0f ",v[i]);
        i = i+1;
        fprintf(arqhtmlanual," / %.0f ",v[i]);
        fprintf(arqhtmlanual,"</td>");
        fprintf(arqhtmlanual,"</tr>");
      i++;
    }
  r++;
    }

 i++;
  }
  fprintf(arqhtmlanual,"</table>" );

fprintf(arqhtmlanual,"<table border='2' align='40px' ><tr class='e'><td>Cadastro</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
for (n = 0;(fscanf(file, "%f", &a)) != EOF;) {
    v2[n] = a;
    for(z=0; v2[z]!= 0;){
    if(v2[n] == ano && z % 5 == 0){
        n = n-5;
        fprintf(arqhtmlanual,"<tr class='t'>");
        fprintf(arqhtmlanual,"<td> Gasto </td>");
        n = n+1;
        fprintf(arqhtmlanual,"<td> R$%.2f </td>",v2[n]);
        n = n+1;
        if(v2[n]== 1){
          fprintf(arqhtmlanual,"<td> Moradia </td>");
        }
        if(v2[n]== 2){
          fprintf(arqhtmlanual,"<td> Estudos </td>");
        }
        if(v2[n]== 3){
          fprintf(arqhtmlanual,"<td> Transportes </td>");
        }
        if(v2[n]== 4){
          fprintf(arqhtmlanual,"<td> Alimentacao </td>");
        }
        if(v2[n]== 5){
          fprintf(arqhtmlanual,"<td> Trabalho </td>");
        }
        n = n+1;
        fprintf(arqhtmlanual,"<td> %.0f ",v2[n]);
        n = n+1;
        fprintf(arqhtmlanual," / %.0f ",v2[n]);
        n = n+1;
        fprintf(arqhtmlanual," / %.0f ",v2[n]);
        fprintf(arqhtmlanual,"</td>");
        fprintf(arqhtmlanual,"</tr>");
      n++;
    }

  z++;
    }

 n++;
  }
    fprintf(arqhtmlanual,"</table>" );
    fprintf(arqhtmlanual,"</body></html>");
    fclose(cssanual);
    fclose(file);
    fclose(arqhtmlanual);
}

void extratomensal(){

}

void cambio(){

}

void emprestimo(){

}

void resetarcarteira(){
    int opção,num;
    printf("--------------------------------------\n");
    printf("           RESETAR CARTEIRA           \n");
    printf("--------------------------------------\n");
    printf("Esta opção serve para deletar todas as informações da carteira, deseja prosseguir? \n");
    printf("1 - SIM \n");
    printf("2 - NÃO \n");
    scanf("%d",&opção);
    if(opção == 1){
      remove("gerenciador_financeiro.txt");
      remove("gerenciadorReceita.txt");
      remove("gerenciadorGasto.txt");
      remove("saldo.txt");
      printf("");
      printf("Resetando dados ....\n");
      printf("");
      sleep(2);
      printf("Dados resetados com sucesso!\n");
      printf("\nDeseja realizar outra operação?\n");
      printf("1 - SIM\n");
      printf("2 - NÃO\n");
      scanf("%d",&num);
      switch(num){
          case 1:
          menu();
          case 2: 
          fecharprog();
      }
    }
    else if(opção == 2){
      printf("Certo, retornando para o menu... \n");
      sleep(1);
      menu();
    }
}

void fecharprog() {
  sleep(2);
  printf("\n Até mais! Saindo...");
  exit(0);
}