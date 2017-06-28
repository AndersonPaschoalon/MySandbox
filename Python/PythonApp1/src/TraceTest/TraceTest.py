import time


class Trace:
    def __init__(self, traceName="trace-name", commentaries="no-comment"):
        self.captureDate = time.strftime("%H:%M:%S") + ", " + time.strftime("%d/%m/%Y")
        self.traceName = traceName
        self.commentaries = commentaries
        self.flowList = []
    def append(self, flow):
        self.flowList.append(flow)


class Flow:
    def __init__(self, flowId=0, protocolLink="", protocolNet=0, protocolTransport=0, macSrc="", macDst="",
                 netSrc="" , netDst="", portSrc=0, portDst=0):
        self.flowId = flowId
        self.protocolLink = protocolLink
        self.protocolNet = protocolNet
        self.protocolTransport = protocolTransport
        self.macSrc = macSrc
        self.macDst = macDst
        self.netSrc = netSrc
        self.netDst = netDst
        self.portSrc = portSrc
        self.portDst = portDst
        self.packetList = []
    def append(self, pkt):
        self.packetList.append(pkt)

class Packet:
    def __init__(self,seq=0, arrivalTime=0, pktSize=0, ttl=0, winSize=0):
        self.seq = seq
        self.arrivalTime = arrivalTime
        self.pktSize = pktSize
        self.ttl = ttl
        self.winSize = winSize

trace = Trace("trace1", "comment1")
#flow = Flow(flowId=0, protocolLink="ether", protocolNet=2054, locals())

#(numb:1 time:0.0 length:60 flowID:0 prot_link:stp mac_src:00:1e:c1:8a:fe:d4 mac_dst:01:80:c2:00:00:00 prot_network:0 ip_src: ip_dst: ttl:0 transport:0 port_src:0 port_dst:0)
#(numb:2 time:0.23060011863708496 length:60 flowID:1 prot_link:ether mac_src:74:d4:35:bb:eb:25 mac_dst:ff:ff:ff:ff:ff:ff prot_network:2054 ip_src: ip_dst: ttl:0 transport:0 port_src:0 port_dst:0)
#(numb:3 time:0.2775294780731201 length:104 flowID:2 prot_link:ether mac_src:70:62:b8:9b:3e:d1 mac_dst:00:15:c5:36:23:44 prot_network:2048 ip_src:10.1.1.48 ip_dst:158.85.224.172 ttl:64 transport:6 port_src:44636 port_dst:443)
#(numb:4 time:0.4337475299835205 length:111 flowID:3 prot_link:ether mac_src:00:15:c5:36:23:44 mac_dst:70:62:b8:9b:3e:d1 prot_network:2048 ip_src:158.85.224.172 ip_dst:10.1.1.48 ttl:49 transport:6 port_src:443 port_dst:44636)
#(numb:5 time:0.43377089500427246 length:66 flowID:2 prot_link:ether mac_src:70:62:b8:9b:3e:d1 mac_dst:00:15:c5:36:23:44 prot_network:2048 ip_src:10.1.1.48 ip_dst:158.85.224.172 ttl:64 transport:6 port_src:44636 port_dst:443)
#(numb:6 time:1.2305233478546143 length:60 flowID:1 prot_link:ether mac_src:74:d4:35:bb:eb:25 mac_dst:ff:ff:ff:ff:ff:ff prot_network:2054 ip_src: ip_dst: ttl:0 transport:0 port_src:0 port_dst:0)
#(numb:7 time:1.9171864986419678 length:66 flowID:4 prot_link:ether mac_src:70:62:b8:9b:3e:d1 mac_dst:00:15:c5:36:23:44 prot_network:2048 ip_src:10.1.1.48 ip_dst:108.177.12.100 ttl:64 transport:6 port_src:45646 port_dst:443)
#(numb:8 time:1.999239444732666 length:60 flowID:0 prot_link:stp mac_src:00:1e:c1:8a:fe:d4 mac_dst:01:80:c2:00:00:00 prot_network:0 ip_src: ip_dst: ttl:0 transport:0 port_src:0 port_dst:0)
#(numb:9 time:2.0403666496276855 length:66 flowID:5 prot_link:ether mac_src:00:15:c5:36:23:44 mac_dst:70:62:b8:9b:3e:d1 prot_network:2048 ip_src:108.177.12.100 ip_dst:10.1.1.48 ttl:46 transport:6 port_src:443 port_dst:45646)
#(numb:10 time:3.897167682647705 length:54 flowID:6 prot_link:ether mac_src:70:62:b8:9b:3e:d1 mac_dst:00:15:c5:36:23:44 prot_network:2048 ip_src:10.1.1.48 ip_dst:104.31.3.183 ttl:64 transport:6 port_src:47194 port_dst:443)