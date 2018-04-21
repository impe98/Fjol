using System;

namespace Simon {
    internal class Program {
        public static void Main(string[] args) {
            Console.WriteLine(
                "Welcome to Simon! Remember the sequence of inputs shown to you and press the correct buttons accordingly!");
            Sequence.PlayGame();
        }
    }
}