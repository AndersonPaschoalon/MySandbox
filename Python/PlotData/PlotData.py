# sudo apt-get build-dep python-matplotlib
# sudo pip3 install matplotlib
import os
import sys
import re
import matplotlib.pyplot as plt
import numpy as np


class EasyPlot:
    def __init__(self, plot_dir='', data_dir='', xlabel='', ylabel='', title='',
                 sizeratio='0', linestyle1='r-', linestyle2='b-', linestyle3='g-', linestyle4='v-',
                 legend1='', legend2='', legend3='', legend4='', line_width='2', font_size=15, font_name='Helvetica'):
        self.__plot_dir = plot_dir
        self.__data_dir = data_dir
        self.__xlabel = xlabel
        self.__ylabel = ylabel
        self.__title = title
        self.__sizeratio = sizeratio
        self.__linestyle1 = linestyle1
        self.__linestyle2 = linestyle2
        self.__linestyle3 = linestyle3
        self.__linestyle4 = linestyle4
        self.__legend1 = legend1
        self.__legend2 = legend2
        self.__legend3 = legend3
        self.__legend4 = legend4
        self.__lw = line_width
        self.__data = []
        self.__font = {'fontname': + font_name, 'size': str(font_size), 'color':'black', 'weight':'normal',
              'verticalalignment':'bottom'}

    @staticmethod
    def __column(data, i):
        data_c = [column[i] for column in data]
        return data_c

    def __load(self, datafile):
        self.__data = []
        self.__data = np.genfromtxt(datafile, delimiter=',')


    def plot_config(self, plot_dir='', data_dir='', font='', xlabel='', ylabel='',
                    title='', sizeratio='', linestyle1='', linestyle2='', linestyle3='',
                    linestyle4='', legend1='', legend2='', legend3='', legend4='', line_width='', type=''):
        """
        Configure plot. Some notes:
        (1) the type of curve must be configured by the  artuments linestyle_i an by the argument type. lynestyle_i
        defines if the
        :param plot_dir: directory whre the plots will be stored
        :param data_dir: directory where the data used on the plots are
        :param font: font configuration string using the format '<fontname>,<fontsize>'. For example: 'Helvetica,15'
        :param xlabel: label of x axes
        :param ylabel: label of y axes
        :param title: title on the upper part of the plot
        :param sizeratio: size ratio of the plot, default 0.
        :param linestyle1: stype of the  plot line.
        :param linestyle2:
        :param linestyle3:
        :param linestyle4:
        :param legend1:
        :param legend2:
        :param legend3:
        :param legend4:
        :param type: possible values are ('lines'|'linespoints'|'points'), except for plots 2functionxyxy, whre the
                values are ('points-points'|'points-lines'|'lines-lines'|'lines-points')
        :param line_width:
        :return:
        """
        if plot_dir != '':
            self.__plot_dir = plot_dir
        if data_dir != '':
            self.__data_dir = data_dir
        if font != '':
            self.__font = font
        if xlabel != '':
            self.__xlabel = xlabel
        if ylabel != '':
            self.__ylabel = ylabel
        if title != '':
            self.__title = title
        if sizeratio != '':
            self.__sizeratio = sizeratio
        if linestyle1 != '':
            self.__linestyle1 = linestyle1
        if linestyle2 != '':
            self.__linestyle2 = linestyle2
        if linestyle3 != '':
            self.__linestyle3 = linestyle3
        if linestyle4 != '':
            self.__linestyle4 = linestyle4
        if legend1 != '':
            self.__legend1 = legend1
        if legend2 != '':
            self.__legend2 = legend2
        if legend3 != '':
            self.__legend3 = legend3
        if legend4 != '':
            self.__legend4 = legend4
        if line_width != '':
            self.__lw = line_width

    def plot_function(self, filename='', datafile=""):
        fig = plt.figure()
        if self.__title != '':
            plt.title(self.__title)
        if self.__xlabel != '':
            plt.xlabel(self.__xlabel)
        if self.__ylabel != '':
            plt.ylabel(self.__ylabel)
        if

        filename = self.__plot_dir + '/' + filename
        datafile = self.__data_dir + '/' + datafile


        fig.savefig( self.__plot_dir + '/' + filename, bbox_inches='tight')


    def plot_2f1error(self, filename="", datafile=""):
        print('todo')

    def plot_2function(self, filename="", datafile=""):
        print('todo')

    def plot_tickbar_label(self, filename="", datafile=""):
        print('todo')

    def plot_2f2data(self, filename="", datafile1="", datafile2=""):
        print('todo')

    def plot_2functionxyxy(self, filename="", datafile=""):
        print('todo')

    def plot_ferror(self, filename="", datafile=""):
        print('todo')

    def plot_xtickerror(self, filename="", datafile=""):
        print('todo')

    def plot_2f2data_log2(self, filename="", datafile1="", datafile2=""):
        print('todo')

    def plot_3function(self, filename="", datafile=""):
        print('todo')



    def plot_2f2data_log(self, filename="", datafile1="", datafile2=""):
        print('todo')

    def plot_4function(self, filename="", datafile=""):
        print('todo')

    def plot_tickbar(self, filename="", datafile=""):
        print('todo')


if __name__ == "__main__":
    data = np.genfromtxt('data1.csv', delimiter=',')
    print(data)
    data_c1 = [column[0] for column in data]
    print(data_c1)
