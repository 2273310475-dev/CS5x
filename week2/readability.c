#include <stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main(void)///程序入口 从main开始执行
{
    string text = get_string("Text:");
    int letters = 0;
    int words =1;
    int sentences = 0;
    for (int i=0;i < strlen(text);i++)
    {
        char c = text[i];
        ///printf("%i %c\n",c,c);
        if(isalpha(c))
        {
            letters++;
        }
        if (isspace(c))
        {
            words++;
        }
        if (c=='.'||c=='!'||c=='?')
        {
            sentences++;
        }
    }
    float L =(letters*100.0)/words;
    float S =(sentences*100.0)/words;
    float index = 0.0588*L - 0.296*S - 15.8;
    int grade = round(index);
    ///printf("%f%f%f%i\n",L,S,index,grade);
    if (grade<1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade>= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",grade);
    }


}
