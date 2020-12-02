#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX_LEN 128



int main()
{
    playagain:

    srand(time(0));


    int random1 = rand()%1;
    int random2 = rand()%1;


    char ans[50],rep,continu;


    char msgwordlist1[50][50] = {"CRYPTOGRAPHY"};
    char msgwordlist2[50][50] = {"CRYPTOGRAPHY"};


    //Pick word from wordlist and copy into string

  	char *encrpt_txt = msgwordlist1[random1];
  	char *decryptedMsg = msgwordlist2[random1];
  	//char *key = keywordlist[random2];

  	//Encryption Process

    int i,n;
    char ch;
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



    //User gets displayed
    printf("--------------\n");
    printf(" ROT13 CIPHER \n");
    printf("--------------\n");
    printf("ROT13 is a simple letter substitution cipher that replaces a letter with the 13th letter after it in the alphabet.\n\n");
    printf("Because there are 26 letters (2×13) in the basic Latin alphabet, ROT13 is its own inverse; that is, to undo ROT13, the same algorithm is applied, so the same action can be used for encoding and decoding. The algorithm provides virtually no cryptographic security, and is often cited as a canonical example of weak encryption\n\n");
    printf(" An additional feature of the cipher is that it is symmetrical; that is, to undo ROT13, the same algorithm is applied, so the same code can be used for encoding and decoding.\n\n ");
    printf("Encryption:\n\nROT13 is one of a set of encryption algorithms known as Caesar ciphers, which are themselves a particularly simple type of substitution cipher. ROT13 is not intended to be used where secrecy is of any concern—the use of a constant shift means that the encryption effectively has no key.It just replaces a letter with the 13th letter after it in the alphabet\n\n");
    printf("Decryption:\n\nApplying ROT13 to a piece of text merely requires examining its alphabetic characters and replacing each one by the letter 13 places further along in the alphabet, wrapping back to the beginning if necessary.[2] A becomes N, B becomes O, and so on up to M, which becomes Z, then the sequence continues at the beginning of the alphabet: N becomes A, O becomes B, and so on to Z, which becomes M. Only those letters which occur in the English alphabet are affected; numbers, symbols, whitespace, and all other characters are left unchanged. Because there are 26 letters in the English alphabet and 26 = 2 × 13, the ROT13 function is its own inverse\n\n");
    printf("--------------\n");
    printf("   LEVEL 1\n");
    printf("--------------\n\n");
    printf("\nEncrypted Message: %s", encrpt_txt);
    //printf("\nKey: %s\n\n", key);
    clock_t t;
    t = clock();
    top:
    printf("\n------------------------\n");
    printf("Enter Decrypted Message: ");
    scanf("%s",&ans);
    printf("------------------------\n\n");

    int compare;
    compare = strcmp(decryptedMsg,ans);

    if (compare == 0) //level 1 compare
    {

        printf("Congratulations, you cleared LEVEL 1.\n\n");
        sleep(5);
        srand(time(0));
        int random1 = rand()%1;
        //int random2 = rand()%1;
        char *encrpt_txt = msgwordlist1[random1];
        char *decryptedMsg = msgwordlist2[random1];
        //char *key = keywordlist2[random2];

        //Encryption Process

            int i,n;
            char ch;
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
            //return encrpt_txt;

        //char* decpt(char encrpt_txt[])

            //int i,n;
           // char ch;
            for(i=0;i<strlen(encrpt_txt);i++)
            {
                n=encrpt_txt[i];
                n=n-13;
                if(n<65)
                {
                    n=91-(65-n);
                    ch=n;
                    encrpt_txt[i]=ch;
                }
                else
                {
                    ch=n;
                    encrpt_txt[i]=ch;
                }
            }
            //return decpt_txt;

        printf("--------------\n");
        printf(" ROT13 CIPHER\n");
        printf("--------------\n");
        printf("--------------\n");
        printf("   LEVEL 2\n");
        printf("--------------\n\n");
        printf("\nMessage: %s", decryptedMsg);
        //printf("\nKey: %s\n\n", key);

        top1:
        printf("------------------------\n");
        printf("Enter Encrypted Message: ");
        scanf("%s",&ans);
        printf("------------------------\n\n");

        int compare;
        compare = strcmp(encrpt_txt,ans);
        if (compare == 0)
        {
            printf("congratulations, you cleared LEVEL 2.\n\n");
        }

        else
        {
            printf("Sorry, your answer does not match the Encrypted message.\nPress Y to Try again, N to skip.\n");
            scanf("%s",&rep);
            printf("\n");
            if (rep == 'Y' | rep == 'y')
            {
                goto top1;
            }
            /*else if (rep == 'N' | rep == 'n')
            {

            }*/
        }

    }

    else
    {
        printf("Sorry, your answer does not match the Encrypted message.\nPress Y to Try again, N to skip.\n");
        scanf("%s",&rep);
        if (rep == 'Y' | rep == 'y')
        {
            goto top;
        }
        /*else if (rep == 'N' | rep == 'n')
        {

        }*/
    }

    t = clock() - t - 5;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    int endscreen;
    printf("Challenges took %f seconds to execute \n\n", time_taken);
    printf("1. Play Again\n2. Move to Display menu\n3. Exit\n");
    printf("Choose : ");
    scanf("%d",&endscreen);

    switch(endscreen)
    {
        case 1:
        system("cls");
        goto playagain;
        break;

        case 2:
        //goto display;
        break;

        case 3:
        exit(0);
    }

}
