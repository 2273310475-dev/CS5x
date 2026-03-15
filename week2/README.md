========================
CS50 TERMINAL + C SYNTAX CHEATSHEET
========================

PART 1 — Terminal Commands (常用命令)

查看当前路径
pwd
(print working directory)

查看当前文件
ls

进入文件夹
cd foldername

例
cd substitution

返回上一级
cd ..

--------------------------------

创建文件夹
mkdir foldername

创建文件
touch filename.c

例
touch substitution.c

--------------------------------

删除文件
rm filename

例
rm hello.c

删除文件夹
rm -r foldername

--------------------------------

编译程序
make programname

例
make substitution

作用
substitution.c → substitution（可执行文件）

--------------------------------

运行程序
./programname

例
./substitution KEY

./ 表示运行当前目录的程序

--------------------------------

自动测试
check50 cs50/problems/2026/x/substitution

作用
CS50自动检查程序正确性

--------------------------------

检查代码风格
style50 substitution.c

--------------------------------

调试程序
debug50 ./substitution KEY

作用
逐行执行程序
查看变量变化

--------------------------------

提交作业
submit50 cs50/problems/2026/x/substitution



========================
PART 2 — 常见 C 语法错误
========================

1. 忘记分号 ;

错误
int x = 5

正确
int x = 5;

--------------------------------

2. printf格式符错误

%i → integer
%c → character
%s → string

例

printf("%i\n", x);
printf("%c\n", c);
printf("%s\n", text);

--------------------------------

3. 字符 vs 字符串

字符
'A'

字符串
"ABC"

例

char c = 'A';
string text = "ABC";

--------------------------------

4. if 条件必须有括号

错误

if isalpha(c)

正确

if (isalpha(c))

--------------------------------

5. 变量作用域错误

错误

{
    char c = text[i];
}

printf("%c", c);

正确

char c = text[i];
printf("%c", c);

--------------------------------

6. for 循环结构

for (初始化; 条件; 更新)

例

for (int i = 0; i < strlen(text); i++)

--------------------------------

7. strlen()

strlen(text)

作用
返回字符串长度

--------------------------------

8. argv 与 argc

argc
argument count

argv
argument vector

例

./substitution KEY

argc = 2

argv[0] = "./substitution"
argv[1] = "KEY"

--------------------------------

9. return

return 0
程序正常结束

return 1
程序异常结束

--------------------------------

10. 字符判断函数

isalpha(c)
是否字母

isdigit(c)
是否数字

isspace(c)
是否空格

isupper(c)
是否大写

islower(c)
是否小写

--------------------------------

11. 字符转换函数

toupper(c)
转为大写

tolower(c)
转为小写



========================
PART 3 — 常用库 (Week1–2)
========================

1. stdio.h

标准输入输出库

常用

printf()

--------------------------------

2. cs50.h

CS50输入函数

get_string()
get_int()
get_float()

--------------------------------

3. string.h

字符串处理

strlen()

--------------------------------

4. ctype.h

字符判断

isalpha()
isdigit()
isspace()
isupper()
islower()

字符转换

toupper()
tolower()



========================
PART 4 — 常见逻辑错误 (CS50常见)
========================

1. 在循环里错误使用 \n

错误

printf("%c\n", c);

会导致每个字符换行

正确

printf("%c", c);

最后统一

printf("\n");

--------------------------------

2. key index 计算错误

正确

int index = c - 'A';

或

int index = c - 'a';

--------------------------------

3. 忘记处理非字母

else
{
    printf("%c", c);
}

--------------------------------

4. 忘记保持大小写

toupper()
tolower()

--------------------------------

5. 循环条件写错

错误

i <= strlen(text)

正确

i < strlen(text)
