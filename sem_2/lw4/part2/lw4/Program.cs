class Program
{
    static Dictionary<string, string> ReadReplacementDictionary()
    {
        string[] dict = ["ИУ6💪"];
        string input;

        Console.WriteLine("Введите словарь замен");
        while (dict.Length % 2 != 0)
        {
            Console.WriteLine("Количество слов должно быть чётным");
            input = Console.ReadLine();
            dict = input.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        }

        Dictionary<string, string> replacements = new Dictionary<string, string>();
        for (int i = 0; i < dict.Length; i += 2)
        {
            replacements.Add(dict[i].Trim('.'), dict[i + 1].Trim('.'));
        }

        return replacements;
    }

    static List<string> ReadInputLines()
    {
        List<string> lines = new List<string>();
        string input;
        Console.WriteLine("Введите строки, которые нужно изменить. Чтобы прекратить ввод, введите пустую строку.");
        while ((input = Console.ReadLine()) != "")
        {
            lines.Add(input.Trim('.'));
        }

        return lines;
    }

    static void PrintLines(List<string> lines, string header)
    {
        Console.WriteLine(header);
        foreach (string line in lines)
        {
            Console.WriteLine(line);
        }
    }

    static List<string> ApplyReplacements(List<string> lines, Dictionary<string, string> replacements)
    {
        List<string> outputLines = new List<string>();

        foreach (string line in lines)
        {
            string rawLine = line.TrimEnd('.');
            string[] words = rawLine.Split(' ', StringSplitOptions.RemoveEmptyEntries);

            for (int j = 0; j < words.Length; j++)
            {
                if (replacements.ContainsKey(words[j]))
                {
                    words[j] = replacements[words[j]];
                }
            }

            outputLines.Add(string.Join(" ", words) + ".");
        }

        return outputLines;
    }

    static void Main()
    {
        Dictionary<string, string> replacements = ReadReplacementDictionary();
        List<string> inputLines = ReadInputLines();
        Console.WriteLine();
        PrintLines(inputLines, "Изначальные строки:");
        List<string> outputLines = ApplyReplacements(inputLines, replacements);
        Console.WriteLine();
        PrintLines(outputLines, "Отредактированные строки:");
    }
}
