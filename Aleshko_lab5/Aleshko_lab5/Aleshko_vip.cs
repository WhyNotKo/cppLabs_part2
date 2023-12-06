using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aleshko_lab5
{
    [Serializable]
    internal class Aleshko_vip : Aleshko_account
    {
        private int credit_limit;
        public override void Input()
        {
            base.Input();
            Console.WriteLine("Введите кредитный лимит ");
            credit_limit = Convert.ToInt32(Console.ReadLine());
        }
        public override void Output() 
        { 
            base.Output();
            Console.WriteLine($"Кредитный лимит: {credit_limit}.");
        }
    }
}
