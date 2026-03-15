========================
SUBSTITUTION
========================

1. Problem Goal

Write a program that encrypts text using a substitution cipher.

A substitution cipher replaces each letter with another letter according to a key.

Example

Key
QWERTYUIOPASDFGHJKLZXCVBNM

Plaintext
HELLO

Ciphertext
ITSSG

--------------------------------

2. What the Program Needs to Do

The program should:

1. Receive a key from the command line
2. Check whether the key is valid
3. Ask the user for plaintext
4. Replace each letter using the key
5. Print the ciphertext

--------------------------------

3. Core Idea

There are two alphabets:

Regular alphabet
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

Key
Q W E R T Y U I O P A S D F G H J K L Z X C V B N M

This means:

A → Q
B → W
C → E
D → R
E → T

So the program must:

- find the position of the plaintext letter
- use that position in the key
- print the corresponding letter

--------------------------------

4. Command-Line Argument Part

This problem does NOT ask the user to type the key later with get_string().

The key must be given when running the program.

Correct example:

./substitution QWERTYUIOPASDFGHJKLZXCVBNM

So we use:

int main(int argc, string argv[])

Meaning:

argc = number of command-line arguments
argv = the content of those arguments

Example:

./substitution ABC

Then:

argc = 2
argv[0] = "./substitution"
argv[1] = "ABC"

So:

string key = argv[1];

--------------------------------

5. Step-by-Step Code Structure

Step 1: Check argument count

if (argc != 2)
{
    printf("Usage: ./substitution key\n");
    return 1;
}

Meaning:

If the user does not provide exactly one key,
the program prints an error message and stops.

--------------------------------

Step 2: Save key

string key = argv[1];

--------------------------------

Step 3: Check key length

if (strlen(key) != 26)
{
    printf("Key must contain 26 characters.\n");
    return 1;
}

Meaning:

The key must have exactly 26 letters,
because the alphabet has 26 letters.

--------------------------------

Step 4: Check whether all characters are letters

for (int i = 0; i < 26; i++)
{
    if (!isalpha(key[i]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
}

Meaning:

If any character in the key is not a letter,
the program stops.

--------------------------------

Step 5: Check repeated letters

for (int i = 0; i < 26; i++)
{
    for (int j = i + 1; j < 26; j++)
    {
        if (toupper(key[i]) == toupper(key[j]))
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
}

Meaning:

Compare each letter with the letters after it.
If two letters are the same, the key is invalid.

--------------------------------

Step 6: Ask user for plaintext

string plaintext = get_string("plaintext: ");

--------------------------------

Step 7: Print ciphertext label

printf("ciphertext: ");

Why?

Because the problem wants output in this format:

ciphertext: ITSSG

--------------------------------

Step 8: Encrypt the plaintext

for (int i = 0; i < strlen(plaintext); i++)
{
    char c = plaintext[i];

    if (isupper(c))
    {
        int index = c - 'A';
        printf("%c", toupper(key[index]));
    }
    else if (islower(c))
    {
        int index = c - 'a';
        printf("%c", tolower(key[index]));
    }
    else
    {
        printf("%c", c);
    }
}

printf("\n");

Meaning:

- if the character is uppercase, keep uppercase
- if the character is lowercase, keep lowercase
- if it is not a letter, print it unchanged

--------------------------------

6. Key Knowledge Points in This Problem

1. command-line arguments
2. argc and argv
3. strlen()
4. isalpha()
5. isupper()
6. islower()
7. toupper()
8. tolower()
9. nested for loops
10. plaintext to ciphertext mapping

--------------------------------

7. My Questions and Confusing Points

These are the things I asked about or did not understand at first:

1. Why do we need argc and argv?
At first I did not understand why the key was not entered later with get_string().
Now I understand:
this problem is specifically designed to practice command-line arguments.

2. Is the key entered by the user or by me?
At first I thought it might be typed later in the program.
Actually, the key is entered when running the program in the terminal.

3. Why can’t we just ask for the key below?
Technically we could, but this problem specifically requires command-line input.

4. Why do we need:
if (argc != 2)
At first it felt unnecessary.
Now I understand:
it checks whether the user ran the program correctly.

5. What does !isalpha(key[i]) mean?
At first I did not understand the !.
Now I understand:
isalpha(key[i]) checks whether the character is a letter.
! means “not”.
So !isalpha(key[i]) means “if it is not a letter”.

6. Why is there j++ in the second loop?
At first I was confused about the nested loop.
Now I understand:
j++ means j moves forward one by one,
so the program can compare the current letter with all later letters.

7. Why do we use toupper(key[i]) == toupper(key[j])?
At first I did not fully understand this.
Now I understand:
it compares letters without caring about uppercase/lowercase,
so 'A' and 'a' are treated as the same letter.

8. Why do we write:
printf("ciphertext: ");
At first I did not understand why this line was necessary.
Now I understand:
it is required by the output format of the problem.

9. Which loop do we put the substitution logic inside?
At first I was unsure where to write the encryption logic.
Now I understand:
it must go inside the plaintext loop,
because we process one plaintext character at a time.

10. What does toupper() mean here?
At first I thought it might mean “find uppercase”.
Now I understand:
toupper() converts a letter to uppercase.

--------------------------------

8. Mistaken Understandings I Had Before

These were my earlier misunderstandings:

- I thought command-line argument might not be necessary.
- I thought the key could maybe be entered later with get_string().
- I was not sure whether argc/argv were input from me or from the user.
- I did not understand why the program must check argc first.
- I was confused about where the substitution logic should be written.
- I was confused about the role of toupper() and tolower().
- I was confused about the second loop and why j keeps increasing.

--------------------------------

9. English Explanation of the Code

This program encrypts a message using a substitution cipher.

First, the program checks whether the user provides a valid key as a command-line argument.

If the argument count is not correct, the program prints an error message and stops.

Then the program checks whether the key has exactly twenty-six characters.

Next, it verifies that every character in the key is a letter.

After that, it checks whether the key contains repeated letters.

If the key is valid, the program asks the user for plaintext.

Then it loops through every character in the plaintext.

If the character is uppercase, the program finds its index using:
c - 'A'

Then it prints the corresponding uppercase letter from the key.

If the character is lowercase, the program finds its index using:
c - 'a'

Then it prints the corresponding lowercase letter from the key.

If the character is not a letter, the program prints it unchanged.

Finally, the program prints a newline.

--------------------------------

10. Useful English Sentences for This Problem

- This program uses a substitution cipher.
- The user provides the key as a command-line argument.
- The program checks whether the key is valid.
- The key must contain twenty-six letters.
- The key must not contain repeated characters.
- The program encrypts the plaintext one character at a time.
- Uppercase letters stay uppercase.
- Lowercase letters stay lowercase.
- Non-alphabetic characters are printed unchanged.

--------------------------------

11. Final Understanding

This problem is mainly about:

- learning command-line arguments
- validating input
- using loops to compare characters
- mapping letters by position
- preserving uppercase and lowercase
- understanding how one character becomes another character through a key
