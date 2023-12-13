using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aleshko_lab5
{
    [Serializable]
    internal class Aleshko_account
    {
        protected string name;
        protected string type;
        protected int money;
        public virtual void Input() //
        {
            Console.WriteLine("Введите ФИО ");
            name = Console.ReadLine();
            Console.WriteLine("Введите тип счёта ");
            type = Console.ReadLine();
            Console.WriteLine("Введите баланс счёта ");
            while (!int.TryParse(Console.ReadLine(), out money))
            {
                Console.WriteLine("Слишком много денег или мимо");
            };
        }
        public virtual void Output()
        {
            Console.WriteLine($"ФИО: {name}");
            Console.WriteLine($"Тип счёта: {type}");
            Console.WriteLine($"Баланс: {money} ");
        }
    }
}
