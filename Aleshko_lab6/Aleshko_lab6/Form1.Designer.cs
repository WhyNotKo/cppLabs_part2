namespace Aleshko_lab6
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label_credit = new System.Windows.Forms.Label();
            this.textBox_name = new System.Windows.Forms.TextBox();
            this.textBox_type = new System.Windows.Forms.TextBox();
            this.textBox_balance = new System.Windows.Forms.TextBox();
            this.textBox_credit = new System.Windows.Forms.TextBox();
            this.buttonchange = new System.Windows.Forms.Button();
            this.button_load = new System.Windows.Forms.Button();
            this.button_save = new System.Windows.Forms.Button();
            this.button_add_main = new System.Windows.Forms.Button();
            this.button_add_vip = new System.Windows.Forms.Button();
            this.button_del = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(19, 27);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(246, 433);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(320, 58);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "ФИО:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(320, 90);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Тип счёта:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(320, 125);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(47, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Баланс:";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // label_credit
            // 
            this.label_credit.AutoSize = true;
            this.label_credit.Location = new System.Drawing.Point(320, 154);
            this.label_credit.Name = "label_credit";
            this.label_credit.Size = new System.Drawing.Size(100, 13);
            this.label_credit.TabIndex = 4;
            this.label_credit.Text = "Кредитный лимит:";
            this.label_credit.Click += new System.EventHandler(this.label3_Click);
            // 
            // textBox_name
            // 
            this.textBox_name.Location = new System.Drawing.Point(384, 55);
            this.textBox_name.Name = "textBox_name";
            this.textBox_name.Size = new System.Drawing.Size(224, 20);
            this.textBox_name.TabIndex = 5;
            // 
            // textBox_type
            // 
            this.textBox_type.Location = new System.Drawing.Point(384, 87);
            this.textBox_type.Name = "textBox_type";
            this.textBox_type.Size = new System.Drawing.Size(224, 20);
            this.textBox_type.TabIndex = 6;
            // 
            // textBox_balance
            // 
            this.textBox_balance.Location = new System.Drawing.Point(384, 122);
            this.textBox_balance.Name = "textBox_balance";
            this.textBox_balance.Size = new System.Drawing.Size(224, 20);
            this.textBox_balance.TabIndex = 7;
            // 
            // textBox_credit
            // 
            this.textBox_credit.Location = new System.Drawing.Point(426, 151);
            this.textBox_credit.Name = "textBox_credit";
            this.textBox_credit.Size = new System.Drawing.Size(182, 20);
            this.textBox_credit.TabIndex = 8;
            // 
            // buttonchange
            // 
            this.buttonchange.Location = new System.Drawing.Point(318, 236);
            this.buttonchange.Name = "buttonchange";
            this.buttonchange.Size = new System.Drawing.Size(289, 26);
            this.buttonchange.TabIndex = 9;
            this.buttonchange.Text = "Сохранить изменения";
            this.buttonchange.UseVisualStyleBackColor = true;
            this.buttonchange.Click += new System.EventHandler(this.buttonchange_Click);
            // 
            // button_load
            // 
            this.button_load.Location = new System.Drawing.Point(318, 268);
            this.button_load.Name = "button_load";
            this.button_load.Size = new System.Drawing.Size(289, 26);
            this.button_load.TabIndex = 10;
            this.button_load.Text = "Загрузить";
            this.button_load.UseVisualStyleBackColor = true;
            this.button_load.Click += new System.EventHandler(this.button_load_Click);
            // 
            // button_save
            // 
            this.button_save.Location = new System.Drawing.Point(318, 300);
            this.button_save.Name = "button_save";
            this.button_save.Size = new System.Drawing.Size(289, 26);
            this.button_save.TabIndex = 11;
            this.button_save.Text = "Сохранить";
            this.button_save.UseVisualStyleBackColor = true;
            this.button_save.Click += new System.EventHandler(this.button_save_Click);
            // 
            // button_add_main
            // 
            this.button_add_main.Location = new System.Drawing.Point(318, 332);
            this.button_add_main.Name = "button_add_main";
            this.button_add_main.Size = new System.Drawing.Size(289, 26);
            this.button_add_main.TabIndex = 12;
            this.button_add_main.Text = "Добавить аккаунт";
            this.button_add_main.UseVisualStyleBackColor = true;
            this.button_add_main.Click += new System.EventHandler(this.button_add_main_Click);
            // 
            // button_add_vip
            // 
            this.button_add_vip.Location = new System.Drawing.Point(318, 364);
            this.button_add_vip.Name = "button_add_vip";
            this.button_add_vip.Size = new System.Drawing.Size(289, 26);
            this.button_add_vip.TabIndex = 13;
            this.button_add_vip.Text = "Добаввить ВИПа";
            this.button_add_vip.UseVisualStyleBackColor = true;
            this.button_add_vip.Click += new System.EventHandler(this.button_add_vip_Click);
            // 
            // button_del
            // 
            this.button_del.Location = new System.Drawing.Point(318, 396);
            this.button_del.Name = "button_del";
            this.button_del.Size = new System.Drawing.Size(289, 26);
            this.button_del.TabIndex = 14;
            this.button_del.Text = "Удалить";
            this.button_del.UseVisualStyleBackColor = true;
            this.button_del.Click += new System.EventHandler(this.button_del_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(635, 518);
            this.Controls.Add(this.button_del);
            this.Controls.Add(this.button_add_vip);
            this.Controls.Add(this.button_add_main);
            this.Controls.Add(this.button_save);
            this.Controls.Add(this.button_load);
            this.Controls.Add(this.buttonchange);
            this.Controls.Add(this.textBox_credit);
            this.Controls.Add(this.textBox_balance);
            this.Controls.Add(this.textBox_type);
            this.Controls.Add(this.textBox_name);
            this.Controls.Add(this.label_credit);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Лучший банк в мире";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label_credit;
        private System.Windows.Forms.TextBox textBox_name;
        private System.Windows.Forms.TextBox textBox_type;
        private System.Windows.Forms.TextBox textBox_balance;
        private System.Windows.Forms.TextBox textBox_credit;
        private System.Windows.Forms.Button buttonchange;
        private System.Windows.Forms.Button button_load;
        private System.Windows.Forms.Button button_save;
        private System.Windows.Forms.Button button_add_main;
        private System.Windows.Forms.Button button_add_vip;
        private System.Windows.Forms.Button button_del;

        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
    }
}

