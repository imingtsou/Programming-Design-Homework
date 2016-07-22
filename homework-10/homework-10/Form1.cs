using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;
using System.Collections;
using System.Threading;

namespace homework_10
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        static int[,] a = new int[100, 100];
        static int[,] b = new int[100, 100];
        static int begin_x,begin_y,end_x,end_y;
        static int ans,m,n;
        static Label[,] lbarray = new Label[100, 100];

        static int tot,step;

        static int[] ax1 = new int[100010];
        static int[] ax2 = new int[100010];
        static int[] ay1 = new int[100010];
        static int[] ay2 = new int[100010];
        static int[] cx1 = new int[100010];
        static int[] cx2 = new int[100010];
        static int[] cy1 = new int[100010];
        static int[] cy2 = new int[100010];
        static int[] fin = new int[100010];

        void produce()
        {
            int i, j;
            Random rd = new Random();
            
            for (i = 1;i <= m;i++)
                for (j = 1;j <= n;j++)
                {
                    a[i, j] = rd.Next(1, 201) - 100;
                    lbarray[i, j] = new Label();
                    lbarray[i, j].Text = a[i, j].ToString();
                    lbarray[i, j].Size = new Size(55, 21);
                    lbarray[i, j].Location = new Point(20 + 55 * (j - 1), 130 + 21 * (i - 1));
                    lbarray[i, j].Font = new Font("微软雅黑", 12);
                    lbarray[i, j].TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
                    lbarray[i, j].BackColor = Color.White;
                    this.Controls.Add(lbarray[i, j]);
                }
        }

        void read(string path)
        {
            StreamReader sr = File.OpenText(path);
            string s = sr.ReadLine();
            string[] filein = s.Split(' ');
            m = Convert.ToInt16(filein[0]);
            n = Convert.ToInt16(filein[1]);
            int i, j, k, flag, p;
            char[] str_char;
            for (i = 1; i <= m; i++)
            {
                s = sr.ReadLine();
                string[] sArray = s.Split(' ');
                for (j = 0; j < n; j++)
                {
                    flag = 0;
                    str_char = sArray[j].ToCharArray();
                    for (k = 0; k < str_char.Length; k++)
                    {
                        if (str_char[k] != '-')
                        {
                            p = Convert.ToInt32(str_char[k]) - 48;
                            a[i, j + 1] = a[i, j + 1] * 10 + p;
                        }
                        else flag = 1;
                    }
                    if (flag == 1) a[i, j + 1] = a[i, j + 1] * (-1);
                }
            }
            for (i = 1; i <= m; i++)
                for (j = 1; j <= n; j++)
                {
                    lbarray[i, j] = new Label();
                    lbarray[i, j].Text = a[i, j].ToString();
                    lbarray[i, j].Size = new Size(55, 21);
                    lbarray[i, j].Location = new Point(20 + 55 * (j - 1), 130 + 21 * (i - 1));
                    lbarray[i, j].Font = new Font("微软雅黑", 12);
                    lbarray[i, j].TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
                    lbarray[i, j].BackColor = Color.White;
                    this.Controls.Add(lbarray[i, j]);
                }
        }

        void paint(int x1,int y1,int x2,int y2)
        {
            int i, j;
            for (i = x1; i <= x2; i++)
                for (j = y1; j <= y2; j++)
                    lbarray[i, j].BackColor = Color.Yellow;
        }

        void repaint(int x1,int y1,int x2,int y2)
        {
            int i, j;
            for (i = x1; i <= x2; i++)
                for (j = y1; j <= y2; j++)
                    lbarray[i, j].BackColor = Color.White;
        }

        void show(int x1, int y1, int x2, int y2)
        {
            int i, j;
            for (i = x1; i <= x2; i++)
                for (j = y1; j <= y2; j++)
                    lbarray[i, j].ForeColor = Color.Red;
        }

        void reshow(int x1, int y1, int x2, int y2)
        {
            int i, j;
            for (i = x1; i <= x2; i++)
                for (j = y1; j <= y2; j++)
                    lbarray[i, j].ForeColor = Color.Black;
        }

        void precalc()
        {
            ans = a[1, 1];
            begin_x = 1; begin_y = 1; end_x = 1; end_y = 1;
            int i, j, temp;
            for (i = 1; i <= m; i++)
                for (j = 1; j <= n; j++)
                    if (a[i,j] > ans)
                    {
                        ans = a[i,j];
                        begin_x = i; begin_y = j;
                        end_x = i; end_y = j;
                    }
            paint(begin_x, begin_y, end_x, end_y);
            show(begin_x, begin_y, end_x, end_y);
            label4.Text = ans.ToString();

            fin[0] = ans;
            cx1[0] = begin_x;
            cy1[0] = begin_y;
            cx2[0] = end_x;
            cy2[0] = end_y;
            ax1[0] = begin_x;
            ay1[0] = begin_y;
            ax2[0] = end_x;
            ay2[0] = end_y;

            for (j = 1; j <= n; j++)
            {
                temp = 0;
                for (i = 1; i <= m; i++)
                {
                    temp = temp + a[i, j];
                    b[i, j] = temp;
                }
            }
        }

        void calc()
        {
            int i,j,k,temp, start;
            
            for (i = 1; i <= m; i++)
                for (j = i; j <= m; j++)
                {
                    temp = 0; start = 1;
                    for (k = 1; k <= n; k++)
                    {
                        cx1[tot] = i;
                        cy1[tot] = start;
                        cx2[tot] = j;
                        cy2[tot] = k;
                        ax1[tot] = ax1[tot - 1];
                        ay1[tot] = ay1[tot - 1];
                        ax2[tot] = ax2[tot - 1];
                        ay2[tot] = ay2[tot - 1];

                        temp = temp + b[j,k] - b[i - 1,k];
                        if (temp > ans)
                        {
                            ans = temp;
                            ax1[tot] = i;
                            ay1[tot] = start;
                            ax2[tot] = j;
                            ay2[tot] = k;
                        }
                        else if (temp < 0)
                        {
                            temp = 0;
                            start = k + 1;
                        }
                        fin[tot++] = ans;
                    }
                }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            m = Convert.ToInt16(textBox1.Text);
            n = Convert.ToInt16(textBox2.Text);
            produce();
            precalc();
            tot = 1;
            calc();
            step = 1;           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string path = textBox3.Text;
            read(path);
            precalc();
            tot = 1;
            calc();
            step = 1;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (step < tot)
            {
                repaint(cx1[step - 1], cy1[step - 1], cx2[step - 1], cy2[step - 1]);
                paint(cx1[step], cy1[step], cx2[step], cy2[step]);
                reshow(ax1[step - 1], ay1[step - 1], ax2[step - 1], ay2[step - 1]);
                show(ax1[step], ay1[step], ax2[step], ay2[step]);
                label4.Text = fin[step].ToString();
                step++;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (step > 1)
            {
                repaint(cx1[step - 1], cy1[step - 1], cx2[step - 1], cy2[step - 1]);
                paint(cx1[step - 2], cy1[step - 2], cx2[step - 2], cy2[step - 2]);
                reshow(ax1[step - 1], ay1[step - 1], ax2[step - 1], ay2[step - 1]);
                show(ax1[step - 2], ay1[step - 2], ax2[step - 2], ay2[step - 2]);
                label4.Text = fin[step].ToString();
                step--;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            while (step < tot)
            {
                repaint(cx1[step - 1], cy1[step - 1], cx2[step - 1], cy2[step - 1]);
                paint(cx1[step], cy1[step], cx2[step], cy2[step]);
                reshow(ax1[step - 1], ay1[step - 1], ax2[step - 1], ay2[step - 1]);
                show(ax1[step], ay1[step], ax2[step], ay2[step]);
                label4.Text = fin[step].ToString();
                step++;
                Application.DoEvents();
                Thread.Sleep(1000);
            }
        }

    }
}
