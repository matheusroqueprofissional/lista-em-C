#include<stdio.h>
#include<stdlib.h>

typedef struct{
int idade;
char nome[20];
struct sPessoa *prox;
}PESSOAS;

typedef struct{
    int idade_cachorros;
    char nome_cachorros[20];
    char rasa[20];
    struct sCachorros *proxdog;
}CACHORROS;



typedef PESSOAS* LISTA_PESSOAS;
typedef CACHORROS* LISTA_CACHORROS;

void iniciar(LISTA_PESSOAS* LISTA_pessoas,LISTA_CACHORROS* LISTA_cachorros)
{
    *LISTA_pessoas = NULL;
    *LISTA_cachorros = NULL;

    if(LISTA_pessoas == NULL || LISTA_cachorros == NULL)
    {
        printf("sem sucesso ao iniciar a fila");
    }
}

void inserir(LISTA_PESSOAS* LISTA_pessoas,int idade, char* nome[20],LISTA_CACHORROS* LISTA_cachorros, int idade_cachorros, char* nome_cachorros[20], char* rasa[20])
{
if(*LISTA_pessoas == NULL && *LISTA_cachorros == NULL)
{

    *LISTA_pessoas = (LISTA_PESSOAS)malloc(sizeof(PESSOAS));
    *LISTA_cachorros = (LISTA_CACHORROS)malloc(sizeof(CACHORROS));

    (*LISTA_pessoas)->idade = idade;
    strcpy((*LISTA_pessoas)->nome,nome);
    (**LISTA_pessoas).prox = NULL;


    (*LISTA_cachorros)->idade_cachorros = idade_cachorros;
    strcpy((*LISTA_cachorros)->nome_cachorros,nome_cachorros);
    strcpy((*LISTA_cachorros)->rasa,rasa);
    (**LISTA_cachorros).proxdog=NULL;

}
else
    inserir(&(**LISTA_pessoas).prox,idade, nome,&(**LISTA_cachorros).proxdog,idade_cachorros, nome_cachorros, rasa);

}

void listar(LISTA_PESSOAS LISTA_pessoas,LISTA_CACHORROS LISTA_cachorros)
{   if(LISTA_pessoas==NULL || LISTA_cachorros == NULL)
        return;
    printf("\npessoas");
    printf("\n%s %d",LISTA_pessoas->nome,LISTA_pessoas->idade,"\n%s %s %d",LISTA_cachorros->nome_cachorros,
                        LISTA_cachorros->rasa,
                        LISTA_cachorros->idade_cachorros);

    listar(LISTA_pessoas->prox, LISTA_cachorros->proxdog);
   }

void apagar(LISTA_PESSOAS* LISTA_pessoas,LISTA_CACHORROS* LISTA_cachorros)
{
    if(*LISTA_pessoas == NULL || *LISTA_cachorros == NULL)
    {
        return;
    }
    LISTA_PESSOAS *pTmp=*LISTA_pessoas;
    LISTA_CACHORROS *cTmp=*LISTA_cachorros  ;
    *LISTA_pessoas=(*LISTA_pessoas)->prox;
    *LISTA_cachorros=(*LISTA_cachorros)->proxdog;
    free(pTmp);
    free(cTmp);


}
void menu()
{ int contador = 0;
    while(contador<= 20)
    {
        printf("#");
        contador=contador+1;
    }
  contador = 0;
  printf("\n[1]inserir cliente\n"
         "[2]apagar cliente\n"
         "[3]listar clientes\n"
         "[4]sair\n");
    while(contador<= 20)
    {
        printf("#");
        contador=contador+1;
    }
}

int main(){
LISTA_PESSOAS LP;
LISTA_CACHORROS LC;

iniciar(&LP,&LC);
while(0==0){
        menu();
char escolha;
char nome_pessoas[20];
char nome_cachorros[20];
int idade_pessoas;
int idade_cachorros;
char rasa_cachorros[20];
scanf("%s",&escolha);
if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4')
{   system("cls");
    printf("\n\ninsira uma opção valida\n\n");
}
    else{
switch(escolha){
    case '1':

    printf("nome");
    scanf("%s",nome_pessoas);
    printf("idade");
    scanf("%d",&idade_pessoas);
    printf("nome_cachorros");
    scanf("%s",nome_cachorros);
    printf("idade_cachorros");
    scanf("%d",&idade_cachorros);
    printf("rasa");
    scanf("%s",rasa_cachorros);
    inserir(&LP,idade_pessoas,nome_pessoas,&LC,idade_cachorros,nome_cachorros,rasa_cachorros);
    break;
    case '2':
        apagar(&LP,&LC);
    break;
    case '3':
        listar(LP,LC);
    break;
    case '4':
        return;
    break;
        }
    }
listar(LP,LC);}
}
