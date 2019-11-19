#include<stdio.h>
#include<stdlib.h>

int main(){
 char matrix[3][3],exit;
 int x,y,a,b,turn,tanda,tanda2;
 
 do{turn=0;
  for(a=0;a<3;a++)
  {
  	for(b=0;b<3;b++)
	  {
	  matrix[a][b]=0;
	  }
  }

  do{
   //cetak
   system("cls");
   printf("XO Table\n");
   printf("=-=-=-=-=-=-\n\n");
   printf("    1 2 3\n");
   printf("           \n");
   for(a=0;a<3;a++)
   {
   	printf("  %d ",a+1);
   	for(b=0;b<3;b++)
	   {
	   if(matrix[a][b]==0)printf("- ");
	   else printf("%c ",matrix[a][b]);
	   }
	if(a<2)printf("\n\n");
	else printf("\n\n\n");
   }

   if(turn==0)
   {
   	printf("\n\n\nPlayer X Turn\n");
   }
   else
   {
	printf("\n\n\nPlayer O Turn\n");
   }
   printf("+-+-+-+-+-+-+-+-+-\n\n");
   
   //input
   do
   {
    do{
     x=0;
     printf("X Coordinate[1..3]: ");
     scanf("%d",&x);
	 fflush(stdin);
    }while(x>3||x<1);

    do{
     y=0;
     printf("Y Coordinate[1..3]: ");
     scanf("%d",&y);
	 fflush(stdin);
    }while(y>3||y<1);
	if(matrix[y-1][x-1]!=0)printf("\nPositions has been filled..\n\n");
   }while(matrix[y-1][x-1]!=0);
   
   //input matrix
   if(turn==0)matrix[y-1][x-1]='X';
   else matrix[y-1][x-1]='O';

   //cek
   tanda=0;
   tanda2=0;
   for(a=0;a<3;a++){
    for(b=0;b<3;b++){
     if(matrix[a][b]==0){tanda=1;}
    }
   }

   for(a=0;a<3;a++){
    if(matrix[a][0]==matrix[a][1]&& matrix[a][1]==matrix[a][2]){
     if(matrix[a][1]!=0){tanda=0;tanda2=1;}
    }
   }
   for(a=0;a<3;a++){
    if(matrix[0][a]==matrix[1][a] && matrix[1][a]==matrix[2][a]){
     if(matrix[1][a]!=0){tanda=0;tanda2=1;}}
   }
   if(matrix[0][0]==matrix[1][1]&& matrix[1][1]==matrix[2][2]){
    if(matrix[1][1]){tanda2=1;tanda=0;}}
   if(matrix[0][2]==matrix[1][1]&& matrix[1][1]==matrix[2][0]){
    if(matrix[1][1]){tanda=0;tanda2=1;}}

   //ubah turn
   if(turn==0)turn=1;
   else turn=0;
  }while(tanda==1);
  printf("XO Table\n");
   printf("=-=-=-=-=-=-\n\n");
   printf("    1 2 3\n");
   printf("                      \n");
   for(a=0;a<3;a++){
    printf("  %d ",a+1);
    for(b=0;b<3;b++){
     if(matrix[a][b]==0)printf("- ");
     else printf("%c ",matrix[a][b]);
    }
    if(a<2)printf(" \n\n");
    else printf(" \n\n\n");
   }

  printf("\n\nGame Over^^\n\n");
  if(tanda2==0){
   printf("Game is Draw..\n");
  }
  else{
   if ( turn == 0 )
    printf("Congratulations,players  \"O\" win!!\n");
   else
    printf("Congratulations,players \"X\" win!!\n");
  }
  printf("\n\n\n");
  do{
   system("pause");
   system("cls");
   printf("You want to repeat this game[y/n]: ");
   scanf("%c",&exit);
   fflush(stdin);
  }while(exit!='y' && exit != 'n');
 }while(exit!='n');
 printf("\n\n. . .Thanks for playing. . . ");
 getchar();
return 0;
}
