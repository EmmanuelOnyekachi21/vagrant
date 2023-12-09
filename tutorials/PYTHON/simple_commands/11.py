import argparse

parser = argparse.ArgumentParser(description='Get information about files')
parser.add_argument('files', nargs='+', help='list of files to process')
parser.add_argument('-v', '--verbose', action='store_true', help='increase output verbosity')
parser.add_argument('-t', '--type', choices=['txt', 'csv'], default='txt', help='file type to process')
args = parser.parse_args()

print("Files to process:", args.files)
print("File type chosen:", args.type)
if args.verbose:
    print("Verbose mode activated!")


