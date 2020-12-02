#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX_LEN 128

/*
testing:
message : CRYPTOGRAPHY
encrypted : MRJXDORZKPSG
key : KALI
*/

int main()
{
    playagain:
    //Random number generation to pick random word from wordlist
    srand(time(0));
    //int random1 = rand()%5;
    //int random2 = rand()%5;
    int random1 = rand()%1;
    int random2 = rand()%1;
    //wordlist

    char ans[50],rep,continu;
    //char msgwordlist[50][50] = {"CRYPTANALYSIS" ,"CRYPTOGRAPHY" ,"HACKING", "LINUX", "ENCRYPTION", "ENCRYPT"};
    //char keywordlist[50][50] = {"WORDLIST","CRYPTO", "KEY", "VIGNERE", "KALI", "ENCRYPTION"};
    char msgwordlist[50][50] = {"CRYPTOGRAPHY"};
    char keywordlist[50][50] = {"KALI"};

    //Pick word from wordlist and copy into string

  	char *msg = msgwordlist[random1];
  	char *key = keywordlist[random2];

  	//Encryption Process

    int msgLen = strlen(msg), keyLen = strlen(key), i, j,compare;
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

    //decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';

    decryptedMsg[i] = '\0';

    //User gets displayed
    printf("--------------\n");
    printf("VIGNERE CIPHER\n");
    printf("--------------\n");
    printf("Vigenere Cipher is a method of encrypting alphabetic text. It uses a simple form of polyalphabetic substitution. A polyalphabetic cipher is any cipher based on substitution, using multiple substitution alphabets .The encryption of the original text is done using the Vigenère square or Vigenère table.\n\n");
    printf("The table consists of the alphabets written out 26 times in different rows, each alphabet shifted cyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar Ciphers.\n\n");
    printf("At different points in the encryption process, the cipher uses a different alphabet from one of the rows.\n\n");
    printf("The alphabet used at each point depends on a repeating keyword.\n\n");
    printf("Encryption:\n\nThe first letter of the plaintext, G is paired with A, the first letter of the key. So use row G and column A of the Vigenère square, namely G. Similarly, for the second letter of the plaintext, the second letter of the key is used, the letter at row E and column Y is C. The rest of the plaintext is enciphered in a similar fashion.\n\n");
    printf("Decryption:\n\nDecryption is performed by going to the row in the table corresponding to the key, finding the position of the ciphertext letter in this row, and then using the column’s label as the plaintext. For example, in row A (from AYUSH), the ciphertext G appears in column G, which is the first plaintext letter. Next we go to row Y (from AYUSH), locate the ciphertext C which is found in column E, thus E is the second plaintext letter.\n\n");
    printf("--------------\n");
    printf("   LEVEL 1\n");
    printf("--------------\n\n");
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nKey: %s\n\n", key);
    clock_t t;
    t = clock();
    top:
    printf("------------------------\n");
    printf("Enter Decrypted Message: ");
    scanf("%s",&ans);
    printf("------------------------\n\n");

    compare = strcmp(decryptedMsg,ans);

    if (compare == 0) //level 1 compare
    {

        printf("Congratulations, you cleared LEVEL 1.\n\n");
        sleep(5);
        srand(time(0));
        int random1 = rand()%1;
        int random2 = rand()%1;
        char *msg = msgwordlist[random1];
        char *key = keywordlist[random2];

        //Encryption Process

        int msgLen = strlen(msg), keyLen = strlen(key), i, j,compare;
        char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

        //generating new key
        for(i = 0, j = 0; i < msgLen; ++i, ++j)
        {
            if(j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }

        newKey[i] = '\0';

        //encryption
        for(i = 0; i < msgLen; ++i)
            encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';

        encryptedMsg[i] = '\0';

        //decryption
        for(i = 0; i < msgLen; ++i)
            decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';

        decryptedMsg[i] = '\0';
        printf("--------------\n");
        printf("VIGNERE CIPHER\n");
        printf("--------------\n");
        printf("--------------\n");
        printf("   LEVEL 2\n");
        printf("--------------\n\n");
        printf("\nMessage: %s", decryptedMsg);
        printf("\nKey: %s\n\n", key);

        top1:
        printf("------------------------\n");
        printf("Enter Encrypted Message: ");
        scanf("%s",&ans);
        printf("------------------------\n\n");

        compare = strcmp(encryptedMsg,ans);
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
