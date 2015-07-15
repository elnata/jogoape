#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


    int main(){
    char palavra[100],secreta[100], dica[100], aux, ast[100], l, tentativa[100], jogador1[100], jogador2[100];
    int i=0,j=0, pontos=0, erros=0, num=0, acertos=0, acertof=0,pontosm=0;
    char url[]="jogador.txt";
	char ch;
	FILE *arq;

    srand(time(NULL));

printf("\33[H\33[2J");

    printf("Bem vindo ao jogo \n");
    printf("Qual seu nome jogador 1? \n");
    scanf("%s", jogador1);
    printf("Digite a palavra secreta: \n");
    scanf("%s", palavra);
    printf("Escreva a dica sobre a palavra secreta \n");
    scanf("%s",dica);

		printf("\33[H\33[2J");

	strcpy(secreta,palavra);

	num = strlen(palavra);


    for(i=0;i<num;i++){
    	j=(rand()%num);
    	aux=palavra[i];
    	palavra[i]=palavra[j];
    	palavra[j]=aux;
    	ast[i] = '*';

    }
    

    //printf("\n\n\n\n");
    	printf("Nome do segundo jogador\n");
    	scanf("%s", jogador2);
    	printf("Aperte enter para continuar\n");
    	getchar();
    	getchar();
    	printf("\33[H\33[2J");
   
  
    while((acertos != num ) || (pontos < 0) || (erros > 3)){
	printf("Olá jogador %s\n\n\n", jogador2 );
	printf("A dica da palavra é: %s \n\n", dica);
	printf("Essa é a palavra: \n");
	for(i=0;i<num;i++){
	printf("%c", ast[i]);
	}
	printf("\nDigite uma letra para: \n");
	scanf("%c",&l);
pontosm = 0;
    for(i=0;i<num;i++){
    	
    	if(l == palavra[i]){
    		pontos = pontos + 10;
    		ast[i]=palavra[i];

    		acertos = acertos + 1;
    		

    	}
    	
  	
    
    }
   /* j=0;
    	for(i=0;i<num;i++){

    		if (l == palavra[i])
    		{
    			j++;
    		}

    		if(j == 0){
    	pontos = pontos - 15;
    		erros= erro + 1;

    	}   	

    	}*/


     
}



printf("\33[H\33[2J");

if (acertos >= num ){
	printf("%s!\n", jogador2);
	printf("Parabens voce conseguiu desvendar as letras e achar a palavra secreta,\nporem as letras estão embaralhadas, voce ganhará pontos se acerta a palavra\n");
	printf("\n\nEssa é a palavra secreta embaralhada: %s \n",palavra);
	printf("\nEssa é a dica: %s\n", dica);
	printf("\nQual é a palavra?\n");
	scanf("%s", tentativa);
	for(i=0;i<num;i++){
	if(tentativa[i]==secreta[i]){

	printf("\33[H\33[2J");

		acertof +=1;
	}
}
if(acertof>=(num)){
	printf("\nParabens voce desvendou a palavra secreta \n\n");
	printf("\nA palavra secreta é %s\n\n", secreta);
	printf("Voce ira receber mais 50 pontos\n\n");
	pontos = pontos + 50;
}else{
	printf("\n\nNão foi dessa vez voce não desvendou a palavra embaralhada\n");
}

}else{
	

	printf("\n\nVoce perdeu!\n");
}
arq = fopen(url, "w");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fprintf(arq, "\nParabens: \n");
		fprintf(arq, "\nNome do jogador2: %s\n", jogador2);
		fprintf(arq, "\nSua pontuação: %d\n", pontos);
		fclose(arq);
	}
	
getchar();
getchar();





	
	

    return 0;
}
