#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int golaco(char *e)
{
    int i, gol = 0;
    int tam = strlen((e));

    for (i = 0; i < tam;)
    {
        if ((e[i] != 'g') && (e[i] != 'G'))
        {
            printf("essa copa nunca sera nossa...\n");
            return -1;
        }
        else
        {
            while (e[i] == 'g' || e[i] == 'G')
                i++;
            if (e[i] != 'o' && e[i] != 'O')
            {
                printf("essa copa nunca sera nossa...\n");
                return -1;
            }

            while (e[i] == 'o' || e[i] == 'O')
                i++;
            if (e[i] != 'l' && e[i] != 'L')
            {
                printf("essa copa nunca sera nossa...\n");
                return -1;
            }

            while (e[i] == 'l' || e[i] == 'L')
                i++;

            gol++;
        }
    }

    return gol;
}

int main()
{
    int n, n_gol;
    scanf("%d", &n);

    char *s = malloc(1000);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        n_gol = golaco(s);

        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
    }

    /*

    char a[100] = "golgolgolgolgolgolgol";
    char b[100] = "GOLGOL";
    char c[100] = "GGGGGOOOOOLLLLLLLLGGGGGOOOOLLLLLLGGGGOOOOLLLL";
    char d[100] = "gOlGolgoLgGggGGGggGGOOOoooOOOoOLLllLLlllL";
    char e[100] = "gol";
    char f[100] = "golacogoleirogoklgoilggggttggglllooobbggggootggootllgooolfffff";
    char g[100] = "aaaaaaaaaaaaaa";
    char h[100] = "GGGGGGGGGGGGGGGGgggggggggggOOOOOOOOOOOOOOoooooooooooooLLLLLLLLLLLLLllllll";
    char i[100] = "golgolgolgolg";
    char j[100] = "golGOLgolGolgOlgoL";
    char k[100] = "log";
    char l[100] = "golgolgolgolgolgolgolgolgolgolgolgolgolgolgol";
    char m[100] = "ggggggggoooooooooollllllll";
    char ene[100] = "golgolgolgolgolgolgo";
    char o[100] = "gol1";
    char p[100] = "loggolgolgolgolgol";

    char pe[100] = "goal";
    char q[100] = "GOOOLGGGOLLLGOLLL";
    char r[250] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGoOOOOOOOOOOLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLa";
    char s[250] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGoOOOOOOOOOOLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";
    char t[100] = "golgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgolgol";
    char u[100] = "GOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgolGOLgol";
    char v[100] = "a";
    char w[100] = "gola";
    char x[100] = "GOLGOLGOLGOLGOLGOLGOLGOLGOLGOLgolgolgolgolgolgolgolgolgolgol";
    char y[100] = "golpe";
    char z[100] = "OJVWDHFUAJSVFWDNOXMCODOndjncbwbadfcihasbdblafidbwajfv";
    char aa[100] = "golgolgol";
    char ab[100] = "Lizandro";
    char ac[100] = "golGOLgolGOLgolgolGOL";

    n_gol = golaco(a);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(b);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(c);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(d);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(e);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(f);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(g);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(h);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(i);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(j);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(k);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(l);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(m);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(ene);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(o);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(p);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(pe);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }

        n_gol = golaco(q);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(r);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(s);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(t);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(u);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(v);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(w);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(x);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(y);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(z);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(aa);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(ab);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        n_gol = golaco(ac);
        if (n_gol >= 0)
        {
            if (n_gol == 1)
                printf(":( \n");
            else
                printf("%ix1 \n", n_gol);
        }
        */
    return 0;
}
