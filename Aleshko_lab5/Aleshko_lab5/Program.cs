using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aleshko_lab5
{
    internal class Program
    {
        void PrintMenu()
        {
            string s = @"Menu:
1. Добавить пользователя
2. Добавить ВИПа
3. Сохранить в файл
4. Загрузить из файла
5. Показать всех клиентов
6. Закрыть банк
0. Exit
";
            Console.WriteLine(s);
        }
        static void Main(string[] args)
        {
            int ans;
            Aleshko_bank bank = new Aleshko_bank();
            Program program = new Program();
            while (true)
            {
                program.PrintMenu();
                ans = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine(" ");
                switch(ans)
                {
                    case 0:
                        return;
                    case 1:
                        bank.Addacc();
                        break;
                    case 2:
                        bank.AddVip();
                        break;
                    case 3:
                        bank.FileSave();
                        break;
                    case 4:
                        bank.FileLoad();
                        break;
                    case 5:
                        bank.Print();
                        break;
                    case 6:
                        bank.Clear();
                        break;
                    default: break;
                }
                    
            }
        }
    }
}
