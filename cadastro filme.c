#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#define TF 100
#define NAME 50

typedef struct 
{
    char filme[NAME];
    char genero[NAME];
    char ator[NAME];
    int minutos;
}netflix;

typedef struct 
{
    char filme[NAME];
    char genero[NAME];
    char ator[NAME];
    int minutos;
}globoplay;

typedef struct 
{
    char filme[NAME];
    char genero[NAME];
    char ator[NAME];
    int minutos;
}prime;

char funcaoMenu()
{
    char m;
    system("cls");
    printf("[A]   CADASTRAR FILMES/SERIES\n");
    printf("[B]   LISTAR TODOS OS CADASTROS\n");
    printf("[C]   LISTAR FILMES/SERIES POR GENERO\n");
    printf("[D]   LISTAR FILMES/SERIES COM DURACAO DE 90 A 120 MINUTOS\n");
    printf("[E]   LISTAR FILMES/SERIES POR PLATAFORMA\n");
    printf("[ESC] SAIR\n");
    m=getch();
    m=toupper(m);
    return m;
}

char funcaoPlataforma()
{
    char m;
    system("cls");
    printf("[A]   PRIME VIDEO\n");
    printf("[B]   GLOBO PLAY\n");
    printf("[C]   NETFLIX\n");
    printf("[ESC] RETORNAR\n");
    m=getch();
    m=toupper(m);
    return m;
}

void funcaoPrime(prime auxP[], int *p)
{
    printf("Nome do filme/serie: "); fflush(stdin);
    gets(auxP[*p].filme);
    printf("Genero: "); fflush(stdin);
    gets(auxP[*p].genero);
    printf("Nome do ator principal: "); fflush(stdin);
    gets(auxP[*p].ator);
    printf("Duracao em minutos: ");
    scanf("%d", &auxP[*p].minutos);
    system("pause");
    (*p)++;
}

void funcaoGlobo(globoplay auxG[], int *g)
{
    printf("Nome do filme/serie: "); fflush(stdin);
    gets(auxG[*g].filme);
    printf("Genero: "); fflush(stdin);
    gets(auxG[*g].genero);
    printf("Nome do ator principal: "); fflush(stdin);
    gets(auxG[*g].ator);
    printf("Duracao em minutos: ");
    scanf("%d", &auxG[*g].minutos);
    system("pause");
    (*g)++;
}

void funcaoNetflix(netflix auxN[], int *n)
{
    printf("Nome do filme/serie: "); fflush(stdin);
    gets(auxN[*n].filme);
    printf("Genero: "); fflush(stdin);
    gets(auxN[*n].genero);
    printf("Nome do ator principal: "); fflush(stdin);
    gets(auxN[*n].ator);
    printf("Duracao em minutos: ");
    scanf("%d", &auxN[*n].minutos);
    system("pause");
    (*n)++;
}

void funcaoListarTodos(prime auxP[], globoplay auxG[], netflix auxN[], int *p, int *g, int *n)
{
    int i;

    if(*p==0)
        printf("\nNenhum filme cadastrado no Prime Video!\n");
    else
    {
        printf("PRIME VIDEO\n");
        for(i=0;i<*p;i++)
        {
            printf("Nome do filme: %s\n", auxP[i].filme);
            printf("Genero: %s\n", auxP[i].genero);
            printf("Ator principal: %s\n", auxP[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxP[i].minutos);
            printf("\n-----------------------\n");
        }
    }

    if (*g==0)
        printf("\nNenhum filme cadastrado na Globo Play!\n");
    else
    {
        printf("GLOBO PLAY\n");
        for(i=0;i<*g;i++)
        {
            printf("Nome do filme: %s\n", auxG[i].filme);
            printf("Genero: %s\n", auxG[i].genero);
            printf("Ator principal: %s\n", auxG[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxG[i].minutos);
            printf("\n-----------------------\n");
        }
    }

    if (*n==0)
        printf("\nNenhum filme cadastrado na Netflix!\n");
    else
    {
        printf("NETFLIX\n");
        for(i=0;i<*n;i++)
        {
            printf("Nome do filme: %s\n", auxN[i].filme);
            printf("Genero: %s\n", auxN[i].genero);
            printf("Ator principal: %s\n", auxN[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxN[i].minutos);
            printf("\n-----------------------\n");
        }
    }
    system("pause");
}

void funcaoListarGereno(prime auxP[], globoplay auxG[], netflix auxN[], int *p, int *g, int *n)
{
    int i;
    char op[NAME];
    printf("Genero desejado: "); fflush(stdin);
    gets(op);

    for(i=0;i<*p;i++)
    {
        if(stricmp(op,auxP[i].genero)==0)
        {
            printf("PRIME VIDEO!\n");
            printf("Nome do filme: %s\n", auxP[i].filme);
            printf("Genero: %s\n", auxP[i].genero);
            printf("Ator principal: %s\n", auxP[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxP[i].minutos);
            printf("\n-----------------------\n");
        }
    }

    for(i=0;i<*g;i++)
    {
        if(stricmp(op,auxG[i].genero)==0)
        {
            printf("GLOBO PLAY!\n");
            printf("Nome do filme: %s\n", auxG[i].filme);
            printf("Genero: %s\n", auxG[i].genero);
            printf("Ator principal: %s\n", auxG[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxG[i].minutos);
            printf("\n-----------------------\n");
        }
    }
    
    for(i=0;i<*n;i++)
    {
        if(stricmp(op,auxN[i].genero)==0)
        {
            printf("NETFLIX!\n");
            printf("Nome do filme: %s\n", auxN[i].filme);
            printf("Genero: %s\n", auxN[i].genero);
            printf("Ator principal: %s\n", auxN[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxN[i].minutos);
            printf("\n-----------------------\n");
        }
    }

    if(*p==0)
        printf("\nNenhum filme cadastrado no Prime Video!\n");
    if(*g==0)
        printf("\nNenhum filme cadastrado no Globo Play!\n");
    if(*n==0)
        printf("\nNenhum filme cadastrado no Netflix!\n");
    system("pause");
}

void funcaoListarMinutos(prime auxP[], globoplay auxG[], netflix auxN[], int *p, int *g, int *n)
{
    int i;
    for(i=0;i<*p;i++)
    {
        if(auxP[i].minutos>=90 && auxP[i].minutos)
        {
            printf("PRIME VIDEO!\n");
            printf("Nome do filme: %s\n", auxP[i].filme);
            printf("Genero: %s\n", auxP[i].genero);
            printf("Ator principal: %s\n", auxP[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxP[i].minutos);
            printf("\n-----------------------\n");
        }
    } 

    for(i=0;i<*g;i++)
    {
        if(auxG[i].minutos>=90 && auxG[i].minutos)
        {
            printf("GLOBO PLAY!\n");
            printf("Nome do filme: %s\n", auxG[i].filme);
            printf("Genero: %s\n", auxG[i].genero);
            printf("Ator principal: %s\n", auxG[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxG[i].minutos);
            printf("\n-----------------------\n");
        }
    }

    for(i=0;i<*n;i++)
    {
        if(auxN[i].minutos>=90 && auxN[i].minutos)
        {
            printf("NETFLIX!\n");
            printf("Nome do filme: %s\n", auxN[i].filme);
            printf("Genero: %s\n", auxN[i].genero);
            printf("Ator principal: %s\n", auxN[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxN[i].minutos);
            printf("\n-----------------------\n");
        }
    } 

    if(*p==0)
        printf("\nNenhum filme cadastrado no Prime Video!\n");
    if(*g==0)
        printf("\nNenhum filme cadastrado no Globo Play!\n");
    if(*n==0)
        printf("\nNenhum filme cadastrado no Netflix!\n");
    system("pause");
}

void funcaoExibirPrime(prime auxP[], int *p)

{
    int i;
    if(*p==0)
        printf("Nenhum filme cadastrado na Prime Video\n");
    else
    {
        printf("PRIME VIDEO!\n");
        for(i=0;i<*p;i++)
        {
            printf("Nome do filme: %s\n", auxP[i].filme);
            printf("Genero: %s\n", auxP[i].genero);
            printf("Ator principal: %s\n", auxP[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxP[i].minutos);
            printf("\n-----------------------\n");
        }
    }
    system("pause");
}

void funcaoExibirGlobo(globoplay auxG[], int *g)
{
    int i;
    if(*g==0)
        printf("Nenhum filme cadastrado na GloboPlay!\n");
    else
    {
        printf("GLOBO PLAY!\n");
        for(i=0;i<*g;i++)
        {
            printf("Nome do filme: %s\n", auxG[i].filme);
            printf("Genero: %s\n", auxG[i].genero);
            printf("Ator principal: %s\n", auxG[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxG[i].minutos);
            printf("\n-----------------------\n");
        }
    }
    system("pause");
}

void funcaoExibirNetflix(netflix auxN[], int *n)
{
    if(*n==0)
        printf("Nenhum filme cadastrado na Netflix!\n");
    else
    {
        int i;
        printf("NETFLIX!\n");
        for(i=0;i<*n;i++)
        {
            printf("Nome do filme: %s\n", auxN[i].filme);
            printf("Genero: %s\n", auxN[i].genero);
            printf("Ator principal: %s\n", auxN[i].ator);
            printf("Duracao em minutos: %d minutos\n", auxN[i].minutos);
            printf("\n-----------------------\n");
        }
    }
    system("pause");
}

int main ()
{
    char menu, plat;
    int PRIME=0, GLOBO=0, NETFLIX=0;
    prime auxP[TF];
    globoplay auxG[TF];
    netflix auxN[TF];

    menu=funcaoMenu();
    while(menu!=27)
    {
        switch(menu)
        {
            case'A':
                plat=funcaoPlataforma();
                while(plat!=27)
                {
                    switch(plat)
                    {
                        case 'A':
                            funcaoPrime(auxP,&PRIME);
                        break;

                        case 'B':
                            funcaoGlobo(auxG,&GLOBO);
                        break;

                        case 'C':
                            funcaoNetflix(auxN,&NETFLIX);
                        break;
                    }
                    plat=funcaoPlataforma();
                }
            break;

            case 'B':
                funcaoListarTodos(auxP,auxG,auxN,&PRIME,&GLOBO,&NETFLIX);
            break;

            case 'C':
                funcaoListarGereno(auxP,auxG,auxN,&PRIME,&GLOBO,&NETFLIX);
            break;

            case 'D':
                funcaoListarMinutos(auxP,auxG,auxN,&PRIME,&GLOBO,&NETFLIX);
            break;

            case 'E':
                plat=funcaoPlataforma();
                switch(plat)
                {
                    case 'A':
                        funcaoExibirPrime(auxP,&PRIME);
                    break;
                    case 'B':
                        funcaoExibirGlobo(auxG,&GLOBO);
                    break;
                    case 'C':
                        funcaoExibirNetflix(auxN,&NETFLIX);
                    break;
                }
            break;
        }
        menu=funcaoMenu();
    }
}