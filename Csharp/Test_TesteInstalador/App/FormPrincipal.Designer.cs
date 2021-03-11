namespace App
{
    partial class FormPrincipal
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.reportViewerButton = new System.Windows.Forms.Button();
            this.crystalReportsButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // reportViewerButton
            // 
            this.reportViewerButton.Location = new System.Drawing.Point(12, 12);
            this.reportViewerButton.Name = "reportViewerButton";
            this.reportViewerButton.Size = new System.Drawing.Size(127, 23);
            this.reportViewerButton.TabIndex = 0;
            this.reportViewerButton.Text = "Report Viewer";
            this.reportViewerButton.UseVisualStyleBackColor = true;
            this.reportViewerButton.Click += new System.EventHandler(this.reportViewerButton_Click);
            // 
            // crystalReportsButton
            // 
            this.crystalReportsButton.Location = new System.Drawing.Point(12, 41);
            this.crystalReportsButton.Name = "crystalReportsButton";
            this.crystalReportsButton.Size = new System.Drawing.Size(127, 23);
            this.crystalReportsButton.TabIndex = 0;
            this.crystalReportsButton.Text = "Crystal Reports";
            this.crystalReportsButton.UseVisualStyleBackColor = true;
            this.crystalReportsButton.Click += new System.EventHandler(this.crystalReportsButton_Click);
            // 
            // FormPrincipal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(147, 86);
            this.Controls.Add(this.crystalReportsButton);
            this.Controls.Add(this.reportViewerButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormPrincipal";
            this.Text = "Exemplo";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button reportViewerButton;
        private System.Windows.Forms.Button crystalReportsButton;
    }
}

