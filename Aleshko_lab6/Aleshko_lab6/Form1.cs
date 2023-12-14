using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Aleshko_lab6
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct Aleshko_account
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 100)]
        public string name;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 100)]
        public string type;

        [MarshalAs(UnmanagedType.I4)]
        public int money;

        [MarshalAs(UnmanagedType.I4)]
        public int credit;

        [MarshalAs(UnmanagedType.Bool)]
        public bool isVIP;
    }
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            textBox_name.Visible = false;
            textBox_type.Visible = false;
            textBox_balance.Visible = false;
            textBox_credit.Visible = false;
            label_credit.Visible = false;
            label1.Visible = false;
            label2.Visible = false;
            label4.Visible = false;


        }

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern int getContainerSize();

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern void loadFromFile(StringBuilder filename);

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern void saveToFile(StringBuilder filename);

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern void deleteAccount(int index);

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern void getAccount(ref Aleshko_account s, int index);

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern void updateAccount(ref Aleshko_account s, int index);

        [DllImport(@"Aleshko_dll.dll", CharSet = CharSet.Ansi)]
        public static extern void addAccount(ref Aleshko_account s);

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        public void refreshListBoxContent(int index = 0)
        {
            int size = getContainerSize();
            if (size == 0)
                return;
            listBox1.Items.Clear();

            for (int i = 0; i < size; i++)
            {
                Aleshko_account s = new Aleshko_account();
                getAccount(ref s, i);
                listBox1.Items.Add(s.name);
            }
            listBox1.SelectedIndex = index;
        }

        private void buttonchange_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index == -1)
                return;

            Aleshko_account s = new Aleshko_account();
            getAccount(ref s, index);

            s.name = textBox_name.Text;
            s.type = textBox_type.Text;
            if (!int.TryParse(textBox_balance.Text, out s.money))
                s.money = 99999999;

            if (textBox_credit.Visible)
            {
                if (!int.TryParse(textBox_credit.Text, out s.credit))
                    s.credit = 99999999;
                s.isVIP = true;
            }

            updateAccount(ref s, index);
            refreshListBoxContent(index);
        }

        private void button_load_Click(object sender, EventArgs e)
        {
            

            listBox1.Items.Clear();
            openFileDialog1.InitialDirectory = Directory.GetCurrentDirectory();
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var FileName = new StringBuilder(openFileDialog1.FileName);
                loadFromFile(FileName);
                refreshListBoxContent();
            }
            if(listBox1.Items.Count != 0)
            {
                textBox_name.Visible = true;
                textBox_type.Visible = true;
                textBox_balance.Visible = true;
                textBox_credit.Visible = true;
                label_credit.Visible = true;
                label1.Visible = true;
                label2.Visible = true;
                label4.Visible = true;
            }
        }

        private void button_save_Click(object sender, EventArgs e)
        {
            saveFileDialog1.InitialDirectory = Directory.GetCurrentDirectory();
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var FileName = new StringBuilder(saveFileDialog1.FileName);
                saveToFile(FileName);
            }
        }

        private void button_add_main_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label2.Visible = true;
            label4.Visible = true;
            textBox_name.Visible = true;
            textBox_type.Visible = true;
            textBox_balance.Visible = true;
            Aleshko_account s = new Aleshko_account()
            {
                isVIP = false,
                name = "Пользователь"
            };
            addAccount(ref s);
            refreshListBoxContent(getContainerSize() - 1);
        }

        private void button_add_vip_Click(object sender, EventArgs e)
        {
            textBox_name.Visible = true;
            textBox_type.Visible = true;
            textBox_balance.Visible = true;
            textBox_credit.Visible = true;
            label_credit.Visible = true;
            label1.Visible = true;
            label2.Visible = true;
            label4.Visible = true;
            Aleshko_account s = new Aleshko_account()
            {
                isVIP = true,
                name = "VIP"
            };
            addAccount(ref s);
            refreshListBoxContent(getContainerSize() - 1);
        }

        private void button_del_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (listBox1.Items.Count == 0)
                return;

            textBox_name.Clear();
            textBox_type.Clear();
            textBox_balance.Clear();
            textBox_credit.Clear();

            deleteAccount(index);
            listBox1.Items.Clear();
            refreshListBoxContent();

            
            if (index == 0)
            {
                if (listBox1.Items.Count == 0)
                {
                    textBox_name.Visible = false;
                    textBox_type.Visible = false;
                    textBox_balance.Visible = false;
                    textBox_credit.Visible = false;
                    label_credit.Visible = false;
                    label1.Visible = false;
                    label2.Visible = false;
                    label4.Visible = false;
                    return;
                }
                return;
            }
                

            if (index == listBox1.Items.Count)
            {
                listBox1.SetSelected(index - 1, true);
            }
            else
            {
                listBox1.SetSelected(index, true);
                
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Aleshko_account s = new Aleshko_account();
            getAccount(ref s, listBox1.SelectedIndex);

            textBox_name.Text = s.name;
            textBox_type.Text = s.type;
            textBox_balance.Text = s.money.ToString();

            if (s.isVIP)
            {
                label_credit.Visible = true;
                textBox_credit.Visible = true;
                textBox_credit.Text = s.credit.ToString();
            }
            else
            {
                label_credit.Visible = false;
                textBox_credit.Visible = false;
            }
        }
    }
}
