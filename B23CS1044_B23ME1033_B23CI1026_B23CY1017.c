#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// NxN tic tac toe
// user against computer


int wincomputer(int turn, int n, int a[n][n])
{

    int sumr = 0, sumc = 0, d1 = 0, d2 = 0;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        sumr = 0;
        sumc = 0;
        d1 = 0;
        d2 = 0;

        for (int j = 0; j < n; j++)
        {
            sumr += a[i][j];
            sumc += a[j][i];
        }
        if (sumr == 5)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i][k] == 5)
                {
                    return (i + 1) * 10 + k + 1;
                    break;
                }
            }
        }

        if (sumc == 5)
        {
            for (int l = 0; l < n; l++)
            {
                if (a[l][i] == 5)
                {
                    return (l + 1) * 10 + i + 1;
                    break;
                }
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        d1 += a[k][k];
        d2 += a[n - k - 1][k];
    }

    if (d1 == 5)
    {

        for (int i = 0; i < n; i++)
        {
            if (a[i][i] == 5)
            {
                return (i + 1) * 10 + i + 1;
                break;
            }
        }
    }
    if (d2 == 5)
    {

        for (int i = 0; i < n; i++)
        {
            if (a[n - i - 1][i] == 5)
            {
                return (n - i) * 10 + i + 1;
                break;
            }
        }
    }

    else
    {
        return 0;
    }

}

int computerturn(int x, int y, int n, int a[n][n])
{

    int row = 0, cul = 0, di1 = 0, di2 = 0;

    if (x == y)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i][i] == 1)
            {
                di1++;
            }
        }
    }

    if (x + y - 2 == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[n - 1 - i][i] == 1)
            {
                di2++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (a[x - 1][i] == 1)
        {
            row++;
        }
        if (a[i][y - 1] == 1)
        {
            cul++;
        }
    }

    int test = 0, turn = 0;

    int max[4];
    max[0] = row;
    max[1] = cul;
    max[2] = di1;
    max[3] = di2;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (max[j] > max[j + 1])
            {
                int c = max[j];
                max[j] = max[j + 1];
                max[j + 1] = c;
            }
        }
    }

    int v = 4;
    while (test != 1)
    {

        if (max[v - 1] == row)
        {

            if (row > 1 && row < n)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[x - 1][i] == 5)
                    {
                        turn = (x)*10 + i + 1;
                        test++;

                        return turn;
                    }
                }
            }
        }

        if (max[v - 1] == cul)
        {

            if (cul > 1 && cul < n)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i][y - 1] == 5)
                    {
                        turn = (i + 1) * 10 + y;
                        test++;

                        return turn;
                    }
                }
            }
        }

        if (max[v - 1] == di1)
        {

            if (di1 > 1 && di1 < n)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i][i] == 5)
                    {
                        turn = (i + 1) * 10 + i + 1;
                        test++;

                        return turn;
                    }
                }
            }
        }
        if (max[v - 1] == di2)
        {

            if (di2 > 1 && di2 < n)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[n - 1 - i][i] == 5)
                    {
                        turn = (n - i) * 10 + i + 1;
                        test++;

                        return turn;
                    }
                }
            }
        }

        else if (v == 0)
            return 0;
        v--;
    }
}

int winner(int n, int a[n][n], int r)
{
    int sumr = 0, sumc = 0, d1 = 0, d2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumr = 0;
        sumc = 0;
        d1 = 0;
        d2 = 0;

        for (int j = 0; j < n; j++)
        {
            sumr += a[i][j];
            sumc += a[j][i];
        }
        if (sumr == 0 || sumc == 0)
        {
            printf("computer won \n");

            return 1;
        }
        if (sumr == n || sumc == n)
        {
            printf("you won \n");

            return 1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        d1 += a[k][k];
        d2 += a[n - k - 1][k];
    }

    if (d1 == 0 || d2 == 0)
    {
        printf("computer won \n");
        return 1;
    }
    if (d1 == n || d2 == n)
    {
        printf("you won \n");
        return 1;
    }

    int tie = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 5)
                tie++;
        }
    }

    if (tie == 0)
    {
        printf("match tie\n");
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{

    srand(time(NULL));
    int n = 3;

    printf("enter value of N for NxN - \n");
    scanf("%d", &n);
     system("cls");
    int min = 0;
    int max = n - 1;

    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 5;
        }
    }

    printf("your turn is X\n\n");
    int x, y;
    int q = 0, w = 0, e, r = 1;

     printf("choose your turn as follow-\n");
//
     for (int i = 0; i < n; i++)
        {
            printf("|");
            for (int j = 0; j < n; j++)
            {

               printf("%d %d|",i+1,j+1);
            }
            printf("\n");
        }

   

//
int tr=0;




    while (w != 1)
    {

        if (r % 2 != 0)
            e = 1;
        else
            e = 0;
        r++;

        if (e == 1)
        {
            tr = 0;
           int clr =1;
           
            while(tr!=1){
                
                  printf("your turn - \n");   
                scanf("%d%d", &x, &y);
                if(clr==1)system("cls");
                printf("you choose %d %d\n",x,y);
               
            //
            if(a[x - 1][y - 1]==5){
                 a[x - 1][y - 1] = e;
                 tr=1;
                 clr = 1;
            }
            else {
                printf("enter valid turn\n");
                clr = 1;
                tr= 0;

                        for (int i = 0; i < n; i++)
        {
            printf("|");
            for (int j = 0; j < n; j++)
            {

                if (a[i][j] == 5)
                    printf("___|");
                if (a[i][j] == 0)
                    printf("_O_|");
                if (a[i][j] == 1)
                    printf("_X_|");
            }
            printf("\n");
        }
                //
            }
            }
            
           //

        }

        else
        {
            int h, b;
            int turn, wturn;
            turn = computerturn(x, y, n, a);
            wturn = wincomputer(turn, n, a);

            if (wturn != 0)
                turn = wturn;
            int test = 0;

            if (turn == 0)
            {
                if(a[n/2][n/2]==5){
                    h=n/2;
                    b=n/2;
                }



                else{
                    h = rand() % (max - min + 1) + min;
                    b = rand() % (max - min + 1) + min;
                }

                while (test != 1)
                {
                    
                    if (a[h][b] == 5)
                    {
                        a[h][b] = 0;
                        
                        printf("computer's turn = %d %d\n", h + 1, b + 1);
                        test = 1;
                    }

                    else if (a[h][b] == 1 || a[h][b] == 0)
                    {
                        h = rand() % (max - min + 1) + min;
                        b = rand() % (max - min + 1) + min;

                        if (a[h][b] == 5)
                        {
                            a[h][b] = 0;
                            printf("computer's turn = %d %d\n", h + 1, b + 1);
                            test = 1;
                        }
                    }
                }
            }

            else
            {
                b = turn % 10;
                h = (turn - b) / 10;
                printf("computer's turn = %d, %d\n", h, b);
                a[h - 1][b - 1] = 0;
            }
        }
          
        for (int i = 0; i < n; i++)
        {
            printf("|");
            for (int j = 0; j < n; j++)
            {

                if (a[i][j] == 5)
                    printf("___|");
                if (a[i][j] == 0)
                    printf("_O_|");
                if (a[i][j] == 1)
                    printf("_X_|");
            }
            printf("\n");
        }

        w = winner(n, a, r);
    }
    
    return 0;
}
