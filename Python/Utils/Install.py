#!/usr/bin/python3
import sys
import os
from imp import find_module
import apt

class Install(object):
    _DISABLE_INSTALL = False

    @staticmethod
    def DISABLE_INSTALL():
        return Install._DISABLE_INSTALL

    # Print a string with the collor given in the first argument.
    # print_color("red", "APPLE")
    # print_color("green", "grass", end="\n")
    @staticmethod
    def __print_color(color, data, end='\n'):
        color_def = {
            # Reset
            "reset": "\033[0m",  # Text Reset
            # Regular Colors
            "black": "\033[0;30m",  # Black
            "red": "\033[0;31m",  # Red
            "green": "\033[0;32m",  # Green
            "yellow": "\033[0;33m",  # Yellow
            "blue": "\033[0;34m",  # Blue
            "purple": "\033[0;35m",  # Purple
            "cyan": "\033[0;36m",  # Cyan
            "white": "\033[0;37m"  # White
        }
        color_code = color_def.get("reset") if color_def.get(color) == "" else color_def.get(color)
        print(color_code + data + color_def.get("reset"), end=end)

    # Install a list of Python Packages
    @staticmethod
    def pip_install(lib_list):
        Install.__print_color('cyan', '\n$ sudo apt-get install python3-pip')
        os.system('sudo apt-get install python3-pip')
        Install.__print_color('cyan', '\n$ sudo python3 -m pip install --user --upgrade pip==9.0.3')
        os.system('sudo python3 -m pip install --user --upgrade pip==9.0.3')
        Install.__print_color('cyan', '\n$ pip3 install setuptools')
        os.system('pip3 install setuptools')
        for item in lib_list:
            if item != '':
                pip_cmd = 'pip3 install ' + item
                print()
                Install.__print_color("purple", "$ " + pip_cmd)
                if not Install.DISABLE_INSTALL():
                    os.system(pip_cmd)

    @staticmethod
    def check_python_pkg(mod):
        try:
            find_module(mod)
            return True
        except ImportError:
            return False

    @staticmethod
    def check_apt_pkg(package_name):
        cache = apt.Cache()
        if cache[package_name].is_installed:
            #print("YES it's installed")
            return True
        else:
            # print("NO it's NOT installed")
            return False

    @staticmethod
    def __print_pkg_status(list_pkg, check_function):
        maxlen = 0
        for item in list_pkg:
            if maxlen < len(item):
                maxlen = len(item)
        padding_size_header = maxlen - 3 + 1
        header = "pkg" + " " * padding_size_header + ":  Status"
        hline = "-" * (padding_size_header + 3 + 10)
        print(header)
        print(hline)
        for item in list_pkg:
            padding_size = maxlen - len(item) + 1
            padding = ' ' * padding_size
            pkg_status = check_function(item)
            if pkg_status:
                Install.__print_color("cyan", item + padding + ":  " + "Installed", end="\n")
            else:
                Install.__print_color("red", item + padding + ":  " + "Missing!", end="\n")

    @staticmethod
    def print_pkg_status(list_pkg, tool):
        if tool == 'apt':
            Install.__print_pkg_status(list_pkg, Install.check_apt_pkg)
        elif tool == 'pip':
            Install.__print_pkg_status(list_pkg, Install.check_python_pkg)
        else:
            Install.__print_color('red', 'select apt or pip as tool')

    @staticmethod
    def apt_install(lib_list):
        apt_up = 'sudo apt-get update'
        Install.__print_color("cyan", "\n$ " + apt_up)
        if not Install.DISABLE_INSTALL():
            os.system(apt_up)
        for item in lib_list:
            print(item)
            if item != '':
                apt_cmd = 'sudo apt-get install ' + item
                Install.__print_color("cyan", "\n$ " + apt_cmd)
                if not Install.DISABLE_INSTALL():
                    os.system(apt_cmd)

if __name__ == '__main__':
    Install.pip_install(['apt', 'numpy'])
    Install.apt_install(['aptitude', 'vim'])
    Install.print_pkg_status(['apt', 'numpy'], 'apt')
    Install.print_pkg_status(['aptitude', 'vim'], 'pip')
