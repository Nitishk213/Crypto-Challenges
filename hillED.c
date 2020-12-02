#include<stdio.h>
#include<math.h>

float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

void encryptionhill();    //encrypts the message
void decryptionhill();    //decrypts the message
void getKeyMessage();    //gets key and message from user
void inverse();       //finds inverse of key matrix

void hillED()
{
    char eord;
    ed:
    printf("-----------\n");
    printf("HILL CIPHER\n");
    printf("-----------\n\n");
    printf("Enter E to Encrypt, D to Decrypt : ");
    scanf("%s",&eord);

    if(eord == 'E' | eord == 'e')
    {
        //encryptionhill
        char message[100], ch;
        int i, key;

        printf("\n----------------------\n");
        printf("HILL CIPHER ENCRPYTION\n");
        printf("----------------------\n\n");
        encryptionhill();
    }

    else if(eord == 'D' | eord == 'd')
    {
        //decryptionhill
        printf("\n-----------------------\n");
        printf("HILL CIPHER DECRYPTION\n");
        printf("-----------------------\n\n");
        decryptionhill();
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

void encryptionhill() {
    int i, j, k;
    getKeyMessage();
    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

    printf("\nEncrypted string is: ");
    for(i = 0; i < 3; i++)
        printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));
  printf("\n");
}

void decryptionhill() {
    int i, j, k;
    getKeyMessage();
    inverse();

    for(i = 0; i < 3; i++)
        for(j = 0; j < 1; j++)
            for(k = 0; k < 3; k++)
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];

    printf("\nDecrypted string is: ");
    for(i = 0; i < 3; i++)
        printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));

    printf("\n");
}

void getKeyMessage() {
    int i, j;
    char msg[3];

    printf("Enter 3x3 matrix for key (It should be inversible):\n");

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
            c[i][j] = a[i][j];
        }

    printf("\nEnter a 3 letter string: ");
    scanf("%s", msg);

    for(i = 0; i < 3; i++)
        mes[i][0] = msg[i] - 97;
}

void inverse() {
    int i, j, k;
    float p, q;

    for(i = 0; i < 3; i++)
    {
 printf("\n");
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;

   printf("\t %d",b[i][j]);
        }
 }
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];

            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];

    printf("\n\nInverse Matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%d ", b[i][j]);

        printf("\n");
    }
}

int main()
{
    hillED();
}
