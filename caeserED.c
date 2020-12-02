#include<stdio.h>

void caeser_ED()
{

    char eord;
    ed:
    printf("-------------\n");
    printf("CAESAR CIPHER\n");
    printf("-------------\n\n");
    printf("Enter E to Encrypt, D to Decrypt : ");
    scanf("%s",&eord);

    if(eord == 'E' | eord == 'e')
    {
        //encryption
        char message[100], ch;
        int i, key;

        printf("\n-------------------------\n");
        printf("CAESAR CIPHER ENCRPYTION\n");
        printf("-------------------------\n\n");
        printf("Enter a message to encrypt: ");
        scanf("%s", &message);
        printf("Enter key: ");
        scanf("%d", &key);

        for(i = 0; message[i] != '\0'; ++i)
        {
            ch = message[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;

                if(ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }

                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + key;

                if(ch > 'Z'){
                    ch = ch - 'Z' + 'A' - 1;
                }

                message[i] = ch;
            }
        }
        printf("\n\n-----------------\n");
        printf("Encrypted message: %s\n", message);
        printf("-----------------\n\n");


    }
    else if (eord == 'D' | eord == 'd')
    {
        //decryption
        char message[100], ch;
        int i, key;

        printf("-------------------------\n");
        printf("CAESAR CIPHER DECRYPTION\n");
        printf("-------------------------\n\n");
        printf("Enter a message to decrypt: ");
        scanf("%s", &message);
        printf("Enter key: ");
        scanf("%d", &key);

        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch - key;

                if(ch < 'a'){
                    ch = ch + 'z' - 'a' + 1;
                }

                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch - key;

                if(ch < 'A'){
                    ch = ch + 'Z' - 'A' + 1;
                }

                message[i] = ch;
            }
        }

        printf("\n\n-----------------\n");
        printf("Decrypted message: %s\n", message);
        printf("-----------------\n\n");

    }
    int endscreen;
    printf("----------------------------");
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

int main()
{
    caeser_ED();
}
