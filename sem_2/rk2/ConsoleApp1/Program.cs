using System;

public abstract class A
{
    protected int[] S; 
    public A(int[] array)
    {
        S = new int[array.Length];
        Array.Copy(array, S, array.Length);
    }
    
    public abstract void Title();
    
    public void Print()
    {
        Title();
        Console.WriteLine("Массив: " + string.Join(", ", S));
    }
}

public class B : A
{
    public B(int[] array) : base(array) { }
    
    public override void Title()
    {
        Console.WriteLine("Это объект класса B");
    }
    public void ZeroEvenElements()
    {
        for (int i = 0; i < S.Length; i++)
        {
            if (S[i] % 2 == 0) 
            {
                S[i] = 0; 
            }
        }
    }
}

public class C : A
{
    public C(int[] array) : base(array) { }
    
    public override void Title()
    {
        Console.WriteLine("Это объект класса C");
    }
   
    public void ZeroOddElements()
    {
        for (int i = 0; i < S.Length; i++)
        {
            if (S[i] % 2 != 0) 
            {
                S[i] = 0; 
            }
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        int[] testArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   
        B objB = new B(testArray);
        C objC = new C(testArray);
        
        Console.WriteLine("Демонстрация работы класса B:");
        objB.Print(); 
        
        objB.ZeroEvenElements(); 
        objB.Print(); 
        
        Console.WriteLine();
        
        Console.WriteLine("Демонстрация работы класса C:");
        objC.Print(); 
        
        objC.ZeroOddElements(); 
        objC.Print(); 
    }
}