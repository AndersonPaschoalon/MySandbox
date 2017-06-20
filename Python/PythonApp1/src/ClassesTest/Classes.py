


_author_ = 'apaschoalon'

#__new__(): construtor
#__init__(): inicializador

class Cell(object):
    """
    Classe para celulas de planilha
    """
    def __init__(self, formula='""', format='%s'):
        self.formula = formula
        self.format = format
    def __repr__(self):
        return (self.format % eval(self.formula))

print(Cell('4*5'))
print(Cell('7+2*2'))
print(Cell('abs(-2/3)+5','%3.3f'))
