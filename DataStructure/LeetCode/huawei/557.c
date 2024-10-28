#include<stdio.h>
#include<string.h>

char* ReverseWord(char c[],int n)
{
    int i=0;
    while (i<n) 
    {
        int start=i;
        while (i<n && c[i]!=' ')    //遇到空格时说明已经获取到一个完整单词
        {
            i++;
        }

        int left=start,right=i-1;   //一个完整单词的长度

        while (left<right)  //交换单词中的字母
        {
            int temp=0;
            temp=c[right];     
            c[right]=c[left];
            c[left]=temp;
            left++;
            right--;
        }

        while (i<n && c[i]==' ')    //跳过空格
        {
            i++;
        }
    }
    return c; 
    
}

int main()
{
    char c[100]="Let's take LeetCode contest";
    int n=strlen(c);

    ReverseWord(c,n);
    printf("%s",c);
}