from src.Calcular.Calcular import *
from src.Calcular.Solver import *
from src.OsTest.OsTest import *

test1 = 0;
test2 = 0;
test3 = 0;
test4 = 1;
test5 = 1;
test6 = 0;
test7 = 0;
test8 = 0;
test9 = 0;
test10 = 0;


if (test1 != 0):
    print("Test Solver class\n")
    solver = Solver()
    solver.demo()
if (test2 != 0):
    print("Test Clacular class")
    lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
    calcular = Calcular()
    print("media = ", calcular.media(lista))
if (test3 != 0):
    testos = TestOs()
    testos.testFile1(51)
if (test4 != 0):
    ospath = TestOs()
    ospath.osPathTest1()
if (test5 != 0):
    ospath = TestOs()
    ospath.globTest1()
