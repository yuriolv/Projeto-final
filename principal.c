#include <stdio.h>

#include <stdlib.h>

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
    char nome[20], endereco[20];

    int matricula, telefone;
}alunos;
typedef struct disciplinas {
    char nome[50];
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

                         };


                    }
                 break;

                case 2:
                    opcao_disciplinas = 0;
                    while(opcao_disciplinas != 5){

                           menuDisciplinas();
                           scanf("%d", &opcao_disciplinas);

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
                                        printf("Por favor, digite apenas numeros de 1 a 5");
                    }
            }

                break;

                case 4:

                    system("cls");

                    printf("_____________________________________________\n\n");

                    printf("Voce tem certeza que deseja sair do sistema?\n\n");

                    printf("1 - Sim\n");

                    printf("2 - Nao\n\n");

                    printf("_____________________________________________\n\n");

                    printf("Digite o numero respectivo ao que deseja fazer:\n");

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

          printf("_____________________________________________\n\n");

          printf("-----------------Menu inicial----------------\n\n");

          printf("1 - Alunos\n");

          printf("2 - Disciplinas\n");

          printf("3 - Notas\n");

          printf("4 - Sair do sistema\n");

          printf("_____________________________________________\n\n");

          printf("Digite o numero respectivo ao que deseja fazer:\n");


}

void menuAlunos()
{
     system("cls");

     printf("_____________________________________________\n\n");

     printf("-----------------Alunos----------------\n\n");

     printf("1 - Cadastrar Alunos\n");

     printf("2 - Editar alunos\n");

     printf("3 - Consultar aluno\n");

     printf("4 - Remover Aluno\n");

     printf("5 - Voltar ao menu inicial\n");

     printf("_____________________________________________\n\n");

     printf("Digite o numero respectivo ao que deseja fazer:\n");
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

            printf("Digite o numero respectivo ao que deseja fazer:\n");

}

void menuDisciplinas()
{
     printf("_____________________________________________\n\n");

     printf("-----------------Disciplinas----------------\n\n");

     printf("1 - Cadastrar Disciplinas\n");

     printf("2 - Editar Disciplinas\n");

     printf("3 - Consultar Disciplinas\n");

     printf("4 - Remover Disciplinas\n");

     printf("5 - Voltar ao menu inicial\n");

     printf("_____________________________________________\n\n");

     printf("Digite o numero respectivo ao que deseja fazer:\n");
}

void cadastraAluno(){
    alunos aluno_cad;
    FILE *fp;

    printf("_______________________"
               "______________________\n\n");
    printf("-------------cadastro de aluno-------------\n\n");
    printf("Digite o nome do aluno:\n");

    setbuf(stdin, NULL);
    gets(aluno_cad.nome);

    printf("\nInsira o endereço do aluno:\n");

    setbuf(stdin,  NULL);
    gets(aluno_cad.endereco);

    printf("\ninsira o numero de matricula:\n");

    scanf("%d", &aluno_cad.matricula);

    printf("\ninsira o telefone (somente numeros):\n");

     scanf("%d", &aluno_cad.telefone);

    fp = fopen("arq_alunos.txt", "a");

      if(fp == NULL){

        printf("\nErro a fazer o cadastro, tente novamente"
               "em outro momento");
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
        printf("Erro ao acessar o arquivo, impossivel prosseguir com alteração");
        return;
    }
    fseek(fp, 0, 2);

    tam = ftell(fp)/sizeof(alunos);

    rewind(fp);

    p = (alunos *) malloc(tam * sizeof(alunos));

    if(!p){
        printf("Erro ao alocar memoria, impossivel prosseguir com alteração");
        return;
    }

    fread(p, sizeof(alunos), tam, fp);

    fclose(fp);

    printf("__________________________________________\n");
    printf("Numero - Nome - Endereco - Matricula - telefone\n");
    for(i=0; i<tam; i++){
      printf("__________________________________________\n");

        printf("%d - %s - %s - %d - %d\n", i+1, p[i].nome,
                p[i].endereco, p[i].matricula, p[i].telefone);



    }
    printf("Digite o numero respectivo ao do aluno que deseja editar\n");

    scanf("%d", &i);

    i--;

    printf("Digite o nome do aluno:\n");

    setbuf(stdin, NULL);
    gets(p[i].nome);

    printf("\nInsira o endereço do aluno:\n");

    setbuf(stdin,  NULL);
    gets(p[i].endereco);

    printf("\ninsira o numero de matricula:\n");

    scanf("%d", &p[i].matricula);

    printf("\ninsira o telefone (somente numeros):\n");

    scanf("%d", &p[i].telefone);

    fp = fopen("arq_alunos.txt", "w");
    
    if(!p){
        printf("Erro ao acessar arquivo, impossivel prosseguir com alteração");
        return;
    }
   
    fwrite(p, sizeof(alunos), tam, fp);
   
   
    fclose(fp);
    free(p);
    
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

    printf("__________________________________________\n");
    printf("Nome - Endereco - Matricula -- telefone\n");
    for(i=0; i<tam; i++){
      printf("__________________________________________\n");

        printf("%s - %s - %d - %d\n", p[i].nome,
                p[i].endereco, p[i].matricula, p[i].telefone);



    }
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
        printf("erro ao alocar memoria, impossivel excluir\n");
        system("pause");
        return;
        
    }
    fwrite(p, sizeof(alunos), tam, fp);
    
    fclose(fp);
    
    consultaAluno();
    
    printf("digite o numero respectivo ao que deseja remover\n");
    scanf("%d", &posi);
    
    posi--;
    
    tam--;
    
    ptr_aux=(alunos *) malloc(tam*sizeof(alunos));
    if(!ptr_aux){
        printf("erro ao alocar memoria, impossivel excluir\n");
        system("pause");
        return;
        
    }
    while(i<=tam){
        
        if(i!= posi){
        ptr_aux[j] = p[i];
        
        j++;
        }
        
        i++;
        
    }
    
    
    free(p);
    
    fp = fopen("arq_alunos.txt", "w");
    
    fwrite(ptr_aux, sizeof(alunos), tam, fp);
    
    fclose(fp);
    
    free(ptr_aux);
    
    printf("\naluno removido com sucesso!\n");
    
    system("pause");
    
    
   
    
    
}

void cadastraDisciplina()
{
    int opcao_disciplinas;
    disciplinas bufdisc;
    FILE *fp;
    
    printf("Digite o nome da disciplina:\n");
    scanf("%s", &bufdisc.nome);
    printf("Digite o codigo da disciplina:\n");
    scanf("%d", &bufdisc.codigo);
                
    fp = fopen("disciplinas.txt", "a");
    if( fp == NULL)
    {
        printf("Erro na abertura o arquivo\n");
        exit(1);
    }
    fwrite(&bufdisc, sizeof(struct disciplinas), 1, fp);
    fclose(fp);
    printf("Cadastro de disciplina realizado com sucesso\n");
    printf("Digite 1 se deseja continuar em notas, e digite 5 se deseja retornar ao menu inicial\n");
    scanf("%d", &opcao_disciplinas);
}

void editaDisciplina()
{
    FILE *fp;
    int tam_arq, i;
    disciplinas *pd;

    fp = fopen ("disciplinas.txt", "r");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
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
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    for(i=0; i<tam_arq; i++)
    {
        printf("Disciplina: %s\n Codigo: %d\n\n", pd[i].nome, pd[i].codigo);
    }
    int cod_disc;
    printf("Digite o codigo da disciplina que quer editar:\n");
    scanf("%d", &cod_disc);
    printf("Digite o novo nome da disciplina:\n");
    for(i=0; i<tam_arq; i++)
    {
        if(cod_disc == pd[i].codigo)
        {   
            scanf("%s", &pd[i].nome);
        }
    }
    fwrite(pd, sizeof(struct disciplinas), tam_arq, fp);
    printf("Alteracao realizada com sucesso\n");
    free(pd);
    fclose(fp);
    system("pause");
}

void consultaDisciplina()
{
    int opcao_disciplinas;
    FILE *fp;
    int tam_arq, i;
    disciplinas *pa;

    fp = fopen ("disciplinas.txt", "r");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    fseek(fp, 0*sizeof(struct disciplinas), SEEK_END);
    tam_arq = ftell(fp)/sizeof(struct disciplinas);
    fseek(fp, 0*sizeof(struct notas), SEEK_SET);
    pa = (struct disciplinas*) malloc(tam_arq*sizeof(struct disciplinas));
    fread(pa, sizeof(struct disciplinas), tam_arq, fp);

    for(i=0; i<tam_arq; i++)
    {
        printf("Disciplina: %s\n Codigo: %d\n\n", pa[i].nome, pa[i].codigo);
    }
    free(pa);
    fclose(fp);
    printf("Digite 1 se deseja continuar em disciplinas, e digite 5 se deseja retornar ao menu inicial\n");
    scanf("%d", &opcao_disciplinas);
}

void cadastrarNotas(){
    FILE *fp;
    int tam,i;
    alunos *pa;
    struct notas buffer;
    struct disciplinas *ptr;
    fp = fopen("arq_alunos.txt", "r");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo");
            exit(1);
        }
    fseek(fp,sizeof(alunos)*0,SEEK_END);
    tam = ftell(fp)/sizeof(alunos);
    rewind(fp);
    pa = (alunos*)malloc(sizeof(alunos)*tam);
    fread(pa,sizeof(alunos),tam,fp);
    fclose(fp);
    printf("Digite o numero de matricula que deseja cadastrar notas:\n");
        for(i=0;i<tam;i++){
            printf(" %s: %d\n", pa[i].nome,pa[i].matricula);
        }
    scanf("%d", &buffer.matricula);
    free(pa);
    system("cls");
    fp = fopen("disciplinas.txt", "r");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo");
            exit(1);
        }
    fseek(fp,sizeof(struct disciplinas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct disciplinas);
    rewind(fp);
    ptr = (struct disciplinas*)malloc(sizeof(struct disciplinas)*tam);
    fread(ptr,sizeof(struct disciplinas),tam,fp);
    fclose(fp);
    printf("Digite o codigo da disciplina em que deseja cadastrar a nota:\n");
          for(i=0;i<tam;i++){
              printf("--> %s: %d\n", ptr[i].nome,ptr[i].codigo);
          }
    scanf("%d", &buffer.cod_disciplina);
    free(ptr);
    system ("cls");
    printf("Digite as 3 notas: \n");
    scanf("%f%f%f", &buffer.nota1,&buffer.nota2,&buffer.nota3);
    buffer.media = calculo_media(buffer.nota1,buffer.nota2,buffer.nota3);
    printf("Digite a frequencia do aluno(%%): \n");
    scanf("%d", &buffer.frequencia);
    fp = fopen("notas.txt", "a");
        if(fp == NULL) {
            printf("Erro na abertura do arquivo");
            exit(1);
        }
    fwrite(&buffer,sizeof(struct notas),1,fp);
    fclose(fp);
    printf("Cadastro realizado com sucesso!\n");
    system("pause");    
}

void editarNotas(){
    FILE *fp;
    int i,tam,buffer_notas,buffer_notas2;
    struct disciplinas *ptr;
    struct notas buffer,*p;
    printf("Digite o codigo da disciplina que deseja editar notas:\n");
    fp = fopen("disciplinas.txt", "r");
      if(fp == NULL) {
                printf("Erro na abertura do arquivo");
                exit(1);
      }
    fseek(fp,sizeof(struct disciplinas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct disciplinas);
    rewind(fp);
    ptr = (struct disciplinas*)malloc(sizeof(struct disciplinas)*tam);
    fread(ptr,sizeof(struct disciplinas),tam,fp);
    fclose(fp);
        for(i=0;i<tam;i++){//mostra todas as disciplinas para editar uma nota qualquer.
            printf("  Disciplina: %s\n  Codigo da disciplina: %d\n\n", ptr[i].nome,ptr[i].codigo);
        }
    free(ptr);
    scanf("%d", &buffer_notas);//vai guardar o código da disciplina para modificar uma específica.
    system("cls");
    fp = fopen("notas.txt","r");
        if(fp == NULL) {
                printf("Erro na abertura do arquivo");
                exit(1);
      }
    fseek(fp,sizeof(struct notas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct notas);
    rewind(fp);
    p = (struct notas*)malloc(sizeof(struct notas)*tam);
    fread(p,sizeof(struct notas),tam,fp);
    fclose(fp);
    printf("Alunos matriculados na disciplina %d:\n", buffer_notas);
        for(i=0;i<tam;i++){
            if(buffer_notas == p[i].cod_disciplina){//mostra todas as matriculas cadastradas naquela disciplina.
                printf(" Matricula: %d\n Disciplina: %d\n Notas: %.1f %.1f %.1f\n Media: %.1f\n"
                " Frequencia: %d%%\n\n",p[i].matricula,p[i].cod_disciplina, p[i].nota1,p[i].nota2,p[i].nota3,p[i].media,p[i].frequencia);
            }
        }
    printf("Digite a matricula do aluno que deseja editar em notas:\n");
    scanf("%d",&buffer_notas2);//vai pegar o aluno em que vai ser editado a nota.
    system("cls");
        for(i=0;i<tam;i++){
            if(buffer_notas2 == p[i].matricula && buffer_notas == p[i].cod_disciplina){
                printf("|Alteracao da nota do aluno com matricula %d, na disciplina %d|\n",p[i].matricula,p[i].cod_disciplina);
                printf("Digite as 3 novas notas:\n");
                scanf("%f%f%f", &p[i].nota1,&p[i].nota2,&p[i].nota3);
                p[i].media = calculo_media(p[i].nota1,p[i].nota2,p[i].nota3);
                printf("Digite a frequencia(%%):\n");
                scanf("%d",&p[i].frequencia);                                        
                break;
            }
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
            printf("Erro na abertura do arquivo");
            exit(1);
        }
    fseek(fp, 0 * sizeof(struct notas), SEEK_END);
    tam = ftell(fp) / sizeof(struct notas);
    rewind(fp);
    p = (struct notas *)malloc(sizeof(struct notas) * tam);
    fread(p, sizeof(struct notas), tam, fp);
        for (i = 0; i < tam; i++){
              printf("Matricula: %d\nDisciplina: %d\nNotas: %.1f %.1f %.1f\nMedia: %.1f\n"
              "Frequencia: %d%%\n\n", p[i].matricula, p[i].cod_disciplina, p[i].nota1, p[i].nota2, p[i].nota3, p[i].media, p[i].frequencia);
        }
    free(p);
    fclose(fp);
    system("pause");
}

void removeNotas(){
    FILE *fp;
    int tam,i,buffer_notas,buffer_notas2,j=0,resultado;
    struct disciplinas *ptr;
    struct notas *p,*p2;
    fp = fopen ("disciplinas.txt", "r");
       if (fp == NULL)
       {
           printf("Erro na abertura do arquivo");
           exit(1);
       }
    fseek(fp, 0*sizeof(struct disciplinas), SEEK_END);
    tam = ftell(fp)/sizeof(struct disciplinas);
    rewind(fp);
    ptr = (struct disciplinas*) malloc(tam*sizeof(struct disciplinas));
    fread(ptr, sizeof(struct disciplinas), tam, fp);
    printf("Digite o codigo da disciplina em que deseja remover notas:\n");
    for(i=0; i<tam; i++)
        {
            printf(" Disciplina: %s\n Codigo: %d\n\n", ptr[i].nome, ptr[i].codigo);
        }
    scanf("%d", &buffer_notas);
    free(ptr);
    fclose(fp);
    system("cls");
    printf("Digite a matricula do aluno que quer remover em notas:\n");
    fp = fopen("notas.txt","r");
        if(fp == NULL) {
                printf("Erro na abertura do arquivo");
                exit(1);
      }
    fseek(fp,sizeof(struct notas)*0,SEEK_END);
    tam = ftell(fp)/sizeof(struct notas);
    rewind(fp);
    p = (struct notas*)malloc(sizeof(struct notas)*tam);
    fread(p,sizeof(struct notas),tam,fp);
    fclose(fp);
    printf("Alunos matriculados na disciplina %d:\n", buffer_notas);
        for(i=0;i<tam;i++){
            if(buffer_notas == p[i].cod_disciplina){//mostra todas as matriculas cadastradas naquela disciplina.
                printf(" Matricula: %d\n Disciplina: %d\n Notas: %.1f %.1f %.1f\n Media: %.1f\n"
                " Frequencia: %d%%\n\n",p[i].matricula,p[i].cod_disciplina, p[i].nota1,p[i].nota2,p[i].nota3,p[i].media,p[i].frequencia);
            }
        }
    printf("Digite a matricula do aluno que deseja remover em notas:\n");
    scanf("%d",&buffer_notas2);
    
    tam--;
    p2 = (struct notas*)malloc(sizeof(struct notas)*tam);
    for(i=0;i<=tam;i++){
        if(buffer_notas != p[i].cod_disciplina && buffer_notas2 != p[i].matricula){
             p2[j] = p[i];
             j++;
        }
    }
    free(p);
    fp = fopen("notas.txt", "w");
        if(fp == NULL) {
                printf("Erro na abertura do arquivo");
                exit(1);
      }
    fwrite(p2,sizeof(struct notas),tam,fp);
    free(p2);
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
