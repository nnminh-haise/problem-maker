import os


def generateInput(generator: str, outputFile: str):
    print(f"[INFO] Generating Testcase Input!")
    os.system(f"c++ --std=c++17 -o generator {generator}")
    os.system(f"./generator >> testcases/{outputFile}")
    print(f"[INFO] Complete!")


def generateOutput(solution: str, inputFile: str, outputFile: str):
    print(f"[INFO] Generating Testcase Output!")
    os.system(f"c++ --std=c++17 -o solution {solution}")
    os.system(f"./solution < testcases/{inputFile} >> testcases/{outputFile}")
    print(f"[INFO] Complete!")


def zipTestcase(numberOfTestcase: int):
    command: str = "Compress-Archive -Path C:/Users/Haise/OneDrive/Desktop/problem-maker/testcases/*.* -DestinationPath C:/Users/Haise/OneDrive/Desktop/problem-maker/testcases.zip"
        
    os.system(command)


def removeFiles(numberOfTestcase: int):
    for i in range(1, numberOfTestcase + 1):
        os.system(f"rm {i}.in {i}.out")


def main():
    generator: str = "generator.cpp"
    solution: str = "solution.cpp"

    NUMBER_OF_TESTCASES: int = 10

    currentTestcase = 0

    os.system(f"mkdir testcases")

    while currentTestcase is not NUMBER_OF_TESTCASES:
        currentTestcase += 1
        
        print(f"[INFO] Creating test {currentTestcase}!")
        generateInput(generator, f"{currentTestcase}.in")
        generateOutput(solution, f"{currentTestcase}.in", f"{currentTestcase}.out")
        print(f"[INFO] Test {currentTestcase} is created!")
    
    # zipTestcase(NUMBER_OF_TESTCASES)
    # removeFiles(NUMBER_OF_TESTCASES)
    

main()
