﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using DreamAcademy;

/* створити ієрархію
 *          Людина
 *  Учень                   Співробітник навчального закладу
 *                          Вчитель                     Бугалтер
 *  
    Маємо мати змогу:
 *1) створити список викладачів, учнів, бухгалтерів
 *2) Учень має: ПІБ, середній бал, рік народження
 *3) Бухгалтер, Вчитель: зарплату (різну)
 *4) друк таблиць з використанням символів псевдографіки
 *5) видалення, додавання, редагування списків(викладачів, учнів, бухгалтерів)
 */
namespace dom_2_3
{
    class Program
    {
        static void Main(string[] args)
        {
             Application myApp = new Application();
             myApp.Run();           
        }
    }
}
