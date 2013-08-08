using System;

namespace SquareCipher
{
    class Program
    {
        static void Main(string[] args)
        {
            SquareCipher s = new SquareCipher();
            Console.WriteLine("Give me a sentence to encode:");
            string inp = Console.ReadLine();
            string res = s.squareCipher(inp);
            Console.WriteLine();
            Console.WriteLine("The sentence: " + "-- " + inp + " -- ");
            Console.WriteLine("Has become: " + "-- " + res + " -- ");
            Console.ReadLine();
        }
    }

    public class SquareCipher
    {
        public string squareCipher(string inp)
        {
            //Remove spaces
            string inputWithoutSpaces = inp.Replace(" ", "");
            //Get square dimensions
            int columns = 2;
            int rows = 1;
            while (columns * rows < inputWithoutSpaces.Length)
            {
                columns++;
                rows++;
            }
            //Add extra spaces
            int spacesToAdd = (columns * rows) - inputWithoutSpaces.Length;
            for (int i = 0; i < spacesToAdd; i++)
                inputWithoutSpaces += " ";
            //Split the word
            int x = 0;
            string[] input = new string[rows];
            for (int i = 0; i < rows; i++)
            {
                input[i] = inputWithoutSpaces.Substring(x, columns);
                x += columns;
            }
            //Encrypt
            string[] res = new string[input[0].Length];
            for (int i = 0; i < input[0].Length; i++)
            {
                for (int a = 0; a < input.Length; a++)
                {
                    string temp = input[a][i].ToString();
                    if (temp != " ")
                        res[i] += input[a][i].ToString();
                }
            }
            string result = "";
            for (int i = 0; i < res.Length; i++)
            {
                result += res[i] + " ";
            }
            result = result.Remove(result.Length - 1, 1);
            return result;
        }
    }
}
