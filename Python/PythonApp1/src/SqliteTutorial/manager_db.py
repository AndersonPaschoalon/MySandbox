# !python3
# manager_db.py
# -*- coding: utf-8 -*-
"""
    Este App gerencia um banco de dados sqlite3.
    Pode-se usar o modo interativo com python ou python3 ou ipython ou ipython3.

    Banco de dados: 'clientes.db'
    Schema: 'clientes_schema.sql'
    Tabela: 'clientes'
"""

#import os
import sqlite3
#import io
#import datetime
# import names
#import csv


# from gen_random_values import *


class Connect(object):
    ''' A classe Connect representa o banco de dados. '''

    def __init__(self, db_name):
        try:
            # conectando...
            self.conn = sqlite3.connect(db_name)
            self.cursor = self.conn.cursor()
            # imprimindo nome do banco
            print("Banco:", db_name)
            # lendo a versão do SQLite
            self.cursor.execute('SELECT SQLITE_VERSION()')
            self.data = self.cursor.fetchone()
            # imprimindo a versão do SQLite
            print("SQLite version: %s" % self.data)
        except sqlite3.Error:
            print("Erro ao abrir banco.")
            return False

    def commit_db(self):
        if self.conn:
            self.conn.commit()

    def close_db(self):
        if self.conn:
            self.conn.close()
            print("Conexão fechada.")


class ClientesDb(object):
    tb_name = 'clientes'

    ''' A classe ClientesDb representa um cliente no banco de dados. '''

    def __init__(self):
        self.db = Connect('db/clientes.db')
        self.tb_name

    # create_schema
    def criar_schema(self, schema_name='sql/clientes_schema.sql'):
        print("Criando tabela %s ..." % self.tb_name)

        try:
            with open(schema_name, 'rt') as f:
                schema = f.read()
                self.db.cursor.executescript(schema)
        except sqlite3.Error:
            print("Aviso: A tabela %s já existe." % self.tb_name)
            return False

        print("Tabela %s criada com sucesso." % self.tb_name)




#if __name__ == '__main__':
