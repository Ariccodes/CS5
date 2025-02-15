#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

struct user{
	char username[100];
	int timePlayed;
	float ticTacToeHighScore;
	float rockPaperScissorsHighScore;
	float guessTheNumberHighScore;
	int guessesLeft;
	float headsOrTailsHighScore;
	float rememberTheNumber;
	int digit;
};
struct user user1;
char username[100];
int logKey=1;

//okay okay i ain't that smart, i did chatgpt the clearScreen function
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux/macOS
    #endif
}

//Functions
			int checkSpaces(char grid[][3]){
					int spaces=0,i,j;
					for(i=0;i<3;i++){
				    	for(j=0;j<3;j++){
					        if(grid[i][j]==0){
					        	spaces++;
							}
				    	}
				    }
				    if(spaces==0){
				    	return 0;
					}
					else{
						return 1;
					}
				}
				
				int checkGame(char grid[][3]){
					if(grid[0][0]=='x' && grid[0][1]=='x' && grid[0][2]=='x'){
						return 0;
					}
					else if(grid[1][0]=='x' && grid[1][1]=='x' && grid[1][2]=='x'){
						return 0;
					}
					else if(grid[2][0]=='x' && grid[2][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][0]=='x' && grid[2][0]=='x'){
						return 0;
					}
					else if(grid[0][1]=='x' && grid[1][1]=='x' && grid[2][1]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][2]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][1]=='x' && grid[2][0]=='x'){
						return 0;
					}
					//
				    else if(grid[0][0]=='o' && grid[0][1]=='o' && grid[0][2]=='o'){
						return 0;
					}
					else if(grid[1][0]=='o' && grid[1][1]=='o' && grid[1][2]=='o'){
						return 0;
					}
					else if(grid[2][0]=='o' && grid[2][1]=='o' && grid[2][2]=='o'){
						return 0;
					}
					else if(grid[0][0]=='o' && grid[1][0]=='o' && grid[2][0]=='o'){
						return 0;
					}
					else if(grid[0][1]=='o' && grid[1][1]=='o' && grid[2][1]=='o'){
						return 0;
					}
					else if(grid[0][2]=='o' && grid[1][2]=='o' && grid[2][2]=='o'){
						return 0;
					}
					else if(grid[0][0]=='o' && grid[1][1]=='o' && grid[2][2]=='o'){
						return 0;
					}
					else if(grid[0][2]=='o' && grid[1][1]=='o' && grid[2][0]=='o'){
						return 0;
					}
					else{
						return 1;	
					}
					}
					
					int checkWinner(char grid[][3]){
						if(grid[0][0]=='x' && grid[0][1]=='x' && grid[0][2]=='x'){
						return 0;
					}
					else if(grid[1][0]=='x' && grid[1][1]=='x' && grid[1][2]=='x'){
						return 0;
					}
					else if(grid[2][0]=='x' && grid[2][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][0]=='x' && grid[2][0]=='x'){
						return 0;
					}
					else if(grid[0][1]=='x' && grid[1][1]=='x' && grid[2][1]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][2]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][1]=='x' && grid[2][0]=='x'){
						return 0;
					}
					//
					else if(grid[0][0]=='o' && grid[0][1]=='o' && grid[0][2]=='o'){
						return 1;
					}
					else if(grid[1][0]=='o' && grid[1][1]=='o' && grid[1][2]=='o'){
						return 1;
					}
					else if(grid[2][0]=='o' && grid[2][1]=='o' && grid[2][2]=='o'){
						return 1;
					}
					else if(grid[0][0]=='o' && grid[1][0]=='o' && grid[2][0]=='o'){
						return 1;
					}
					else if(grid[0][1]=='o' && grid[1][1]=='o' && grid[2][1]=='o'){
						return 1;
					}
					else if(grid[0][2]=='o' && grid[1][2]=='o' && grid[2][2]=='o'){
						return 1;
					}
					else if(grid[0][0]=='o' && grid[1][1]=='o' && grid[2][2]=='o'){
						return 1;
					}
					else if(grid[0][2]=='o' && grid[1][1]=='o' && grid[2][0]=='o'){
						return 1;
					}
					}
					
					int validateMove(char grid[][3],int row,int column){
						if(grid[row][column]==0){
							return 0;
						}
						else if(grid[0][0]!=0 && grid[0][1]!=0 && grid[0][2]!=0 && grid[1][0]!=0 && grid[1][1]!=0 && grid[1][2]!=0 && grid[2][0]!=0 && grid[2][1]!=0 && grid[2][2]!=0){
							return 0;
						}
						else{
							return 1;
						}
					}
					
				//hol' up
					
					
int home(){
	int option=1;
	while(option!=3){
	    printf("=============================================================================\n");
	printf("                                  CS5 Games\n");
	printf("=============================================================================\n");
	printf("1.Login\n");
	printf("2.Sign Up\n");
	printf("3.Exit\n");	
	    printf("Choose your option:");
    	scanf("%d",&option);
	    switch(option){
		    case 1:
		    	while(logKey==1){
		    	printf("Enter your username:");
		    	scanf("%s",username);
		    	logKey++;
		    }
		    	FILE *fptr3=fopen("users.txt","r");
		    	while(fscanf(fptr3,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",user1.username,&user1.timePlayed,&user1.ticTacToeHighScore,&user1.rockPaperScissorsHighScore,&user1.guessTheNumberHighScore,&user1.guessesLeft,&user1.headsOrTailsHighScore,&user1.rememberTheNumber,&user1.digit)!=EOF){
		    		if(strcmp(user1.username,username)==0){
		    			printf("LOGIN SUCCESSFUL!!!\n");
		    			int startTime=time(NULL);
		    			int endTime;
	printf("=============================================================================\n");
	printf("                                  CS5 Games\n");
	printf("=============================================================================\n");
	printf("1.Tic Tac Toe\n");
	printf("2.Rock Paper Scissors\n");
	printf("3.Guess the number\n");
	printf("4.Heads or Tails\n");
	printf("5.Remember the number\n");
	printf("6.View profile\n");
	printf("7.Exit\n");
	int option;
	printf("Select an option:");
	scanf("%i",&option);
	switch(option){
		case 1:
			printf("=============================================================================\n");
	    	printf("                                Tic Tac Toe\n");
			printf("=============================================================================\n");
			option=1;
			float ticTacToeScore=0.0;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				char grid[3][3]={0};
				int i,j;
				printf("Assuming you are lonely, you will be playing against a computer making random moves.\n");
				printf("Each box in the grid has been encoded as the below layout.Type the assigned index to play your move(x) there.\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%i,%i   ",i,j);
					}
					printf("\n");
				}
				printf("-----------------------------------------------------------------------------\n");
				int row,column;
				while(checkSpaces(grid) && checkGame(grid)){
					printf("Enter your row and column:");
					scanf("%i %i",&row,&column);
					grid[row][column]='x';
					srand(time(0));
					int row=(rand()%(2-0+1))+0;
				   	int column=(rand()%(2-0+1))+0;
					while(validateMove(grid,row,column)){
						row=(rand()%(2-0+1))+0;
				    	column=(rand()%(2-0+1))+0;
					}
					if(grid[row][column]==0){
						grid[row][column]='o';
					}
					for(i=0;i<3;i++){
					    for(j=0;j<3;j++){
						    printf("%c", grid[i][j] == 0 ? '-' : grid[i][j]); //GPT
				    	}
				    	printf("\n");
				    }
				    printf("\n");
				}
				if(checkWinner(grid)==0){
					printf("YOU WON!!!\n");
					ticTacToeScore++;
				}
				else if(checkWinner(grid)==1){
					printf("COMPUTER WON!!!\n");
				}
				else{
				    printf("DRAW!\n");
					ticTacToeScore+=0.5;	
				}
				getch();
			}
			if(ticTacToeScore>user1.ticTacToeHighScore){
					struct user temp;
			FILE *fptr5=fopen("users.txt","r");
			FILE *temp2=fopen("temp.txt","w");
			while(fscanf(fptr5,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",temp.username,&temp.timePlayed,&temp.ticTacToeHighScore,&temp.rockPaperScissorsHighScore,&temp.guessTheNumberHighScore,&temp.guessesLeft,&temp.headsOrTailsHighScore,&temp.rememberTheNumber,&temp.digit)!=EOF){
				if(strcmp(temp.username,user1.username)==0){
				   temp.ticTacToeHighScore=ticTacToeScore;
				}
				fprintf(temp2,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",temp.username,temp.timePlayed,temp.ticTacToeHighScore,temp.rockPaperScissorsHighScore,temp.guessTheNumberHighScore,temp.guessesLeft,temp.headsOrTailsHighScore,temp.rememberTheNumber,temp.digit);
			};
			remove("users.txt");
			rename("temp.txt","users.txt");
			fclose(fptr5);
			fclose(temp2);
			}
			home();
		break;
		
		case 2:
			printf("=============================================================================\n");
	    	printf("                               Rock Paper Scissors\n");
			printf("=============================================================================\n");
			option=1;
			float rockPaperScissorsScore=0.0;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("Assuming you are lonely like me, you will be playing against a computer making random moves.\n");
				printf("Type the corresponding number to play that move.\n");
				printf("1.Rock\n");
				printf("2.Paper\n");
				printf("3.Scissors\n");
				printf("-----------------------------------------------------------------------------\n");
				int playerMove;
				printf("Play your move:");
				scanf("%i",&playerMove);
				switch(playerMove){
					case 1:
						printf("You played Rock. ");
					break;
					case 2:
						printf("You played Paper. ");
					break;
					case 3:
						printf("You played Scissors. ");
					break;
				}
				srand(time(0));
				int computerMove=(rand()%(3-1+1))+1;
				switch(computerMove){
					case 1:
						printf("Computer played Rock.\n");
					break;
					case 2:
						printf("Computer played Paper.\n");
					break;
					case 3:
						printf("Computer played Scissors.\n");
					break;
				}
				if(playerMove==computerMove){
					printf("DRAW!");
					rockPaperScissorsScore+=0.5;
				}
				else if(playerMove==1 && computerMove==2 ){
					printf("COMPUTER WINS!!!");
				}
				else if(playerMove==1 && computerMove==3 ){
					printf("YOU WIN!!!");
					rockPaperScissorsScore++;
				}
				else if(playerMove==2 && computerMove==1 ){
					printf("YOU WIN!!!");
					rockPaperScissorsScore++;
				}
				else if(playerMove==2 && computerMove==3 ){
					printf("COMPUTER WINS!!!");
				}
				else if(playerMove==3 && computerMove==1 ){
					printf("COMPUTER WINS!!!");
				}
				else if(playerMove==3 && computerMove==2 ){
					printf("YOU WIN!!!");
					rockPaperScissorsScore++;
				}
				printf("\n");
				printf("-----------------------------------------------------------------------------\n");
				getch();
              clearScreen();
			}
			if(rockPaperScissorsScore>user1.rockPaperScissorsHighScore){
					struct user temp;
			FILE *fptr6=fopen("users.txt","r");
			FILE *temp3=fopen("temp.txt","w");
			while(fscanf(fptr6,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",temp.username,&temp.timePlayed,&temp.ticTacToeHighScore,&temp.rockPaperScissorsHighScore,&temp.guessTheNumberHighScore,&temp.guessesLeft,&temp.headsOrTailsHighScore,&temp.rememberTheNumber,&temp.digit)!=EOF){
				if(strcmp(temp.username,user1.username)==0){
				   temp.rockPaperScissorsHighScore=rockPaperScissorsScore;
				}
				fprintf(temp3,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",temp.username,temp.timePlayed,temp.ticTacToeHighScore,temp.rockPaperScissorsHighScore,temp.guessTheNumberHighScore,temp.guessesLeft,temp.headsOrTailsHighScore,temp.rememberTheNumber,temp.digit);
			};
			fclose(fptr6);
			fclose(temp3);
			remove("users.txt");
			rename("temp.txt","users.txt");
			}
			home();
		break;	
		
		case 3:
	    	printf("=============================================================================\n");
	    	printf("                               Guess The Number\n");
			printf("=============================================================================\n");
		    option=1;
		    int totalGuessesLeft=0;
		    float guessTheNumberScore=0.0;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("\nThe computer will generate a random number from 1 to 100 without telling you and you have to guess the number within 10 tries.\n");
				//If your guess is more than 10 units higher than\
 the generated number ,the console will print \"Too High\" , if it is less than 10 units higher, the console will print \"High\" and correspondingly if your guess is more than 10 units lower, the console will print \"Too Low\",and if it is less than 10 units lower, the console will print \"Low\"
				getch();
				srand(time(0));
				int randnum=(rand()%(100-1+1))+1,guess=10,num=-1;
				while(guess>=1 || randnum!=num){
					printf("No. of guesses left:%d\n",guess);
					printf("Guess:");
					scanf("%d",&num);
					if(randnum>num){
						if(randnum-num > 10){
						printf("Too Low.\n");
					    }
					    else{
					    printf("Low.\n");
						}
					}
					else if(randnum<num){
						if(num-randnum > 10){
						printf("Too High.\n");
					    }
					    else{
					    printf("High.\n");
						}
					}
					else{
						printf("CORRECT!!!\n");
						getch();
						totalGuessesLeft+=guess;
						guessTheNumberScore++;
						break;
					}
					guess--;
				}
             printf("-----------------------------------------------------------------------------\n");
              clearScreen();
			}
			if(guessTheNumberScore>user1.guessTheNumberHighScore || (guessTheNumberScore==user1.guessTheNumberHighScore && totalGuessesLeft>user1.guessesLeft)){
					struct user temp;
			FILE *fptr7=fopen("users.txt","r");
			FILE *temp4=fopen("temp.txt","w");
			while(fscanf(fptr7,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",temp.username,&temp.timePlayed,&temp.ticTacToeHighScore,&temp.rockPaperScissorsHighScore,&temp.guessTheNumberHighScore,&temp.guessesLeft,&temp.headsOrTailsHighScore,&temp.rememberTheNumber,&temp.digit)!=EOF){
				if(strcmp(temp.username,user1.username)==0){
				   temp.guessTheNumberHighScore=guessTheNumberScore;
				   temp.guessesLeft=totalGuessesLeft;
				}
				fprintf(temp4,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",temp.username,temp.timePlayed,temp.ticTacToeHighScore,temp.rockPaperScissorsHighScore,temp.guessTheNumberHighScore,temp.guessesLeft,temp.headsOrTailsHighScore,temp.rememberTheNumber,temp.digit);
			};
			fclose(fptr7);
			fclose(temp4);
			remove("users.txt");
			rename("temp.txt","users.txt");
			}
			home();
		break;	
		
		case 4:
			printf("=============================================================================\n");
	    	printf("                               Heads or Tails\n");
			printf("=============================================================================\n");
		    option=1;
		    float headsOrTailsScore=0.0;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("Call dibs on either heads or tails.\n");
				printf("Type the corresponding number to call dibs on that side.\n");
				printf("1.Heads\n");
				printf("2.Tails\n");
				int side;
				printf("Call dibs on:");
				scanf("%i",&side);
				switch(side){
					case 1:
						printf("You called dibs on Heads.\n");
					break;
					case 2:
						printf("You called dibs on Tails.\n");
					break;
				}
				srand(time(0));
				int randSide=(rand()%2)+1;
				switch(randSide){
					case 1:
						printf("It landed Heads.\n");
					break;
					case 2:
						printf("It landed Tails.\n");
					break;
				}
				if(randSide==side){
					printf("You won.\n");
					headsOrTailsScore++;
				}
				else{
					printf("BRUHHHHH you lost with 1 in 2 odds.\n");
				}
				printf("-----------------------------------------------------------------------------\n");
				getch();
				clearScreen();
			}
			if(headsOrTailsScore>user1.headsOrTailsHighScore){
					struct user temp;
			FILE *fptr8=fopen("users.txt","r");
			FILE *temp5=fopen("temp.txt","w");
			while(fscanf(fptr8,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",temp.username,&temp.timePlayed,&temp.ticTacToeHighScore,&temp.rockPaperScissorsHighScore,&temp.guessTheNumberHighScore,&temp.guessesLeft,&temp.headsOrTailsHighScore,&temp.rememberTheNumber,&temp.digit)!=EOF){
				if(strcmp(temp.username,user1.username)==0){
				   temp.headsOrTailsHighScore=headsOrTailsScore;
				}
				fprintf(temp5,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",temp.username,temp.timePlayed,temp.ticTacToeHighScore,temp.rockPaperScissorsHighScore,temp.guessTheNumberHighScore,temp.guessesLeft,temp.headsOrTailsHighScore,temp.rememberTheNumber,temp.digit);
			};
			fclose(fptr8);
			fclose(temp5);
			remove("users.txt");
			rename("temp.txt","users.txt");
			}
			home();
		break;	
		
		case 5:
			printf("=============================================================================\n");
	    	printf("                              Remember The Number\n");
			printf("=============================================================================\n");
			option=1;
			float rememberTheNumberScore=0.0;
			int totalDigits=0;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("The computer will generate a random n digit number then in 5 seconds, it will clear the screen and you have to remember the number.\n");
				int n;
				printf("Enter the value of n:");
				scanf("%i",&n);
				srand(time(0));
				int randnum=(rand()%((int)(pow(10,n)-1)-(int)(pow(10,n-1))+1))+(int)pow(10,n-1);
				printf("Your number is %i.",randnum);
				time_t beginTime=time(NULL);
				while(time(NULL)-beginTime<=5){
				}
				clearScreen();
				int num;
				printf("Enter the number:");
				scanf("%i",&num);
				if(num==randnum){
					printf("CORRECT!!!\n");
					rememberTheNumberScore++;
					totalDigits+=n;
				}
				else{
					printf("INCORRECT!\n");
					printf("The number was %i.",randnum);
				}
				printf("-----------------------------------------------------------------------------\n");
              getch();
              clearScreen();
			}
			if(rememberTheNumberScore>user1.rememberTheNumber || (rememberTheNumberScore==user1.rememberTheNumber && totalDigits>user1.digit)){
					struct user temp;
			FILE *fptr9=fopen("users.txt","r");
			FILE *temp6=fopen("temp.txt","w");
			while(fscanf(fptr9,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",temp.username,&temp.timePlayed,&temp.ticTacToeHighScore,&temp.rockPaperScissorsHighScore,&temp.guessTheNumberHighScore,&temp.guessesLeft,&temp.headsOrTailsHighScore,&temp.rememberTheNumber,&temp.digit)!=EOF){
				if(strcmp(temp.username,user1.username)==0){
				   temp.rememberTheNumber=rememberTheNumberScore;
				   temp.digit=totalDigits;
				}
				fprintf(temp6,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",temp.username,temp.timePlayed,temp.ticTacToeHighScore,temp.rockPaperScissorsHighScore,temp.guessTheNumberHighScore,temp.guessesLeft,temp.headsOrTailsHighScore,temp.rememberTheNumber,temp.digit);
			};
			fclose(fptr9);
			fclose(temp6);
			remove("users.txt");
			rename("temp.txt","users.txt");
			}
			home();
		break;	
		
		case 6:
			printf("=============================================================================\n");
	    	printf("                                  Statistics\n");
			printf("=============================================================================\n");
			option=1;
			while(option==1){
				printf("1.View\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("\nUsername:%s\n",user1.username);
				printf("Time Played:%i\n",user1.timePlayed);
				printf("Tic Tac Toe High Score:%.1f\n",user1.ticTacToeHighScore);
				printf("Rock Paper Scissors High Score:%.1f\n",user1.rockPaperScissorsHighScore);
				printf("Guess The Number High Score:%.1f\n",user1.guessTheNumberHighScore);
				printf("   Guesses Left:%i\n",user1.guessesLeft);
				printf("Heads or Tails High Score:%.1f\n",user1.headsOrTailsHighScore);
				printf("Remember The Number High Score:%.1f\n",user1.rememberTheNumber);
				printf("   Digit:%i\n",user1.digit);
				getch();
			}
			home();
		break;
	
		case 7:
			endTime=time(NULL);
			int sessionTime=(endTime-startTime)/60;
			printf("In this session, You played for %d minutes.\n",sessionTime);
			user1.timePlayed+=sessionTime;
			struct user temp;
			FILE *fptr4=fopen("users.txt","r");
			FILE *temp1=fopen("temp.txt","w");
			while(fscanf(fptr4,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d",temp.username,&temp.timePlayed,&temp.ticTacToeHighScore,&temp.rockPaperScissorsHighScore,&temp.guessTheNumberHighScore,&temp.guessesLeft,&temp.headsOrTailsHighScore,&temp.rememberTheNumber,&temp.digit)!=EOF){
				if(strcmp(temp.username,user1.username)==0){
					temp.timePlayed+=sessionTime;
					printf("Total time played: %i minutes\n",temp.timePlayed);
				}
				fprintf(temp1,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",temp.username,temp.timePlayed,temp.ticTacToeHighScore,temp.rockPaperScissorsHighScore,temp.guessTheNumberHighScore,temp.guessesLeft,temp.headsOrTailsHighScore,temp.rememberTheNumber,temp.digit);
			};
			fclose(fptr4);
			fclose(temp1);
			remove("users.txt");
			rename("temp.txt","users.txt");
			return 0;
		break;
	}
					}
					else{
						printf("Username does not exist.\n");	
					}
				}
	    	break;
		    case 2:
			    printf("Pick a username:");
		    	scanf("%s",username);
		    	FILE *fptr2=fopen("users.txt","r");
		    	char testUsername[100];
		    	while(fscanf(fptr2,"%s %*d %*f %*f %*f %*d %*f %*f %*d",testUsername)!=EOF){
		    		if(strcmp(testUsername,username)==0){
		    			printf("The username already exists.\n");
		    			break;
					}
				}
				if(strcmp(testUsername,username)!=0){
					FILE *fptr1=fopen("users.txt","a");
			        fprintf(fptr1,"%s %d %.1f %.1f %.1f %d %.1f %.1f %d\n",username,0,0.0,0.0,0.0,0,0.0,0.0,0);
			        fclose(fptr1);
					}
				
		        fclose(fptr2);
		    break;
		    case 3:
			    return 0;
	    	break;
	}
}
    return 0;
}

//=============================================================================================================================================
//=============================================================================================================================================
//=============================================================================================================================================

int main(){
	home();
}
