import threading
import time
import logging

logging.basicConfig(level=logging.DEBUG, format='[%(levelname)s] (%(threadName)-10s) %(message)s', )

opt = 4


def work5seconds():  # 5
    print(threading.currentThread().getName(), '\tStarting')
    time.sleep(5)
    print(threading.currentThread().getName(), '\tExiting')


def work2seconds():  # 2
    print(threading.currentThread().getName(), '\tStarting')
    time.sleep(2)
    print(threading.currentThread().getName(), '\tExiting')


def work5secondsLog():  # 5
    logging.debug("Starting")
    time.sleep(5)
    logging.debug("Existing")


def work2secondsLog():  # 2
    logging.debug("Starting")
    time.sleep(2)
    logging.debug("Existing")


class Worker:
    def simpleWork(self):  # 0
        print('simple work')
        return

    def workNtimes(self, ntimes):  # 1
        print("worked ", ntimes, " times!")


workesArray = []

for i in range(5):
    # create thread
    if (opt == 0):
        t = threading.Thread(target=Worker().simpleWork())
    elif (opt == 1):
        t = threading.Thread(target=Worker().workNtimes, args=(i,))
    elif (opt == 2):
        t = threading.Thread(target=Worker().simpleWork())
    elif (opt == 3):
        break;
    elif (opt == 4):
        break;
    elif (opt == 5):
        t = threading.Thread(target=Worker().simpleWork())
    else:
        print("wrong option")

if (opt == 3):
    t1 = threading.Thread(name="work-2s", target=work2seconds)
    t2 = threading.Thread(name="work-5s", target=work5seconds)
    t3 = threading.Thread(target=work2seconds)
    t1.start()
    t2.start()
    t3.start()

elif (opt == 4):
    xdd = 1
    ydd = 3
    zdd = 0
    t1 = threading.Thread(name="work-2s", target=work2secondsLog)
    t2 = threading.Thread(name="work-5s", target=work5secondsLog)
    zdd = ydd + xdd
    t3 = threading.Thread(target=work2secondsLog)
    t1.start()
    t2.start()
    t3.start()

else:
    # Append and start thread
    workesArray.append(t)
    t.start()
