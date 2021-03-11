using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tutorial_WpfDataContext
{
    public class AnotherClass : INotifyPropertyChanged
    {
        private string anotherfield;
        private Employee emp;
        public string AnotherField
        {
            get { return anotherfield; }
            set
            {
                anotherfield = value;
                OnPropertyChanged("AnotherField");
            }
        }
        public Employee EmployeeNameTest
        {
            get { return emp; }
            set
            {
                emp = value;
                OnPropertyChanged("EmployeeNameTest");
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        //// Create the OnPropertyChanged method to raise the event
        protected void OnPropertyChanged(string name)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(name));
            }
        }
        public override string ToString()
        {
            return string.Format("My ToString implementation of AnotherClass");
        }
    }
}
