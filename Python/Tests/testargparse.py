# Tutorial
# https://docs.python.org/2/howto/argparse.html

import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--kill", help="Ends the packet capture and traffic generation", action="store_true")
parser.add_argument("--nrun", type=int, help="Number of the run")

args = parser.parse_args()
if args.kill:
    print("verbosity turned on")
if args.nrun:
    print("nruns: "+str(args.nrun))