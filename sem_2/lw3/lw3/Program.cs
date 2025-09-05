class Program {
    static void Main() {
        double a = 0, b = 0, c = 0, x1, x2, discr;
        bool Flag = true;
        while (Flag)
        {
            try
            {
                Console.WriteLine("Введите коэффициент перед x^2:");
                a = double.Parse(Console.ReadLine());
                if (a == 0)
                {
                    Console.WriteLine("Это не квадратное уравнение. Коэффициент a не может быть равен 0.");
                    
                }

                Console.WriteLine("Введите коэффициент перед x^1:");
                b = double.Parse(Console.ReadLine());

                Console.WriteLine("Введите коэффициент перед x^0:");
                c = double.Parse(Console.ReadLine());

                Flag = false; 
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка. Введите числовые значения!");
            }
        }

        discr = b * b - 4 * a * c;

        if (discr > 0)
        {
            x1 = (-b - Math.Sqrt(discr)) / (2 * a);
            x2 = (-b + Math.Sqrt(discr)) / (2 * a);
            Console.WriteLine($"Первый корень: {x1}\nВторой корень: {x2}");
        }
        else if (discr == 0)
        {
            x1 = -b / (2 * a);
            Console.WriteLine($"Единственный корень: {x1}");
        }
        else
        {
            Console.WriteLine("Действительных корней нет.");
        }
    }
}
