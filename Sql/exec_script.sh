#!/bin/bash

rm trace.db 
sqlite3 trace.db < create-test.sql
sqlite3 trace.db < insert-test.sql
sqlite3 trace.db   ".headers ON" ".mode column" "select * from Packets;" "select * from Flows;" "select * from Traces"