import sys
import os.path
import glob

_author_ = 'apaschoalon'

class TestOs:
    def testFile1(self, n_int):
        temp = open("temp.txt", 'w')
        for i in range(int(n_int)):
            temp.write('%03d\n' % i)
        temp.close()
        temp = open("temp.txt", 'r')
        for x in temp:
            sys.stdout.write(x)
        temp.close()
    def osPathTest1(self):
        print(os.path.basename("./temp.txt"))
        print(os.path.dirname("./temp.txt"))
        print(os.path.exists("./temp.txt"))
        print(os.path.getsize("./temp.txt"))
    def globTest1(self):
        print(glob.glob("*"))
