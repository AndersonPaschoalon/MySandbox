#!/usr/bin/python3
import sys
import os

class Sudo(object):
    @staticmethod
    def requires_sudo():
        if os.geteuid() != 0:
            exit("You need to have root privileges to run this script.\n"+
                 "Please try again, this time using 'sudo'. Exiting.")

def requires_sudo():
    if os.geteuid() != 0:
        exit("You need to have root privileges to run this script.\n" +
             "Please try again, this time using 'sudo'. Exiting.")

if __name__ == '__main__':
    Sudo.requires_sudo()
    print("Hello Sudo!")