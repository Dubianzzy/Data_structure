#include <stdio.h>
#include <string.h>
char S[50], T[20], rep[20], ans[50];
int stringmatch()
{
    int m = strlen(S), n = strlen(T),found=0;
    for (int i = 0; i <= m; i++)
    {
        int j = 0;
        while (j < n && S[i + j] == T[j])
            j++;
        if (j == n)
        {
            int k = 0, l, x = 0, tmp = strlen(rep);
            found=1;
            for (l = 0; l < m - n + tmp; l++)
            {

                if (l == i)
                {
                    x = tmp - n;
                    for (k = 0; k < tmp; k++)
                    {
                        ans[i + k] = rep[k];
                    }
                    k--;
                }
                ans[l + k + x] = S[l + k];
            }
            strcpy(S,ans);
            i=i+tmp-n;
        }
    }
    if(found)return 1;
    else return 0;
}
int main()
{
    int found = 0;
    printf("\n 请输入主串：");
    gets(S);
    printf("\n 请输入模式串：");
    gets(T);
    printf("\n 请输入替换串：");
    gets(rep);
    found = stringmatch();
    if (found)
        printf("\n 最终结果是 %s", ans);
    else
        printf("\n 未能匹配模式串");
    return 0;
}