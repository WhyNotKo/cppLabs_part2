using System;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Aleshko_lab5
{
    [Serializable]
    internal class Aleshko_bank
    {
        private List<Aleshko_account> bank = new List<Aleshko_account>();
        public void Addacc()
        {
            Aleshko_account acc;
            Console.WriteLine();
            acc = new Aleshko_account();
            acc.Input();
            bank.Add(acc);
        }
        public void AddVip()
        {
            Aleshko_vip acc;
            Console.WriteLine();
            acc = new Aleshko_vip();
            acc.Input();
            bank.Add(acc);
        }
        public void Print()
        {
            if (bank.Count == 0)
                Console.WriteLine("Банк банкрот ");
            else
            {
                Console.WriteLine("Клиенты банка: \n");
                foreach (Aleshko_account acc in bank)
                {
                    acc.Output();
                    Console.WriteLine("");
                }
            }
        }
        public void FileSave()
        {
            Console.WriteLine("Введите имя файла без расширения: ");
            string fileName = Console.ReadLine() + ".dat";
            using (FileStream fout = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                formatter.Serialize(fout, bank); // перевод данных в байты
            }
        }
        public void FileLoad()
        {

            Console.WriteLine("Введите имя файла без расширения: ");
            string fileName = Console.ReadLine() + ".dat";
            using (FileStream fin = new FileStream(fileName, FileMode.Open))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                bank = formatter.Deserialize(fin) as List<Aleshko_account>;
            }
        }
        public void Clear()
        {
            bank.Clear();
        }
    }
}
