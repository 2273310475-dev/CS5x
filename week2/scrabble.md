# CS50 Week 1 — Scrabble Notes

## 1. Problem Description

In this problem, we simulate a simplified Scrabble game.

Two players enter a word.

Each letter has a specific point value.

The program calculates the total score of each word and prints the winner.

Example:

Player 1: DOG  
Player 2: CAT  

The program calculates the score for each word and prints:

Player 1 wins  
or  
Player 2 wins  
or  
Tie

---

# 2. Program Structure

The program has two main parts:

1️⃣ Main function  
2️⃣ Score calculation function

Main flow:

```
get two words
calculate score1
calculate score2
compare scores
print result
```

---

# 3. Key Idea

The key idea of the program is:

Use an **array** to store the score for each letter.

Then convert each letter into an **index** to access that score.

Example:

```
A → index 0
B → index 1
C → index 2
...
Z → index 25
```

---

# 4. Letter Score Array

The program stores letter scores in an array:

```c
int POINTS[] = {
1,3,3,2,1,4,2,4,1,8,
5,1,3,1,1,3,10,1,1,1,
1,4,4,8,4,10
};
```

This means:

| Letter | Score |
|------|------|
A | 1  
B | 3  
C | 3  
D | 2  
E | 1  

The computer uses the **index position** to find the score.

---

# 5. Converting Letters to Index

The program converts letters to numbers using ASCII math.

Uppercase:

```
index = letter - 'A'
```

Example:

```
'C' - 'A' = 2
```

So:

```
POINTS[2]
```

returns the score for **C**.

Lowercase:

```
index = letter - 'a'
```

Example:

```
'c' - 'a' = 2
```

This allows the program to handle both uppercase and lowercase letters.

---

# 6. Loop Through Each Letter

The program processes each letter using a loop.

```c
for (int i = 0; i < strlen(word); i++)
```

Meaning:

Start at index **0**

Continue while **i < length of the word**

Increase **i** by 1 each time.

Example:

Word: HELLO

```
H  E  L  L  O
0  1  2  3  4
```

Each iteration processes one letter.

---

# 7. Score Calculation Logic

Inside the loop, the program:

1️⃣ Reads the letter

```
char letter = word[i];
```

2️⃣ Checks if the letter is uppercase

```
isupper(letter)
```

3️⃣ Checks if the letter is lowercase

```
islower(letter)
```

4️⃣ Converts the letter to index

5️⃣ Adds the score to the total

Example:

```
score += POINTS[index];
```

This means:

```
score = score + POINTS[index];
```

---

# 8. Function Design

We use a function:

```
compute_score()
```

Function definition:

```c
int compute_score(string word)
```

This function:

- receives a word
- calculates its score
- returns the score

Example:

```
score1 = compute_score(word1)
score2 = compute_score(word2)
```

Why only one function?

Because both players use the **same logic**.

---

# 9. Why We Need Return

Inside the function:

```
return score;
```

This sends the result back to `main()`.

Without `return`, the main function would not know the score.

---

# 10. Comparing Scores

After computing both scores:

```
if (score1 > score2)
```

print Player 1 wins

```
else if (score2 > score1)
```

print Player 2 wins

```
else
```

print Tie

---

# 11. Key Concepts Learned

This problem combines multiple C concepts:

• arrays  
• indexes  
• strings  
• characters  
• loops  
• functions  
• return values  
• ASCII character math  

This is why Scrabble is an important Week 1 problem.

---

# 12. Mistakes / Confusing Parts (My Questions)

Today I was confused about:

1️⃣ Why arrays start at index **0**

2️⃣ Why we subtract `'A'`

3️⃣ How letters map to indexes

4️⃣ Why we use `return`

5️⃣ Why `score +=` adds values

6️⃣ Why we only need **one function**

7️⃣ How the loop processes each letter

8️⃣ Why uppercase and lowercase need separate checks

---

# 13. Code Words I Learned

| Word | Meaning |
|----|----|
string | 字符串
char | 单个字符
int | 整数
score | 分数
letter | 字母
word | 单词
index | 索引位置
array | 数组
loop | 循环
function | 函数
return | 返回值
uppercase | 大写
lowercase | 小写
length | 长度
value | 值
variable | 变量

---

# 14. Important Functions

| Function | Meaning |
|------|------|
get_string() | 获取字符串输入
printf() | 打印输出
strlen() | 获取字符串长度
isupper() | 判断是否大写字母
islower() | 判断是否小写字母

---

# 15. Symbols and How to Read Them

| Symbol | English |
|------|------|
() | parentheses
[] | square brackets
{} | curly braces
"" | double quotes
'' | single quotes
, | comma
; | semicolon
% | percent sign
= | equals
== | equals equals
+= | plus equals
- | minus
/ | slash
\n | newline / backslash n

---

# 16. How to Read Code in English

Example:

```c
printf("%i\n", score);
```

Read as:

```
printf
parentheses
percent i
backslash n
comma
score
semicolon
```

Example:

```c
int index = letter - 'A';
```

Read as:

```
int index
equals
letter
minus
A in single quotes
semicolon
```

Example:

```c
score += POINTS[index];
```

Read as:

```
score
plus equals
POINTS
square bracket
index
square bracket
semicolon
```

---

# 17. English Sentences to Explain This Program

This program calculates the Scrabble score of two words.

The program loops through each letter of the word.

It converts the letter into an index.

Then it uses the index to find the score in the array.

Finally, it compares the two scores and prints the winner.
