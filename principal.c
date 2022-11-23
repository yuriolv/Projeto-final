
#include <stdio.h>
#include <stdlib.h>
float calculo_media(float a, float b, float c);
int
main ()
{

  int opcao = 0, opcao_alunos, opcao_disciplinas, opcao_notas, confirma_saida;
  float media_notas;
  FILE *fp;
  system("color 0B");
  struct notas {
      int matricula,cod_disciplina,frequencia;
      float nota1,nota2,nota3,media;
  };
  struct notas buffer;
  while (opcao !=4) 
   {
      system ("cls");  
      printf ("----------Seja bem-vindo ao portal da UECE----------\n\n");
      printf ("_____________________________________________\n\n");
      printf ("-----------------Menu inicial----------------\n\n");
      printf ("1 - Alunos\n");
      printf ("2 - Disciplinas\n");
      printf ("3 - Notas\n");
      printf ("4 - Sair do sistema\n");
      printf ("_____________________________________________\n\n");
      printf ("Digite o numero respectivo ao que deseja fazer:\n");
      scanf ("%d", &opcao);

      switch (opcao)
{
case 1:

 system ("cls");
 printf ("_____________________________________________\n\n");
 printf ("-----------------Alunos----------------\n\n");
 printf ("1 - Cadastrar Alunos\n");
 printf ("2 - Editar alunos\n");
 printf ("3 - Consultar aluno\n");
 printf ("4 - Remover Aluno\n");
 printf("5 - Voltar ao menu inicial\n");
 printf ("_____________________________________________\n\n");
 printf ("Digite o numero respectivo ao que deseja fazer:\n");
 scanf ("%d", &opcao_alunos);
            if(opcao_alunos == 5)
                break;
            
 break;
case 2:

 system ("cls");
 printf ("_____________________________________________\n\n");
 printf ("-----------------Disciplinas----------------\n\n");
 printf ("1 - Cadastrar Disciplinas\n");
 printf ("2 - Editar Disciplinas\n");
 printf ("3 - Consultar Disciplinas\n");
 printf ("4 - Remover Disciplinas\n");
 printf("5 - Voltar ao menu inicial\n");
 printf ("_____________________________________________\n\n");
 printf ("Digite o numero respectivo ao que deseja fazer:\n");
 scanf ("%d", &opcao_disciplinas);
            if (opcao_disciplinas == 5)
                break;
            

 break;

case 3:
  while (opcao_notas != 5){
        system ("cls");
        printf ("_____________________________________________\n\n");
        printf ("-----------------Notas----------------\n\n");
        printf ("1 - Cadastrar notas\n");
        printf ("2 - Editar notas\n");
        printf ("3 - Consultar notas\n");
        printf ("4 - Remover notas\n");
        printf("5 - Voltar ao menu inicial\n");
        printf ("_____________________________________________\n\n");
        printf ("Digite o numero respectivo ao que deseja fazer:\n");
        scanf ("%d", &opcao_notas);
        system ("cls");
                    switch (opcao_notas){
                        case 1:  
                              printf("Digite a matricula e o codigo da disciplina: \n");
                              scanf("%d%d", &buffer.matricula,&buffer.cod_disciplina);
                              printf("Digite as 3 notas: \n");
                              scanf("%f%f%f", &buffer.nota1,&buffer.nota2,&buffer.nota3);
                              buffer.media = calculo_media(buffer.nota1,buffer.nota2,buffer.nota3);
                              printf("Digite a frequencia do aluno: \n");
                              scanf("%d", &buffer.frequencia);
                              fp = fopen("notas.txt", "a");
                                  if(fp == NULL) {
                                      printf("Erro na abertura do arquivo");
                                      exit(1);
}
                              fwrite(&buffer,sizeof(struct notas),1,fp);
                              fclose(fp);
                              printf("Cadastro realizado com sucesso!\n");
                              printf("Digite 1 se deseja continuar em notas, e digite 5 se deseja retornar ao menu inicial\n");
                              scanf("%d", &opcao_notas);
                        break;
                        case 2: 
                        break;
                        case 3: //ignorem o caso 3 por enquanto, ainda não está funcional.
                              fopen ("notas.txt", "r");
                              if(fp == NULL) {
                                      printf("Erro na abertura do arquivo");
                                      exit(1);
}
                              fread(&buffer,sizeof(struct notas),1,fp);
                              printf("%d %d %f %f %f %f %d", buffer.matricula,buffer.cod_disciplina, buffer.nota1,buffer.nota2,buffer.nota3,buffer.media,buffer.frequencia);
                              fclose(fp);
                              scanf("%d", &opcao_notas);
                        break;
                        case 4:
                        break;
                        case 5: 
                        break;
                        default:
                              printf("Por favor, digite apenas numeros de 1 a 5");
}
}
 break;
case 4:

 system ("cls");
 printf ("_____________________________________________\n\n");
 printf ("Voce tem certeza que deseja sair do sistema?\n\n");
 
 printf ("1 - Sim\n");
 printf ("2 - Nao\n\n");

 printf ("_____________________________________________\n\n");
 printf ("Digite o numero respectivo ao que deseja fazer:\n");
 scanf ("%d", &confirma_saida);
 
 if(confirma_saida==1)
     return 0;
 else {
   opcao = 0; 
   break;
}
 break;

default:

 printf ("Por favor digite apenas numeros de 1 a 4");

 break;
};
    }
  return 0;
}
float calculo_media(float a, float b, float c){
      float media;
      media = (a + b + c)/3;
return media;
}
