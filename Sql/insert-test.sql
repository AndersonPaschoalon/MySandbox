begin transaction;


insert into Traces(traceName, captureDate, commentaries, traceID) values ("skype-trace", "01/04/2017", "testando", 01);

insert into Flows(traceID, flowID, protocolLink) values (01, 0, "zero");
insert into Flows(traceID, flowID, protocolLink) values (01, 1, "um");
insert into Flows(traceID, flowID, protocolLink) values (01, 2, "dois");
insert into Flows(traceID, flowID, protocolLink) values (01, 3, "tres");
insert into Flows(traceID, flowID, protocolLink) values (01, 4, "quatro");

insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 0, "aa");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 1, "bb");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 2, "cc");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 3, "dd");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 4, "ee");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 5, "ff");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 6, "gg");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 7, "hh");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 8, "ii");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 9, "jj");

insert into Packets(traceID, flowID, seq, ttl) values (01, 1, 10, "kk");
insert into Packets(traceID, flowID, seq, ttl) values (01, 1, 11, "ll");
insert into Packets(traceID, flowID, seq, ttl) values (01, 1, 12, "mm");
insert into Packets(traceID, flowID, seq, ttl) values (01, 1, 13, "nn");
insert into Packets(traceID, flowID, seq, ttl) values (01, 1, 14, "oo");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 15, "pp");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 16, "qq");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 17, "rr");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 18, "ss");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 19, "tt");

insert into Packets(traceID, flowID, seq, ttl) values (01, 3, 20, "uu");
insert into Packets(traceID, flowID, seq, ttl) values (01, 4, 21, "vv");
insert into Packets(traceID, flowID, seq, ttl) values (01, 4, 22, "xx");
insert into Packets(traceID, flowID, seq, ttl) values (01, 4, 23, "zz");
insert into Packets(traceID, flowID, seq, ttl) values (01, 4, 24, "ww");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 25, "yy");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 26, "11");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 27, "22");
insert into Packets(traceID, flowID, seq, ttl) values (01, 0, 28, "33");
insert into Packets(traceID, flowID, seq, ttl) values (01, 4, 29, "44");

commit transaction;