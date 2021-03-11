using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.IO;
using System.ComponentModel;

namespace Tutorial_WpfTask2
{

    public class TestProcessReport : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string name)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }



        public bool finalized { 
            get
            {
                return this._finalized;
            }
            set
            { 
            } 
        }

        public IEnumerable<string> files { get; set; }

        public string status { get; set; }

        private IEnumerable<string> _files;
        private string _status;
        private bool _finalized;




    }

    public class TestProcess2
    {
        private CancellationTokenSource cancellationTokenSource;
        private TestProcessReport state;


        public TestProcess2()
        {
            this.state = new TestProcessReport();
        }

        public void cancelProcess()
        {
            if (cancellationTokenSource != null)
            {
                cancellationTokenSource.Cancel();
            }
        }


        public Task<IEnumerable<string>> AsycnLerArquivos()
        {
            this.cancellationTokenSource = new CancellationTokenSource();
            return Task.Run(() => {
                return this.LerArquivos(cancellationTokenSource.Token);
            });

        }


        public async Task<int> taskLerArquivos(CancellationTokenSource tokenSource)
        {
            CancellationToken ct = tokenSource.Token;
            var ret = await Task<int>.Factory.StartNew(() =>
            {

                return 1;
            }, ct);

            return 1;


        public IEnumerable<string> LerArquivos(CancellationToken cancellationToken)
        {
            // CancellationToken ct = tokenSource.Token;
            CancellationToken ct = tokenSource.Token;

            bool isCanceled = false;
            string[] arquivos = Directory.GetFiles(@".");
            //var arquivos = from arquivo Directory.GetFiles(@".") select arquivo;
            for (int i = 0; i < 10; i++)
            {
                if (cancellationToken.IsCancellationRequested)
                {
                    isCanceled = true;
                    break;
                }
                Thread.Sleep(1000);
            }
            if (isCanceled)
            {
                Console.WriteLine("Operation was cancelled!");
                IEnumerable<string> emptyList = Enumerable.Empty<string>();
                emptyList = emptyList.Append("Cancelled!");
                return emptyList;
            }
            Console.WriteLine("Operation NOT cancelled!");
            return arquivos;
        }
 
    }
}
