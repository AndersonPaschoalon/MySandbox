import xml.etree.ElementTree as ET

class XmlFirst:
    def __init__(self, xmlfile):
        self.tree = ET.ElementTree(file=xmlfile)
        self.root = self.tree.getroot()

    def getText(self, xpath):
        return self.root.find(xpath).text

    def getAttribute(self, xpath, atrib):
        return self.root.find(xpath).attrib.get(atrib)

class XmlFirstStatic:
    @staticmethod
    def getText(xmlfile, xpath):
        tree = ET.ElementTree(file=xmlfile)
        root = tree.getroot()
        return root.find(xpath).text

    @staticmethod
    def getAttribute( xmlfile, xpath, atrib):
        tree = ET.ElementTree(file=xmlfile)
        root = tree.getroot()
        return root.find(xpath).attrib.get(atrib)



#xmlfirst = XmlFirst("sample.xml")
#print("> " + xmlfirst.getText("subdoc/branch"))
#print("> " + xmlfirst.getAttribute("subdoc/branch", "name"))

simitar_validation = XmlFirst("simitar-validation.xml")
print("> pcaps_dir:" + simitar_validation.getText("pcaps_dir"))
print("> plots_dir:" + simitar_validation.getText("plots_dir"))
print("> pcap_file_1:" + simitar_validation.getText("pcap_file_1"))
print("> pcap_file_1:" + simitar_validation.getText("pcap_file_1"))
print("> pcap_file_2_prefix:" + simitar_validation.getText("pcap_file_2_prefix"))
print("> pcap_name_2_prefix:" + simitar_validation.getText("pcap_name_2_prefix"))
print("> n_runs:" + simitar_validation.getText("n_runs"))
print("> analysis_name:" + simitar_validation.getText("analysis_name"))
print("> pcap1_type:" + simitar_validation.getText("pcap1_type"))
print("> pcap2_type:" + simitar_validation.getText("pcap2_type"))
print("> comments:" + simitar_validation.getText("comments"))


print("~ " + XmlFirstStatic.getText("simitar-validation.xml", "pcaps_dir"))




