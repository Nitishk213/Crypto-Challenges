#include<stdio.h>
#include<string.h>

int main()
{
    char eord,msg[100], key[100];
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
        printf("Enter Text to Encrypt: ");
        scanf("%s", &msg);
        printf("Enter Key: ");
        scanf("%s",&key);
        int msgLen = strlen(msg), keyLen = strlen(key), i, j;

        char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

        //generating new key
        for(i = 0, j = 0; i < msgLen; ++i, ++j){
            if(j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }

        newKey[i] = '\0';

        //encryption
        for(i = 0; i < msgLen; ++i)
            encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';

        encryptedMsg[i] = '\0';


        printf("Original Message: %s", msg);
        printf("\nKey: %s", key);
        printf("\n\nNew Generated Key: %s", newKey);
        printf("\nEncrypted Message: %s", encryptedMsg);

        //return 0;
    }
    else if (eord == 'D' | eord == 'd')
    {
        //decryption
        printf("\n--------------------------\n");
        printf("VIGENERE CIPHER DEDCRPYTION\n");
        printf("--------------------------\n\n");
        printf("Enter Text to Decrypt: ");
        scanf("%s", &msg);
        printf("Enter Key: ");
        scanf("%s",&key);
        int msgLen = strlen(msg), keyLen = strlen(key), i, j;

        char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

        //generating new key
        for(i = 0, j = 0; i < msgLen; ++i, ++j){
            if(j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }

        newKey[i] = '\0';

        //decryption
        for(i = 0; i < msgLen; ++i)
            decryptedMsg[i] = (((msg[i] - newKey[i]) + 26) % 26) + 'A';

        decryptedMsg[i] = '\0';


        printf("Original Message: %s", msg);
        printf("\nKey: %s", key);
        printf("\n\nNew Generated Key: %s", newKey);
        printf("\nDecrypted Message: %s", decryptedMsg);


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
