#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "desenhos.h"

typedef struct Data{
    int dia, mes, ano;
}Data;

typedef struct Cliente{
    char nome[80], cpf[14], email[80], telefone[20];
    Data dataNascimento;
}Cliente;

typedef struct Celular{
    char marca[30], modelo[30], so[50];
    int ano, memoria;
    float preco;
}Celular;

typedef struct Venda{
    Cliente cliente;
    Celular celular;
    Data dataVenda;
}Venda;

void paginaClientes(){

    FILE* arc;
    int  escolhaMenus = 0, numClientes = 0;
    char verificaCadastro = ' ';

    Cliente cliente;
    Cliente listaClientes[256];

    do{
        desenhaCliente();
        criaTituloClientes();

        printf("\nMENU:\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Procurar Cliente\n");
        printf("0 - Voltar\n");
        printf("Escolha um item: ");

        scanf("%d", &escolhaMenus);
        switch(escolhaMenus){

            case 1:
                system("cls");

                numClientes = 0;

                printf("Cadastrando Clientes\n");

                arc = fopen("clientes.Dat", "ab");
                if(arc == NULL){
                    printf("Erro ao abrir o arquivo!");
                    exit(1);
                }else{
                    do{
                        printf("\nDigite o nome do cliente: ");
                        fflush(stdin);
                        gets(cliente.nome);

                        printf("Digite o CPF do cliente: ");
                        fflush(stdin);
                        gets(cliente.cpf);

                        printf("Digite o email do cliente: ");
                        fflush(stdin);
                        gets(cliente.email);

                        printf("Digite o telefone do cliente: ");
                        fflush(stdin);
                        gets(cliente.telefone);

                        printf("Digite o dia de nascimento do cliente: ");
                        scanf("%d", &cliente.dataNascimento.dia);

                        printf("Digite o mês de nascimento do cliente: ");
                        scanf("%d", &cliente.dataNascimento.mes);

                        printf("Digite o ano de nascimento do cliente: ");
                        scanf("%d", &cliente.dataNascimento.ano);

                        numClientes++;

                        printf("\n\nCliente cadastrado com sucesso!\n\n");
                        printf("Nome: %s\n", cliente.nome);
                        printf("CPF: %s\n", cliente.cpf);
                        printf("Email: %s\n", cliente.email);
                        printf("Telefone: %s\n", cliente.nome);
                        printf("Data de Nascimento: %d/%d/%d\n\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);

                        if(fwrite(&cliente, sizeof(struct Cliente), 1, arc) != 1)
                            printf("Erro na escrita.");

                        printf("Continuar cadastrando? (s/n)\n");
                        fflush(stdin);
                        scanf("%c", &verificaCadastro);

                    }while(verificaCadastro == 's' || verificaCadastro == 'S');

                }

                fclose(arc);

                system("cls");

                printf("Voltando...\n\n");

                break;

            case 2:
                system("cls");

                int escolhaCliente = 0;
                numClientes = 0;

                arc = fopen("clientes.Dat", "rb");

                if(arc == NULL){
                    printf("Erro ao abrir o arquivo!");
                    exit(1);
                }else{
                    while(fread(listaClientes[numClientes].nome, sizeof(struct Cliente), 1, arc)){
                        numClientes++;
                    }
                }
                fclose(arc);

                do{
                    system("cls");

                    printf("Consultando Clientes\n\n");

                    printf("MENU:\n");
                    printf("1 - Mostrar todos\n");
                    printf("2 - Procurar por nome\n");
                    printf("0 - Voltar\n");
                    printf("Escolha um item: ");
                    scanf("%d", &escolhaCliente);

                    switch(escolhaCliente){
                        case 1:
                            system("cls");
                            printf("Clientes cadastrados: \n");

                            for(int i = 0; i < numClientes; i++){
                                printf("\nCliente %d\n", i+1);
                                printf("Nome: %s\n", listaClientes[i].nome);
                                printf("CPF: %s\n", listaClientes[i].cpf);
                                printf("Email: %s\n", listaClientes[i].email);
                                printf("Telefone: %s\n", listaClientes[i].telefone);
                                printf("Data de Nascimento: %d/%d/%d\n", listaClientes[i].dataNascimento.dia, listaClientes[i].dataNascimento.mes, listaClientes[i].dataNascimento.ano);
                            }

                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 2:
                            system("cls");

                            char nome[80];
                            printf("Digite o nome que deseja buscar: ");
                            fflush(stdin);
                            gets(nome);

                            printf("\nBuscando clientes de nome: %s\n", nome);

                            for(int i = 0; i < numClientes; i++){
                                if(strcmp(listaClientes[i].nome, nome) == 0){
                                    printf("\nNome: %s\n", listaClientes[i].nome);
                                    printf("CPF: %s\n", listaClientes[i].cpf);
                                    printf("Email: %s\n", listaClientes[i].email);
                                    printf("Telefone: %s\n", listaClientes[i].telefone);
                                    printf("Data de Nascimento: %d/%d/%d\n", listaClientes[i].dataNascimento.dia, listaClientes[i].dataNascimento.mes, listaClientes[i].dataNascimento.ano);
                                }
                            }

                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 0:
                            system("cls");
                            printf("Voltando...\n\n");
                            break;

                        default:
                            system("cls");
                            printf("Valor não encontrado no menu, digite outro número!\n\n");
                            break;
                    }
                }while(escolhaCliente != 0);

                system("cls");
                break;

            case 0:
                system("cls");
                printf("Voltando...\n\n");
                break;

            default:
                system("cls");
                printf("Valor não encontrado no menu, digite outro número!\n\n");
                break;
        }
    }while(escolhaMenus != 0);
}

void paginaCelulares(){

    FILE* arc;
    int escolhaMenus = 0, numCelulares = 0;
    char verificaCadastro = ' ';

    Celular celular;
    Celular listaCelulares[256];

    do{
        desenhaCelulares();
        criaTituloCelulares();

        printf("\nMENU:\n");
        printf("1 - Cadastrar Celular\n");
        printf("2 - Procurar Celular\n");
        printf("0 - Voltar\n");
        printf("Escolha um item: ");

        scanf("%d", &escolhaMenus);
        switch(escolhaMenus){

            case 1:
                system("cls");

                numCelulares = 0;

                printf("Cadastrando Celulares\n");

                arc = fopen("celulares.Dat", "ab");
                if(arc == NULL){
                    printf("Erro ao abrir o arquivo!");
                    exit(1);
                }else{
                    do{
                        printf("\nDigite a marca do celular: ");
                        fflush(stdin);
                        gets(celular.marca);

                        printf("Digite o modelo do celular: ");
                        fflush(stdin);
                        gets(celular.modelo);

                        printf("Digite o sistema operacional do celular: ");
                        fflush(stdin);
                        gets(celular.so);

                        printf("Digite o ano de lançamento do celular: ");
                        fflush(stdin);
                        scanf("%d", &celular.ano);

                        printf("Digite a capacidade de memória do celular: ");
                        scanf("%d", &celular.memoria);

                        printf("Digite o preço do celular: ");
                        scanf("%f", &celular.preco);

                        numCelulares++;

                        printf("\nCelular cadastrado com sucesso!\n\n");
                        printf("Marca: %s\n", celular.marca);
                        printf("Modelo: %s\n", celular.modelo);
                        printf("Sistema Operacional: %s\n", celular.so);
                        printf("Ano de Lançamento: %d\n", celular.ano);
                        printf("Capacidade de Memória: %d\n", celular.memoria);
                        printf("Preço: %.2f\n\n", celular.preco);

                        if(fwrite(&celular, sizeof(struct Celular), 1, arc) != 1)
                            printf("Erro na escrita.");

                        printf("Continuar cadastrando? (s/n)\n");
                        fflush(stdin);
                        scanf("%c", &verificaCadastro);

                    }while(verificaCadastro == 's' || verificaCadastro == 'S');

                }

                fclose(arc);

                system("cls");

                printf("Voltando...\n\n");

                break;

            case 2:
                system("cls");

                int escolhaCelulares = 0;
                numCelulares = 0;

                arc = fopen("celulares.Dat", "rb");

                if(arc == NULL){
                    printf("Erro ao abrir o arquivo!");
                    exit(1);
                }else{
                    while(fread(listaCelulares[numCelulares].marca, sizeof(struct Celular), 1, arc)){
                        numCelulares++;
                    }
                }
                fclose(arc);

                do{
                    system("cls");

                    printf("Consultando Celulares\n\n");

                    printf("MENU:\n");
                    printf("1 - Mostrar todos\n");
                    printf("2 - Procurar por marca\n");
                    printf("0 - Voltar\n");
                    printf("Escolha um item: ");
                    scanf("%d", &escolhaCelulares);

                    switch(escolhaCelulares){
                        case 1:
                            system("cls");
                            printf("Celulares cadastrados: \n");

                            for(int i = 0; i < numCelulares; i++){
                                printf("\nCelular %d\n", i+1);
                                printf("Marca: %s\n", listaCelulares[i].marca);
                                printf("Modelo: %s\n", listaCelulares[i].modelo);
                                printf("Sistema Operacional: %s\n", listaCelulares[i].so);
                                printf("Ano de Lançamento: %d\n", listaCelulares[i].ano);
                                printf("Capacidade de Memória: %d\n", listaCelulares[i].memoria);
                                printf("Preço: %.2f\n", listaCelulares[i].preco);
                            }

                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 2:
                            system("cls");

                            char marca[30];
                            printf("Digite a marca que deseja buscar: ");
                            fflush(stdin);
                            gets(marca);

                            printf("\nBuscando celulares de marca: %s\n", marca);

                            for(int i = 0; i < numCelulares; i++){
                                if(strcmp(listaCelulares[i].marca, marca) == 0){
                                    printf("\nMarca: %s\n", listaCelulares[i].marca);
                                    printf("Modelo: %s\n", listaCelulares[i].modelo);
                                    printf("Sistema Operacional: %s\n", listaCelulares[i].so);
                                    printf("Ano de Lançamento: %d\n", listaCelulares[i].ano);
                                    printf("Capacidade de Memória: %d\n", listaCelulares[i].memoria);
                                    printf("Preço: %.2f\n", listaCelulares[i].preco);
                                }
                            }

                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 0:
                            system("cls");
                            printf("Voltando...\n\n");
                            break;

                        default:
                            system("cls");
                            printf("Valor não encontrado no menu, digite outro número!\n\n");
                            break;
                    }
                }while(escolhaCelulares != 0);

                break;

            case 0:
                system("cls");
                printf("Voltando...\n\n");
                break;

            default:
                system("cls");
                printf("Valor não encontrado no menu, digite outro número!\n\n");
                break;
        }
    }while(escolhaMenus != 0);
}

void paginaVendas(){

    FILE* arc;
    int escolhaMenus = 0, numVendas = 0, contador = 0;
    char verificaCadastro = ' ';

    Venda venda;
    Venda listaVendas[256];

    do{
        desenhaVendas();
        criaTituloVendas();

        printf("\nMENU:\n");
        printf("1 - Cadastrar Venda\n");
        printf("2 - Procurar Venda\n");
        printf("0 - Voltar\n");
        printf("Escolha um item: ");

        scanf("%d", &escolhaMenus);
        switch(escolhaMenus){

            case 1:
                system("cls");

                numVendas = 0;

                printf("Cadastrando Vendas\n\n");

                arc = fopen("vendas.Dat", "a+b");
                if(arc == NULL){
                    printf("Arquivo não pode ser aberto!");
                    exit(1);
                }else{
                    do{
                        printf("\nDigite o nome do cliente: ");
                        fflush(stdin);
                        gets(venda.cliente.nome);

                        printf("Digite o CPF do cliente: ");
                        fflush(stdin);
                        gets(venda.cliente.cpf);

                        printf("Digite a marca do celular: ");
                        fflush(stdin);
                        gets(venda.celular.marca);

                        printf("Digite o modelo do celular: ");
                        fflush(stdin);
                        gets(venda.celular.modelo);

                        printf("Digite o dia da venda: ");
                        scanf("%d", &venda.dataVenda.dia);

                        printf("Digite o mês da venda: ");
                        scanf("%d", &venda.dataVenda.mes);

                        printf("Digite o ano da venda: ");
                        scanf("%d", &venda.dataVenda.ano);

                        numVendas++;

                        printf("\nVenda cadastrada com sucesso!\n\n");
                        printf("Nome: %s\n", venda.cliente.nome);
                        printf("CPF: %s\n", venda.cliente.cpf);
                        printf("Marca: %s\n", venda.celular.marca);
                        printf("Modelo: %s\n", venda.celular.modelo);
                        printf("Data de Venda: %d/%d/%d\n\n", venda.dataVenda.dia, venda.dataVenda.mes, venda.dataVenda.ano);

                        if(fwrite(&venda, sizeof(struct Venda), 1, arc) != 1)
                            printf("Erro na escrita.");

                        printf("Continuar cadastrando? (s/n)\n");
                        fflush(stdin);
                        scanf("%c", &verificaCadastro);

                    }while(verificaCadastro == 's' || verificaCadastro == 'S');
                }

                fclose(arc);

                numVendas++;

                system("cls");
                printf("Venda cadastrada com sucesso!\n\n");
                printf("Voltando...\n\n");

                break;

            case 2:
                system("cls");

                int escolhaVendas = 0;
                numVendas = 0;

                arc = fopen("vendas.Dat", "rb");

                if(arc == NULL){
                    printf("Erro ao abrir o arquivo!");
                    exit(1);
                }else{
                    while(fread(listaVendas[numVendas].cliente.nome, sizeof(struct Venda), 1, arc)){
                        numVendas++;
                    }
                }
                fclose(arc);

                do{
                    system("cls");

                    printf("Consultando Vendas\n\n");

                    printf("MENU:\n");
                    printf("1 - Mostrar todos\n");
                    printf("2 - Quantos celulares determinada pessoa tem?\n");
                    printf("3 - Quantos celulares dessa marca foram vendidos?\n");
                    printf("4 - Neste mês, quantos celulares foram comprados?\n");
                    printf("0 - Voltar\n");
                    printf("Escolha um item: ");
                    scanf("%d", &escolhaVendas);

                    switch(escolhaVendas){
                        case 1:
                            system("cls");
                            printf("Vendas cadastradas: \n");

                            for(int i = 0; i < numVendas; i++){
                                printf("\nVenda %d\n", i+1);
                                printf("Cliente: %s\n", listaVendas[i].cliente.nome);
                                printf("CPF: %s\n", listaVendas[i].cliente.cpf);
                                printf("Marca Celular: %s\n", listaVendas[i].celular.marca);
                                printf("Modelo: %s\n", listaVendas[i].celular.modelo);
                                printf("Data da Venda: %d/%d/%d\n", listaVendas[i].dataVenda.dia, listaVendas[i].dataVenda.mes, listaVendas[i].dataVenda.ano);
                            }

                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 2:
                            system("cls");

                            contador = 0;
                            char nome[80];
                            printf("Digite o nome que deseja buscar: ");
                            fflush(stdin);
                            gets(nome);

                            printf("\nBuscando vendas no nome de: %s\n", nome);

                            for(int i = 0; i < numVendas; i++){
                                if(strcmp(listaVendas[i].cliente.nome, nome) == 0){
                                    contador++;
                                    printf("\nVenda %d\n", i+1);
                                    printf("Cliente: %s\n", listaVendas[i].cliente.nome);
                                    printf("CPF: %s\n", listaVendas[i].cliente.cpf);
                                    printf("Marca Celular: %s\n", listaVendas[i].celular.marca);
                                    printf("Modelo: %s\n", listaVendas[i].celular.modelo);
                                    printf("Data da Venda: %d/%d/%d\n", listaVendas[i].dataVenda.dia, listaVendas[i].dataVenda.mes, listaVendas[i].dataVenda.ano);
                                }
                            }

                            printf("\n%s comprou %d celulares!\n", nome, contador);
                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 3:
                            system("cls");

                            contador = 0;
                            char marca[30];
                            printf("Digite a marca que deseja buscar: ");
                            fflush(stdin);
                            gets(marca);

                            printf("\nBuscando vendas de marca: %s\n", marca);

                            for(int i = 0; i < numVendas; i++){
                                if(strcmp(listaVendas[i].celular.marca, marca) == 0){
                                    contador++;
                                    printf("\nVenda %d\n", i+1);
                                    printf("Cliente: %s\n", listaVendas[i].cliente.nome);
                                    printf("CPF: %s\n", listaVendas[i].cliente.cpf);
                                    printf("Marca Celular: %s\n", listaVendas[i].celular.marca);
                                    printf("Modelo: %s\n", listaVendas[i].celular.modelo);
                                    printf("Data da Venda: %d/%d/%d\n", listaVendas[i].dataVenda.dia, listaVendas[i].dataVenda.mes, listaVendas[i].dataVenda.ano);
                                }
                            }

                            printf("\n%d celulares da marca %s foram comprados!\n", contador, marca);
                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 4:
                            system("cls");

                            contador = 0;
                            int mes, ano;
                            printf("Digite o mês que deseja buscar: ");
                            scanf("%d", &mes);
                            printf("Digite o ano que deseja buscar: ");
                            scanf("%d", &ano);

                            printf("\nBuscando vendas em %d/%d\n", mes, ano);

                            for(int i = 0; i < numVendas; i++){
                                if(listaVendas[i].dataVenda.mes == mes && listaVendas[i].dataVenda.ano == ano){
                                    contador++;
                                    printf("\nVenda %d\n", i+1);
                                    printf("Cliente: %s\n", listaVendas[i].cliente.nome);
                                    printf("CPF: %s\n", listaVendas[i].cliente.cpf);
                                    printf("Marca Celular: %s\n", listaVendas[i].celular.marca);
                                    printf("Modelo: %s\n", listaVendas[i].celular.modelo);
                                    printf("Data da Venda: %d/%d/%d\n", listaVendas[i].dataVenda.dia, listaVendas[i].dataVenda.mes, listaVendas[i].dataVenda.ano);
                                }
                            }

                            printf("\nNo mês de %d/%d foram vendidos %d celulares!\n", mes, ano, contador);
                            printf("\nConsulta realizada com sucesso!\n\n");
                            system("pause");
                            break;

                        case 0:
                            system("cls");
                            printf("Voltando...\n\n");
                            break;

                        default:
                            system("cls");
                            printf("Valor não encontrado no menu, digite outro número!\n\n");
                            break;
                    }

                }while(escolhaVendas != 0);

                system("cls");
                break;

            case 0:
                system("cls");
                printf("Voltando...\n\n");
                break;

            default:
                system("cls");
                printf("Valor não encontrado no menu, digite outro número!\n\n");
                break;
        }
    }while(escolhaMenus != 0);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int escolhaPrincipal = 0;

    do{
        desenhaLogo();
        criaNomeLoja();
        criaSaudacao();

        printf("\nMENU:\n");
        printf("1 - Clientes\n");
        printf("2 - Celulares\n");
        printf("3 - Vendas\n");
        printf("0 - Sair\n");
        printf("O que deseja fazer agora: ");

        scanf("%d", &escolhaPrincipal);
        switch(escolhaPrincipal){

            case 1: // Página Clientes
                system("cls");

                paginaClientes();

                break;

//////////////////////////////////////////////////////////////////////////////

            case 2: // Página Celulares
                system("cls");

                paginaCelulares();

                break;

//////////////////////////////////////////////////////////////////////////////

            case 3: // Página Vendas
                system("cls");

                paginaVendas();

                break;

//////////////////////////////////////////////////////////////////////////////

            case 0:
                system("cls");
                printf("Obrigado por usar nosso sistema!\n\n");
                printf("Até a próxima!\n\n");
                break;

            default:
                system("cls");
                printf("Valor não encontrado no menu, digite outro número!\n\n");
                break;
        }

    }while(escolhaPrincipal != 0);

    system("pause");
    return 0;
}
