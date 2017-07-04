import sqlite3
import os


class Database(object):
    ''' The class Database represents the SQLite database interface. It jsut hide some commands and checks.'''

    def __init__(self, database_name, verbose=False):
        '''
        :param database_name:
        :param verbose:
        '''
        self.verbose = verbose
        self.db_name = database_name
        try:
            # conectando...
            self.conn = sqlite3.connect(self.db_name)
            self.cursor = self.conn.cursor()
            # imprimindo nome do banco
            if self.verbose == True:
                print("Database:", self.db_name)
                # lendo a versão do SQLite
                self.cursor.execute('SELECT SQLITE_VERSION()')
                self.data = self.cursor.fetchone()
                # imprimindo a versão do SQLite
                print("SQLite version: %s" % self.data)
        except:
            print("Error oppening database " + self.db_name)
            return False

    def commit_db(self):
        '''
        Commit last operation on the database.
        :return:
        '''
        if self.conn:
            self.conn.commit()

    def close_db(self):
        '''
        Close connection to the database
        :return:
        '''
        if self.conn:
            self.conn.close()
            if self.verbose == True:
                print("Database " + self.db_name + " connection closed")


class TraceDatabaseManager:
    ''' Database manager. It is an interface for the creation and management of the trace database'''

    def __init__(self, verbose=True):
        '''
        Connect to the database. If it does not exists, create a new one.
        :param verbose: Prints outputs about actions
        '''
        self.database_dir = 'db/'
        self.database_name = self.database_dir + 'clientes.db'
        self.verbose = verbose
        os.system('mkdir -p ' + self.database_dir )
        self.db = Database(self.database_name, verbose=self.verbose)
        try:
            # creating table (schema)
            self.db.cursor.execute("""
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
        except sqlite3.OperationalError as e:
            if self.verbose == True:
                print(str(e))
        print('Database ' + self.database_name + ' created successfully')

    def insert(self, theList):
        '''

        :param theList:
        :return:
        '''
        try:
            self.db.cursor.executemany("""
            INSERT INTO clientes (nome, idade, cpf, email, fone, cidade, uf, criado_em)
            VALUES (?,?,?,?,?,?,?,?)
            """, theList)
            # recording insert
            self.db.commit_db()
            print("Dados inseridos da lista com sucesso: %s registros." %
                  len(theList))
            return True
        except sqlite3.IntegrityError as e:
            print(str(e))
            return False

    def getTraceId(self, traceName):
        ttt = self.db.cursor.execute('SELECT id FROM clientes WHERE cidade = ?;', ('Campinas',))
        traceIdList = self.db.cursor.fetchone()
        print(traceIdList)
        print(ttt)
        #return traceIdList[0]
        return 'kkkk'

    def delete_id(self, table_id):
        '''
        Delete a row based on a table id, and all its subtables
        :param table_id:
        :return:
        '''
        self.db.cursor.execute("""
        DELETE FROM clientes
        WHERE id = ?
        """, str(table_id))
        # recording delete
        self.db.commit_db()

    def rm_database(self):
        '''
        Delete physically created database
        :return:
        '''
        os.system('rm -f ' + self.database_name)

    def print(self, table_name):
        '''
        Prints a formated table on the standard output.
        :param table_name: table to be printed
        :return:
        '''
        os.system(
            'sqlite3 ' + self.database_name + '  ".headers ON" ".mode column" "select * from ' + table_name + ';"')


if __name__ == '__main__':
    db = TraceDatabaseManager(verbose=True)
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
    db.print('clientes')
    print("")
    db.delete_id(3)
    db.print('clientes')
    print('Trace ID of Bianca Antunes is ' + db.getTraceId('Bianca Antunes'))
    #db.rm_database()
