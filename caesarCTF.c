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
