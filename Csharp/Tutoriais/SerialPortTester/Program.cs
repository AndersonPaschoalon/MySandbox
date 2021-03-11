using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace SerialPortTester
{
    class Program
    {
        public static void letSerialPortOpen(String portName)
        {
            SerialPort comport = new SerialPort(portName, 9600, Parity.None, 8, StopBits.One);
            if (comport.IsOpen)
            {
                Console.WriteLine("Reseting serial port " + portName + "...");
                comport.Close();
            }

            Console.WriteLine("Open serial port...");
            comport.Open();


            Console.WriteLine("Let serial port open!");
            comport.WriteLine("Let serial port open!");
 
        }

        public static void forceCloseSerialPort(String portName)
        {
            SerialPort comport = new SerialPort(portName, 9600, Parity.None, 8, StopBits.One);
            if (comport.IsOpen)
            {
                Console.WriteLine("Reseting serial port " + portName + "...");
                comport.Close();
            }

            Console.WriteLine("Open serial port...");
            comport.Open();

            Console.WriteLine("Sending data to real port");
            comport.WriteLine("Sending data to real port...");

            Console.WriteLine("Close serial port...");
            comport.Close();

        }

        static void Main(string[] args)
        {
            int opt = 2;

            if (opt == 1)
            {
                Program.letSerialPortOpen("COM1");
            }
            else if (opt == 2)
            {
                Program.forceCloseSerialPort("COM1");
            }

            Console.ReadKey();
        }
    }
}
