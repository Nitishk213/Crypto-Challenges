// C program to implement Playfair Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define SIZE 100

// Function to convert the string to lowercase
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

// Driver code
int main()
{


	char key[SIZE];
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
  	printf("%s\n",strans);
  	printf("%s\n",str);

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
    printf("%s\n",strans);

    clock_t t;
    t = clock();
    top:
    printf("------------------------\n");
    printf("Enter Decrypted Message: ");
    scanf("%s",&ans);
    printf("------------------------\n\n");

    int compare;
    compare = strcmp(strans,ans);
    printf("%d\n",compare);
    printf("%s\n",str);
    printf("%s\n",strans);
    printf("%s\n",ans);

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

// This code is contributed by AbhayBhat
