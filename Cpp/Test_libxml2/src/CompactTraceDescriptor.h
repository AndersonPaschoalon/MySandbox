/*
 * CompactTraceDescriptor.h
 *
 *  Created on: 15/06/2019
 *      Author: anderson
 */

#ifndef COMPACTTRACEDESCRIPTOR_H_
#define COMPACTTRACEDESCRIPTOR_H_

enum protocol
{
    PROT_NULL,    //!< No valid protocol setted
    // Link layer protocols
    PROT_ETHERNET,    //!< Ethernet protocol
    //Network layer protocols
    PROT_IPV4,    //!< IPv4 network protocol
    PROT_IPV6,    //!< IPv6 network protocol
    PROT_ARP,     //!< ARP protocol
    PROT_ICMP,    //!< ICMP network protocol
    PROT_ICMPV6,  //!< ICMPv6 network protocol
    PROT_OSPF,    //!<
    // Transport layer protocols
    PROT_TCP,     //!< TCP transport protocol
    PROt_UDP,     //!< UDP transport protocol
    PROT_DCCP,    //!< DCCP protocol
    PROT_GRE,     //!< GRE protocol
    PROT_SCTP,    //!< SCTP protocol
    // Application layer protocols
    PROT_HTTP,    //!< HTTP application protocol
    PROT_HTTPS,   //!< HTTPS application protocol
    PROT_SNMP,    //!< SNMP application protocol
    PROT_SMTP,    //!< SMTP application protocol
    PROT_FTP,     //!< FTP application protocol
    PROT_BGP,     //!< BGP protocol
    PROT_DHCP,    //!< DHCP application protocol
    PROT_DNS,     //!< DNS application protocol
    PROT_SSH,     //!< SSH application protocol
    PROT_Telnet,  //!< Telnet application protocol
    PROT_TACACS  //!< TACACS application protocol

};

enum stochastic_process
{
    WEIBULL,
    CAUCHY,
    EXPONENTIAL_ME,
    EXPONENTIAL_LR,
    NORMAL,
    PARETO_LR,
    PARETO_MLH,
    GAMMA,
    CONSTANT
};

typedef struct struct_flow_entry_raw
{
    int a;
} FlowEntryRaw;

typedef struct struct_flow_entry_soft
{
    int a;
} FlowEntrySoft;


class CompactTraceDescriptor
{
    public:
        CompactTraceDescriptor();
        virtual ~CompactTraceDescriptor();
        static FlowEntrySoft flowEntry_Raw2Soft(FlowEntryRaw);
        static FlowEntryRaw flowEntry_Soft2Raw(FlowEntrySoft);
    private:

};

#endif /* COMPACTTRACEDESCRIPTOR_H_ */
