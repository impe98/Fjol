using System;

namespace Hangman2 {
    public class PlayGame {
        private static string hiddenWord = new string('*', WordFinder.findAWord().Length);
        public static int lifes = 5;

        private static void loseLife() {
            lifes--;
            Console.WriteLine("{0}", hiddenWord);
            askForGuess();

        }


        private static void showWord(char c, int n) {
            char[] array = hiddenWord.ToCharArray();
            array[n] = c;
            hiddenWord = new string(array);
            Console.WriteLine(hiddenWord);
            askForGuess();
        }

        public static void askForGuess() {
            if (lifes == 0) {
                Console.WriteLine("You lost! Booooh!");
                lifes = 6;
                WordFinder.findAWord();
            }
            else {
                Console.WriteLine("Guess a letter!");
                char guess = Console.ReadKey().KeyChar;
                for (int i = 0; i < (WordFinder.findAWord().Length - 1); i++) {
                    if (WordFinder.findAWord()[i] == guess) {
                        showWord(guess, i);


                    }

                loseLife();
                    


                }

            }

            
        }
    }
    }

