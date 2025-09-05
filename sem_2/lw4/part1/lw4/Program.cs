class Program
{
    static int[,] ReadMatrix(int n)
    {
        Console.WriteLine("Введите элементы матрицы построчно:");
        int[,] matrix = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            for (int j = 0; j < n; j++)
            {
                matrix[i, j] = int.Parse(inputs[j]);
            }
        }
        return matrix;
    }

    static void PrintMatrix(int[,] matrix)
    {
        int n = matrix.GetLength(0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                Console.Write(matrix[i, j] + " ");
            Console.WriteLine();
        }
    }

    static int ReadMatrixOrder()
    {
        int n;
        while (true)
        {
            Console.WriteLine("Введите порядок матрицы: ");
            if (int.TryParse(Console.ReadLine(), out n) && n > 0)
                return n;
            Console.WriteLine("Порядок должен быть положительным целым числом.");
        }
    }

    static void SwapRows(int[,] matrix, int n1, int n2)
    {
        int cols = matrix.GetLength(1);
        for (int i = 0; i < cols; i++)
        {
            int temp = matrix[n1, i];
            matrix[n1, i] = matrix[n2, i];
            matrix[n2, i] = temp;
        }
    }

    static void SortMatrixByMainDiagonal(int[,] matrix)
    {
        int n = matrix.GetLength(0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (matrix[i, i] > matrix[j, j])
                    SwapRows(matrix, i, j);
            }
        }
    }

    static void Main()
    {
        int n = ReadMatrixOrder();
        int[,] matrix = ReadMatrix(n);

        Console.WriteLine("Введённая матрица:");
        PrintMatrix(matrix);

        SortMatrixByMainDiagonal(matrix);

        Console.WriteLine("Отсортированная матрица:");
        PrintMatrix(matrix);
    }
}
