unsigned __int64 __fastcall sub_40138B(__int64 a1)
{
    char v2; // [rsp+1Fh] [rbp-21h]
    unsigned __int64 i; // [rsp+20h] [rbp-20h]
    unsigned __int64 j; // [rsp+28h] [rbp-18h]
    unsigned __int64 k; // [rsp+30h] [rbp-10h]
    unsigned __int64 v6; // [rsp+38h] [rbp-8h]

    v6 = __readfsqword(0x28u);
    //ascii 中 10 -> '\n' ，结合后文，可以在注入时开头放一个换行符跳过排序
    for (i = 0LL; *(_BYTE*)(a1 + i) != 10 && *(_BYTE*)(a1 + i); ++i);
    //排序到i为止为止
    //愚蠢的选择排序
    for (j = 0LL; j < i; ++j)
    {
        for (k = j + 1; k < i; ++k)
        {
            if (*(_BYTE*)(a1 + j) > *(_BYTE*)(a1 + k))
            {
                v2 = *(_BYTE*)(a1 + j);
                *(_BYTE*)(a1 + j) = *(_BYTE*)(a1 + k);
                *(_BYTE*)(k + a1) = v2;
            }
        }
    }
    return v6 - __readfsqword(0x28u);
}