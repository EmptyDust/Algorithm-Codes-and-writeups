#include<bits/stdc++.h>

void main(int a1, char** a2, char** a3)
{
    int v3; // [rsp+Ch] [rbp-114h] BYREF
    char s[264]; // [rsp+10h] [rbp-110h] BYREF
    unsigned __int64 v5; // [rsp+118h] [rbp-8h]

    v5 = __readfsqword(0x28u);
    sub_4011B6();
    memset(s, 0, sizeof(s));
    puts("Welcome! You can leave a message here.");
    puts("But we reject dollars!");
    puts("Have fun!");
    while (1)
    {
        sub_40123E();
        __isoc99_scanf();
        if (v3 == 4)
        {
            puts("Goodbye, hacker!");
            exit(0);
        }
        if (v3 > 4)
        {
        LABEL_12:
            puts("Invalid choice");
        }
        else
        {
            switch (v3)
            {
            case 3:
                printf("Original message: ");
                puts(byte_4035A0);
                break;
            case 1:
                memset(byte_4035A0, 0, 0x100uLL);
                printf("Enter your message > ");
                sub_4012E4(0, byte_4035A0, 0x100uLL);
                memcpy(s, byte_4035A0, 0x100uLL);
                break;
            case 2:
                //排序函数 
                sub_40138B((__int64)s);
                printf("Sorted message: ");
                //绕过排序可攻击
                printf(s, &v3);
                break;
            default:
                goto LABEL_12;
            }
        }
    }
}