//============================================================================
// Name        : Tutorial_iperf.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;
typedef enum {
	bits, on_time, packets
} enum_transmission_type;

std::string iperf_command();
int iperf_popen();

/**
 Usage: iperf [-s|-c host] [options]
 iperf [-h|--help] [-v|--version]

 Client/Server:
 u		-b, --bandwidth #[KMG | pps]  bandwidth to send at in bits/sec or packets per second
 x		-e, --enhancedreports    use enhanced reporting giving more tcp/udp and traffic information
 u 		-f, --format    [kmKM]   format to report: Kbits, Mbits, KBytes, MBytes
 x		-i, --interval  #        seconds between periodic bandwidth reports
 ?		-l, --len       #[KM]    length of buffer to read or write (default 8 KB)
 x		-m, --print_mss          print TCP maximum segment size (MTU - TCP/IP header)
 x		-o, --output    <filename> output the report or error message to this specified file
 ?		-p, --port      #        server port to listen on/connect to
 u		-u, --udp                use UDP rather than TCP
 ?		-w, --window    #[KM]    TCP window size (socket buffer size)
 u		-z, --realtime           request realtime scheduler
 ?		-B, --bind      <host>   bind to <host>, an interface or multicast address
 x		-C, --compatibility      for use with older versions does not sent extra msgs
 ?		-M, --mss       #        set TCP maximum segment size (MTU - 40 bytes)
 u		-N, --nodelay            set TCP no delay, disabling Nagle's Algorithm
 x		-V, --ipv6_domain        Set the domain to IPv6

 Server specific:
 u		-s, --server             run in server mode
 x		-U, --single_udp         run in single threaded UDP mode
 x		-D, --daemon             run the server as a daemon

 Client specific:
 u		-c, --client    <host>   run in client mode, connecting to <host>
 x		-d, --dualtest           Do a bidirectional test simultaneously
 u		-n, --num       #[KM]    number of bytes to transmit (instead of -t)
 x		-r, --tradeoff           Do a bidirectional test individually
 u		-t, --time      #        time in seconds to transmit for (default 10 secs)
 x		-B, --bind [<ip> | <ip:port>] bind src addr(s) from which to originate traffic
 ?		-F, --fileinput <name>   input the data to be transmitted from a file
 x		-I, --stdin              input the data to be transmitted from stdin
 x		-L, --listenport #       port to receive bidirectional tests back on
 ?		-P, --parallel  #        number of parallel client threads to run
 u		-T, --ttl       #        time-to-live, for multicast (default 1)
 -Z, --linux-congestion <algo>  set TCP congestion control algorithm (Linux only)

 Miscellaneous:
 -x, --reportexclude [CDMSV]   exclude C(connection) D(data) M(multicast) S(settings) V(server) reports
 -y, --reportstyle C      report as a Comma-Separated Values
 -h, --help               print this message and quit
 -v, --version            print version information and quit

 [KM] Indicates options that support a K or M suffix for kilo- or mega-

 The TCP window size option can be set by the environment variable
 TCP_WINDOW_SIZE. Most other options can be set by an environment variable
 IPERF_<long option name>, such as IPERF_BANDWIDTH.

 Source at <http://sourceforge.net/projects/iperf2/>
 Report bugs to <iperf-users@lists.sourceforge.net>

 **/
int main(void) {
	std::thread th1(iperf_popen);
	std::thread th2(iperf_popen);
	std::thread th3(iperf_popen);

	th1.join();
	th2.join();
	th3.join();

	return 0;
}

std::string iperf_command() {
	/// iperf running options. Traffic generation custom options
	enum_transmission_type transmission_type = on_time;
	std::string congestion_algorithm_name = "reno";
	bool real_time = true;
	bool congestion_algorithm = true;
	bool no_delay = true;

	/// Simitar values. Values captured form the compact trace descriptor
	int bw = 3;
	int pps = 3;
	int npackets = 12;
	int onTime = 13;
	int nkbytes = 14;
	int nkbits = 15;
	int ttlVal = 64;
	bool tcp = true;
	bool ipv6 = false;
	std::string server_ip = "10.0.0.2";
	std::string client_ip = "10.0.0.1";
	int tranport_port = 2222;
	std::string format = "k"; // format to report: kbits, mbits, KBytes, MBytes

	/// Iperf config opts. Iperf command options
	std::string opt_bandwidth;
	std::string opt_tranmission;
	if (transmission_type == on_time) {
		opt_tranmission = " --time " + std::to_string(onTime);
		opt_bandwidth = " --bandwidth " + std::to_string(bw) + "k";
	} else if (transmission_type == bits) {
		opt_tranmission = " --time " + std::to_string(onTime);
		opt_bandwidth = " --bandwidth " + std::to_string(bw) + "k";
	} else // transmission_type == packets
	{
		opt_tranmission = " --num " + std::to_string(npackets);
		opt_bandwidth = " --bandwidth " + std::to_string(npackets / onTime)
				+ "pps";
	}
	std::string opt_format = " --format k "; // format to report: Kbits, Mbits, KBytes, MBytes
	std::string opt_transport_protocol = (tcp == true) ? "" : " --udp ";
	std::string opt_transport_port = std::string(" --bind ") + client_ip
			+ std::string(":") + std::to_string(tranport_port);
	std::string opt_real_time = (real_time == true) ? " --realtime " : "";
	std::string opt_nodelay = " --nodelay ";
	std::string opt_congestion_algorithm =
			(congestion_algorithm == true) ?
					std::string(" --linux-congestion ")
							+ congestion_algorithm_name :
					"";
	std::string opt_ipv6 = (ipv6 == true) ? " --ipv6_domain " : "";
	std::string opt_ttl = " --ttl " + std::to_string(ttlVal);
	std::string opt_no_delay = (no_delay == true) ? " --nodelay " : "";

	/// iperf command
	std::string command_client = std::string("iperf -c ") + server_ip + opt_bandwidth
			+ opt_tranmission + opt_format + opt_transport_protocol
			+ opt_transport_port + opt_real_time + opt_nodelay
			+ opt_congestion_algorithm + opt_ipv6 + opt_ttl + opt_no_delay;

	return (command_client);
}



int iperf_popen() {
	// popen args
	FILE *in;
	char buff[512];
	//iperf args

	char command[2048];
	strcpy(command, iperf_command().c_str());

	if (!(in = popen(command, "r"))) {
		return 1;
	}

	while (fgets(buff, sizeof(buff), in) != NULL) {
		mtx.lock();
		std::cout << buff;
		mtx.unlock();
	}

	pclose(in);
	return (0);
}
