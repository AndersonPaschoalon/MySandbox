using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Forms_ObjectToDataGridView
{
    public partial class Form1 : Form
    {
        private DataGridView dataGridView1 = new DataGridView();
        private BindingSource bindingSource1 = new BindingSource();
        private string selectedRow = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //loadComboBoxTest1();
            loadComboBoxTest2();
        }

        # region loadComboBoxTest1
        private void loadComboBoxTest1()
        {
            // Populate the data source.
            bindingSource1.Add(new Knight(Title.King, "Uther", true));
            bindingSource1.Add(new Knight(Title.King, "Arthur", true));
            bindingSource1.Add(new Knight(Title.Sir, "Mordred", false));
            bindingSource1.Add(new Knight(Title.Sir, "Gawain", true));
            bindingSource1.Add(new Knight(Title.Sir, "Galahad", true));

            // Initialize the DataGridView.
            dataGridView1.AutoGenerateColumns = false;
            dataGridView1.AutoSize = true;
            dataGridView1.DataSource = bindingSource1;

            dataGridView1.Columns.Add(CreateComboBoxWithEnums());

            // Initialize and add a text box column.
            DataGridViewColumn column = new DataGridViewTextBoxColumn();
            column.DataPropertyName = "Name";
            column.Name = "Knight";
            dataGridView1.Columns.Add(column);

            // Initialize and add a check box column.
            column = new DataGridViewCheckBoxColumn();
            column.DataPropertyName = "GoodGuy";
            column.Name = "Good";
            dataGridView1.Columns.Add(column);

            // Initialize the form.
            this.Controls.Add(dataGridView1);
            this.AutoSize = true;
            this.Text = "DataGridView object binding demo";
        }
        DataGridViewComboBoxColumn CreateComboBoxWithEnums()
        {
            DataGridViewComboBoxColumn combo = new DataGridViewComboBoxColumn();
            combo.DataSource = Enum.GetValues(typeof(Title));
            combo.DataPropertyName = "Title";
            combo.Name = "Title";
            return combo;
        }

        #endregion loadComboBoxTest1

        private void dataGridView1_CellMouseClick(object sender, DataGridViewCellEventArgs e)
        {
            var a = dataGridView1.Rows[0].Cells[0].Value;
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                dataGridView1.Rows[i].Cells[0].Value = false;
            }
            dataGridView1.RefreshEdit();

            if (e.RowIndex >= 0)
            {
                dataGridView1.Rows[e.RowIndex].Cells[0].Value = true;
                dataGridView1.RefreshEdit();
                DataGridViewRow row = dataGridView1.Rows[e.RowIndex];
                
                textBox1.Text = row.Cells[0].Value.ToString();
                textBox2.Text = row.Cells[1].Value.ToString();
                textBox3.Text = "row.Cells[2].Value.ToString()";

            }
        }

        private void dataGridView1_DataBindingComplete(object sender, DataGridViewBindingCompleteEventArgs e)
        {

        }

        private void findSelectedRow(object sender, System.EventArgs e)
        {
            this.selectedRow = dataGridView1.SelectedRows[0].Index.ToString() + ":" +
                dataGridView1.FirstDisplayedScrollingRowIndex.ToString();
        }



        private void loadComboBoxTest2()
        {
            
            List<Profile> lp = new List<Profile>();
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile01"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile02"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile03"));
            /*
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile04"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile05"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile06"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile07"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile08"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile09"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile10"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile11"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile12"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile13"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile14"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile15"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile16"));
            lp.Add(new Profile(ProfType.DESACTIVATED, Color.FromName("SlateBlue"), "Profile17"));
            */
            bindingSource1.DataSource = lp;
            // Initialize the DataGridView.
            dataGridView1.AutoGenerateColumns = false;
            dataGridView1.AllowUserToResizeRows = false;
            dataGridView1.AllowUserToResizeColumns = false;
            dataGridView1.AllowUserToResizeColumns = false;
            dataGridView1.AllowUserToAddRows = false;
            dataGridView1.ColumnHeadersVisible = false;
            dataGridView1.AutoSize = true;
            dataGridView1.DataSource = bindingSource1;
            dataGridView1.RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            dataGridView1.RowHeadersVisible = false;
            dataGridView1.CellContentClick += new DataGridViewCellEventHandler(dataGridView1_CellMouseClick);
            dataGridView1.DataBindingComplete += new DataGridViewBindingCompleteEventHandler(dataGridView1_DataBindingComplete);
            dataGridView1.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCellsExceptHeaders;
            //dataGridView1.RowHeaderMouseClick += new DataGridViewCellMouseEventHandler(findSelectedRow);

            // Initialize and add a check box column.
            DataGridViewColumn column = new DataGridViewTextBoxColumn();
            column = new DataGridViewCheckBoxColumn();
            column.DataPropertyName = "isChecked";
            column.Name = "isProfileChecked";
            dataGridView1.Columns.Add(column);

            // Initialize and add a text box column.
            column = new DataGridViewTextBoxColumn();
            column = new DataGridViewTextBoxColumn();
            column.DataPropertyName = "name";
            column.Name = "NAME";
            column.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            column.ReadOnly = true;
            dataGridView1.Columns.Add(column);


            // Initialize the DataGridView.
            dataGridView1.AutoGenerateColumns = false;
            dataGridView1.AutoSize = true;

            this.panelA.Controls.Add(dataGridView1);
            //this.panelB.Controls.Add(dataGridView1);
            //this.Controls.Add(dataGridView1);
            this.AutoSize = true;

        }


        #region "business object"
        private class Knight
        {
            private string hisName;
            private bool good;
            private Title hisTitle;

            public Knight(Title title, string name, bool good)
            {
                hisTitle = title;
                hisName = name;
                this.good = good;
            }

            public Knight()
            {
                hisTitle = Title.Sir;
                hisName = "<enter name>";
                good = true;
            }

            public string Name
            {
                get
                {
                    return hisName;
                }

                set
                {
                    hisName = value;
                }
            }

            public bool GoodGuy
            {
                get
                {
                    return good;
                }
                set
                {
                    good = value;
                }
            }

            public Title Title
            {
                get
                {
                    return hisTitle;
                }
                set
                {
                    hisTitle = value;
                }
            }
        }

        private enum ProfType
        {
            INACTIVE,
            ACTIVE,
            DESACTIVATED
        }

        private class Profile
        {
            public Profile(ProfType _state, Color _color, string _name)
            {
                this.isChecked = false;
                this.state = _state;
                this.color = _color;
                this.name = _name;
            }

            public bool isChecked { get; set; }
            public ProfType state;
            public Color color { get; set; }
            public string name { get; set; }

           
        }
        #endregion

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(this.selectedRow, "VALUE");
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
