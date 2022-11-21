
#include <stdio.h>
#include <stdlib.h>

int
main ()
{

  int opcao = 0, opcao_alunos, opcao_disciplinas, opcao_notas, confirma_saida;
  system("color 0B");
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
            if (opcao_notas == 5)
                break;

 break;
case 4:

 system ("cls");
 printf ("_____________________________________________\n\n");
 printf ("Voce tem certeza que deseja sair do sistema?\n\n");
 
 printf ("1 - Sim\n");
 printf ("2 - Não\n\n");

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