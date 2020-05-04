import multiprocessing as mp
import bisecc as bs

# Setup a list of processes that we want to run
processes = [mp.Process(target=bs.f0, args=(-2, 4)) ]

# Run processes
for p in processes:
    p.start()

# Exit the completed processes
for p in processes:
    p.join()

# Get process results from the output queue
results = [output.get() for p in processes]

print(results)

