# CS50 Readability Problem Notes

## 1. Problem Description

In this problem, we write a program that calculates the approximate grade level needed to comprehend some text.

中文理解：

这道题要你写一个程序，计算一段文字大概需要什么阅读年级才能看懂。

Key words:

- implement = 实现
- calculate = 计算
- approximate = 大概的 / 近似的
- grade level = 年级水平
- comprehend = 理解
- text = 文本

---

## 2. Program Goal

The program needs to:

1. Ask the user to input some text
2. Count the number of letters
3. Count the number of words
4. Count the number of sentences
5. Use the Coleman-Liau formula
6. Print the reading grade

中文理解：

程序要做六件事：

1. 让用户输入一段文字
2. 统计字母数量
3. 统计单词数量
4. 统计句子数量
5. 用 Coleman-Liau 公式计算
6. 输出阅读等级

---

## 3. Program Structure

Main flow:

input text  
↓  
count letters  
count words  
count sentences  
↓  
calculate L and S  
↓  
calculate index  
↓  
round the result  
↓  
print the grade  

---

## 4. Read the Text

```c
string text = get_string("Text: ");
```

English explanation:

- We ask the user to enter some text.
- We store the input in a string called `text`.

中文理解：

- 我们让用户输入一段文字
- 把输入内容存到 `text` 这个字符串里

---

## 5. Counters

```c
int letters = 0;
int words = 1;
int sentences = 0;
```

English explanation:

- We initialize three variables.
- `letters` counts the number of letters.
- `words` counts the number of words.
- `sentences` counts the number of sentences.

中文理解：

- 我们先初始化三个变量
- `letters` 统计字母
- `words` 统计单词
- `sentences` 统计句子

Why is `words = 1`?

Because:

words = spaces + 1

Example:

`Hello world`

There is 1 space, but there are 2 words.

---

## 6. Loop Through the String

```c
for (int i = 0; i < strlen(text); i++)
{
    char c = text[i];
}
```

English explanation:

- We use a `for` loop to go through every character in the string.
- We store the current character in a variable called `c`.

中文理解：

- 我们用 `for` 循环遍历字符串里的每一个字符
- 当前字符存到变量 `c` 里面

Important idea:

`text[i]` means the character at position `i`.

Example:

If:

```c
string text = "cat";
```

Then:

- `text[0] = 'c'`
- `text[1] = 'a'`
- `text[2] = 't'`

---

## 7. Count Letters

```c
if (isalpha(c))
{
    letters++;
}
```

English explanation:

- If the character is a letter, we increase the letter count.

中文理解：

- 如果这个字符是字母，就让字母数量加一

`isalpha(c)` means:

Check whether `c` is a letter.

Examples:

- `A` → true
- `b` → true
- `!` → false
- `3` → false

---

## 8. Count Words

```c
if (isspace(c))
{
    words++;
}
```

English explanation:

- If the character is a space, we increase the word count.

中文理解：

- 如果字符是空格，就让单词数量加一

`isspace(c)` means:

Check whether `c` is a whitespace character.

It can detect:

- space
- tab
- newline

---

## 9. Count Sentences

```c
if (c == '.' || c == '!' || c == '?')
{
    sentences++;
}
```

English explanation:

- If the character is a period, an exclamation mark, or a question mark, we increase the sentence count.

中文理解：

- 如果字符是句号、感叹号、问号，就让句子数量加一

Vocabulary:

- period = 句号
- exclamation mark = 感叹号
- question mark = 问号

---

## 10. Coleman-Liau Formula

We need:

- `L` = average number of letters per 100 words
- `S` = average number of sentences per 100 words

```c
float L = (letters * 100.0) / words;
float S = (sentences * 100.0) / words;
```

English explanation:

- `L` is the number of letters per 100 words.
- `S` is the number of sentences per 100 words.

中文理解：

- `L` 表示每 100 个单词里有多少字母
- `S` 表示每 100 个单词里有多少句子

Then:

```c
float index = 0.0588 * L - 0.296 * S - 15.8;
```

English explanation:

- We apply the Coleman-Liau formula to calculate the readability index.

中文理解：

- 我们把 `L` 和 `S` 带入公式，算出阅读等级指数

Why use `100.0` instead of `100`?

Because `100.0` makes the calculation use `float`.

中文理解：

因为如果写 `100`，可能会变成整数除法，结果不够精确。

---

## 11. Round the Result

```c
int grade = round(index);
```

Need library:

```c
#include <math.h>
```

English explanation:

- We round the readability index to the nearest integer.

中文理解：

- 把指数四舍五入成最接近的整数

---

## 12. Print the Grade

```c
if (grade < 1)
{
    printf("Before Grade 1\n");
}
else if (grade >= 16)
{
    printf("Grade 16+\n");
}
else
{
    printf("Grade %i\n", grade);
}
```

English explanation:

- If the grade is less than 1, print `Before Grade 1`.
- If the grade is 16 or higher, print `Grade 16+`.
- Otherwise, print `Grade X`.

中文理解：

- 如果小于 1，输出 `Before Grade 1`
- 如果大于等于 16，输出 `Grade 16+`
- 否则输出 `Grade X`

---

## 13. Important C Concepts in This Problem

This problem uses:

- string
- char
- array-like indexing
- for loop
- if statement
- functions
- float
- integer
- round
- library functions

中文理解：

这题综合用了很多 C 语言前期核心概念：

- 字符串
- 字符
- 索引
- 循环
- 判断
- 函数
- 浮点数
- 整数
- 数学函数
- 库函数

---

## 14. Mistakes / Confusing Parts

Things I was confused about:

1. Why `main` uses `()`, not `<>`
2. Why functions like `printf()` need `;`
3. Why `if (...)` does not need `;`
4. Why `%c` is for a character
5. Why `%s` is for a string
6. Why `text[i]` is a single character
7. Why `words` starts at 1
8. Why `isspace` is used for counting words
9. Why `100.0` is used instead of `100`
10. Why we need `return` in a function
11. Why libraries are needed
12. Why `ctype.h` is needed

---

## 15. Code Words I Learned

| Word | Meaning |
|------|---------|
| `string` | 字符串 |
| `char` | 单个字符 |
| `int` | 整数 |
| `float` | 浮点数 |
| `letters` | 字母数量 |
| `words` | 单词数量 |
| `sentences` | 句子数量 |
| `index` | 索引 |
| `loop` | 循环 |
| `function` | 函数 |
| `return` | 返回 |
| `uppercase` | 大写 |
| `lowercase` | 小写 |
| `space` | 空格 |
| `grade` | 年级 |
| `text` | 文本 |
| `current character` | 当前字符 |
| `nearest integer` | 最接近的整数 |

---

## 16. Important Functions

| Function | Meaning |
|----------|---------|
| `get_string()` | 获取用户输入的字符串 |
| `printf()` | 打印输出 |
| `strlen()` | 获取字符串长度 |
| `isalpha()` | 判断是不是字母 |
| `isspace()` | 判断是不是空白字符 |
| `round()` | 四舍五入 |

---

## 17. Symbols and How to Read Them

| Symbol | English |
|--------|---------|
| `()` | parentheses |
| `[]` | square brackets |
| `{}` | curly braces |
| `""` | double quotes |
| `''` | single quotes |
| `,` | comma |
| `;` | semicolon |
| `%` | percent sign |
| `=` | equals |
| `==` | equals equals |
| `++` | plus plus |
| `||` | or |
| `<` | less than |
| `>=` | greater than or equal to |
| `\n` | backslash n / newline |

---

## 18. How to Read the Code in English

### Example 1

```c
string text = get_string("Text: ");
```

Read like this:

- string text
- equals
- get string
- parentheses
- double quotes Text colon double quotes
- semicolon

Meaning:

- We get a string from the user.

---

### Example 2

```c
for (int i = 0; i < strlen(text); i++)
```

Read like this:

- for
- parentheses
- int i equals zero
- semicolon
- i is less than strlen of text
- semicolon
- i plus plus

Meaning:

- We loop through every character in the string.

---

### Example 3

```c
char c = text[i];
```

Read like this:

- char c
- equals
- text
- square bracket i square bracket
- semicolon

Meaning:

- We store the current character in `c`.

---

### Example 4

```c
if (isalpha(c))
{
    letters++;
}
```

Read like this:

- if
- parentheses
- isalpha of c
- close parentheses
- curly brace
- letters plus plus
- curly brace

Meaning:

- If the character is a letter, increase the letter count.

---

### Example 5

```c
if (isspace(c))
{
    words++;
}
```

Meaning:

- If the character is a space, increase the word count.

---

### Example 6

```c
if (c == '.' || c == '!' || c == '?')
{
    sentences++;
}
```

Meaning:

- If the character is a period, an exclamation mark, or a question mark, increase the sentence count.

---

### Example 7

```c
float L = (letters * 100.0) / words;
```

Meaning:

- `L` is the number of letters per 100 words.

---

### Example 8

```c
int grade = round(index);
```

Meaning:

- Round the index to the nearest integer and store it in `grade`.

---

## 19. Useful English Sentences for Explaining This Program

- This program calculates the readability of a text.
- It counts the number of letters, words, and sentences.
- Then it applies the Coleman-Liau formula.
- The program estimates the grade level needed to understand the text.
- We loop through the string one character at a time.
- The index tells the computer which position to read.
- We use `isspace()` to count words.
- We use `isalpha()` to count letters.
- We round the final result before printing the grade.

---

## 20. My Final Understanding

This problem taught me how to:

- scan a string character by character
- use conditions to classify characters
- count different kinds of information
- use a mathematical formula in a C program
- explain code in English, not only write it
