#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>

void menu();
void registromovimentacao();
void deposito();
void resetarcarteira();
void extratoanual();
void extratomensal();
void emprestimo();
void loteria();
void fecharprog();
void saldo();

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
    float emprestimo;
}dados;

int main(){
    setlocale(LC_ALL,"portuguese");
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
    printf("5. Saldo\n");
    printf("6. Loteria\n");
    printf("7. Empréstimos\n");
    printf("8. Resetar carteira\n");
    printf("9. Sair\n");
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
        saldo();
    }
    else if (num == 6) {
        loteria();
    }
    else if (num == 7) {
        emprestimo();
    }
    else if(num == 8){
        resetarcarteira();
    }
    else if (num == 9) {
        fecharprog();
    }
    else if (num >= 10) {
        printf("Opção Invalida, Por favor selecione outra opção");
        menu();
    }
}

void deposito(){
    FILE *file = fopen("gerenciador_financeiro.txt","a");
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
    fprintf(deposito," 1");
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
    FILE *htmlanual = fopen("relatorio_12meses.html","w");
    FILE *gasto = fopen("gerenciadorGasto.txt","r");
    FILE *deposito = fopen("gerenciadorReceita.txt","r");
    printf("--------------------------------------\n");
    printf("             EXTRATO ANUAL            \n");
    printf("--------------------------------------\n");
    printf("\nDigite o ano do extrato a ser emitido: \n");
    scanf("%d", &ano);
    int r = 0;
    float x;
    float v[1000];
    int i=0;
    int z = 0;
    float a;
    float v2[1000];
    int n = 0;
    float y;
    int d = 0;
    int t =0;

    fprintf(htmlanual,"<!DOCTYPE html>");
    fprintf(htmlanual,"<html>");
    fprintf(htmlanual,"<head><meta charset='UTF-8'><title>Relatorio Anual</title><link href='estilo.css'rel='stylesheet'></head><body class='body' align='center'> <a class='a' >Relatorio Anual</a><br>");
    fprintf(htmlanual,"<table border='2' align='left' ><tr class='e'><td>Tipo de Movimentação</td><td>Valor</td><td>Data</td></tr>");
    for (i = 0;(fscanf(deposito, "%f", &x)) != EOF;) {
        v[i] = x;
        for(r=0; v[r]!= 0;){
        if(v[i] == ano && r % 5 == 0){
            i = i-5;
            fprintf(htmlanual,"<tr class='t'>");
            fprintf(htmlanual,"<td> Entrada </td>");
            i = i+1;
            fprintf(htmlanual,"<td> R$%.2f </td>",v[i]);
            i = i+1;
            if(v[i]== 1){
            fprintf(htmlanual,"");
            }
            i = i+1;
            fprintf(htmlanual,"<td> %.0f ",v[i]);
            i = i+1;
            fprintf(htmlanual," / %.0f ",v[i]);
            i = i+1;
            fprintf(htmlanual," / %.0f ",v[i]);
            fprintf(htmlanual,"</td>");
            fprintf(htmlanual,"</tr>");
        i++;
        }
    r++;
        }

    i++;
    }
    fprintf(htmlanual,"</table>" );

fprintf(htmlanual,"<table border='2' align='40px' ><tr class='e'><td>Tipo de Movimentação</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
for (n = 0;(fscanf(gasto, "%f", &a)) != EOF;) {
    v2[n] = a;
    for(z=0; v2[z]!= 0;){
    if(v2[n] == ano && z % 5 == 0){
        n = n-5;
        fprintf(htmlanual,"<tr class='t'>");
        fprintf(htmlanual,"<td> Saída </td>");
        n = n+1;
        fprintf(htmlanual,"<td> R$%.2f </td>",v2[n]);
        n = n+1;
        if(v2[n]== 1){
          fprintf(htmlanual,"<td> Moradia </td>");
        }
        if(v2[n]== 2){
          fprintf(htmlanual,"<td> Estudos </td>");
        }
        if(v2[n]== 3){
          fprintf(htmlanual,"<td> Transportes </td>");
        }
        if(v2[n]== 4){
          fprintf(htmlanual,"<td> Alimentacao </td>");
        }
        if(v2[n]== 5){
          fprintf(htmlanual,"<td> Trabalho </td>");
        }
        n = n+1;
        fprintf(htmlanual,"<td> %.0f ",v2[n]);
        n = n+1;
        fprintf(htmlanual," / %.0f ",v2[n]);
        n = n+1;
        fprintf(htmlanual," / %.0f ",v2[n]);
        fprintf(htmlanual,"</td>");
        fprintf(htmlanual,"</tr>");
      n++;
    }

  z++;
    }

 n++;
  }
  fprintf(htmlanual,"</table>" );
fprintf(htmlanual,"</body></html>");
  fclose(deposito);
  fclose(gasto);
  fclose(htmlanual);
  printf("\nExtrato Anual em HTML e CSS criado\n");
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

void extratomensal(){
    int ano, mes, categoria;
    printf("--------------------------------------\n");
    printf("             EXTRATO MENSAL           \n");
    printf("--------------------------------------\n");
    FILE *mensalhtml = fopen("relatorio_mensal_categoria.html","w");
    FILE *gasto = fopen("gerenciadorGasto.txt","r");
    FILE *deposito = fopen("gerenciadorReceita.txt","r");
    printf("\nInsira o ano do extrato a ser emitido: \n");
    scanf("%d", &ano);
    printf("\nInsira o mês do extrato a ser emitido: \n");
    scanf("%d", &mes);
    printf("\nInsira a categoria do extrato a ser emitido: \n");
    printf(" \n 1. MORADIA");
    printf(" \n 2. ESTUDOS");
    printf(" \n 3. TRANSPORTE");
    printf(" \n 4. ALIMENTAÇÃO");
    printf(" \n 5. TRABALHO \n");
    scanf("%d", &categoria);

      int r = 0;
      float x;
      float v[1000];
      int i=0;
      int z = 0;
      float a;
      float v2[1000];
      int n = 0;
      fprintf(mensalhtml,"<!DOCTYPE html>");
      fprintf(mensalhtml,"<html>");
      fprintf(mensalhtml,"<head><meta charset='UTF-8'><title>Relatorio Mensal</title><link href='estilo.css'rel='stylesheet'></head><body class='body' align='center'> <a class='a' >Relatorio Mensal por categoria</a><br>");
      fprintf(mensalhtml,"<table border='2' align='left' ><tr class='e'><td>Tipo de Movimentação</td><td>Valor</td><td>Data</td></tr>");
      for (i = 0;(fscanf(deposito, "%f", &x)) != EOF;) {
        v[i] = x;
        for(r=0; v[r]!= 0;){
        if(v[i] == ano && r == 5){
            i = i-1;
            if(v[i] == mes){
              i = i-2;
              if(v[i] == categoria){
                i = i - 2;
            fprintf(mensalhtml,"<tr class='t'>");
            fprintf(mensalhtml,"<td> Entrada </td>");
            i = i+1;
            fprintf(mensalhtml,"<td> R$%.2f </td>",v[i]);
            i = i+1;
            if(v[i]== 1){
              fprintf(mensalhtml,"");
            }
            i = i+1;
            fprintf(mensalhtml,"<td> %.0f ",v[i]);
            i = i+1;
            fprintf(mensalhtml," / %.0f ",v[i]);
            i = i+1;
            fprintf(mensalhtml," / %.0f ",v[i]);
            fprintf(mensalhtml,"</td>");
            fprintf(mensalhtml,"</tr>");
          i++;
              }
            }

        }
      r++;
        }
    i++;
      }
        fprintf(mensalhtml,"</table>" );
        fprintf(mensalhtml,"<table border='2' align='left' ><tr class='e'><td>Tipo de Movimentação</td><td>Valor</td><td>Categoria</td><td>Data</td></tr>");
        for (n = 0;(fscanf(gasto, "%f", &a)) != EOF;) {
          v2[n] = a;
          for(z=0; v2[z]!= 0;){
          if(v2[n] == ano && z == 5){
              n = n-1;
              if(v2[n]== mes){
                n = n-2;
                if(v2[n]== categoria){
                  n = n - 2;
                  fprintf(mensalhtml,"<tr class='t'>");
              fprintf(mensalhtml,"<td> Saída </td>");
              n = n+1;
              fprintf(mensalhtml,"<td> R$%.2f </td>",v2[n]);
              n = n+1;
              if(v2[n]== 1){
                fprintf(mensalhtml,"<td> Moradia </td>");
              }
              if(v2[n]== 2){
                fprintf(mensalhtml,"<td> Estudos </td>");
              }
              if(v2[n]== 3){
                fprintf(mensalhtml,"<td> Transportes </td>");
              }
              if(v2[n]== 4){
                fprintf(mensalhtml,"<td> Alimentacao </td>");
              }
              if(v2[n]== 5){
                fprintf(mensalhtml,"<td> Trabalho </td>");
              }
              n = n+1;
              fprintf(mensalhtml,"<td> %.0f ",v2[n]);
              n = n+1;
              fprintf(mensalhtml," / %.0f ",v2[n]);
              n = n+1;
              fprintf(mensalhtml," / %.0f ",v2[n]);
              fprintf(mensalhtml,"</td>");
              fprintf(mensalhtml,"</tr>");
            n++;
                }
              }

          }
        z++;
          }

      n++;
        }
      fprintf(mensalhtml,"</table>" );
      fprintf(mensalhtml,"</body></html>");
      fclose(deposito);
      fclose(gasto);
      fclose(mensalhtml);
      printf("\nExtrato Anual em HTML e CSS criado\n");
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

void saldo(){
  printf("--------------------------------------\n");
  printf("                  SALDO               \n");
  printf("--------------------------------------\n");
  printf("Consultando seu saldo ...\n");
  sleep(1);
  FILE *gasto = fopen("gerenciadorGasto.txt","a");
  FILE *saldo = fopen("saldo.txt","a");
  FILE *gastor = fopen("gerenciadorGasto.txt","r");
  FILE *s= fopen("saldo.txt","r");
  int z = 0;
  float a,x;
  float v2[1000], v[1000];
  int n = 0, m =0;
  int b = 0;
  float aux_soma=0.0, aux_soma2=0.0;
  for (m = 0;(fscanf(s, "%f", &x)) != EOF;) {
    v[m] = x;
        aux_soma2 = v[m] + aux_soma2;
 m++;
  }

  for (n = 0;(fscanf(gastor, "%f", &a)) != EOF;) {
    v2[n] = a;

    for(z=0; v2[z]!= 0;){

    if(v2[n] < 0&&z == 1){

        aux_soma = v2[n] + aux_soma;
      n++;

    b++;}
    z++;}

 n++;

  }
  float aux = aux_soma2 + aux_soma;
  printf("\n");
  printf("Seu saldo é de: R$%.2f \n",(aux_soma2 + aux_soma));
  fclose(gastor);
  fclose(s);
  fclose(gasto);
  fclose(saldo);
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

void loteria(){
  int num1, num2, num3;
  float premio = 1000.00;
  int ent1, ent2, ent3;
  srand(time(NULL));
  num1 = rand() % 7;
  num2 = rand() % 7;
  num3 = rand() % 7;
  printf("--------------------------------------\n");
  printf("                 LOTERIA              \n");
  printf("--------------------------------------\n");
  printf("Digite três valores (inteiros entre 0 a 6): \n");
  printf("Valor 1: ");scanf("%d",&ent1);
  printf("\n");
  printf("Valor 2: ");scanf("%d",&ent2);
  printf("\n");
  printf("Valor 3: ");scanf("%d",&ent3);
  printf("\n");
  printf("Processando...\n");
  sleep(1);
  if(ent1 == num1 && ent2 == num2 && ent3 == num3){
    printf("\nParabéns!!!!\n");
    printf("Você ganhou o prêmio de R$ 1000,00\n");
    printf("\nPor Favor, digite a data:\n");
    printf("");
    printf("\nDia:");
    scanf("%d",&data.dia);
    printf("\nMês:");
    scanf("%d",&data.mes);
    printf("\nAno:");
    scanf("%d",&data.ano);
    FILE *file = fopen("gerenciador_financeiro.txt","a");
    FILE *saldo = fopen("saldo.txt","a");
    fprintf(saldo," %.2f", premio);
    fclose(saldo);
    FILE *deposito = fopen("gerenciadorReceita.txt","a");
    fprintf(file,"");
    fprintf(file,"|Loteria");
    fprintf(file," |Valor: R$ %.2f", premio);
    fprintf(file," |Data: %d ", data.dia);
    fprintf(file,"/ %d ", data.mes);
    fprintf(file,"/ %d", data.ano);
    fprintf(deposito,"1");
    fprintf(deposito," %.2f", premio);
    fprintf(deposito," 1");
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
  else{
    printf("Que pena, não foi dessa vez que você ganhou o prêmio\n");
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
}

void emprestimo(){
  FILE *file = fopen("gerenciador_financeiro.txt","a");
    printf("--------------------------------------\n");
    printf("               EMPRÉSTIMO             \n");
    printf("--------------------------------------\n");
    printf("Digite o valor que você deseja solicitar: \n");
    printf("R$ ");scanf("%f",&dados.emprestimo);
    printf("\nDigite a data do empréstimo\n");
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
    printf("\nEmpréstimo realizado com sucesso!\n");
    FILE *saldo = fopen("saldo.txt","a");
    fprintf(saldo," %.2f", dados.emprestimo);
    fclose(saldo);
    FILE *deposito = fopen("gerenciadorReceita.txt","a");
    fprintf(file,"");
    fprintf(file,"|Empréstimo");
    fprintf(file," |Valor: R$ %.2f", dados.emprestimo);
    fprintf(file," |Data: %d ", data.dia);
    fprintf(file,"/ %d ", data.mes);
    fprintf(file,"/ %d", data.ano);
    fprintf(deposito,"1");
    fprintf(deposito," %.2f", dados.emprestimo);
    fprintf(deposito," 1");
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
      remove("relatorio_12meses.html");
      remove("relatorio_mensal_categoria.html");
      remove("estilo.css");
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

void fecharprog(){
  sleep(1);
  printf("\nAté mais! Saindo...\n");
  sleep(1);
  exit(0);
}
