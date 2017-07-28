import os

from .easysqlite import Database


class TraceDatabaseManager:
    ''' Database manager. It is an interface for the creation and management of the trace database'''

    def __init__(self):
        '''
        Connect to the database. If it does not exists, create a new one.
        '''
        self.database_dir = 'db/'
        self.database_name = self.database_dir + 'clientes.db'
        os.system('mkdir -p ' + self.database_dir)
        self.db = Database(self.database_name)
        self.db.query("""
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
        """);

    def insert(self, theList):
        '''
        Tries to insert a list of elements. Returns the last ID case succed. Returns -1 otherwise
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

        except sqlite3.IntegrityError as e:
            print(str(e))
            return -1

    def getTraceId(self, traceName):
        ttt = self.db.cursor.execute('SELECT id FROM clientes WHERE cidade = ?;', ('Campinas',))
        traceIdList = self.db.cursor.fetchone()
        return traceIdList[0]

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
