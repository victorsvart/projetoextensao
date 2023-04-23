#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define PESO_PRECO 70.00
#define VENDAS 100

char *menu[] = {
    "Carne Cozida \n                                       (Acompanha: Arroz "
    "branco, feijao, macarrao, farofa, batata frita, salada de xuxu)\n",
    "Escondidinho de Carne Seca\n                                   "
    "(Acompanha: Polenta "
    "Rocheada com Queijo, Salada Americana, Feijao, Arroz Grego)",
    "Costela de Porco\n                                    (Acompanha: Arroz "
    "Branco, Feijao Tropeiro, Vinegrete, Farofa, Salada de Legumes)\n",
    "Salmao Defumado\n                                     (Acompanha: Arroz "
    "de Brocolis, Batata Baroa, Molho Teriyaki)\n",
    "Frango Xadrez\n                                       (Acompanha: Cebola, "
    "Pure de Batata, Feijao, Salada, Arroz Branco)\n",
    "Feijoada\n                                            (Acompanha: Arroz "
    "Branco, Farofa, Laranja, Torresmo, Mandioca)\n"};

typedef struct {
  char *pratoPrincipal[50];
  char *acompanhamento[200];
} Prato;

void flush_in() {
  int ch;
  do {
    ch = fgetc(stdin);
  } while (ch != EOF && ch != '\n');
}

float calcPorcao(float pesoProteina, float porcao, float peso) {
  return pesoProteina + porcao * peso;
}

float calcPrecoFinal(float peso) {
  float pesoFinal = peso / 1000;
  return pesoFinal * PESO_PRECO;
}

void menuKilo() {
  system("cls");

  char *itemPrincipal[] = {
      "Churrasco",        "Tilapia",         "Frango Empanado",
      "Costela de Porco", "Salmao Grelhado", "Feijoada",
      "Strogonoff",       "Omelete",         "Empadao de Frango"};
  float pesoPrincipal = 200;
  int size = sizeof(itemPrincipal) / sizeof(itemPrincipal[0]);

  char *acompanhamentos[] = {
      "Arroz Branco" /*0*/,
      "Feijao" /*1*/,
      "Macarrao" /*2*/,
      "Farofa" /*3*/,
      "Batata Frita" /*4*/,
      "Salada de Xuxu" /*5*/,
      "Ovo" /*6*/,
      "Tabule" /*7*/,
      "Ovo de Codorna" /*8*/,
      "Alface" /*9*/,
      "Tomate" /*10*/,
      "Cenoura Ralada" /*11*/,
      "Pure de Batata" /*12*/,
      "Farofa de Ovo" /*13*/,
      "Beterraba ralada" /*14*/,
      "Cebola" /*15*/,
      "Pimentao" /*16*/,
      "Cebola Roxa" /*17*/,
      "Cebola Caramelizada" /*18*/,
      "Cebola Roxa Caramelizada" /*19*/,
      "Grao de Bico" /*20*/,
      "Feijao Tropeiro" /*21*/,
      "Vinagrete" /*22*/,
      "Batata Doce" /*23*/
  };
  int acompanhamentosPeso[] = {
      100 /*0*/, 150 /*1*/,  150 /*2*/, 30 /*3*/,   100 /*4*/, 50 /*5*/,
      70 /*6*/,  40 /*7*/,   10 /*8*/,  10 /*9*/,   15 /*10*/, 50 /*11*/,
      70 /*12*/, 100 /*13*/, 50 /*14*/, 40 /*15*/,  20 /*16*/, 40 /*17*/,
      90 /*18*/, 120 /*19*/, 30 /*20*/, 150 /*21*/, 10 /*22*/, 150 /*23*/
  };

  int sizeAcompanhamentos =
      sizeof(acompanhamentos) / sizeof(acompanhamentos[0]);

  int proteina;

  printf("            /\\_/\\\n");
  printf("           ( o o )");
  printf("      Gatonho Estranho:\n            =_~_=           Ola, estranho! "
         "Voce escolheu a KG! Estas sao nossas opcoes de proteina: \n");
  for (int i = 0; i < size; i++) {
    printf("                               ->  %d - %s\n", i + 1,
           itemPrincipal[i]);
  }
  printf("                              Qual vai ser a da vez?\n");
  printf("                              >> ");
  scanf("%d", &proteina);

  int acompanhentoEscolha;
  char *acompanhamentosEscolhidos[10];
  float pesoFinal;
  int PORCOES = 10;
  float porcoesEscolhidas;
  int index = 0;
  while (PORCOES != 0) {
    system("cls");
    printf("                              Agora escolha seus acompanhamentos "
           "(Limite de 10 Porcoes): \n");

    for (int i = 0; i < sizeAcompanhamentos; i++) {
      printf("                               ->  %d - %s\n", i + 1,
             acompanhamentos[i]);
    }

    printf("            /\\_/\\\n");
    printf("           ( o o )");
    printf("      Gatonho Estranho:\n            =_~_=           Voce tem "
           "direito a mais %d porcoes.\n",
           PORCOES);
    printf("                            >> ");
    scanf("%d", &acompanhentoEscolha);

    printf("                              Quantas porcoes voce gostaria?\n");
    printf("                              >> ");

    scanf("%f", &porcoesEscolhidas);

    acompanhamentosEscolhidos[index] = acompanhamentos[acompanhentoEscolha - 1];
    index++;

    PORCOES -= porcoesEscolhidas;

    float pesoEscolhido =
        calcPorcao(pesoPrincipal, porcoesEscolhidas,
                   acompanhamentosPeso[acompanhentoEscolha - 1]);
    pesoFinal += pesoEscolhido;
  }

  system("cls");
  printf("            /\\_/\\\n");
  printf("           ( o o )");
  printf("      Gatonho Estranho:\n            =_~_=           Calculando seu "
         "peso final...\n");
  Sleep(2000);
  printf("                              [...");
  Sleep(2000);
  printf("...");
  Sleep(2000);
  printf("...");
  Sleep(1000);
  printf("...");
  Sleep(1000);
  printf("...");
  Sleep(1000);
  printf("...]\n");
  Sleep(1000);
  printf("                              O peso final do prato foi: %.2fg\n",
         pesoFinal);
  printf("                              Calculando preco final do prato...\n");
  Sleep(2000);
  printf("                              [...");
  Sleep(2000);
  printf("...");
  Sleep(2000);
  printf("...");
  Sleep(1000);
  printf("...");
  Sleep(1000);
  printf("...");
  Sleep(1000);
  printf("...]\n");
  Sleep(1000);

  int sizeAcompanhamentosEscolhidos =
      sizeof(acompanhamentosEscolhidos) / sizeof(acompanhamentosEscolhidos[0]);

  Prato prato = {.pratoPrincipal = itemPrincipal[proteina - 1]};
  for (int i = 0; i < sizeAcompanhamentosEscolhidos; i++) {
    prato.acompanhamento[i] = acompanhamentosEscolhidos[i];
  }
  // fflush( stdin );

  printf("\n                    Seu prato ficou assim: \n");
  printf("                      %s com ", prato.pratoPrincipal[0]);
  for (int i = 0; i < index; i++) {
    printf(" %s, ", prato.acompanhamento[i]);
  }

  printf("\n");
  // flush_in();

  printf("                              O preco final do prato foi: R$%.2f\n",
         calcPrecoFinal(pesoFinal));
  printf("                              Obrigado pela preferencia! Volte "
         "sempre! :)\n");
}

char *menuDia(int dia) {
  system("cls");
  char *refeicaoFinal[1];
  char *dias[] = {"Domingo", "Segunda", "Terca", "Quarta",
                  "Quinta",  "Sexta",   "Sabado"};
  if (dia == 0) {
    printf("            /\\_/\\\n");
    printf("           ( o o )");
    printf("      Gatonho Estranho:\n            =_~_=           Ola, "
           "estranho! Nos nao servimos aos domingos... :(\n");
    printf("       /_______________\\\n");
    printf("      |                 |\n");
    printf("      |     VENDEDOR    |\n");
    printf("      |_________________|     >> \n");
    printf("       || ||       || ||\n");
    printf("       || ||       || ||\n");
    printf("       <> <>       <> <>\n");
  }

  printf("            /\\_/\\\n");
  printf("           ( o o )");
  printf("      Gatonho Estranho:\n            =_~_=           Todas as nossas "
         "quentinhas custam R$20.00 (+ R$0.50 a embalagem)!");
  printf("                                                                     "
         "          Hoje e %s esta e nossa quentinha de hoje:\n\n",
         dias[dia]);
  printf("                               ->  %s\n", menu[dia - 1]);
  printf("                               Gerando sua notinha...");
  Sleep(3000);
  system("cls");
  printf("            /\\_/\\\n");
  printf("           ( o o )");
  printf("               Seu pedido foi:\n");
  printf("                               ->  %s\n", menu[dia - 1]);
  printf("                               Total: R$20.50\n");
  printf("                               Obrigado pela preferencia!\n");
  Sleep(3000);
  char *refeicao = menu[dia - 1];
  *refeicaoFinal = refeicao;
  return *refeicaoFinal;
}

char *puppet(int dia) {
  system("cls");
  char *refeicaoFinal[1];
  char *dias[] = {"Domingo", "Segunda", "Terca", "Quarta",
                  "Quinta",  "Sexta",   "Sabado"};
  if (dia == 0) {
    return "Nao servimos aos domingos.";
  }
  char *refeicao = menu[dia - 1];
  *refeicaoFinal = refeicao;
  return *refeicaoFinal;
}

void relatorioDiario() {
  system("cls");
  srand(time(NULL));
  char *list[100];
  for (int i = 0; i <= 100; i++) {
    list[i] = puppet(rand() % 7);
  }
  printf("            /\\_/\\\n");
  printf("           ( o o )");
  printf("      Gatonho Estranho:\n            =_~_=           Relatorio de "
         "Hoje: \n");

  for (int i = 0; i <= VENDAS; i++) {
    printf("                               ->  %s\n", list[i]);
  }
  printf("Total: R$ %3.f", 20.50 * VENDAS);
}

int main() {
  system("cls");
  int choice;
  setlocale(LC_ALL, "Portuguese");
  printf("            /\\_/\\\n");
  printf("           ( o o )");
  printf("      Gatonho Estranho:\n            =_~_=           Ola, estranho! "
         "Qual vai ser a da vez?\n");
  printf("       /_______________\\\n");
  printf("      |                 |     1 - Kilo\n");
  printf("      |                 |     2 - Quentinha\n");
  printf("      |                 |     3 - Relatorios\n");
  printf("      |_________________|     >> ");
  scanf("%d", &choice);
  printf("       || ||       || ||\n");
  printf("       || ||       || ||\n");
  printf("       <> <>       <> <>\n");
  switch (choice) {
  case 1:
    menuKilo();
    break;
  case 2:
    menuDia(5);
    break;
  case 3:
    relatorioDiario();
    break;

  default:
    printf("Opcao invalida!\n");
    break;
  }
}