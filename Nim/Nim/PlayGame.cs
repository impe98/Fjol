using System;
using System.Security.Cryptography.X509Certificates;

namespace Nim {
    public class PlayGame {
        public static string playerOne;
        public static string playerTwo;
        public static int round = 1;
        public bool gameIsPlaying = true;
        public static int[] arrayOfHeaps;

        public static int[] InitializeHeaps() {
            Console.WriteLine("Welcome to Nim!");
            Console.WriteLine("Who will be playing?");
            Console.WriteLine("Please give name of player one: ");
            playerOne = Console.ReadLine();
            Console.WriteLine("Great! Now give the name of player two please: ");
            playerTwo = Console.ReadLine();
            Console.WriteLine("Please give an amount of heaps to initialize: ");
            int amountOfHeaps = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("The game will be played with {0} heaps!", amountOfHeaps);
            Console.WriteLine("\n");
            Console.WriteLine("Please give an amount of matches for each heap to have: ");
            int amountOfMatches = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Each heap will have {0} matches and the game is set!", amountOfMatches);
            arrayOfHeaps = new int[amountOfHeaps];
            Console.WriteLine("\n");
            for (int i = 0; i < arrayOfHeaps.Length; i++) {
                arrayOfHeaps.SetValue(amountOfMatches, i);
            }

            foreach (var c in arrayOfHeaps) {
                Console.WriteLine("{0}", c);
            }

            TakeTurn();
            return arrayOfHeaps;

        }

        public static void TakeMatches(int c, int i) {
            Console.WriteLine("\n");
            if (arrayOfHeaps[c] - i > 0) {
                arrayOfHeaps.SetValue((arrayOfHeaps[c] - (i + 1)), c);
            }
            else {
                arrayOfHeaps.SetValue(0, c);
            }

            foreach (var k in arrayOfHeaps) {
                Console.WriteLine("This heap has {0} matches left to take", k);
            }

            if (IsGameOver()) {
                
                Console.WriteLine("Game over! The winner is {0}, congratulations!", WhoseTurnIsIt());
            }
            else {
                TakeTurn();
            }
        }

        public static void TakeTurn() {
            Console.WriteLine("The current turn belongs to {0}", WhoseTurnIsIt());
            Console.WriteLine("Please give a heap to take matches from: ");
            int chosenHeap = Convert.ToInt32(Console.ReadLine()) - 1;
            Console.WriteLine("Please specify the amount of matches to take: ");
            int chosenMatches = Convert.ToInt32(Console.ReadLine()) -1;
            if (IsCorrectIndex(chosenHeap) && IsCorrectAmountOfMatches(chosenMatches)) {
                TakeMatches(chosenHeap, chosenMatches);
            }
            else {
                TakeTurn();
            }

        }

        public static bool IsGameOver() {
            int i = 0;
            foreach (var v in arrayOfHeaps) {
                if (v == 0) {
                    i++;
                }
            }

            if (i == arrayOfHeaps.Length) {
                return true;
            }

            return false;
        }

        public static bool IsCorrectIndex(int i) {
            if (i < 0) {
                Console.WriteLine("Illegal input, please specify heap by giving the correspondent number from 1 to {0} \n",
                    arrayOfHeaps.Length - 1);
                round--;
                return false;
            }
            else if (i > arrayOfHeaps.Length - 1) {
                Console.WriteLine("Illegal input, please specify heap by giving the correspondent number from 1 to {0} \n",
                    arrayOfHeaps.Length - 1);
                round--;
                return false;
            }
            else {
                return true;
            }
        }

        public static bool IsCorrectAmountOfMatches(int i) {
            if (i < 0) {
                Console.WriteLine("Amount of matches to be taken cannot be negative nor zero \n");
                round--;
                return false;
            }
            else if (i >= 3) {
                Console.WriteLine("You can only take 1, 2 or 3 mathces \n");
                round--;
                return false;
            }
            else {
                return true;
            }
            
        }

        public static string WhoseTurnIsIt() {
            if (round % 2 == 0) {
                round++;
                return playerTwo;
            }

            round++;
            return playerOne;
        }
        
    }
}