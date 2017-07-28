#!/usr/bin/python3
import argparse
import re


class SnifferManager:
    @staticmethod
    def new(trace_name='trace-name', trace_type='live', target_name='eth0', comment=''):
        print("Subbcomand new> trace_name:" + trace_name + " trace_type:" + trace_type + " target_name:" +
              target_name + " comment:" + comment)

    @staticmethod
    def rm(trace_name='trace-name'):
        print("Subbcomand rm> trace_name:" + trace_name)

    @staticmethod
    def list():
        print("Subbcomand list>")


def livepcap_regex_type(s, pat=re.compile(r"(pcap|live)$")):
    if not pat.match(s):
        raise argparse.ArgumentTypeError
    return s


def subcommand_new(args):
    if args.comment == None:
        args.comment = ""
    SnifferManager.new(trace_name=args.trace_name, trace_type=args.trace_type, target_name=args.target_name,
                       comment=args.comment)
    # print(
    #    "Subbcomand new> trace_name:" + args.trace_name + " trace_type:" + args.trace_type + " target_name:" + args.target_name + " comment:" + args.comment)


def subcommand_rm(args):
    SnifferManager.rm(trace_name=args.trace_name)
    # print("Subbcomand rm> trace_name:" + args.trace_name)


def subcommand_list():
    SnifferManager.list()
    # print("Subbcomand list>")


if __name__ == '__main__':
    # create the top-level parser
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers()

    # create the parse for the "new" command
    parser_new = subparsers.add_parser('new', help='Process a new traffic trace eigter live or pcap')
    parser_new.add_argument('trace_name', type=str, default='trace-name',
                            help='Trace name that will be recorded in the database')
    parser_new.add_argument('trace_type', type=livepcap_regex_type, default='live',
                            help='Input trace type, live or pcap')
    parser_new.add_argument('target_name', type=str, default='eth0',
                            help='Target trace, the internet interface (eg. eth0) name or the pcap file')
    parser_new.add_argument('--comment', help='description of the trace (optional)')
    parser_new.set_defaults(func=subcommand_new)

    # create the parser for the "rm" command
    parser_rm = subparsers.add_parser('rm', help='Remove a trace from the database')
    parser_rm.add_argument('trace_name')
    parser_rm.set_defaults(func=subcommand_rm)

    # create the parser for the "list" command
    parser_list = subparsers.add_parser('list', help='Display all the trace capture table')
    parser_list.set_defaults(func=subcommand_list)

    # parse the args and call whatever function was selected
    args = parser.parse_args()
    args.func(args)
