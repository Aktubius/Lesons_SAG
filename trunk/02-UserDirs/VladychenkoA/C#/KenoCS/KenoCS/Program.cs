﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace KenoCS
{
    class Program
    {
        static void Main(string[] args)
        {
           
            Keno keno = new Keno();
            //keno.Print();
            //keno.Num = 1234;
            //keno.Date = "05.04.2010";
            //keno.Numberloto = "A";
            //keno.Numberballs = 3;
            //int[] a = {01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
            //keno.Number = a;
            //Console.WriteLine();
            //keno.ArrayListKeno.Add(keno);
            //keno.ArrayLiistKenoPrint(keno.ArrayListKeno);
            //Console.WriteLine();
            keno.ReadFile();
            keno.ArrayLiistKenoPrint(keno.ArrayListKeno);
        }
    }
}
