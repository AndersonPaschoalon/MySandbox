# 07_update_data.py
import sqlite3

conn = sqlite3.connect('db/clientes.db')
cursor = conn.cursor()

id_cliente = 11
novo_fone = '11-1000-2014'
novo_criado_em = '2017-06-23'

# alterando os dados da tabela
cursor.execute("""
UPDATE clientes
SET fone = ?, criado_em = ?, cidade = ?
WHERE id = ?
""", (novo_fone, novo_criado_em,'Zion',id_cliente))

conn.commit()

print('Dados atualizados com sucesso.')

conn.close()