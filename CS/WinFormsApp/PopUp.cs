using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp
{
    public partial class Popup : Form
    {
        public Popup(String text)
        {
            InitializeComponent();
            RichTextBox1.Text = text;

        }

        private void RichTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Popup_Load(object sender, EventArgs e)
        {

        }
    }
}
