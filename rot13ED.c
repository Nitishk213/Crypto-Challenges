#include<stdio.h>
#include<string.h>

int main()
{
    char eord,msg[100], key[100];
    char input[500], encrpt_txt[500], decpt_txt[500];
    ed:
    printf("---------------\n");
    printf("VIGENERE CIPHER\n");
    printf("---------------\n\n");
    printf("Enter E to Encrypt, D to Decrypt : ");
    scanf("%s",&eord);

    if(eord == 'E' | eord == 'e')
    {
        //encryption
        printf("\n--------------------------\n");
        printf("VIGENERE CIPHER ENCRPYTION\n");
        printf("--------------------------\n\n");
        int i,n;
        char ch;
        printf("Enter Plaintext: ");
        scanf("%s",&encrpt_txt);

        for(i=0;i<strlen(encrpt_txt);i++)
        {
            n=encrpt_txt[i];
            n= n+13;
            if(n>90)
            {
                n=n-90+64;
                ch=n;
                encrpt_txt[i]=ch;
            }
            else
            {
                ch=n;
                encrpt_txt[i]=ch;
            }
        }
        printf("%s",encrpt_txt);
    }

    else if (eord == 'D' | eord == 'd')
    {
        //decryption
        printf("\n--------------------------\n");
        printf("VIGENERE CIPHER DECRPYTION\n");
        printf("--------------------------\n\n");
        int i,n;
        char ch;
        printf("\nEnter Decrypted text : ");
        scanf("%s",decpt_txt);

        for(i=0;i<strlen(decpt_txt);i++)
        {
            n=decpt_txt[i];
            n=n-13;
            if(n<65)
            {
                n=91-(65-n);
                ch=n;
                decpt_txt[i]=ch;
            }
            else
            {
                ch=n;
                decpt_txt[i]=ch;
            }
        }
        printf("%s",decpt_txt);

    }

    int endscreen;
    printf("\n\n----------------------------");
    printf("\n\n1. Encrypt/Decrypt Again\n2. Move to Display menu\n3. Exit\n");
    printf("Choose : ");
    scanf("%d",&endscreen);

    switch(endscreen)
    {
        case 1:
        system("cls");
        goto ed;
        break;

        case 2:
        //goto display;
        break;

        case 3:
        exit(0);
    }

}
