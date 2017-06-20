import logging

#log configuration
#logging.basicConfig(filename='example.log',level=logging.DEBUG)
logging.basicConfig(format='[%(levelname)s] (%(threadName)-10s) %(message)s',level=logging.DEBUG)

a = 10
b = 3.14
logging.debug('This message should go to the log file . Vars: %s, %s, %s, %d', str(a), str(b), 'banana', 5)
logging.info('info')
logging.warning('warning')
logging.error('error')
logging.critical('critical')

