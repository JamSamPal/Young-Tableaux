import struct
import subprocess
import numpy as np
from pathlib import Path

executable = Path(__file__).parent.parent / "src/main"
bin = Path(__file__).parent.parent / "partitionNumber.bin"


def test_YoungTableaux_4():
    # we run the executable with arguments then grab the number of
    # diagrams
    subprocess.run(f"{str(executable)} {str(4)}", shell=True)

    numberDiagrams = np.loadtxt("partitionNumber.txt")

    assert numberDiagrams == count_partitions(4)


def test_YoungTableaux_10():
    # we run the executable with arguments then grab the number of
    # diagrams
    subprocess.run(f"{str(executable)} {str(10)}", shell=True)
    numberDiagrams = np.loadtxt("partitionNumber.txt")

    assert numberDiagrams == count_partitions(10)


def count_partitions(n):
    # Create a list to store the number of partitions for each number up to n
    partitions = [0] * (n + 1)
    partitions[0] = 1

    for i in range(1, n + 1):
        for j in range(i, n + 1):
            partitions[j] += partitions[j - i]

    return partitions[n]
