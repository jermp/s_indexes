import sys, os

input_filename = sys.argv[1]
output_filename = sys.argv[2]

os.system("./build " + input_filename + " 0.01 -o " + output_filename + ".0.01.bin")
os.system("./build " + input_filename + " 0.001 -o " + output_filename + ".0.001.bin")
os.system("./build " + input_filename + " 0.0001 -o " + output_filename + ".0.0001.bin")
