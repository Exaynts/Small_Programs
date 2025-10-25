using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SearchInAGraph
{
    class Input_nums
    {
        public static int InputNatural()
        {
            int a = 0;
            string num_string;
            int num;
            while (true) {
                num_string = Console.ReadLine();
                try
                {
                    num = int.Parse(num_string);

                }
                catch {
                    Console.WriteLine("Input a natural number, please");
                    continue;
                }
                break;
            }
            return num;
        }
    }
}