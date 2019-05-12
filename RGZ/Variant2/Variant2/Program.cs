using System;

namespace Variant2
{
    internal class Program
    {
        private static readonly int SIZE = 5;
        private static readonly int RAND_MAXI = 10;
        private static readonly int RAND_MINI = 1;
        static void Init(ref int[][] a, int size)
        {
            a = new int[size][];
            Random rand = new Random();
            for (int i = 0; i < size; i++)
                a[i] = new int[rand.Next(RAND_MINI,RAND_MAXI)];
        }

        static int Add(ref int[][] a, int size, int num)
        {
            int result = 0;
            if(a != null)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < a[i].Length; j++)
                    {
                        if (a[i][j] == 0)
                        {
                            result = 1;
                            a[i][j] = num;
                        }

                    }
                }
            }
            //return 1 - successfully added, 0 - failed
            return result;
        }

        static int Delete(ref int[][] a, int size, int row, int col)
        {
            if (row > size || a[row].Length < col)
                return 0;
            a[row][col] = 0;

            return 1;
        }

        static int Expand(ref int[][] a, int size, int row, int newSizeRow)
        {
            if (size < row)
                return 0;

            int[] newRow = new int[newSizeRow];
            for (int i = 0; i < a[row].Length; i++)
            {
                newRow[i] = a[row][i];
            }

            a[row] = newRow;
            
            return 1;
        }

        static void Free(ref int[][] a, int size)
        {
            for (int i = 0; i < size; i++)
            {
                a[i] = null;
            }

            a = null;
        }

        static void Show(ref int[][] a, int size)
        {
            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < a[i].Length; j++)
                    Console.Write(a[i][j] + " ");
                Console.Write("\n");
            }
        }

        static float PercentPerSize(int[][] a, int size)
        {
            float percent = 100.00f;
            for (int i = 0; i < size; i++)
            {
                int count = 0;
                for (int j = 0; j < a[i].Length; j++)
                {
                    if (a[i][j] != 0)
                        count++;
                }

                if (((float) count / a[i].Length) < percent)
                    percent = (float) count / a[i].Length;
            }
            
            return percent * 100;
        }

        static int Smallest(int[][] a, int size)
        {
            int min = a[0].Length;
            for (int i = 0; i < size; i++)
            {
                if (min > a[i].Length)
                    min = a[i].Length;
            }

            return min;
        }
        
        public static void Main(string[] args)
        {
            Random rand = new Random();
            int[][] myArr = null;
            Init(ref myArr, SIZE);
            for(int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < myArr[i].Length; j++)
                {
                    int number = rand.Next(RAND_MINI, RAND_MAXI);
                    Add(ref myArr, SIZE, number);   
                }
            }

            Show(ref myArr, SIZE);
            Console.WriteLine(
                Delete(
                    ref myArr, SIZE, 
                    1, 
                    1) == 0
                ? "Doesn't exist on this position"
                : "Deleted successfully");
            Show(ref myArr, SIZE);
            Console.WriteLine("Min percentage of filling: {0}%", PercentPerSize(myArr, SIZE));
            Console.WriteLine("The smallest size in stair array: {0}", Smallest(myArr, SIZE));
            Console.WriteLine(Expand(ref myArr,
                    SIZE,
                    10,
                    10) == 0
                ? "Doesn't exist on this position"
                : "Expanded successfully") ;
            Free(ref myArr, SIZE);
        }
    }
}