//This program is written by "Hassan Sardar"   roll no."22p-9108".

#include<stdio.h>
#include<time.h>      // header file for time function.
#include<stdlib.h>     // header file for random function.


int compute_sum();      // function declaration for computing sum of two cards from two decks.
int get_rounds();       // function declaration for getting no. of rounds from user.
int computer_guess();   // function declaration for which computer will guess the number.
int player_guess();     // function declaration from which player will guess the number.
int player_capital(int rounds);    // function declaration for which calculate the player's capital.
int computer_capital(int rounds);   // function declaration which will calculate the computer's capital.
int play(int rounds);       // function declaration which will tell us that whether player wins or lose. 

int main()
{
int r;
srand(time(NULL));    // random Time function call.

r=get_rounds();     // function call which will get the number of the rounds from user.
printf("\nplayer %d \n",play(r));   // function call which will tell us that whether player win or lose.

return 0;
}

int get_rounds()        // function definition which will get the number of rounds.
{
int r;

printf("Enter the number of rounds:");
scanf("%d",&r);

return r;    // return the no. of rounds to main.
}


int compute_sum()   // function that will calculate the sum of the two cards from deck.
{
int a, b, sum;
a=rand()%(10+1-0)+0;   // random function that will choose card from deck A.
b=rand()%(10+1-0)+0;   // random function that will choose card from deck B.
sum=a+b;          // sum of both cards.
return sum;   // return sum.
}


int computer_guess()  // function that will  return the computer's guess.
{
int a;
a=rand()%(20+1-3)+3;    // computer's guess.
return a;
}


int player_guess()     //  Function that will return the user's guess.
{
int guess;
printf("\nEnter your guess:");  
scanf("%d",&guess);      // User will enter his guess.
return guess;           // return the guess of user.
}


int player_capital(int rounds)    // This function will calculate the user's money that he won. 
{
int a;
int i=1;
while(i<=rounds)         
{
   if(player_guess() != compute_sum())  //  If user's guess is not equal to sum of cards.
   {
   printf("your guess is wrong");
   a=rounds-10;                           // Then it will detuct 10 rupees from user's money.
   }
   else
   {
   printf("your guess is right");
   a=rounds+compute_sum();              // If user's guess is right then that sum will include in User's money.
   }
i++;
}
return a;               // return's the amount money that user have won or lost.
}


int computer_capital(int rounds)           // This function will calculate the computer's money that he won. 
{
int b;
for(int i=1;i<=rounds;i++)
{
  if(computer_guess()==compute_sum())     // If computer's guess is right then that sum will include in computer's money.
  {
    b=rounds+compute_sum();
  }
  else                        //  If computer's guess is not equal to sum of cards.
  b=rounds-10;                // Then it will detuct 10 rupees from computer's money.
}

return b;
}


int play(int rounds)          // this function will return that user win or lost.
{
int c=player_capital(rounds);

if(c>computer_capital(rounds) || c==rounds)  // if user won then it will return 1.
return 1;
else                           // if user lost then it will return 0.
return 0;
}


