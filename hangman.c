using System;
using System.Collections.Generic;

namespace HangmanGame
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> words = new List<string>
            {
                "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
                "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugli",
                "vanilla", "watermelon", "xigua", "yellowpassionfruit", "zucchini"
            };

            Random random = new Random();
            string wordToGuess = words[random.Next(words.Count)];
            char[] guessedWord = new string('_', wordToGuess.Length).ToCharArray();
            int attemptsLeft = 6;
            List<char> guessedLetters = new List<char>();

            Console.WriteLine("행맨 게임에 오신 것을 환영합니다!");
            Console.WriteLine($"단어: {new string(guessedWord)}");

            while (attemptsLeft > 0)
            {
                Console.Write("글자를 추측하세요: ");
                char guess = char.ToLower(Console.ReadLine()[0]);

                if (guessedLetters.Contains(guess))
                {
                    Console.WriteLine("이미 추측한 글자입니다. 다시 시도하세요.");
                    continue;
                }

                guessedLetters.Add(guess);

                if (wordToGuess.Contains(guess))
                {
                    for (int i = 0; i < wordToGuess.Length; i++)
                    {
                        if (wordToGuess[i] == guess)
                        {
                            guessedWord[i] = guess;
                        }
                    }
                }
                else
                {
                    attemptsLeft--;
                    Console.WriteLine($"틀렸습니다! 남은 시도 횟수: {attemptsLeft}");
                }

                Console.WriteLine($"단어: {new string(guessedWord)}");

                if (new string(guessedWord) == wordToGuess)
                {
                    Console.WriteLine("축하합니다! 단어를 맞추셨습니다.");
                    break;
                }
            }

            if (attemptsLeft == 0)
            {
                Console.WriteLine($"아쉽게도 실패하셨습니다. 정답은 '{wordToGuess}'였습니다.");
            }
        }
    }
}
