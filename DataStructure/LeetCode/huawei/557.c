#include<stdio.h>
#include<string.h>

char* ReverseWord(char c[],int n)
{
    int i=0;
    while (i<n) 
    {
        int start=i;
        while (i<n && c[i]!=' ')    //�����ո�ʱ˵���Ѿ���ȡ��һ����������
        {
            i++;
        }

        int left=start,right=i-1;   //һ���������ʵĳ���

        while (left<right)  //���������е���ĸ
        {
            int temp=0;
            temp=c[right];     
            c[right]=c[left];
            c[left]=temp;
            left++;
            right--;
        }

        while (i<n && c[i]==' ')    //�����ո�
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