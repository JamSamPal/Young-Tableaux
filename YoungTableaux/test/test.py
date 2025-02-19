import numpy as np
import struct
import subprocess

from pathlib import Path

executable = Path(__file__).parent / "../src/main"
bin = Path(__file__).parent.parent.parent / "partitionNumber.bin"

def YoungTableauxTest(order:int):
    # we run the executable with arguments then grab the number of
    # diagrams
    subprocess.run(f"{str(executable)} {str(order)}", shell=True)
    
    data = bin.read_bytes()

    numberDiagrams = struct.unpack('I' * (len(data) // 4), data)[0]

    assert numberDiagrams == count_partitions(order)

    print("Test Passed")


def count_partitions(n):
    # Create a list to store the number of partitions for each number up to n
    partitions = [0] * (n + 1)
    partitions[0] = 1

    for i in range(1, n + 1):
        for j in range(i, n + 1):
            partitions[j] += partitions[j - i]

    return partitions[n]