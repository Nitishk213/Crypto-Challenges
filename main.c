#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include <ctype.h>
#define MX 5


                                                //FUNCTION FOR CAESAR CTF

void caesar_ctf()
{
    playagain:
    //Random number generation to pick random word from wordlist
    srand(time(0));
    //int random1 = rand()%5;
    //int random2 = rand()%5;
    int random1 = rand()%1;
    int random2 = rand()%26;
    //wordlist

    char ans[50],rep,continu;
    //char msgwordlist[50][50] = {"CRYPTANALYSIS" ,"CRYPTOGRAPHY" ,"HACKING", "LINUX", "ENCRYPTION", "ENCRYPT"};
    //char keywordlist[50][50] = {"WORDLIST","CRYPTO", "KEY", "VIGNERE", "KALI", "ENCRYPTION"};
    char msgwordlist1[50][50] = {"CRYPTOGRAPHY"};
    char msgwordlist2[50][50] = {"CRYPTOGRAPHY"};

    //Pick word from wordlist and copy into string

  	char *msg = msgwordlist1[random1];
  	char *decryptedMsg = msgwordlist2[random1];
  	int key = random2;

  	//Encryption Process
    int i;
    char ch;
    for(i = 0; msg[i] != '\0'; ++i){
		ch = msg[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			msg[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			msg[i] = ch;
		}
	}

    //User gets displayed
    printf("-------------\n");
    printf("CAESAR CIPHER\n");
    printf("-------------\n");
    printf("Vigenere Cipher is a method of encrypting alphabetic text. It uses a simple form of polyalphabetic substitution. A polyalphabetic cipher is any cipher based on substitution, using multiple substitution alphabets .The encryption of the original text is done using the Vigenère square or Vigenère table.\n\n");
    printf("The table consists of the alphabets written out 26 times in different rows, each alphabet shifted cyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar Ciphers.\n\n");
    printf("At different points in the encryption process, the cipher uses a different alphabet from one of the rows.\n\n");
    printf("The alphabet used at each point depends on a repeating keyword.\n\n");
    printf("Encryption:\n\nThe first letter of the plaintext, G is paired with A, the first letter of the key. So use row G and column A of the Vigenère square, namely G. Similarly, for the second letter of the plaintext, the second letter of the key is used, the letter at row E and column Y is C. The rest of the plaintext is enciphered in a similar fashion.\n\n");
    printf("Decryption:\n\nDecryption is performed by going to the row in the table corresponding to the key, finding the position of the ciphertext letter in this row, and then using the column’s label as the plaintext. For example, in row A (from AYUSH), the ciphertext G appears in column G, which is the first plaintext letter. Next we go to row Y (from AYUSH), locate the ciphertext C which is found in column E, thus E is the second plaintext letter.\n\n");
    printf("--------------\n");
    printf("   LEVEL 1\n");
    printf("--------------\n\n");
    printf("\nEncrypted Message: %s", msg);
    printf("\nKey: %d\n\n", key);
    clock_t t;
    t = clock();
    top:
    printf("------------------------\n");
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
        int random2 = rand()%2;
        char *enc_msg = msgwordlist1[random1];
        char *msg = msgwordlist2[random1];
        int key2 = random2;

        //Encryption Process

        int i;
        char ch2;
        for(i = 0; enc_msg[i] != '\0'; ++i)
        {
            ch2 = enc_msg[i];

            if(ch2 >= 'a' && ch2 <= 'z'){
                ch2 = ch2 + key2;

                if(ch2 > 'z'){
                    ch2 = ch2 - 'z' + 'a' - 1;
                }

                enc_msg[i] = ch2;
            }
            else if(ch2 >= 'A' && ch2 <= 'Z'){
                ch2 = ch2 + key2;

                if(ch2 > 'Z'){
                    ch2 = ch2 - 'Z' + 'A' - 1;
                }

                enc_msg[i] = ch2;
            }
        }


        printf("--------------\n");
        printf("VIGNERE CIPHER\n");
        printf("--------------\n");
        printf("--------------\n");
        printf("   LEVEL 2\n");
        printf("--------------\n\n");
        printf("\nMessage: %s", msg);
        printf("\nKey: %d\n\n", key2);

        top1:
        printf("------------------------\n");
        printf("Enter Encrypted Message: ");
        scanf("%s",&ans);
        printf("------------------------\n\n");

        int compare;
        compare = strcmp(enc_msg,ans);
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

                                                //FUNCTION FOR CAESAR ED
void caeser_ED()
{
    char eord;
    ed:
    printf("-------------\n");
    printf("CAESER CIPHER\n");
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

                                                //FUNCTION FOR ROT13 CTF

void rot_ctf()
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

                                                //FUNCTION FOR ROT 13 E/D
void rot_ed()
{

    char eord,msg[100], key[100];
    char input[500], encrpt_txt[500], decpt_txt[500];
    ed:
    printf("------------\n");
    printf("ROT13 CIPHER\n");
    printf("------------\n\n");
    printf("Enter E to Encrypt, D to Decrypt : ");
    scanf("%s",&eord);

    if(eord == 'E' | eord == 'e')
    {
        //encryption
        printf("\n----------------------\n");
        printf("ROT13 CIPHER ENCRPYTION\n");
        printf("-----------------------\n\n");
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
        printf("\n----------------------\n");
        printf("ROT13 CIPHER DECRPYTION\n");
        printf("-----------------------\n\n");
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


                                                //FUNCTION FOR VIGENERE CTF


void vigenere_ctf()
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
    printf("\n--------------\n");
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


                                                //function for vigenere E/D


void vigenere_ed()
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

                                            //Function for Playfair CTF

void toLowerCase(char plain[], int ps)
{
	int i;
	for (i = 0; i < ps; i++) {
		if (plain[i] > 64 && plain[i] < 91)
			plain[i] += 32;
	}
}

// Function to remove all spaces in a string
int removeSpaces(char* plain, int ps)
{
	int i, count = 0;
	for (i = 0; i < ps; i++)
		if (plain[i] != ' ')
			plain[count++] = plain[i];
	plain[count] = '\0';
	return count;
}

// Function to generate the 5x5 key square
void generateKeyTable(char key[], int ks, char keyT[5][5])
{
	int i, j, k, flag = 0, *dicty;

	// a 26 character hashmap
	// to store count of the alphabet
	dicty = (int*)calloc(26, sizeof(int));
	for (i = 0; i < ks; i++) {
		if (key[i] != 'j')
			dicty[key[i] - 97] = 2;
	}

	dicty['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (dicty[key[k] - 97] == 2) {
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (dicty[k] == 0) {
			keyT[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

// Function to search for the characters of a digraph
// in the key square and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

// Function to find the modulus with 5
int mod5(int a)
{
	return (a % 5);
}

// Function to make the plain text length to be even
int prepare(char str[], int ptrs)
{
	if (ptrs % 2 != 0) {
		str[ptrs++] = 'z';
		str[ptrs] = '\0';
	}
	return ptrs;
}

// Function for performing the encryption
void encrypt(char str[], char keyT[5][5], int ps)
{
	int i, a[4];

	for (i = 0; i < ps; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}
		else if (a[1] == a[3]) {
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}
		else {
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}

// Function to encrypt using Playfair Cipher
void encryptByPlayfairCipher(char str[], char key[])
{
	char ps, ks, keyT[5][5];

	// Key
	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	// Plaintext
	ps = strlen(str);
	toLowerCase(str, ps);
	ps = removeSpaces(str, ps);

	ps = prepare(str, ps);

	generateKeyTable(key, ks, keyT);

	encrypt(str, keyT, ps);
}


void playfair_ctf()
{
    char key[100];
    playagain:
	// Key to be encrypted
	strcpy(key, "Monarchy");
	//printf("Key text: %s\n", key);


	//random funct to pick plain text
    srand(time(0));
    //int random1 = rand()%5;
    //int random2 = rand()%5;
    int random1 = rand()%1;
    //int random2 = rand()%1;
    //wordlist

    //char msgwordlist[50][50] = {"CRYPTANALYSIS" ,"CRYPTOGRAPHY" ,"HACKING", "LINUX", "ENCRYPTION", "ENCRYPT"};
    //char keywordlist[50][50] = {"WORDLIST","CRYPTO", "KEY", "VIGNERE", "KALI", "ENCRYPTION"};
    char msgwordlist[50][50] = {"CRYPTOGRAPHY"};
    char msgwordlist1[50][50] = {"CRYPTOGRAPHY"};

    //Pick word from wordlist and copy into string

  	char *str = msgwordlist[random1];
  	char const *strans = msgwordlist1[random1];

  	char ans[100],rep,continu;
  	//printf("%s\n",strans);
  	//printf("%s\n",str);

	// Plaintext to be encrypted
	//strcpy(str, "instruments");
	//printf("Plain text: %s\n", str);

	// encrypt using Playfair Cipher
	encryptByPlayfairCipher(str, key);

    printf("---------------\n");
    printf("PLAYFAIR CIPHER\n");
    printf("---------------\n");
    printf("--------------\n");
    printf("   LEVEL 1\n");
    printf("--------------\n\n");
    printf("\nEncrypted Message: %s", str);
    printf("\nKey: %s\n\n", key);
    //printf("%s\n",strans);

    clock_t t;
    t = clock();
    top:
    printf("------------------------\n");
    printf("Enter Decrypted Message: ");
    scanf("%s",&ans);
    printf("------------------------\n\n");

    int compare;
    compare = strcmp(strans,ans);
    //printf("%d\n",compare);
    //printf("%s\n",str);
    //printf("%s\n",strans);
    //printf("%s\n",ans);

    if (compare == 0) //level 1 compare
    {

        printf("Congratulations, you cleared LEVEL 1.\n\n");
        sleep(5);
        srand(time(0));
        int random1 = rand()%1;
        //int random2 = rand()%1;
        char msgwordlist2[50][50] = {"CRYPTOGRAPHY"};
        char msgwordlist3[50][50] = {"CRYPTOGRAPHY"};
        char *strlevel2 = msgwordlist2[random1];
        char *strlevel2ans = msgwordlist3[random1];

        //char *key = keywordlist[random2];
        //printf("\nMessage: %s", strlevel2);

        // encrypt using Playfair Cipher
        encryptByPlayfairCipher(strlevel2, key);

        printf("--------------\n");
        printf("VIGNERE CIPHER\n");
        printf("--------------\n");
        printf("--------------\n");
        printf("   LEVEL 2\n");
        printf("--------------\n\n");
        printf("\nMessage: %s", strlevel2ans);
        printf("\nKey: %s\n\n",key);

        top1:
        printf("------------------------\n");
        printf("Enter Encrypted Message: ");
        scanf("%s",&ans);
        printf("------------------------\n\n");

        compare = strcmp(strlevel2,ans);
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

	return 0;
}


                                                //FUNCTION OF PLAYFAIR ED

int choice;
void playfair(char ch1, char ch2, char key[MX][MX])
{
    int i, j, w, x, y, z;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (ch1 == key[i][j]) {
                w = i;
                x = j;
            } else if (ch2 == key[i][j]) {
                y = i;
                z = j;
            }
        }
    }

    //printf("%d%d %d%d",w,x,y,z);
    if (w == y) {
		if(choice==1){
			x = (x + 1) % 5;
			z = (z + 1) % 5;
		}
		else{
			x = ((x - 1) % 5+5)%5;
			z = ((z - 1) % 5+5)%5;
		}
        printf("%c%c", key[w][x], key[y][z]);
    } else if (x == z) {
		if(choice==1){
			w = (w + 1) % 5;
			y = (y + 1) % 5;
		}
		else{
			w = ((w - 1) % 5+5)%5;
			y = ((y - 1) % 5+5)%5;
		}
        printf("%c%c", key[w][x], key[y][z]);
    }
	else {
        printf("%c%c", key[w][z], key[y][x]);
    }
}
void removeDuplicates(char str[]){
    int hash[256]        =  {0};
    int currentIndex     = 0;
    int lastUniqueIndex  = 0;
    while(*(str+currentIndex)){
        char temp = *(str+currentIndex);
        if(0 == hash[temp]){
            hash[temp] = 1;
            *(str+lastUniqueIndex) = temp;
            lastUniqueIndex++;
        }
        currentIndex++;
    }
    *(str+lastUniqueIndex) = '\0';

}
void playfair_ed()
{

    int i, j, k = 0, l, m = 0, n;
    char key[MX][MX], keyminus[25], keystr[10], str[25] = {
        0
    };

    char alpa[26] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    playfaired:
    printf("-------------\n");
    printf("PLAYFAIR CIPHER\n");
    printf("-------------\n\n");
	printf("Enter 1 to Encrypt, 2 to Decrypt: ");
    scanf("%d",&choice);
	if(choice!=1 && choice!=2){ printf("Invalid Choice"); return;}
	fflush(stdin);
    printf("\nEnter key:");
    gets(keystr);
    printf("Enter the text:");
    gets(str);
	removeDuplicates(keystr);
    n = strlen(keystr);
    //convert the characters to uppertext
    for (i = 0; i < n; i++) {
        if (keystr[i] == 'j') keystr[i] = 'i';
        else if (keystr[i] == 'J') keystr[i] = 'I';
        keystr[i] = toupper(keystr[i]);
    }
    //convert all the characters of plaintext to uppertext
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'j') str[i] = 'i';
        else if (str[i] == 'J') str[i] = 'I';
        str[i] = toupper(str[i]);
    }
    // store all characters except key
    j = 0;
    for (i = 0; i < 26; i++) {
        for (k = 0; k < n; k++) {
            if (keystr[k] == alpa[i]) break;
            else if (alpa[i] == 'J') break;
        }
        if (k == n) {
            keyminus[j] = alpa[i];
            j++;
        }
    }
    //construct key keymatrix
    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < n) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }
    // construct diagram and convert to cipher text
    printf("\nEntered text :%s\nOutput Text :", str);
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'J') str[i] = 'I';
        if (str[i + 1] == '\0') playfair(str[i], 'X', key);
        else {
            if (str[i + 1] == 'J') str[i + 1] = 'I';
            if (str[i] == str[i + 1]) playfair(str[i], 'X', key);
            else {
                playfair(str[i], str[i + 1], key);
                i++;
            }
        }
    }
	if(choice==2) printf(" (Remove unnecessary X)\n");
	int endscreen;
    printf("----------------------------");
    printf("\n\n1. Encrypt/Decrypt Again\n2. Move to Display menu\n3. Exit\n");
    printf("Choose : ");
    scanf("%d",&endscreen);

    switch(endscreen)
    {
        case 1:
        system("cls");
        goto playfaired;
        break;

        case 2:
        //goto display;
        break;

        case 3:
        exit(0);
    }
}



                                                //FUNCTION FOR HILL CTF


                                                //FUNCTION FOR HILL ED

void encryptionhill();    //encrypts the message
void decryptionhill();    //decrypts the message
void getKeyMessage();    //gets key and message from user
void inverse();        //finds inverse of key matrix

void hill_ed()
{
    float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
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

void encryptionhill()
{
    float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
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

void decryptionhill()
{
    float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
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

void getKeyMessage()
{
    float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
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

void inverse()
{
    float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
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
    int start1,start1_1,start2;
    char eord;
    homescreen:
    printf("----------------------------------------\n");
    printf("CHALLENGES USING CRYPTOGRAPHY TECHNIQUES\n");
    printf("----------------------------------------\n\n");
    printf("1. Challenges\n2. Encryptor | Decryptor\n3. Exit\n\nSelect : ");

    scanf("%d",&start1);

    switch(start1)
    {
        case 1:  //Challenges
            system("cls");
            printf("--------------------------\n");
            printf("Welcome to the Challenges!\n");
            printf("--------------------------\n\n");
            printf("--------------\n");
            printf("    Easy\n");
            printf("--------------\n\n");
            printf("1. Caesar\n2. ROT13\n\n");
            printf("--------------\n");
            printf("   Medium\n");
            printf("--------------\n\n");
            printf("3. Vignere\n\n");
            printf("--------------\n");
            printf("    Hard\n");
            printf("--------------\n\n");
            printf("4. Playfair\n5. Hill\n\n");
            printf("Choose Difficulty Level : ");
            scanf("%d",&start1_1);

            switch(start1_1)  //Choose Difficulty
            {
                case 1:
                    //Caesar
                    system("cls");
                    caesar_ctf();
                    system("cls");
                    goto homescreen;
                    break;

                case 2:
                    //ROT13
                    system("cls");
                    rot_ctf();
                    system("cls");
                    goto homescreen;
                    break;

                case 3:
                    //Vignere
                    system("cls");
                    vigenere_ctf();
                    system("cls");
                    goto homescreen;
                    break;

                case 4:
                    //Playfair
                    system("cls");
                    playfair_ctf();
                    system("cls");
                    goto homescreen;
                    break;

                case 5:
                    //Hill

                    break;
            }

        break;

        case 2:  //Encryptor/Decryptor

            system("cls");
            printf("----------------------------\n");
            printf("ENCRYPTION | DECRYPTION TOOL\n");
            printf("----------------------------\n\n");
            printf("1. Caesar\n2. ROT13\n3. Vignere\n4. Playfair\n5. Hill\n\n");
            printf("Choose Cipher : ");
            scanf("%d",&start2);

            switch(start2)
            {
                case 1:

                    //Caesar
                    system("cls");
                    caeser_ED();
                    system("cls");
                    goto homescreen;
                    break;

                case 2:

                    //ROT13
                    system("cls");
                    rot_ed();
                    system("cls");
                    goto homescreen;
                    break;

                case 3:

                    //Vigenere
                    system("cls");
                    vigenere_ed();
                    system("cls");
                    goto homescreen;
                    break;

                case 4:

                    //Playfair
                    system("cls");
                    playfair_ed();
                    system("cls");
                    goto homescreen;

                    break;

                case 5:

                    //Hill
                    system("cls");
                    hill_ed();
                    system("cls");
                    goto homescreen;
                    break;

            }

        case 3:

            exit(0);

    }
}
