#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuPrincipal();
void menuAlunos();
void menuNotas();
void menuDisciplinas();

void cadastraDisciplina();
void editaDisciplina();
void consultaDisciplina();
void removeDisciplina();

void cadastraAluno();
void consultaAluno();
void editarAluno();
void removeAluno();

void cadastrarNotas();
void editarNotas();
void consultarNotas();
void removeNotas();

float calculo_media(float a, float b, float c);
struct notas{
    int matricula, cod_disciplina, frequencia;

    float nota1, nota2, nota3, media;
};

typedef struct alunos{
    char nome[70], endereco[70],telefone[17];

    int matricula;
}alunos;
typedef struct disciplinas {
    char nome[70];
    int codigo;
} disciplinas;

int main(){
    int opcao = 0, opcao_alunos, opcao_disciplinas,
          opcao_notas, confirma_saida, tam;

    int i,buffer_notas,buffer_notas2;

    float media_notas;

    FILE *fp;

    struct notas *p, buffer;
    struct disciplinas bufdisc;
    
    struct disciplinas *ptr;


    system("color 0B");

        while (opcao != 4){

            system("cls");

            menuPrincipal();

            scanf("%d", &opcao);

            system("cls");

                switch (opcao){

                    case 1:
                        opcao_alunos=0;

                        while(opcao_alunos != 5){
                        
                        system("cls");
                        menuAlunos();
                        scanf("%d", &opcao_alunos);

                        switch(opcao_alunos){

                            case 1:
                                system("cls");
                                cadastraAluno();
                            break;

                            case 2:
                                system("cls");
                                editarAluno();
                            break;

                            case 3:
                                system("cls");
                                consultaAluno();
                            break;
                            
                            case 4:
                                system("cls");
                                removeAluno();
                                break;
                            
                            case 5:
                                system("cls");
                                opcao_alunos=5;
                                break;
                                

                            default:
                                printf("Por favor digite apenas numeros"
                                    " de 1 a 5");
                                system("pause");

                         };


                    }
                 break;

                case 2:
                    opcao_disciplinas = 0;
                    while(opcao_disciplinas != 5){
                           menuDisciplinas();
                           scanf("%d", &opcao_disciplinas);
                           system("cls");       

                                switch (opcao_disciplinas){
                                    case 1:
                                        system("cls");
                                        cadastraDisciplina();
                                        
                                    break;
                                        
                                    case 2:
                                         system("cls");
                                         editaDisciplina();
                                    break;
                                        
                                    case 3:
                                        system("cls");
                                        consultaDisciplina();
                                    break;

                                    case 4:
                                        system("cls");
                                        removeDisciplina();
                                    break;
                                    case 5:
                                    break;
                                    default: 
                                        printf("Por favor, digite apenas numeros de 1 a 5!");
                                        system("pause");
                                }
 }
                break;

                case 3:
                    opcao_notas = 0;
                        while (opcao_notas != 5){
                            menuNotas();
                            scanf("%d", &opcao_notas);

                            system("cls");

                                switch (opcao_notas){
                                            
                                    case 1:  
                                        cadastrarNotas();
                                    break;

                                    case 2 :
                                        editarNotas();
                                    break;

                                    case 3 :
                                        consultarNotas();
                                    break;

                                    case 4 :
                                        removeNotas();
                                    break;
                                    case 5 :
                                    break;
                                    default :
                                        printf("Por favor, digite apenas numeros de 1 a 5!");
                                        system("pause");
                    }
            }

                break;

                case 4:

                    system("cls");

                    printf("_____________________________________________________\n\n");

                    printf("Voce tem certeza que deseja sair do sistema?\n\n");

                    printf("1 - Sim\n");

                    printf("2 - Nao\n\n");

                    printf("_____________________________________________________\n\n");

                    printf("Digite o numero respectivo ao que deseja fazer:\n-> ");

                    scanf("%d", &confirma_saida);

                        if (confirma_saida == 1)
                            return 0;

                        else
                    {
                            opcao = 0;
                                break;
                    }

                break;

                default:

                    printf("Por favor digite apenas numeros de 1 a 4");

                break;
        };


    }

      return 0;
}

void menuPrincipal()
{
    system("cls");


    printf("----------Seja bem-vindo ao portal da UECE----------\n\n");

    printf("____________________________________________________\n\n");

    printf("---------------------Menu inicial-------------------\n\n");

    printf("1 - Alunos\n");

    printf("2 - Disciplinas\n");

    printf("3 - Notas\n");

    printf("4 - Sair do sistema\n");

    printf("_____________________________________________\n\n");

    printf("Digite o numero respectivo ao que deseja fazer:\n-> ");


}

void menuAlunos()
{
     system("cls");

     printf("_____________________________________________\n\n");

     printf("--------------------Alunos-------------------\n\n");

     printf("1 - Cadastrar Alunos\n");

     printf("2 - Editar alunos\n");

     printf("3 - Consultar aluno\n");

     printf("4 - Remover Aluno\n");

     printf("5 - Voltar ao menu inicial\n");

     printf("_____________________________________________\n\n");

     printf("Digite o numero respectivo ao que deseja fazer:\n-> ");
}

void menuNotas()
{
    system("cls");

            printf("_____________________________________________\n\n");

            printf("-----------------Notas----------------\n\n");

            printf("1 - Cadastrar notas\n");

            printf("2 - Editar notas\n");

            printf("3 - Consultar notas\n");

            printf("4 - Remover notas\n");

            printf("5 - Voltar ao menu inicial\n");

            printf("_____________________________________________\n\n");

            printf("Digite o numero respectivo ao que deseja fazer:\n-> ");

}

void menuDisciplinas()
{
     system("cls");

     printf("_____________________________________________\n\n");

     printf("-----------------Disciplinas----------------\n\n");

     printf("1 - Cadastrar Disciplinas\n");

     printf("2 - Editar Disciplinas\n");

     printf("3 - Consultar Disciplinas\n");

     printf("4 - Remover Disciplinas\n");

     printf("5 - Voltar ao menu inicial\n");

     printf("_____________________________________________\n\n");

     printf("Digite o numero respectivo ao que deseja fazer:\n-> ");
}

void cadastraAluno(){
    alunos aluno_cad;
    FILE *fp;

    printf("_______________________"
               "______________________\n\n");
    printf("-------------Cadastro de Aluno-------------\n\n");
    printf("Digite o nome do aluno:\n-> ");

    setbuf(stdin, NULL);
    gets(aluno_cad.nome);

    printf("\nInsira o endereco do aluno:\n-> ");

    setbuf(stdin,  NULL);
    gets(aluno_cad.endereco);

    printf("\nInsira o numero de matricula:\n-> ");

    scanf("%d", &aluno_cad.matricula);

    printf("\nInsira o telefone desta forma ->  (ddd) 9 9999-9999:\n-> ");

    setbuf(stdin,  NULL);
    gets(aluno_cad.telefone);

    fp = fopen("arq_alunos.txt", "a");

      if(fp == NULL){

        printf("\nErro ao abrir o arquivo, impossivel"
               " concluir cadastro!");
     return;
      }
    fwrite(&aluno_cad, sizeof(alunos), 1, fp);

    fclose(fp);

    printf("\nCadastro bem sucedido\n");

    system("pause");
}


void editarAluno(){
    FILE *fp;

    alunos *p;

    int i, tam, cont=0;

    fp = fopen("arq_alunos.txt", "r");
    if(!fp){
        printf("Erro ao acessar o arquivo, impossivel prosseguir com alteracao");
        return;
    }
    fseek(fp, 0, 2);

    tam = ftell(fp)/sizeof(alunos);

    rewind(fp);

    p = (alunos *) malloc(tam * sizeof(alunos));

    if(!p){
        printf("Erro ao alocar memoria, impossivel prosseguir com alteracao");
        system("pause");
        return;
    }

    fread(p, sizeof(alunos), tam, fp);

    fclose(fp);
    i = -1;
    while(i<=0 || i > tam){  
        printf("____________________________________________________________________________________________________________\n");
        printf("Num -\t\t     Nome\t\t\t-\t Endereco \t -  Matricula -     Telefone\n");
        for(i=0; i<tam; i++){
        printf("_____________________________________________________________________________________________________________\n");

            printf("%-2d  -  %-40s - %-20s   -    %d    - %s\n", i+1, p[i].nome,
                    p[i].endereco, p[i].matricula, p[i].telefone);



        }
        printf("_____________________________________________________________________________________________________________\n");

        printf("\nDigite o numero respectivo ao do aluno que deseja editar\n-> ");

        scanf("%d", &i);
            if( i<=0 || i>tam){
                printf("Digite apenas numeros contidos na sequencia!\n");
                system("pause");
                system("cls");
            }
    }

    i--;

    printf("Digite o nome do aluno:\n-> ");

    setbuf(stdin, NULL);
    gets(p[i].nome);

    printf("\nInsira o endereco do aluno:\n-> ");

    setbuf(stdin,  NULL);
    gets(p[i].endereco);

    printf("\nInsira o numero de matricula:\n-> ");

    scanf("%d", &p[i].matricula);

    printf("\nInsira o telefone desta forma\n  (ddd) 9 9999-9999:\n-> ");

    setbuf(stdin,  NULL);
    gets(p[i].telefone);

    fp = fopen("arq_alunos.txt", "w");
    
    if(!p){
        printf("Erro ao acessar arquivo, impossivel prosseguir com alteracao");
        return;
    }
   
    fwrite(p, sizeof(alunos), tam, fp);
    fclose(fp);
    free(p);
    printf("Edicao realizada com sucesso!\n");
    system("pause");
}



void consultaAluno(){
    alunos *p;
    FILE *fp;

    int tam, opcaoNum, i;

    char opcaoStr[20];

    fp = fopen("arq_alunos.txt", "r");
    if(fp == NULL){
        printf("Erro ao fazer consulta!");
        system("pause");
        return;

    }
    fseek(fp, 0, 2);

    tam = ftell(fp)/sizeof(alunos);

    rewind(fp);

    p = (alunos *) malloc(tam * sizeof(alunos));

    if(p == NULL){
        printf("Erro na alocação, impossivel"
                   " concluir consulta");
        system("pause");
        return;

    }
    fread(p, sizeof(alunos), tam, fp);
    fclose(fp);

    printf("________________________________________________________________________________________\n");
    printf("\tNome \t\t       -\t Endereco \t- Matricula  -  Telefone\n");
    for(i=0; i<tam; i++){
        printf("________________________________________________________________________________________\n");
        printf("%-31s- %-20s   -    %d    - %s\n", p[i].nome,
                p[i].endereco, p[i].matricula, p[i].telefone);
    }
    
    printf("________________________________________________________________________________________\n");
    system("pause");

    free(p);
}

void removeAluno(){
    FILE *fp;
    alunos *p, *ptr_aux;
    int i=0, j=0, posi, tam;
    
    fp = fopen("arq_alunos.txt", "r");
    if(!fp){
        printf("Erro ao acessar arquivo, impossivel prosseguir remoção");
        system("pause");
        return;
    }
    fseek(fp, sizeof(alunos)*0, SEEK_END);
    
    tam= ftell(fp)/sizeof(alunos);
    
    rewind(fp);
    
    p = (alunos *) malloc(tam*sizeof(alunos));
    if(!p){
        printf("Erro ao alocar memoria, impossivel excluir\n");
        system("pause");
        return;
        
    }
    fread(p, sizeof(alunos), tam, fp);
    posi = -1;
    while(posi<=0 || posi > tam){      
        fclose(fp);
        printf("___________________________________________________________________________________________________________\n");
        printf("Num -\t\t     Nome\t\t\t-\t Endereco \t -  Matricula -     Telefone\n");
        for(i=0; i<tam; i++){
            printf("___________________________________________________________________________________________________________\n");
            printf("%-2d  -  %-40s - %-20s   -    %d    - %s\n", i+1, p[i].nome,
                    p[i].endereco, p[i].matricula, p[i].telefone);
        }
    
    printf("Digite o numero respectivo ao que deseja remover\n-> ");
    scanf("%d", &posi);
        if(posi<=0 || posi > tam){
            printf("Por favor, digite apenas numeros contidos na sequencia!\n");
            system("pause");
            system("cls");
        }
    }
    posi--;
    
    tam--;
    while(posi<=tam){
        p[posi] = p[posi+1];
        posi++;
        
    }

    p = (alunos *) realloc(p,tam*sizeof(alunos));

    fp = fopen("arq_alunos.txt", "w");
    
    fwrite(p, sizeof(alunos), tam, fp);
    
    fclose(fp);
    
    free(p);
    
    printf("\nAluno removido com sucesso!\n");
    
    system("pause"); 
}

void cadastraDisciplina()
{
    disciplinas bufdisc;
    FILE *fp;
    
    printf("Digite o nome da disciplina:\n-> ");
    setbuf(stdin, NULL);
    gets(bufdisc.nome);
    printf("Digite o codigo da disciplina:\n-> ");
    scanf("%d", &bufdisc.codigo);
                
    fp = fopen("disciplinas.txt", "a");
    if( fp == NULL)
    {
        printf("Erro na abertura o arquivo, impossivel concluir cadastro!\n");
        system("pause");
        return;
    }
    fwrite(&bufdisc, sizeof(struct disciplinas), 1, fp);
    fclose(fp);
    printf("Cadastro de disciplina realizado com sucesso\n");
    system("pause");
}

void editaDisciplina()
{
    FILE *fp;
    int tam_arq, i,cont=0;
    disciplinas *pd;

    fp = fopen ("disciplinas.txt", "r");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo, impossivel prosseguir com edicao!");
        system("pause");
        return;
    }
    fseek(fp, 0*sizeof(struct disciplinas), SEEK_END);
    tam_arq = ftell(fp)/sizeof(struct disciplinas);
    fseek(fp, 0*sizeof(struct notas), SEEK_SET);
    pd = (struct disciplinas*) malloc(tam_arq*sizeof(struct disciplinas));
    fread(pd, sizeof(struct disciplinas), tam_arq, fp);
    fclose(fp);

    fp = fopen("disciplinas.txt", "w");
    if(fp == NULL)
    {
        printf("Erro na abertura do arquivo, impossivel prosseguir com edicao!");
        system("pause");
        return;
    }

    printf("_________________________________________________________________\n");
    printf("\t\tDisciplina\t\t-   Codigo da disciplina\n");
       for(i=0; i<tam_arq; i++){       
        printf("_________________________________________________________________\n");
        printf("%-40s-\t %d\n", pd[i].nome, pd[i].codigo);
    }
    printf("_________________________________________________________________\n");
    int cod_disc;
    printf("Digite o codigo da disciplina que quer editar:\n-> ");
    scanf("%d", &cod_disc);
    printf("Digite o novo nome da disciplina:\n-> ");
    for(i=0; i<tam_arq; i++)
    {
        if(cod_disc == pd[i].codigo)
        {   
            cont++;
            setbuf(stdin, NULL);
            gets(pd[i].nome);
        }
    }
        if(cont == 0){
            printf("Disciplina nao encontrada!\n");
            system("pause");
            return;
        }
    fwrite(pd, sizeof(struct disciplinas), tam_arq, fp);
    printf("Alteracao realizada com sucesso!\n");
    free(pd);
    fclose(fp);
    system("pause");
}

void consultaDisciplina()
{
    
    FILE *fp;
    int tam_arq, i;
    disciplinas *pa;

    fp = fopen ("disciplinas.txt", "r");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo, impossivel fazer consulta!");
        system("pause");
        return;
    }
    fseek(fp, 0*sizeof(struct disciplinas), SEEK_END);
    tam_arq = ftell(fp)/sizeof(struct disciplinas);
    fseek(fp, 0*sizeof(struct notas), SEEK_SET);
    pa = (struct disciplinas*) malloc(tam_arq*sizeof(struct disciplinas));
    fread(pa, sizeof(struct disciplinas), tam_arq, fp);
    
    printf("_________________________________________________________________\n");
    printf("\t\tDisciplina\t\t-   Codigo da disciplina\n");
    for(i=0; i<tam_arq; i++){       
        printf("_________________________________________________________________\n");
        printf("%-40s-\t %d\n", pa[i].nome, pa[i].codigo);
    }
    printf("_________________________________________________________________\n");

    
    free(pa);
    fclose(fp);
    system("pause");
}

void removeDisciplina()
{
    FILE *fp;
    disciplinas *pa;
    int i, tam;

    fp = fopen("disciplinas.txt", "r");
    if (!fp)
    {
        printf("Erro ao abrir o arquivo, impossivel remover nota!\n");
        system("pause");
        return;
    }

    fseek(fp, 0*sizeof(disciplinas), SEEK_END);
    tam = ftell(fp)/sizeof(disciplinas);
    rewind(fp);

    
    pa = (disciplinas*) malloc(tam*sizeof(disciplinas));
    if(!pa)
    {
        printf("Erro ao alocar, impossivel remover disciplina!");
        system("pause");
        return;
    }

    fread(pa, sizeof(disciplinas), tam, fp);
    fclose(fp);

    i = -1;
    while(i<=0 || i>tam){

        printf("_______________________________________________________________________\n");
        printf("num -\t\tDisciplina\t\t       -  Codigo da disciplina\n");
        for(i=0; i<tam; i++){
            printf("_______________________________________________________________________\n");
            printf("%-3d -  %-40s-\t %d\n", i+1, pa[i].nome, pa[i].codigo);
        }
        printf("_______________________________________________________________________\n");


        printf("Digite o numero respectivo a disciplina que deseja remover\n-> ");
        scanf("%d", &i);
        if(i<=0 || i>tam){
            printf("Digite um numero que esta na sequencia!\n");
            system("pause");
            system("cls");
        }
    }
    i--;
    tam--;

    while(i <= tam)
    {
        pa[i] = pa[i+1];
        i++;
    }

    pa = (disciplinas*) realloc(pa, tam*sizeof(disciplinas));
    fp = fopen("disciplinas.txt", "w");
    if(!fp)
    {
        printf("Erro ao abrir oo arquivo, impossivel remover disciplina!\n");
        system("pause");
        return;
    }

    
    fwrite(pa, sizeof(disciplinas), tam, fp);
    fclose(fp);
    free(pa);
    printf("Remocao realizada com sucesso!\n");
    system("pause");
}

void cadastrarNotas(){
    FILE *fp;
    int tam,i;
    alunos *pa;
    struct notas buffer;
    struct disciplinas *ptr;
    fp = fopen("arq_alunos.txt", "r");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo, impossivel cadastrar nota!");
            system("pause");
            return;
        }
    fseek(fp,sizeof(alunos)*0,SEEK_END);
    tam = ftell(fp)/sizeof(alunos);
    rewind(fp);
    pa = (alunos*)malloc(sizeof(alunos)*tam);
    fread(pa,sizeof(alunos),tam,fp);
    fclose(fp);
    printf("________________________________________________________\n");
    printf("\t\tNome\t\t\t-  Matricula\n");
        for(i=0;i<tam;i++){
            printf("________________________________________________________\n");
            printf("%-40s-   %d\n", pa[i].nome,pa[i].matricula);
        }
    printf("________________________________________________________\n");

    printf("Digite o numero de matricula que deseja cadastrar notas:\n-> ");
    scanf("%d", &buffer.matricula);
    free(pa);
    system("cls");
    fp = fopen("disciplinas.txt", "r");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo, impossivel cadastrar nota!");
            system("pause");
            return;
        }
    fseek(fp,sizeof(struct disciplinas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct disciplinas);
    rewind(fp);
    ptr = (struct disciplinas*)malloc(sizeof(struct disciplinas)*tam);
    fread(ptr,sizeof(struct disciplinas),tam,fp);
    fclose(fp);
    printf("______________________________________________________________________\n");
    printf("    Disciplina\t\t\t\t -\tCodigo da disciplina\n");
          for(i=0;i<tam;i++){
            printf("______________________________________________________________________\n");
            printf("%-40s -\t%d\n", ptr[i].nome,ptr[i].codigo);
          }
    printf("______________________________________________________________________\n");

    printf("Digite o codigo da disciplina em que deseja cadastrar a nota:\n-> ");
    scanf("%d", &buffer.cod_disciplina);
    free(ptr);
    system ("cls");
    printf("Digite a nota 1 : \n-> ");
    scanf("%f", &buffer.nota1);
    printf("Digite a nota 2: \n-> ");
    scanf("%f",&buffer.nota2);
    printf("Digite a nota 3 : \n-> ");
    scanf("%f",&buffer.nota3);
    buffer.media = calculo_media(buffer.nota1,buffer.nota2,buffer.nota3);
    printf("Digite a frequencia do aluno(%%): \n");
    scanf("%d", &buffer.frequencia);
    fp = fopen("notas.txt", "a");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo,impossivel cadastrar nota!");
            system("pause");
            return;
        }
    fwrite(&buffer,sizeof(struct notas),1,fp);
    fclose(fp);
    printf("Cadastro realizado com sucesso!\n");
    system("pause");    
}

void editarNotas(){
    FILE *fp;
    int i,tam,buffer_notas,buffer_notas2,cont=0;
    struct disciplinas *ptr;
    struct notas buffer,*p;
    fp = fopen("disciplinas.txt", "r");
      if(fp == NULL) {
            printf("Erro na abertura do arquivo,impossivel editar nota!");
            system("pause");
            return;
      }
    fseek(fp,sizeof(struct disciplinas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct disciplinas);
    rewind(fp);
    ptr = (struct disciplinas*)malloc(sizeof(struct disciplinas)*tam);
    fread(ptr,sizeof(struct disciplinas),tam,fp);
    fclose(fp);
    printf("");

        printf("____________________________________________________________\n");
        printf("\tDisciplina\t\t  - \tCodigo\n");
        for(i=0;i<tam;i++){//mostra todas as disciplinas para editar uma nota qualquer.
            printf("____________________________________________________________\n");
            printf("%-30s  - \t %d\n\n", ptr[i].nome, ptr[i].codigo);
        }
    printf("____________________________________________________________\n");
    free(ptr);
    printf("Digite o codigo da disciplina que deseja editar notas:\n-> ");
    scanf("%d", &buffer_notas);//vai guardar o código da disciplina para modificar uma específica.
    system("cls");
    fp = fopen("notas.txt","r");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo,impossivel editar nota!");
            system("pause");
            return;
      }
    fseek(fp,sizeof(struct notas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct notas);
    rewind(fp);
    p = (struct notas*)malloc(sizeof(struct notas)*tam);
    fread(p,sizeof(struct notas),tam,fp);
    fclose(fp);
    printf("Alunos matriculados na disciplina %d:\n", buffer_notas);
    printf("____________________________________________________________________________\n");
    printf("Matricula - Disciplina - Nota 1 - Nota 2 - Nota 3 - Media - Frequencia\n");
    for(i=0;i<tam;i++){
        if(buffer_notas == p[i].cod_disciplina){//mostra todas as matriculas cadastradas naquela disciplina.

            cont++;
            printf("____________________________________________________________________________\n");

            printf("   %d\t  -    %d    -  %-6.1f-  %-6.1f-  %-6.1f-  %-5.1f-%6d%%\n\n", p[i].matricula, p[i].cod_disciplina,
               p[i].nota1, p[i].nota2, p[i].nota3, p[i].media, p[i].frequencia);
        }
    }
    printf("____________________________________________________________________________\n");

    if(cont==0){
        printf("\nDisciplina nao encontrada ou nenhum aluno cadastrado nesta disciplina!\n");
        system("pause");
        return;
    }
    printf("Digite a matricula do aluno que deseja editar em notas:\n-> ");
    scanf("%d",&buffer_notas2);//vai pegar o aluno em que vai ser editado a nota.
    system("cls");
    cont = 0;
        for(i=0;i<tam;i++){
            if(buffer_notas2 == p[i].matricula && buffer_notas == p[i].cod_disciplina){
                cont++;
                printf("|Alteracao da nota do aluno com matricula %d, na disciplina %d|\n-> ",p[i].matricula,p[i].cod_disciplina);
                printf("Digite a nota 1:\n-> ");
                scanf("%f", &p[i].nota1);
                printf("Digite a nota 2:\n-> ");
                scanf("%f", &p[i].nota2);
                printf("Digite a nota 3:\n-> ");
                scanf("%f", &p[i].nota3);
                p[i].media = calculo_media(p[i].nota1,p[i].nota2,p[i].nota3);
                printf("Digite a frequencia(%%):\n-> ");
                scanf("%d",&p[i].frequencia);                                        
                break;
            }
        }
    if(cont == 0){
        printf("Matricula nao encontrada!\n");
        system("pause");
        return;
    }
    fp = fopen("notas.txt", "w");
    fwrite(p,sizeof(struct notas),tam,fp);
    printf("Edicao realizada com sucesso!\n");
    fclose(fp);
    free(p);
    system("pause");
}

void consultarNotas(){
    FILE *fp;
    int tam,i;
    struct notas *p;
    fp =  fopen("notas.txt", "r");
        if (fp == NULL){
            printf("Erro na abertura do arquivo, impossivel consultar nota!");
            system("pause");
            return;
        }
    fseek(fp, 0 * sizeof(struct notas), SEEK_END);
    tam = ftell(fp) / sizeof(struct notas);
    rewind(fp);
    p = (struct notas *)malloc(sizeof(struct notas) * tam);
    fread(p, sizeof(struct notas), tam, fp);
    printf("_______________________________________________________________________\n");
    printf("Matricula - Disciplina - Nota 1 - Nota 2 - Nota 3 - Media - Frequencia\n");
        for (i = 0; i < tam; i++){
            printf("_______________________________________________________________________\n");
            printf("   %d\t  -    %d    -  %-6.1f-  %-6.1f-  %-6.1f-  %-5.1f-%6d%%\n\n", p[i].matricula, p[i].cod_disciplina,
               p[i].nota1, p[i].nota2, p[i].nota3, p[i].media, p[i].frequencia);
        }
    printf("_______________________________________________________________________\n");
    free(p);
    fclose(fp);
    system("pause");
}

void removeNotas(){
    FILE *fp;
    int tam,i,buffer_notas,buffer_notas2,j=0,*pos,cont=0;
    struct disciplinas *ptr;
    struct notas *p;
    fp = fopen ("disciplinas.txt", "r");
       if (fp == NULL)
       {
           printf("Erro na abertura do arquivo, impossivel remover notas");
           system("pause");
           return;
       }
    fseek(fp, 0*sizeof(struct disciplinas), SEEK_END);
    tam = ftell(fp)/sizeof(struct disciplinas);
    rewind(fp);
    ptr = (struct disciplinas*) malloc(tam*sizeof(struct disciplinas));
    fread(ptr, sizeof(struct disciplinas), tam, fp);
    
    printf("____________________________________________________________\n");
    printf("\tDisciplina\t\t  - \tCodigo\n");
    for(i=0; i<tam; i++){
        printf("____________________________________________________________\n");
        printf("%-30s  - \t %d\n\n", ptr[i].nome, ptr[i].codigo);
        }
    printf("____________________________________________________________\n");

    printf("Digite o codigo da disciplina em que deseja remover notas:\n");
    scanf("%d", &buffer_notas);
    free(ptr);
    fclose(fp);
    system("cls");
    fp = fopen("notas.txt","r");
        if(fp == NULL) {
                printf("Erro na abertura do arquivo");
                system("pause");
                return;
      }
    fseek(fp,sizeof(struct notas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct notas);
    rewind(fp);
    p = (struct notas*)malloc(sizeof(struct notas)*tam);
    fread(p,sizeof(struct notas),tam,fp);
    fclose(fp);
    pos = (int*)malloc(sizeof(int)*tam);
        if(!pos){
            printf("Nao foi possivel concluir a remocao");
            system("pause");
            return;
        }
    i = -1;
        while( i <= 0 || i > tam){ 
            j = 0;
            printf("____________________________________________________________________________\n");
            printf("num - Matricula - Disciplina - Nota 1 - Nota 2 - Nota 3 - Media - Frequencia\n");
            
            for(i=0;i<tam;i++){
                if(buffer_notas == p[i].cod_disciplina){//mostra todas as matriculas cadastradas naquela disciplina.
                    pos[j] = i;
                    j++;
                    printf("____________________________________________________________________________\n");
                    printf("%-4d-    %-7d-    %d    -  %-6.1f-  %-6.1f-  %-6.1f-  %-5.1f-%6d%%\n\n",j, p[i].matricula, p[i].cod_disciplina,
                    p[i].nota1, p[i].nota2, p[i].nota3, p[i].media, p[i].frequencia);
                }
            }
            printf("____________________________________________________________________________\n");

            if(j == 0){
                system("cls");
                printf("Nenhum aluno cadastrado nesta disciplina!\n");
                system("pause");
                return;
            }
            pos = (int*)realloc(pos,sizeof(int)*(j+1));
            printf("Digite a posicao do aluno que deseja remover em notas:\n-> ");
            scanf("%d",&i);
            if(i <= 0 || i > tam){
                printf("Por favor, digite apenas numeros contidos na sequencia!\n");
                system("pause");
                system("cls");
            }
        }
    i--;
    buffer_notas2 = pos[i];
    free(pos);
    tam--;
        while(buffer_notas2<=tam){
            p[buffer_notas2] = p[buffer_notas2 + 1];
            buffer_notas2++;
        }
    p = (struct notas*)realloc(p,sizeof(struct notas)*tam);
    fp = fopen("notas.txt", "w");
        if(fp == NULL) {
                printf("Erro na abertura do arquivo, impossivel remover nota");
                system("pause");
                return;
      }
    fwrite(p,sizeof(struct notas),tam,fp);
    free(p);
    fclose(fp);
    printf("Nota removida com sucesso!\n");
    system("pause");
}

float calculo_media(float a, float b, float c)
{
          float media;

          media = (a + b + c) / 3;

    return media;
}
