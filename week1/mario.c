#include <stdio.h>
#include <cs50.h>
int hight;
void print_row(int spaces,int bricks);
int main(void)
{
    do
    {
        hight= get_int("hight: ");

    }
    while (hight<1||hight>8);

    for (int row =0; row<hight; row++)
    {
        int spaces = hight-row-1;
        int bricks = row+1;
        print_row(spaces,bricks);
    }

}
void print_row(int spaces,int bricks)
{
    for(int i =0;i<spaces;i++)
    {
        printf(" ");
    }
    for(int i =0; i<bricks; i++)
        {
            printf("#");
        }
        printf("\n");
}
