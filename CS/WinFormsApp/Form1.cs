using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
//using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {

            WinRTComponent.Class c1 = new WinRTComponent.Class();
            String textFromComponent = c1.MyProperty.ToString();
            TextBox1.Text = textFromComponent;

            var popup = new Popup(textFromComponent);
            popup.Show(this);
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
