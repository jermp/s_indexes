import sys, os

index_filename = sys.argv[1]
query_logs_path = sys.argv[2]
runs = 3

for i in xrange(0, runs):
    os.system("./decode " + index_filename)

for i in xrange(0, runs):
    os.system("./intersect " + index_filename + " 1000 < " + query_logs_path + "/pairwise_queries.1k")

for i in xrange(0, runs):
    os.system("./union " + index_filename + " 1000 < " + query_logs_path + "/pairwise_queries.1k")

for i in xrange(0, runs):
    os.system("./select " + index_filename + " 1000 < " + query_logs_path + "/select_queries.1k")

for i in xrange(0, runs):
    os.system("./next_geq " + index_filename + " 1000 < " + query_logs_path + "/next_geq_queries.1k")