CREATE TABLE if not exists Traces (
	traceName varchar,
	captureDate text,
	commentaries text,
	traceID integer,
	constraint Traces_pk primary key (traceName)
);

CREATE TABLE if not exists Flows (
	flowID integer,
	protocolLink varchar,
	protocolNetwork varchar,
	protocolTransport varchar,
	macSrc varchar,
	macDst varchar,
	netSrc varchar,
	netDst varchar,
	portSrc integer,
	portDst integer,
	traceID integer,
	constraint flows_fk foreign key (traceID) references Traces(traceID),
	constraint flows_pk primary key (traceID, flowID)
);

CREATE TABLE if not exists Packets (
	seq integer,
	arrivalTime varchar,
	pktSize integer,
	ttl integer,
	winSize integer,
	flowID integer,
	traceID integer,
	constraint packets_pk primary key (traceID, flowID, seq),
	constraint packets_fk foreign key (traceID, flowID) references Flows(traceID, flowID)
);

/*

create table if not exists Traces(
	traceName varchar,
	captureDate varchar,
	commentaries  varchar,
	constraint Traces_pk primary key (traceName)
);


create table if not exists Flows(
	tracename varchar,
	flowID integer,
	someData varchar,
	constraint flows_fk foreign key (traceName) references Traces(traceName),
	constraint flows_pk primary key (traceName, flowID)
);


create table if not exists Packets(
	traceName varchar,
	flowID integer,
	seq integer,
	someData varchar,
	constraint packets_pk primary key (traceName, flowID, seq),
	constraint packets_fk foreign key (traceName, flowID) references Flows(traceName, flowID)
);

*/