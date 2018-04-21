using System;
using System.Collections.Generic;

namespace Simon {
    public class Sequence {
        private static List<char> ListOfChars = new List<char>();
        
        private static char[] array = new char[] {'a', 's', 'd', 'f'};

        private static char findChar() {
            Random rnd = new Random();
            int rndInt = rnd.Next(4);
            return array[rndInt];

        }

        private static List<char> addCharToList() {
            ListOfChars.Add(findChar());
            return ListOfChars;
        }

        public static bool PlayGame() {
            addCharToList();
            Console.WriteLine(" ");
            Console.WriteLine("Please remember this sequence  don't write anything!:");
            ListOfChars.ForEach(i => Console.Write("{0}", i));
            Console.WriteLine(" ");
            System.Threading.Thread.Sleep(3000);
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("******************************************************\n");
            Console.WriteLine("Please write the sequence shown before: ");
            int numberOfInputs = 0;
            List<char> listOfInputs = new List<char>();
            while (numberOfInputs < ListOfChars.Count) {
                Char guess = Console.ReadKey().KeyChar;
                listOfInputs.Add(guess);
                numberOfInputs++;
            }
            for (int i = 0; i < ListOfChars.Count; i++) {
                if (listOfInputs[i] != ListOfChars[i]) {
                    Console.WriteLine(" ");
                    Console.WriteLine("You made a mistake");
                    Console.WriteLine("The correct sequence was:");
                    ListOfChars.ForEach(j => Console.Write("{0}", j));
                    return false;
                }
                    
            }

            PlayGame();
            return true;
        }
    }
}
