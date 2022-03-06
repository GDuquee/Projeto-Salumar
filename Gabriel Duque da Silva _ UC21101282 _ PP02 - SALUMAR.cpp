//Nome: Gabriel Duque da Silva //Mátricula: UC21101282 //Curso: BCC

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>  
#include<conio.h>
#include<string.h>

//funcao para cores
enum DOS_COLORS{
 preto, azul, verde, CYAN, vermelho, MAGENTA, castanho,
 cizento_claro, cizento_escuro, azul_claro, verde_claro, CYAN_claro,
 vermelho_claro, MAGENTA_claro, amarelo, branco
};


void textcolor(int iColor){
 HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
 BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
 bufferInfo.wAttributes &= 0x00F0;
 SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}
int main(void){//iníco do algoritimo 
	
int menuPrincipal, menu, numero_passagem=0,matriz_numero[10][20], qnt_local, i = 0, j = 0, contador = 0, local_escolhido, numero_cliente, idade,local[10][20],contadorreservas=0, contadordisponiveis=0, contadorconfirmada=0;
char localPartida[50], localChegada[50], horario[10], letra[10][20], nome[30], cpf[12];
float preco, preco_total=0;


//float - %f
//double - %lf
//int - %d ou %i
//char - %c	

do{//funcao para retornar ao inicio do sistema
   
    do{//funcao para retornar ao menu

 	textcolor(azul_claro);
 	printf("--------------------COMPANHIA DE LINHAS AEREAS---------------------\n");
 	textcolor(branco);
 	printf("\n                            SALUMAR                              \n");
 	textcolor(azul_claro);
 	printf("\n\n      Voce acaba de inicializar o sistema de vendas da empresa \n");
 	printf("\n                       O que deseja realizar?                    \n");
 	printf("\n\n\n                       1- Registrar um Voo \n                       2- Cadastro do Cliente\n                       3- Realizar Reserva \n                       4- Confirmar Reserva \n                       5- Cancelar Reserva \n                       6- Informacoes do Voo\n                       7- Fechar programa\n");
 	textcolor(branco);
	printf("\n\n                  *Digite o numero correspondente* \n");
	textcolor(azul_claro);
 	printf("-------------------------------------------------------------------\n");
 	printf("\n->");
 	textcolor(branco);
	scanf("%d", &menuPrincipal);
 	fflush(stdin);
 
 
 
	
	
	switch (menuPrincipal){
		
			case 1: 
			textcolor(azul_claro);
			printf("\n-------------------------------------------------------------------");
			printf("\n                            Bem Vindo!\n                           ");
			printf("\n		Para registrar o seu voo, digite:                          \n");
			printf("\n			*Local de partida: 									   \n");	
			fflush(stdin);
			printf("\n->");
 			textcolor(branco);
			do{
					fgets(localPartida, 50, stdin);
					if(strlen(localPartida)<3)
					{
					textcolor(branco);
					printf("Ponto de partida nao encontrada, digite novamente\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}	
			}
					while(strlen(localPartida)<3);
					textcolor(azul_claro);
					printf("\n			*Local de chegada:									   \n");
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					fgets(localChegada, 50, stdin);
					if(strlen(localChegada)<3)
					{
					textcolor(branco);
					printf("Ponto de chegada nao encontrada, digite novamente\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}
			}
					while (strlen(localChegada)<3);
					textcolor(azul_claro);
					printf("\n	    	    *Horario do voo desejado:\n	    	              (24h)         \n");
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					fgets(horario, 10, stdin);
					if(strlen(horario)<0)
					{
						textcolor(branco);
					printf("Nenhum voo encontrado neste horario\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}
			}
					while(strlen(horario)<0);
					textcolor(azul_claro);
					printf("\n 	    	    *Quantidade de assentos nesse voo.\n	  OBS: quantidade deve ser maior que 90 e menor que 200\n");
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					scanf("%d", &qnt_local );
					if(qnt_local < 90 || qnt_local > 200)
					{
					printf("Aviao com quantidade de assesntos inexistente\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}	
			}
					while(qnt_local < 90 || qnt_local > 200);
					textcolor(azul_claro);
					printf("	    	    *Informe o preco das passagens\n");
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					scanf("%f", &preco);
					if(preco < 60)
					{
					printf("O valor minimo da passagem aerea custa 100 Reais\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);	
					}
			}
					while(preco<60);
					
					system("pause");
					system("cls");
					
								 for ( i = 0; i < 10; i++)//criacao da matriz para os locais no voo
			        {
			            for ( j = 0; j < 20; j++)
			            {
			               contador++;
			               local[i][j]=contador;
			            }  
			        }
			        for ( i = 0; i < 10; i++)
			        {
			            for ( j = 0; j < 20; j++)
			            {
			               if (local[i][j] <= qnt_local)
			               {
			                   letra[i][j] = 'D';//os locais recebem o valor da variavel D = disponivel no inicio
			               }
           				}  
        			}
        			break;
        			
			case 2:
					textcolor(azul_claro);
					printf("\n-------------------------------------------------------------------");
					printf("\n                            Bem Vindo!\n                           ");
					printf("\n	     Para fazer o cadastro do cliente, digite:                          \n");
					printf("\n			*Nome do cliente: 									   \n");	
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					fgets(nome, 30, stdin);
					if (strlen(nome)<3)
					{
					printf("Nome ivalido, insira outro nome\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}
			}
					while(strlen(nome)<3);
					textcolor(azul_claro);
					printf("			*CPF do cliente:\n");
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					fgets(cpf,12,stdin);
					if (strlen(cpf)!=11)
					{
					printf("O CPF deve conter 11 digitos\n");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}
			}		
					while(strlen(cpf)!=11);
						textcolor(azul_claro);
					printf("			*Idade do cliente:\n");
					fflush(stdin);
					printf("\n->");
 					textcolor(branco);
			do{
					scanf("%d", &idade);
					if(idade< 1 || idade > 100)
					{
					printf("Idade invalida");
					textcolor(azul_claro);
					printf("->");
					textcolor(branco);
					}
			}
					while(idade< 1 || idade > 100);
					 if (idade <= 5)//se a idade for menor ou igual a 5 
       				 {
           			 preco = preco/2;//define o valor do preco 
        			}
        			break;
        			system("pause");
					system("cls");
        			
        	case 3:
        			textcolor(azul_claro);
			        system("cls");
			       	printf("\n-------------------------------------------------------------------");
					printf("\n                            Bem Vindo!\n                           ");
					textcolor(branco);
					printf("\n	                Realizar uma Reserva                       \n");
					textcolor(azul_claro);
					printf("\n		  *Locais disponiveis para escolha 									   \n");
			        fflush(stdin);
			        numero_passagem++;//autoincrement para realizar os numeros das passagens diferentes 
			        textcolor(amarelo);
        
			        for(j=0;j<20;j++){//matriz dos lugares disponiveis
			        for(i=0;i<10;i++){
			            if(local[i][j]<= qnt_local && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
			                if (letra[i][j]=='R')//define o local como reservado na cor vermelha
			                {
			                    textcolor(vermelho);
			                    printf("%.3d ", local[i][j]);
			                    printf("%c ", letra[i][j]);
			                    textcolor(verde_claro);
			                }else if (letra[i][j]=='D')//define o local com disponivel na cor verde claro
			                {
			                    textcolor(verde_claro);
			                    printf("%.3d ", local[i][j]);
			                    printf("%c ", letra[i][j]);
			                } else if (letra[i][j]=='C')//define o local como confirmado na cor azul
			                        {
			                        textcolor(azul);
			                        printf("%.3d ", local[i][j]);
			                        printf("%c ", letra[i][j]);
			                        textcolor(branco);
			                        }
			                }
			            } 
			        printf("\n"); //pula uma linha 
			        }
			        textcolor(azul_claro);
			        printf("\n		  Escolha o numero do local desejado \n");
			        textcolor(CYAN);
			        printf("-> ");
			        textcolor(amarelo);
			        scanf("%d", &local_escolhido);
			        system("cls");
			        textcolor(verde_claro);
			        fflush(stdin);//aloca o numero do local escolhido na variavel
			        for(j=0;j<20;j++){
			        for(i=0;i<10;i++){
			            if(local[i][j] == local_escolhido){
			                letra[i][j] = 'R';
			                matriz_numero[i][j]= numero_passagem;//gera o numero de passagem para realizar a confirmacao ou cancelar
			                } 
			            }       
			        }
        
			        for(j=0;j<20;j++){//atualizacao dos lugares no voo definindo os assentos corretamente depois da escolha
			        for(i=0;i<10;i++){
			            if(local[i][j]<= qnt_local && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
			                if (letra[i][j]=='R')
			                {
			                    textcolor(vermelho);
			                    printf("%.3d ", local[i][j]);
			                    printf("%c ", letra[i][j]);
			                    textcolor(verde_claro);
			                }else if (letra[i][j]=='D')
			                {
			                    textcolor(verde_claro);
			                    printf("%.3d ", local[i][j]);
			                    printf("%c ", letra[i][j]);
			                } else if (letra[i][j]=='C')
			                        {
			                        textcolor(azul);
			                        printf("%.3d ", local[i][j]);
			                        printf("%c ", letra[i][j]);
			                        textcolor(amarelo);
			                        }
			                }
			            } 
			        printf("\n");       
			        }
			        textcolor(amarelo);
			        textcolor(azul_claro);
			        printf("\n		  Local escolhido: %d \n", local_escolhido);
			        printf("\n		Numero da sua reserva: %d \n", numero_passagem);
			        printf("\n-------------------------------------------------------------------\n\n");
			        system("pause");
			        system("cls");
			    break;
    
    case 4: 
    
		    		textcolor(azul_claro);
			        system("cls");
			        printf("\n-------------------------------------------------------------------");
					printf("\n                            Bem Vindo!\n                           ");
					textcolor(branco);
					printf("\n	               Confirmar uma Reserva                       \n");
					textcolor(azul_claro);
			        printf("\n       Para confirmar sua passagem ensira o numero da reserva: \n");
			        printf("\n-> ");
			        textcolor(branco);
			        fflush(stdin);
			        do
			        {
			            scanf("%d", &numero_cliente);//recebe o valor da variavel do numero da passagem passando para o numero do cliente
			            if (numero_cliente > numero_passagem)//checagem do numero da passagem
			            {
			                printf("Reserva nao encontrada \n");
			                textcolor(azul_claro);
			                printf("-> ");
			                textcolor(branco);
			            }
			            
			        } while (numero_cliente > numero_passagem);  
			
			        
			        for(j=0;j<20;j++){//transformacao do local reservado para confirmado
			            for(i=0;i<10;i++){
			                if(matriz_numero[i][j] == numero_cliente && letra[i][j]== 'R'){
			                    letra[i][j] = 'C';
			                    } 
			                }       
			            } 
			            textcolor(azul_claro);
			        printf("\n	          Reserva Confirmada com Sucesso!\n");
			        printf("\n-------------------------------------------------------------------\n\n");
				system("pause");
				system("cls");		      
			    break;
			    
			    case 5:
			    	
			    		 textcolor(azul_claro);
			    		  system("cls");
			        printf("\n-------------------------------------------------------------------");
					printf("\n                            Bem Vindo!\n                           ");
					textcolor(branco);
					printf("\n	               Cancelar uma Reserva                       \n");
					textcolor(azul_claro);
			        printf("\n       Para cancelar sua passagem ensira o numero da reserva: \n");
			        printf("\n-> ");
			        textcolor(branco);
			        fflush(stdin);
			        do
			        {
		            scanf("%d", &numero_cliente);
		            if (numero_cliente > numero_passagem)
		            {
		               printf("Reserva nao encontrada \n");
			            textcolor(azul_claro);
			            printf("-> ");
			            textcolor(branco);
		            }
		            
		        } while (numero_cliente > numero_passagem);  

        
        for(j=0;j<20;j++){//transformacao do local de reservado para disponivel
            for(i=0;i<10;i++){
                if(matriz_numero[i][j] == numero_cliente && (letra[i][j]== 'R' ||letra[i][j]== 'C')){
                    letra[i][j] = 'D';
                    
                    } 
                }       
            }
             textcolor(azul_claro);
			 printf("\n	          Reserva Cancelada com Sucesso!\n");
			 printf("\n-------------------------------------------------------------------\n\n");
    system("pause");
    system("cls");
    break;
    
    case 6:
    	
    		textcolor(azul_claro);
       		system("cls");
        	printf("\n-------------------------------------------------------------------");
			printf("\n                            Bem Vindo!\n                           ");
			textcolor(branco);
			printf("\n	           Verificar Locais Disponiveis                       \n");
			textcolor(azul_claro);
			printf("\n		 *Locais disponiveis para escolha 									   \n");
			fflush(stdin);
        
        for(j=0;j<20;j++){//exibicao da matriz dos assentos atualizada, mostrando os lugares disponiveis, reservados e confirmados
        for(i=0;i<10;i++){
            if(local[i][j]<=contador && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                if (letra[i][j]=='R')
                {
                    textcolor(vermelho);
                    printf("%.3d ", local[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(verde_claro);
                } else if (letra[i][j]=='D'){
                    textcolor(verde_claro);
                    printf("%.3d ", local[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(branco);
                } else if (letra[i][j]=='C')
                {
                    textcolor(azul);
                    printf("%.3d ", local[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(amarelo);
                }
                
                } 
            } 
        printf("\n");       
        }
        printf("\n");
        textcolor(vermelho);
        printf("Reservado  ");
        textcolor(azul);
        printf("Confirmado  ");
        textcolor(verde);
        printf("Disponivel  \n");
        textcolor(branco);
         textcolor(azul_claro);
       	printf("-------------------------------------------------------------------\n");
          
        system("pause");
        system("cls");
        
        textcolor(azul_claro);
        system("cls");
        	printf("\n-------------------------------------------------------------------");
			textcolor(branco);
			printf("\n	                INFORMACOES DO VOO                      \n");
			textcolor(azul_claro);
			fflush(stdin);
       
        printf("\n	                Lugar de partida: %s \n", localPartida);//exibicao do valor da variavel origem
        printf("\n	                Lugar de chegada: %s \n", localChegada);//exibicao da variavel destino
        printf("\n	                Local escolhido: %d \n",local_escolhido);//exibicao da variavel local_escolhido
       	printf("\n-------------------------------------------------------------------\n");
        
        system("pause");
        system("cls");
        
        printf("\n-------------------------------------------------------------------\n");
        
        for(j=0;j<20;j++){//matriz para o contador dos locais
                for(i=0;i<10;i++){
                    if(local[i][j]<=contador && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                        if (letra[i][j]=='R')
                        {
                            textcolor(vermelho);
                            printf("%.3d ", local[i][j]);
                            printf("%c ", letra[i][j]);
                            contadorreservas++;//contador para os locais reservados
                            textcolor(verde_claro);
                        } else if (letra[i][j]=='D'){
                            textcolor(verde_claro);
                            printf("%.3d ", local[i][j]);
                            printf("%c ", letra[i][j]);
                            contadordisponiveis++;//contador para os locais disponiveis
                            textcolor(amarelo);
                        } else if (letra[i][j]=='C')
                        {
                            textcolor(azul);
                            printf("%.3d ", local[i][j]);
                            printf("%c ", letra[i][j]);
                            contadorconfirmada++;//contador para os locais confirmados
                            preco_total  += preco;
                            textcolor(amarelo);
                        }
                        
                        } 
                    } 
                printf("\n");       
                }
                textcolor(azul_claro);
                printf("	                Quantidade de locais disponiveis: %d \n", contadordisponiveis);//exibicao do total de locais disponiveis
                printf("\n	                Quantidade de locais reservados: %d \n", contadorreservas);//exibicao do total de locais reservados
                printf("\n	                Quantidade de locais confirmados: %d \n", contadorconfirmada);
                printf("\n	                Preco da passagem: %.2lf \n", preco);
                printf("\n	                Valor total das passagens confirmadas: %.2lf \n", preco_total);
                printf("-------------------------------------------------------------------\n");
            
        system("pause");
        system("cls");
        break;
        
        case 7://sair do programa
    	textcolor(azul_claro);
        system("cls");
        printf("\n-----------------------------SALUMAR--------------------------------------\n");
        textcolor(branco);
        printf("\n           Obrigado por utilizar o nosso sistema de vendas!\n");
        textcolor(azul_claro);
        printf("\n-----------------------------SALUMAR--------------------------------------\n");
        system("pause");
        exit(1);//finalizacao do programa
    
    break;
    
    default: system("cls");//caso nao seja selecionado nenhuma das opcoes no menu o programa limpa a tela
        break;	
        			
			}	
			
			
    
      
    } while (menu >= 1 && menu < 9);//comando para voltar ao 2 "do" onde ira abrir o menu novamente
    
    if(menu <1|| menu > 9)//chegacem para ver se o numero que foi enserido existe no meu
    {
    	printf("Ensira uma opcao valida\n");
    	
	}  
}while(menu <1|| menu > 9);//retorna para o 1 "do" caso a opcao do menu escolhida nao seja identificada	
				
					
	
	
	return 0;}
