import time
import multiprocessing


def worker(num, wait):
    """thread worker function"""
    print("Thread {0}, Time: {1}".format(num, time.ctime()) )
    time.sleep(wait)
    print ('{0}~Worker:'.format(' '*num))
    return


def tests_process():
    jobs = []
    wait = 1
    for i in range(5):
        p = multiprocessing.Process(target=worker, args=(i, wait))
        jobs.append(p)
        p.start()
        time.sleep(wait)


if __name__ == "__main__":
    tests_process()