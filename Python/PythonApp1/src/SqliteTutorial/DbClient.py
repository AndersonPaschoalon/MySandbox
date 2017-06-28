import sqlite3
import os

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

class dbClient:
    def __init__(self, verbose=True):
        self.database_name = 'db/clientes.db'
        # conectando...
        conn = sqlite3.connect(self.database_name)
        # definindo um cursor
        cursor = conn.cursor()
        try:
            # criando a tabela (schema)
            cursor.execute("""
            CREATE TABLE clientes (
                id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
                nome TEXT NOT NULL,
                idade INTEGER,
                cpf	VARCHAR(11) NOT NULL,
                email TEXT NOT NULL,
                fone TEXT,
                cidade TEXT,
                uf VARCHAR(2) NOT NULL,
                criado_em DATE NOT NULL
            );
            """)
        except sqlite3.OperationalError:
            if verbose == True:
                print('table already exists')

        print('Tabela criada com sucesso.')
        # desconectando...
        conn.close()
        self.db = Connect(self.database)

    def rm_table(self):
        os.system('rm -f ' + self.database_name)

    def insert(self, theList):
        try:
            self.db.cursor.executemany("""
            INSERT INTO clientes (nome, idade, cpf, email, fone, cidade, uf, criado_em)
            VALUES (?,?,?,?,?,?,?,?)
            """, theList)
            # gravando no bd
            self.db.commit_db()
            print("Dados inseridos da lista com sucesso: %s registros." %
                  len(theList))
        except sqlite3.IntegrityError:
            print("Aviso: O email deve ser único.")
            return False


if __name__ == '__main__':

    db = dbClient()

    # criando uma lista de dados
    lista = [('Agenor de Sousa', 23, '12345678901', 'agenor@email.com',
              '(10) 8300-0000', 'Salvador', 'BA', '2014-07-29 11:23:01.199001'),
             ('Bianca Antunes', 21, '12345678902', 'bianca@email.com',
              '(10) 8350-0001', 'Fortaleza', 'CE', '2014-07-28 11:23:02.199002'),
             ('Carla Ribeiro', 30, '12345678903', 'carla@email.com',
              '(10) 8377-0002', 'Campinas', 'SP', '2014-07-28 11:23:03.199003'),
             ('Fabiana de Almeida', 25, '12345678904', 'fabiana@email.com',
              '(10) 8388-0003', 'São Paulo', 'SP', '2014-07-29 11:23:04.199004'),
             ]

    db.insert(lista)

    db.rm_table()