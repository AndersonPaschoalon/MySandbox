create table if not exists Traces(
	traceName varchar;
	captureDate varchar;
	commentaries  varchar;
	constraint Traces_pk primary key (traceName);
);
/*
create table if not exists Flows(
	tracename varchar;
	flowID integer;
	someData varchar;
	constraint flows_pk primary key (traceName, flowID);
	constraint flows_fk foreign key (traceName);
);

create table if not exists Packets(
	traceName varchar;
	flowID integer;
	seq integer;
	someData varchar;
	constraint packets_pk primary key (traceName, flowID, seq);
	constraint packets_fk foreign key (traceName, flowID);
);
*/