using System;
using System.Collections.Generic;

namespace Hangman2 {
    public class WordFinder {
        
        public static string findAWord() {
            List<string> listOfWords = new List<string>();
            listOfWords.Add("Adult");
           // listOfWords.Add("Money");
            // listOfWords.Add("Prostitute");
            // listOfWords.Add("Beer");
            // listOfWords.Add("Redbull");
            Random r = new Random();
            int rInt = r.Next(0, listOfWords.Count);
            string foundWord = listOfWords[rInt];
            return foundWord;
            
            

        }   
    }
}