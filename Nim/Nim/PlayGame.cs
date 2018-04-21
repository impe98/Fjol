using System;

namespace Nim {
    public class PlayGame {
        public static int[] InitializeHeaps() {
            Console.WriteLine("Welcome to Nim!");
            Console.WriteLine("Please give an amount of heaps to initialize: ");
            int amountOfHeaps = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("\n");
            Console.WriteLine("Please give an amount of matches for each heap to have: ");
            int amountOfMatches = Convert.ToInt32(Console.ReadLine());
            int[] arrayOfHeaps = new int[amountOfHeaps];

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
            InitializeHeaps().SetValue(i, c);
            foreach (var k in InitializeHeaps()) {
                Console.WriteLine("{0}", k);
            }

            TakeTurn();
        }

        public static void TakeTurn() {
            Console.WriteLine("Please give a heap to take matches from: ");
            int chosenHeap = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Please specify the amount of matches to take: ");
            int chosenMatches = Convert.ToInt32(Console.ReadLine());
            TakeMatches(chosenHeap, chosenMatches);
        }
    }
}