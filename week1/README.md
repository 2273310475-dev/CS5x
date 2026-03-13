# Week 1

Problems:
- hello
- mario
- credit

# CS50 Terminal Command Map

## 1 查看当前位置文件
ls

显示当前文件夹里的文件

例子：
ls

输出：
hello.c
mario.c
readability.c


--------------------------------------------------

## 2 进入文件夹
cd foldername

例子：
cd readability

进入 readability 文件夹


--------------------------------------------------

## 3 返回上一层目录
cd ..

例子：
cd ..

回到上一个文件夹


--------------------------------------------------

## 4 创建文件夹
mkdir foldername

例子：
mkdir readability


--------------------------------------------------

## 5 创建文件
touch filename.c

例子：
touch readability.c


--------------------------------------------------

## 6 删除文件
rm filename

例子：
rm readability


--------------------------------------------------

## 7 删除文件夹
rm -r foldername


--------------------------------------------------

## 8 编译程序
make filename

例子：
make readability

作用：
把

readability.c

编译成

readability


--------------------------------------------------

## 9 运行程序
./filename

例子：
./readability


--------------------------------------------------

## 10 提交作业
submit50 cs50/problems/2026/x/readability


--------------------------------------------------

## 11 检查正确性
check50 cs50/problems/2026/x/readability


--------------------------------------------------

## 12 检查代码风格
style50 readability.c
