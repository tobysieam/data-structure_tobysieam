#include <stdio.h>
#include <stdlib.h> // 添加对 malloc 和 free 的支持
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 255
/*
串，即字符串(String),是由零个或多个字符组成的有限序列。一般记为s是串名
可以是字母、数字或其他字符；串中字符的个数称为串的长度。n=0时的串称为空串（用0表示）。
引号（单/双引号都可）括起来的字符序列是串的值：S='a1a2..an'(n>=0)
空串：不包含任何字符的串称为空串
子串：串中任意个连续的字符组成的子序列称为该串的子串
空格串：由一个或多个空格组成的串称为空格串（空格串不是空串，其长度为串中空格字符的个数）
线性表的基本操作主要以单个元素作为操作对象，如查找，插入，删除某个元素等；
而串的基本操作通常以子串作为操作对象，如查找，插入，删除一个字串等
串的存储形式有多种
*/

//方案1：char[n]充当length
//方案2：char[1]充当；length


//1、定义顺序存储结构
/*类似于线性表的顺序存储结构，用一组地址连续的存储单元存储串值的字符序列。
在串的顺序存储结构中，为每个串变量分配一个固定长度的存储区，即定长数组*/
typedef struct String
{
    char ch[MAXSIZE];  //为每个分量存储一个字符
    int length;  //串的实际长度
}String;


//2、初始操作
void initString(String string)
{
    for(int i = 0; i < MAXSIZE; ++i)
    {
        string.ch[i] = '\0';
    }
    string.length = 0;
}


//3、赋值操作
void strAssign(String string,char* str)
{
    int i,j;
    for(i = 0;i < strlen(str); ++i)
    {
        string.ch[i] = str[i];
    }
    for(j = i; j < string.length; ++j)
    {
        string.ch[i] = '\0';
    }
    string.length = strlen(str);
}


//4、复制操作
/*
把串str复制到string
*/
void strCopy(String string,String str)
{
    int i,j;
    for(i = 0; i < strlen(str.ch); ++i)
    {
        string.ch[i] = str.ch[i];
    }

    for(j = i; j < strlen(string.ch); ++j)
    {
        string.ch[i] = '\0';
    }
    string.length = strlen(str.ch);
}


//5、判空操作
bool strIsEmpty(String string)
{
    if(string.length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//6、比较操作
/*
首先比较同位序的字母大小，其次比较字符串的长度大小
*/
int strCompare(String string,String str)
{
    for(int i = 0; i < string.length&&i<str.length; ++i)
    {
        if(string.ch[i] != str.ch[i])
        {
            return string.ch[i] - str.ch[i];
        }
    }
    return string.length - str.length;
}


//7、截取操作
/*
用sub返回串string的第pos个字符起长度为len的字串
*/
bool subString(String sub,String string,int pos,int len)
{
    if(pos + len > string.length)
    {
        return 0;
    }
    for(int i = pos; i < pos + len; ++i)
    {
        sub.ch[i-pos] = string.ch[i];
    }
    sub.length = len;
    return 1;
}


//8、连接操作
/*
连接操作：把两个串相连
*/
void strConcat(String sub,String string,String str)
{
    int i;
    for(i = 0; i < string.length; ++i)
    {
        sub.ch[i] = str.ch[i];
    }
    for(int j = 0; j < str.length; ++j,++i)
    {
        sub.ch[i] = str.ch[j];
    }
    sub.length = string.length + str.length;
}


//9、定位操作
/*
返回子串在主串中的位序
*/
int strIndex(String string,String str)
{
    int i = 0,n = string.length,m = str.length;
    String sub;  //用于暂存子串
    while(i <= n-m)
    {
        subString(sub,string,i,m);
        if(strCompare(sub,str) != 0)
        {
            i++;
        }
        else
        {
            return i;
        }
    }
    return 0;

}
//子串的定位操作通常称为串的模式匹配，它求的是子串在主串中的位置。


//10、清空操作
void strClear(String string)
{
    for(int i = 0; i<string.length; ++i)
    {
        string.ch[i] = '\0';
    }
    string.length = 0;
}