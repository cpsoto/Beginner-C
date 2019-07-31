#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
float x;
int change, coins, quarter, dime, nickel, penny;
coins = 0;
quarter = 25;
dime = 10;
nickel = 5;
penny = 1;
do
    {
     printf("How much change is owed?");
     x = get_float ();
    }
while (x<0);

change = round(x*100);

while (change >= quarter)
    {coins++;
     change = (change - quarter);
    }
while (change >= dime)
    {coins++;
     change = (change - dime);
    }
while (change >= nickel)
    {coins++;
     change = (change - nickel);
    }
while (change >= penny)
    {coins++;
     change = (change - penny);
    }

printf("%i coins are owed.\n", coins);

return 0;
}