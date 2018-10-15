#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findIndexInWord(char wordToGuess[], char c);
bool isAllZeroes(char wordToCheck[]);

char arrayOfGuessedLetters[];

int main(int argc, char *argv[]) {
  char *words[] = {
    "computer",
    "smartphone",
    "banana",
    "car",
    "brother",
    "newphew",
    "videogame",
    "pepsi",
    "donkey",
    "science",
    "obligation",
    "teenager",
    "adult",
    NULL
  };
  int i = 0;
  int numberOfWords = 0;
  bool shallIncrement = true;
  while (shallIncrement) {
    if (words[i] == NULL) {
      numberOfWords = i;
      shallIncrement = false;
    }
    else {
      i++;
    }
  }
  time_t t;
  srand((unsigned) time(&t));
  int pickWord = rand() % numberOfWords;
  char *wordPlayed = words[pickWord];
  int lengthOfWord;
  for (int j = 0; wordPlayed[j] != NULL; j++) {
    lengthOfWord = j+1;
  }
  arrayOfGuessedLetters[lengthOfWord];
  memset( arrayOfGuessedLetters, '1', lengthOfWord);
  int lives = 5;
  bool haveNotGuessedAll = true;
  while (haveNotGuessedAll && lives > 0) {
    printf("Guessed letters: %s\n", arrayOfGuessedLetters);
    printf("Please guess a letter\n");
    char c = getchar();
    getchar();
    int plads = findIndexInWord(wordPlayed, c);
    while (plads != -1 && plads != -2) {
      arrayOfGuessedLetters[plads] = c;
      if (findIndexInWord(wordPlayed, c) != -1) {
	plads = findIndexInWord(wordPlayed, c);
      }
      else {
	plads = -2;
      }
    }
    if (plads == -1) {
      lives--;
      printf("Amount of lives left: %d\n", lives);
    }
    if (isAllZeroes(arrayOfGuessedLetters)) {
      haveNotGuessedAll = false;
    }
  }
}
    

int findIndexInWord(char wordToGuess[], char c) {
  int lengthOfWordToGuess;
  for (int i = 0; wordToGuess[i] != NULL; i++) {
    lengthOfWordToGuess = i;
  }
  for (int i = 0; i < lengthOfWordToGuess+1; i++) {
    if (wordToGuess[i] == c && arrayOfGuessedLetters[i] == '1') {
      return i;
    }
  }
  return -1;
}

bool isAllZeroes(char wordToCheck[]) {
  int lengthOfWordToCheck;
  for (int i = 0; wordToCheck[i] != NULL; i++) {
    lengthOfWordToCheck = i+1;
  }
  int numberOfZeroes = 0;
  for (int i = 0; i < lengthOfWordToCheck; i++) {
    if (wordToCheck[i] == '1') {
      numberOfZeroes++;
    }
  }
  if (numberOfZeroes == 0) {
    return true;
  }
  return false;
}


