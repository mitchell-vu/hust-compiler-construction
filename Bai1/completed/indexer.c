#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dllist.c"

treetype searchTreeByWord(treetype T, char *word)
{
	elmType wordData;
	strcpy(wordData.word, word);
	return searchT(T, wordData);
}

void addWord(treetype *wordTree, char *word, int line)
{
	treetype curword = searchTreeByWord(*wordTree, word);
	if (curword == NULL)
	{
		elmType wordData;
		strcpy(wordData.word, word);
		wordData.appearCount = 1;
		makeNullList(&(wordData.rootLine), &(wordData.curLine), &(wordData.tailLine));
		AppendList(line, &(wordData.rootLine), &(wordData.curLine), &(wordData.tailLine));
		insertNode(wordTree, wordData);
	}
	else
	{
		curword->element.appearCount++;
		AppendList(line, &(curword->element.rootLine), &(curword->element.curLine), &(curword->element.tailLine));
	}
}

void readFile(char *fileName, treetype *wordTree, treetype *stopTree)
{
	char c, prevC;
	int count, line;
	char word[20];
	bool properNoun, isWord;
	FILE *ptr = fopen(fileName, "r");
	if (ptr == NULL)
	{
		printf("cannot open %s\n", fileName);
		return;
	}
	for (count = 0, line = 1, prevC = 'f', isWord = false, properNoun = false; (c = fgetc(ptr)) != EOF; prevC = c)
	{
		if (c >= 65 && c <= 90)
		{
			c += 32;
			if (prevC == ' ')
			{
				properNoun = true;
			}
		}

		if (c < 97 || c > 122)
		{
			if (!properNoun && isWord)
			{
				word[count] = '\0';
				if (searchTreeByWord(*stopTree, word) == NULL)
				{
					addWord(wordTree, word, line);
				}
			}

			count = 0;
			properNoun = false;
			isWord = false;

			if (c == '\n')
			{
				line++;
			}
		}
		else
		{
			if (!isWord)
				isWord = true;
			word[count++] = c;
		}
	}
	fclose(ptr);
}

int main(int argc, char const *argv[])
{
	// system("clear && printf \'\e[3J\'");

	treetype wordTree, stopTree;
	char stopWordFilePath[] = "exercise1.txt";
	char wordFilePath[] = "alice30.txt";


	makeNullTree(&wordTree);
	makeNullTree(&stopTree);

	readFile(stopWordFilePath, &stopTree, &wordTree);
	readFile(wordFilePath, &wordTree, &stopTree);

	inOrderLog(wordTree);

	freeTree(wordTree);
	freeTree(stopTree);
	
	return 0;
}