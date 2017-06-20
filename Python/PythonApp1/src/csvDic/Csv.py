import csv
import re
#re.sub( '\s+', ' ', mystring ).strip()
class CsvDic:
    def load(self, fileName):
        result = {}
        reader = csv.reader(open(fileName))
        comment = re.compile('^#.*')  # ignore commentaties
        for row in reader:
            key = row[0].strip()
            res = comment.match(key)
            if res != None:
                continue
            else:
                result[key] = row[1:]
        return (result)

class CsvList:
    def load(self, fileName):
        result = []
        reader = csv.reader(open(fileName))
        comment = re.compile('^#.*')  # ignore commentaties
        for row in reader:
            key = row[0].strip()
            res = comment.match(key)
            if res != None:
                continue
            else:
                value = row[1]
                error = row[2]
                listTuple = (key, value, error)
                result.append(listTuple)
        return (result)



'''
# test
print('\n#################\n')
Csv = CsvDic()
dic1 = Csv.load('data.csv')
dic2 = Csv.load('Correlation.dat')
dic3 = Csv.load('Hurst Exponent.dat')
dic4 = Csv.load('Mean.dat')
print(dic1)
print(dic2)
print(dic3)
print(dic4)
'''